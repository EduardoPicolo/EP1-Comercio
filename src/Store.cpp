#include "Store.hpp"

void Store::start_session(){
    system("clear");
    cout<< "============================== Start Session ==============================" <<endl;
    cout<<'\t'<<left<<setw(15)<< "[1]:Sign in"<<setfill(' ')<<setw(16)<< "[2]:Register"<<setfill(' ')<< "[3]:Exit"<< endl;
    Store::input_option(3, "Enter [1] to login, [2] to register or [3] to exit.");
    switch (option){
        case 1:
            Logon::sign_in();
        break;
        case 2:
            Logon::sign_up();
        break;
        case 3:
            exit(EXIT_SUCCESS);
        break;
        default:
            throw e_option;
        break;
    }
    try{
        Store::main_menu();
    }catch(Exception& e){
        cout<<'\t'<< e.what() <<endl;
        cout<< "Returning to main menu..." <<endl;
        Store::main_menu();
    }
}

void Store::main_menu(){
    cout<< "================================ Main Menu ================================" <<endl;
    if(client->get_cpf()=="00000000011"){
        cout<<'\t'<<left<<setw(12)<< "[1]:Shop"<<setfill(' ')<<setw(22)<< "[2]:Recommendations"<<setfill(' ')
        <<setw(15)<< "[3]:Profile"<<setfill(' ')<<setw(13)<< "[4]:Logout"<<setfill(' ')<< "[5]:Stock"<<endl;
        Store::input_option(5 ,"Enter [1] to shop, [2] for recommendations, [3] to edit profile, [4] to logout or [5] for stock.");
    }
    else{
        cout<<'\t'<<left<<setw(12)<< "[1]:Shop"<<setfill(' ')<<setw(22)<< "[2]:Recommendations"<<setfill(' ')<<setw(15)<< "[3]:Profile"<<setfill(' ')<< "[4]:Logout"<<endl;
        Store::input_option(4 ,"Enter [1] to shop, [2] for recommendations, [3] to edit profile or [4] to logout.");
    }

    switch(option){
        case 1:
            Store::shop_mode();
        break;
        case 2:
            Store::recommendation_mode();
        break;
        case 3:
            client->edit_data();
        break;
        case 4:
            system("clear");
            *client = Client();
            Store::start_session();
        break;
        case 5:
            Store::stock_mode();
        break;
        default:
         throw e_option;
        break;
    }
    Store::main_menu();
}

void Store::stock_mode(){
    cout<< "================================= *STOCK* =================================" <<endl;
    cout<<'\t'<<left<<setw(19)<< "[1]:Add product"<<setfill(' ')<<setw(23)<< "[2]:Replenish stock"<<setfill(' ')<< "[3]:Main menu"<<endl;
    Store::input_option(3, "Enter [1] to add product, [2] to replenish stock or [3] to cancel.");
    switch (option){
        case 1:
            Stock::add_product();
        break;
        case 2:
            Stock::restock();
        break;
        case 3:
            cout<< "Returning to main menu..."<<endl;
            Store::main_menu();
        break;
        default:
            throw e_option;
        break;
    }
    cout<< "Returning to stock..."<<endl;
    Store::stock_mode();
}

void Store::shop_mode(){
    system("clear");
    cout<< "================================= *SHOP* =================================" <<endl;

    Cart cart;
    int product, amount; string category;
    vector<Product> productList = Stock::get_stock();  vector<string> product_categories;
    map<string, vector<Product*>> catalogue;
    for(size_t i=0; i<productList.size(); i++){
        product_categories = split(productList[i].get_category(), '/');
        for(auto& category : product_categories){
            catalogue[category].push_back(&productList[i]);
        }
    }

    do{
        cout<<"\t\t\t" "*CATALOGUE*"<<endl;
        cout<<"\t\t"<< "*CATEGORIES*"<<endl;
        for(auto it = catalogue.begin(); it!=catalogue.end(); it++){
            cout<<"\t|"<<left<<setw(15)<< it->first<<setfill(' '); 
            if((++it)!=catalogue.end()){
                cout<<"|"<<left<<setw(15)<< it->first<<setfill(' ')<<"|"<<endl;
            }
            else{ cout<<endl; break;}
        }
        cout<<endl;
        cout<< "Category: ";
        cin>>category;
            lowercase(category);
        while(!(catalogue.find(category)!=catalogue.end())){
            cout<<'\t'<< "Invalid category"<<endl;
            cout<< "Category: ";
            cin>>category;
                lowercase(category);
        }
        cout<<endl;
        cout<<"\t\t\t"<< "*PRODUCTS*"<<endl;
        cout<<'\t'<<"Index"<<'\t'<<left<<setw(20)<<"[Product]"<<setfill(' ')<<setw(11)<<"Price"<<setfill(' ')<<"Amount"<<endl;
        for(size_t i=0; i<catalogue[category].size(); i++){
            cout<<'\t'<<'['<<i<<']'<<'\t'; catalogue[category][i]->displayProduct();
        }
        cout<<endl;
        product = get_input<int>("Product index: ");
        while((product<0)||((unsigned int)product>catalogue[category].size()-1)){
            cout<<'\t'<< "Invalid product index"<<endl;
            product = get_input<int>("Product index: ");
        }
        if(catalogue[category][product]->get_amount()==0){
            cout<<'\t'<< catalogue[category][product]->get_product_name() + " is currently out of stock" <<endl;
            option = 1;
            continue;
        }
        amount = get_input<int>("Amount: ");
        while(!Stock::verify_amount(*catalogue[category][product], amount)){
            cout<<'\t'<< "Invalid amount"<<endl;
            amount = get_input<int>("Amount: ");
        }
        cart.add_product(*catalogue[category][product], amount);

        cout<<'\t'<<left<<setw(25)<< "[1]:Continue shopping"<<setfill(' ')<<setw(24)<< "[2]:Confirm purchase"<<setfill(' ')<< "[3]:Cancel Purchase"<<endl;
        Store::input_option(3, "Enter [1] to continue shopping, [2] to confirm purchase or [3] to cancel purchase");
        switch(option){
            case 1:
                catalogue[category][product]->set_amount(catalogue[category][product]->get_amount()-amount); //Update catalogue
            break;
            case 2:
                cart.confirm_purchase();
            break;
            case 3:
                cart.cancel_purchase();
            break;
            default:
                throw e_option;
            break;
        }
    } while(option==1);
}

void Store::recommendation_mode(){
    cout<< "===========================================================================" <<endl;
    if(client->get_name().length()==0){
        cout<< "A client must be logged in to see recommendations."<<endl;
        return;
    }
    if(client->get_shop_history().size()<=1){
        cout<<"\t"<< "Customer doesn't have a purchase history!"<<endl;
        cout<< "Returning to main menu..." <<endl;
        return;
    }

    int cont = 1;
    vector<Product> productList = Stock::get_stock();
    map<string, float> shop_history = client->get_shop_history();
    vector<pair<string, float>> sorted_history = order(shop_history);
    map<string, vector<Product>> catalogue;
    vector<string> product_categories;

    for(size_t i=0; i<productList.size(); i++){
        product_categories = split(productList[i].get_category(), '/');
        for(auto& category : product_categories){
            catalogue[category].push_back(productList[i]);
        }
    }

    srand(time(NULL));
    int randInt;
    cout<<"\t\t\t"<< "*RECOMMENDED PRODUCTS*"<<endl;
    cout<<'\t'<<left<<setw(18)<<"Product"<<setfill(' ')<<setw(11)<<"Price"<<setfill(' ')<<"Amount"<<endl;
    for(auto category=sorted_history.cbegin(); category!=sorted_history.cend(); category++){
        if(category->first == "TOTAL")
            continue;
        // cout<< category->first<<endl;
        randInt = rand() % catalogue[category->first].size();
        cout<<'\t'<< cont <<"."; catalogue[category->first][randInt].displayProduct();
        cont++;
    }
    cout<<endl;
}

void Store::input_option(const int& n_options, const string& e_message){
    // vector<int> options(n_options);
    // iota(options.begin(), options.end(), 1);
    option = get_input<int>(">> ");
    // while(!(find(begin(options), end(options), option)!=end(options))){
        // cout<<'\t'<< "Invalid option. "<< e_message <<endl;
    //     option = get_input<int>(">> ");
    // }
    while(option<1||option>n_options){
        cout<<'\t'<< "Invalid option. "<< e_message <<endl;
        option = get_input<int>(">> ");
    }
}