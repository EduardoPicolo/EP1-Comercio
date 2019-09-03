#include "stockMode.hpp"

void stock(){
    int option;
    cout<< "STOCK"<< endl;
    cout<<"\t" "1:Add product"<< "\t"<< "2:Replenish stock"<< endl;cout<< ">> ";
    cin >> option;
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
            if (cin.fail()){
                // get rid of failure state
                cin.clear();
                cin.ignore(1000, '\n');
        }
            cout<< "Invalid. Enter 1 to add a new product or 2 to cancel: ";
            cin>>  option;
        }
        if(option==1){
            add_product();
        }
        else if(option==2) {
            start();
        }
    }
    cout<< "Product category: ";
    getline(cin>>ws, category);
        fill_string_spaces(category);
    cout<< "Price: ";
    cin>> price;
    price = price*100;
    cout<< "Quantity: ";
    cin>> amount;
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
        cout<< "Product not found"<<endl;
        cout<< "Product: ";
        getline(cin>>ws, product_name);
            fill_string_spaces(product_name);
    }

    cout<< "Quantity increase "<<"⇪ ";
    cin>> amount;
    Stock::restock(product_name, amount);
    start();
}