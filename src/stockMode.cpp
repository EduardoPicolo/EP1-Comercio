#include "stockMode.hpp"

void stock(){
    int option;
    cout<<"\t" "*STOCK*"<< endl;
    cout<<"\t" "1:Add product"<< "\t"<< "2:Replenish stock"<< endl;cout<< ">> ";
    cin >> option;
    while(option!=1&&option!=2){
        clear_fail_state();
        cout<< "Invalid. Enter 1 to add product or 2 to replenish stock: ";
        cin>> option;
    }
    switch (option){
        case 1: // Add product
            add_product();
        break;

        case 2: //Increase product amount
            restock();
        break;

        default:
            start();
        break;
    }
}

void add_product(){
    int option = 0;
    string product_name, category;
    double price; int amount;

    cout<< "Product name: ";
    getline(cin>>ws, product_name);
        fill_string_spaces(product_name);
    while(Stock::verify_product(product_name)){
        cout<< "Product already registered"<<endl;
        cout<<"\t" "1:Add new product"<<"\t"<<"2:Cancel"<<endl;cout<< ">> ";
        cin>> option;
        while(option!=1&&option!=2){
            clear_fail_state();
            cout<< "Invalid. Enter 1 to add a new product or 2 to cancel: ";
            cin>>  option;
        }
        switch(option){
            case 1:
                add_product();
            break;
            case 2:
                start();
            break;
            default:
            break;
        }
    }
    cout<< "Product category: ";
    getline(cin>>ws, category);
        fill_string_spaces(category);
    cout<< "Price: ";
    cin>> price;
    while(price<=0){
        clear_fail_state();
        cout<<"\t" "Invalid"<<endl;
        cout<< "Price: ";
        cin>> price;
    }
    cout<< "Amount: ";
    cin>> amount;
    while(amount<=0){
        clear_fail_state();
        cout<<"\t" "Invalid"<<endl;
        cout<< "Amount: ";
        cin>> amount;
    }
    Stock::register_product(product_name, category, price, amount);
    start();
}

void restock(){
    string product_name, category;
    int amount;

    cout<<"Product: ";
    getline(cin>>ws, product_name);
        fill_string_spaces(product_name);
    while(!(Stock::verify_product(product_name))){
        cout<<"\t" "Product not found"<<endl;
        cout<< "Product: ";
        getline(cin>>ws, product_name);
            fill_string_spaces(product_name);
    }

    cout<< "Quantity increase "<<"⇪ ";
    cin>> amount;
    while(amount<=0){
        clear_fail_state();
        cout<< "Invalid amount"<<endl;
        cin>> amount;
    }
    Stock::restock(product_name, amount);
    start();
}