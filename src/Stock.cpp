#include "Stock.hpp"
#include "Functions.hpp"

vector<Product> Stock::productList;
int index;

void Stock::register_product(string product_name, string category, double price, int amount){
    if(!verify_product(product_name)){
        Product product(product_name, category, price, amount);
        productList.push_back(product);
        write_file<Product>("stock.txt", product);
    }
    else{
        cout<<"Product already registered."<<endl;
    }
}

void Stock::add_product(){
    int option = 0;
    string product_name, category;
    double price; int amount;

    cout<< "Product name: ";
    getline(cin>>ws, product_name);
        fill_string_spaces(product_name);
        lowercase(product_name);
    if(verify_product(product_name)){
        cout<< "Product already registered"<<endl;
        cout<<"\t" "1:Add new product"<<"\t"<< "2:Stock"<<"\t"<< "3:Cancel"<<endl;cout<< ">> ";
        cin>> option;
        validate_option(option, "Invalid. Enter 1 to add a new product, 2 to go back to stock or 3 to cancel.");
        switch(option){
            case 1:
                add_product();
            break;

            case 2:
                Store::stock_mode();
            break;

            case 3:
                Store::main_menu();
            break;

            default:
            break;
        }
    }
    // while(verify_product(product_name)){
    //     cout<< "Product already registered"<<endl;
    //     cout<<"\t" "1:Add new product"<<"\t"<< "2:Stock"<<"\t"<< "3:Cancel"<<endl;cout<< ">> ";
    //     cin>> option;
    //     validate_option(option, "Invalid. Enter 1 to add a new product, 2 to go back to stock or 3 to cancel.");
    //     break;
    // }
    // switch(option){
    //     case 1:
    //         add_product();
    //     break;

    //     case 2:
    //         Store::stock_mode();
    //     break;

    //     case 3:
    //         Store::main_menu();
    //     break;

    //     default:
    //     break;
    // }

    cout<< "Product category: ";
    getline(cin>>ws, category);
        fill_string_spaces(category);
        lowercase(category);
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
    register_product(product_name, category, price, amount);
}

void Stock::restock(){
    string product_name; int amount;

    cout<<"Product: ";
    getline(cin>>ws, product_name);
        fill_string_spaces(product_name);
        lowercase(product_name);
    while(!(Stock::verify_product(product_name))){
        cout<<"\t" "Product not found"<<endl;       //Todo opção pra sair do loop!
        cout<< "Product: ";
        getline(cin>>ws, product_name);
            fill_string_spaces(product_name);
            lowercase(product_name);
    }

    cout<< "Quantity increase "<<"⇪ ";
    cin>> amount;
    while(amount<=0){
        clear_fail_state();
        cout<< "Invalid amount"<<endl;
        cin>> amount;
    }

    if(verify_product(product_name)){
        productList[index].set_amount(productList[index].get_amount()+amount);
        over_write<Product>("stock.txt", productList);
    }
    else{
        cout<<"Product not found."<<endl;
    }
}

bool Stock::verify_product(string product_name){
    productList = read_file<Product>("stock.txt");
    for(size_t i =0; i<productList.size();i++){
        if(product_name == productList[i].get_product_name()){ // Product already registered
            index = i;
            return true;
        }
    }
    return false; // Product NOT registered
}

bool Stock::verify_amount(Product product, int amount){
    if(product.get_amount()>=amount && amount>0){
        return true;
    }
    else {
        return false;
    }
}

vector<Product> Stock:: get_productList(){
    productList = read_file<Product>("stock.txt");
    return productList;
}