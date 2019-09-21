#include "Store.hpp"
#include <iomanip>
#include <string>

const Exception invalid_option("Invalid option.");

void Store::main_menu(){
    cout<< "================================ Main Menu ================================" <<endl;
    cout<<'\t'<<left<<setw(10)<< "1:Shop"<<setfill(' ')<<setw(11)<< "2:Stock"<<setfill(' ')<< "3:Recommendation"<<endl;cout<< ">> ";
    Store::input_option("Invalid. Enter 1 for shop, 2 for stock or 3 for recommendation mode.");

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
                Store::stock_mode();
            }catch(Exception& e){
                cout<<'\t'<< e.what() <<endl;
                cout<< "Returning to main menu..." <<endl;
                Store::main_menu();
            }
        break;

        case 3:
        try{
            Store::recommendation_mode();
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
    cout<<'\t'<<left<<setw(17)<< "1:Add product"<<setfill(' ')<<setw(21)<< "2:Replenish stock"<<setfill(' ')<< "3: Cancel"<<endl;cout<< ">> ";
    Store::input_option("Invalid. Enter 1 to add product, 2 to replenish stock or 3 to cancel.");
    switch (option){
        case 1:
            Stock::add_product();
            cout<< "Returning to main menu..."<<endl;
            Store::main_menu();
        break;

        case 2:
            Stock::restock();
            cout<< "Returning to main menu..."<<endl;
            Store::main_menu();
        break;
        
        case 3:
            cout<< "Returning to main menu..."<<endl;
            Store::main_menu();
        break;

        default:
            throw e_option;
        break;
    }
}

void Store::shop_mode(){
    cout<< "================================ *SHOP* ================================" <<endl;
    cout<<'\t'<<left<<setw(11)<< "1:Login"<<setfill(' ')<<setw(21)<< "2:Register client"<<setfill(' ')<< "3:Cancel"<<endl;cout<< ">> ";
    Store::input_option("Invalid. Enter 1 to login, 2 to register client or 3 to cancel.");
    switch(option){
        case 1:
            Management::login();
        break;

        case 2:
            Management::register_client();
        break;

        case 3:
            Store::main_menu();
        break;

        default:
            throw e_option;
        break;
    }

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
        while(product>productList.size()){
            clear_fail_state();
            cout<<'\t'<< "Invalid product index"<<endl;
            cout<< "Product Index: ";
            cin>> product;
        }
        cout<< "Amount: ";
        cin>> amount;
            clear_fail_state();
        cart.add_product(productList[product], amount);
        cout<<'\t'<<left<<setw(23)<< "1:Continue shopping"<<setfill(' ')<<setw(22)<< "2:Confirm purchase"<<setfill(' ')<< "3:Cancel"<<endl;cout<< ">> ";
        Store::input_option("Invalid. Enter 1 to continue shopping, 2 to confirm purchase or 3 to cancel");
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
    Management::login();

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
    main_menu();
}

void Store::input_option(char* message){
    cin>> option;
    while(option!=1&&option!=2&&option!=3){
        clear_fail_state();
        cout<<'\t'<< message <<'\n'<< ">> ";
        cin>> option;
    }
}