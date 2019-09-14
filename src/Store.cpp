#include "Store.hpp"
#include <iomanip>

int option = 0;

void Store::main_menu(){
    cout<<"\t" "1:Shop"<<" \t "<< "2:Stock"<<" \t "<< "3:Recommendation"<<endl;cout<< ">> ";
    cin>>  option;
    validate_option(option, "Invalid. Enter 1 for shop, 2 for stock or 3 for recommendation mode.");

    switch(option){
        case 1:
            shop_mode();
        break;

        case 2:
            stock_mode();
        break;

        case 3:
            recommendation_mode();
        break;

        default:
        break;
    }
}

void Store::stock_mode(){
    cout<<"\t" "*STOCK*"<< endl;
    cout<<"\t" "1:Add product"<< "\t"<< "2:Replenish stock"<<"\t"<< "3: Cancel"<<endl;cout<< ">> ";
    cin >> option;
    validate_option(option, "Invalid. Enter 1 to add product, 2 to replenish stock or 3 to cancel.");

    switch (option){
        case 1: // Add product
            Stock::add_product();
            main_menu();
        break;

        case 2: //Increase product amount
            Stock::restock();
            main_menu();
        break;
        
        case 3:
            main_menu();
        break;

        default:
        break;
    }
}

void Store::shop_mode(){
    cout<<"\t" "1:Login"<<"\t"<< "2:Register client"<<"\t"<< "3:Cancel"<<endl;cout<< ">> ";
    cin>> option;
    validate_option(option, "Invalid. Enter 1 to login, 2 to register client or 3 to cancel.");
    switch(option){
        case 1:
            Management::login();
        break;

        case 2:
            Management::register_client();
        break;

        case 3:
            main_menu();
        break;

        default:
        break;
    }

    Cart cart;
    unsigned int product, amount;
    vector<Product> productList = Stock::get_productList();

    do{
        cout<<"\t\t\t" "*CATALOGUE*"<<endl;
        cout<<'\t'<<"Index"<<'\t'<<left<<setw(18)<<"Product"<<setfill(' ')<<setw(11)<<"Price"<<setfill(' ')<<setw(12)<<"Category"<<setfill(' ')<<"Amount"<<endl;
        for(size_t i=0; i<productList.size(); i++){
            cout<<"\t"<<i<<"\t";productList[i].displayProduct();
        }

        cout<< "Product Index: ";
        cin>> product;
        while(product>productList.size()){
            clear_fail_state();
            cout<<"\t" "Invalid product index"<<endl;
            cout<< "Product Index: ";
            cin>> product;
        }
        cout<< "Amount: ";
        cin>> amount;
            clear_fail_state();
        cart.add_product(productList[product], amount);
        cout<<"\t" "1:Continue shoppping"<<"\t"<< "2:Confirm purchase"<<"\t"<< "3:Cancel"<<endl;cout<< ">> ";
        cin>> option;
        validate_option(option,  "Invalid. Enter 1 to continue shopping, 2 to confirm purchase or 3 to cancel");
        switch(option){
            case 1:
            break;
            case 2:
                // client->update_shop_history();
                cart.confirm_purchase();
                main_menu();
            break;
            case 3:
                cart.cancel_purchase();
                main_menu();
            break;

            default:
            break;
        }
        if(Stock::verify_amount(productList[product], amount)){
            productList[product].set_amount(productList[product].get_amount()-amount);
        }
    } while(option==1);
}

void Store::recommendation_mode(){
    Management::login();

    int cont = 1;
    vector<Product> productList = Stock::get_productList();
    map<string, int> shop_history = client->get_shop_history();
    if(shop_history.empty()){
        cout<<"\t"<< "Customer doesn't have a purchase history!"<<endl;
        main_menu();
    }
    else{
        vector<pair<string, int>> sorted_vector = order(shop_history);
        cout<<"\t\t" "*RECOMMENDED PRODUCTS*"<<endl;
        for (auto it = sorted_vector.cbegin(); it != sorted_vector.cend(); it++){
            for(size_t i=0; i<productList.size() ; i++){
                if(it->first == productList[i].get_category()){
                    cout<<"\t"<<cont<<". ";productList[i].displayProduct();
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