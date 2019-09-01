#include "Functions.hpp"

void add_product();
void login();
void fill_string_spaces(string & str);
void restock();

int start(void){
    int option = 0;
    cout<< "1:Shop"<<"\t"<< "2:Stock"<<endl;
    cin>>  option;
    while(option!=1&&option!=2){
        if (cin.fail()){
            // get rid of failure state
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cout << "Invalid. Enter 1 for shop or 2 for stock: ";
        cin>>  option;
    }

    switch(option){
        case 1:
            shop();
        break;

        case 2:
            stock();
        break;

        default:
        break;
    }

    return 0;
}

int shop(void){
    Cart cart;
    int product, amount, option = 0;
    vector<Product> productList = Stock::get_productList();
    
    login();

    do{
        cout<<"CATALOGUE"<<endl;
        cout<<"Index"<<"\t"<<"Product"<<"\t"<<"Category"<<"\t"<<"Price"<<"\t"<<"Amount"<<endl;
        for(size_t i=0; i<productList.size(); i++){
            cout<<i<<"\t";productList[i].displayProduct();
        }
        cout<< "Product: ";
        cin>> product;
        cout<< "Amount: ";
        cin>> amount;
        cart.add_product(productList[product], amount);
        cout<< "1:Continue shoppping"<<"\t"<<"2:Confirm purchase"<<"\t"<<"3:Cancel"<<endl;
        cin>> option;
        while(option!=1&&option!=2&&option!=3){
            if (cin.fail()){
                // get rid of failure state
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cout << "Invalid. Enter 1 to continue shopping, 2 to confirm purchase or 3 to cancel: ";
            cin>>  option;
        }
        if(option==3){
            cart.cancel_purchase();
            start();
        }
        if(Stock:: verify_amount(productList[product], amount)){
            productList[product].set_amount(productList[product].get_amount()-amount);
        }
    } while(option==1);

    cout<<"Total: "<<cart.get_total()<<endl;
    cart.confirm_purchase();
    start();

    return 0;
}

int stock(void){
    int option;
    cout<< "STOCK"<< endl;
    cout<< "1: Add product"<< "\t"<< "2: Replenish stock"<< endl;
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
    return 0;
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
        cout<< "1:Add new product"<<"\t"<<"2:Cancel"<<endl;
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
        cout<<"Product: ";
        getline(cin>>ws, product_name);
            fill_string_spaces(product_name);
    }

    cout<< "Quantity increase "<<"⇪ ";
    cin>> amount;
    Stock::restock(product_name, amount);
    start();
}

void fill_string_spaces(string & str){
    for(size_t i=0; i<str.length(); i++){
        if(str[i] == ' ')
            str[i] = '-';
    }
}

void login(){
    string cpf;

    cout<<"Client CPF: ";
    getline(cin>>ws, cpf);
    for(size_t i=0; i<cpf.length(); i++){
        if(!isdigit(cpf[i])){
            cout<<"Invalid."<<endl;
        }
    }
}