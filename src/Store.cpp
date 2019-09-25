#include "Store.hpp"

void Store::start_session(){
    cout<< "============================== Start Session ==============================" <<endl;
    cout<<'\t'<<left<<setw(13)<< "1:Sign in"<<setfill(' ')<<setw(14)<< "2:Register"<<setfill(' ')<< "3:Exit"<< endl;
    Store::input_option(3, "Enter 1 to login, 2 to register or 3 to exit.");
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
        cout<<'\t'<<left<<setw(10)<< "1:Shop"<<setfill(' ')<<setw(20)<< "2:Recommendations"<<setfill(' ')
        <<setw(14)<< "3:Settings"<<setfill(' ')<<setw(11)<< "4:Logout"<<setfill(' ')<< "5:Stock"<<endl;
        Store::input_option(5 ,"Enter 1 to shop, 2 for recommendations, 3 to edit account, 4 to logout or 5 for stock.");
    }
    else{
        cout<<'\t'<<left<<setw(10)<< "1:Shop"<<setfill(' ')<<setw(20)<< "2:Recommendations"<<setfill(' ')<<setw(14)<< "3:Settings"<<setfill(' ')<< "4:Logout"<<endl;
        Store::input_option(4 ,"Enter 1 to shop, 2 for recommendations, 3 to edit account or 4 to logout.");
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
    cout<<'\t'<<left<<setw(17)<< "1:Add product"<<setfill(' ')<<setw(21)<< "2:Replenish stock"<<setfill(' ')<< "3:Main menu"<<endl;
    Store::input_option(3, "Enter 1 to add product, 2 to replenish stock or 3 to cancel.");
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
    cout<< "================================= *SHOP* =================================" <<endl;

    Cart cart;
    unsigned int product, amount; string category;
    vector<Product> productList = Stock::get_stock();
    map<string, vector<Product>> catalogue;
    for(size_t i=0; i<productList.size(); i++){
        catalogue[productList[i].get_category()].push_back(productList[i]);
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
        cout<< "Category: ";
        cin>>category;
            lowercase(category);
        while(!(catalogue.find(category)!=catalogue.end())){
            cout<<'\t'<< "Invalid category"<<endl;
            cout<< "Category: ";
            cin>>category;
            lowercase(category);
        }
        cout<<'\t'<<"Index"<<'\t'<<left<<setw(18)<<"Product"<<setfill(' ')<<setw(11)<<"Price"<<setfill(' ')<<"Amount"<<endl;
        for(size_t i=0; i<catalogue[category].size(); i++){
            cout<<'\t'<<i<<'\t'; catalogue[category][i].displayProduct();
        }
        cout<< "Product Index: ";
        cin>> product;
        while((product>catalogue[category].size()-1)||product<0){
            clear_fail_state();
            cout<<'\t'<< "Invalid product index"<<endl;
            cout<< "Product Index: ";
            cin>> product;
        }
        cout<< "Amount: ";
        cin>> amount;
        while(!Stock::verify_amount(catalogue[category][product], amount)){
            clear_fail_state();
            cout<< "Invalid amount"<<endl;
            cout<< "Amount: ";
            cin>> amount;
        }
        cart.add_product(catalogue[category][product], amount);

        cout<<'\t'<<left<<setw(23)<< "1:Continue shopping"<<setfill(' ')<<setw(22)<< "2:Confirm purchase"<<setfill(' ')<< "3:Cancel"<<endl;
        Store::input_option(3, "Enter 1 to continue shopping, 2 to confirm purchase or 3 to cancel purchase");
        switch(option){
            case 1:
                catalogue[category][product].set_amount(catalogue[category][product].get_amount()-amount); //Update catalogue
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
        // Store::main_menu();
        return;
    }

    int cont = 1;
    vector<Product> productList = Stock::get_stock();
    map<string, float> shop_history = client->get_shop_history();
        vector<pair<string, float>> sorted_history = order(shop_history);


    map<string, vector<Product>> catalogue;
    for(size_t i=0; i<productList.size(); i++){
        catalogue[productList[i].get_category()].push_back(productList[i]);
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
        cout<<'\t'<< cont <<". "; catalogue[category->first][randInt].displayProduct();
        cont++;
    }
    cout<<endl;
}

void Store::input_option(const int& n_options, const string& e_message){
    vector<int> options(n_options);
    iota(options.begin(), options.end(), 1);
    cout<< ">> ";
    cin>> option;
    while(!(find(begin(options), end(options), option)!=end(options))){
        clear_fail_state();
        cout<<'\t'<< "Invalid option. "<< e_message <<'\n'<< ">> ";
        cin>> option;
    }
}