#include "Store.hpp"
#include <numeric>

void Store::start_session(){
    cout<< "================================ Start Session ================================" <<endl;
    cout<<'\t'<<left<<setw(11)<< "1:Login"<<setfill(' ')<<setw(14)<< "2:Register"<<setfill(' ')<< "3:Exit"<< endl;
    Store::input_option(3, "Enter 1 to login, 2 to register or 3 to exit.");
    switch (option){
        case 1:
            Management::login();
        break;
        case 2:
            Management::register_client();
        break;
        case 3:
            exit(EXIT_SUCCESS);
        break;
        default:
            throw e_option;
        break;
    }
    Store::main_menu();
}

void Store::main_menu(){
    cout<< "================================ Main Menu ================================" <<endl;
    if(client->get_cpf()=="0000"){
        cout<<'\t'<<left<<setw(10)<< "1:Shop"<<setfill(' ')<<setw(20)<< "2:Recommendation"<<setfill(' ')<<setw(12)<< "3:Logout"<<setfill(' ')<< "4:Stock"<<endl;
        Store::input_option(4 ,"Enter 1 to shop, 2 for recommendations, 3 to logout or 4 for stock.");
    }
    else{
        cout<<'\t'<<left<<setw(10)<< "1:Shop"<<setfill(' ')<<setw(20)<< "2:Recommendation"<<setfill(' ')<< "3:Logout"<<endl;
        Store::input_option(3 ,"Enter 1 to shop, 2 for recommendations or 3 to logout.");
    }

    switch(option){
        case 1:
            try{
                Store::shop_mode();
            }catch(Exception& e){
                cout<<'\t'<< e.what() <<endl;
                cout<< "Returning to main menu..." <<endl;
                Store::main_menu();
            }
        break;
        case 2:
            try{
                Store::recommendation_mode();
            }catch(Exception& e){
                cout<<'\t'<< e.what() <<endl;
                cout<< "Returning to main menu..." <<endl;
                Store::main_menu();
            }
        break;
        case 3:
            *client = Client();
            Store::start_session();
        break;
        case 4:
            try{
                Store::stock_mode();
            }catch(Exception& e){
                cout<<'\t'<< e.what() <<endl;
                cout<< "Returning to main menu..." <<endl;
                Store::main_menu();
            }
        break;
        default:
         throw e_option;
        break;
    }
}

void Store::stock_mode(){
    cout<< "================================ *STOCK* ================================" <<endl;
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
    cout<< "================================ *SHOP* ================================" <<endl;

    Cart cart;
    unsigned int product, amount;
    vector<Product> productList = Stock::get_productList();

    do{
        cout<<"\t\t\t" "*CATALOGUE*"<<endl;
        cout<<'\t'<<"Index"<<'\t'<<left<<setw(18)<<"Product"<<setfill(' ')<<setw(11)<<"Price"<<setfill(' ')<<"Amount"<<endl;
        for(size_t i=0; i<productList.size(); i++){
            cout<<"\t"<<i<<"\t";productList[i].displayProduct();
        }

        cout<< "Product Index: ";
        cin>> product;
        while(product>productList.size()-1){
            clear_fail_state();
            cout<<'\t'<< "Invalid product index"<<endl;
            cout<< "Product Index: ";
            cin>> product;
        }
        cout<< "Amount: ";
        cin>> amount;
            clear_fail_state();
        cart.add_product(productList[product], amount);
        cout<<'\t'<<left<<setw(23)<< "1:Continue shopping"<<setfill(' ')<<setw(22)<< "2:Confirm purchase"<<setfill(' ')<< "3:Cancel"<<endl;
        Store::input_option(3, "Enter 1 to continue shopping, 2 to confirm purchase or 3 to cancel purchase");
        switch(option){
            case 1:
            break;
            case 2:
                cart.confirm_purchase();
                Store::main_menu();
            break;
            case 3:
                cart.cancel_purchase();
                Store::main_menu();
            break;
            default:
                throw e_option;
            break;
        }
        if(Stock::verify_amount(productList[product], amount)){
            productList[product].set_amount(productList[product].get_amount()-amount);
        }
    } while(option==1);
}

void Store::recommendation_mode(){
    cout<< "================================ *RECOMMEND* ================================" <<endl;

    int cont = 1;
    vector<Product> productList = Stock::get_productList();
    map<string, int> shop_history = client->get_shop_history();
    if(shop_history.empty()){
        cout<<"\t"<< "Customer doesn't have a purchase history!"<<endl;
        cout<< "Returning to main menu..." <<endl;
        main_menu();
    }
    else{
        vector<pair<string, int>> sorted_vector = order(shop_history);
        cout<<"\t\t" "*RECOMMENDED PRODUCTS*"<<endl;
        for (auto it = sorted_vector.cbegin(); it != sorted_vector.cend(); it++){
            for(size_t i=0; i<productList.size() ; i++){
                if(it->first == productList[i].get_category()){
                    cout<<'\t'<<cont<<". ";productList[i].displayProduct();
                    cont++;
                    break;
                }
            }
            if(cont==10)
                break;
        }
    }
    cout<<endl;
    Store::main_menu();
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