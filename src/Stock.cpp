#include "Stock.hpp"
#include "Store.hpp"

vector<Product> Stock::stock;
int index;

void Stock::add_product(){
    string product_name, category;
    double price; int amount;

    cout<< "Product name: ";
    getline(cin>>ws, product_name);
        fill_string_spaces(product_name);
        lowercase(product_name);
    switch(Stock::verify_stock(product_name)){
        case true:
            cout<< "Product already registered"<<endl;
            cout<<'\t'<<left<<setw(21)<< "1:Add new product"<<setfill(' ')<<setw(11)<< "2:Stock"<<setfill(' ')<< "3:Cancel"<<endl;
            Store::input_option(3, "Enter 1 to add a new product, 2 to go back to stock or 3 to cancel.");
            switch(option){
                case 1:
                    Stock::add_product();
                break;
                case 2:
                    Store::stock_mode();
                break;
                case 3:
                    Store::main_menu();
                break;
                default:
                    throw e_option;
                break;
            }
        break;
        case false:
            cout<< "Product category (Separate multiple categories with '/'): ";
            getline(cin>>ws, category);
                fill_string_spaces(category);
                lowercase(category);
            cout<< "Price: ";
            cin>> price;
            while(price<=0){
                clear_fail_state();
                cout<<'\t'<< "Invalid"<<endl;
                cout<< "Price: ";
                cin>> price;
            }
            cout<< "Amount: ";
            cin>> amount;
            while(amount<=0){
                clear_fail_state();
                cout<<'\t'<< "Invalid"<<endl;
                cout<< "Amount: ";
                cin>> amount;
            }
            Product product(product_name, category, price, amount);
            stock.push_back(product);
            write_file("stock.txt", product);
        break;
    }
}

void Stock::restock(){
    string product_name, category; int amount;

    cout<< "Product: ";
    getline(cin>>ws, product_name);
        fill_string_spaces(product_name);
        lowercase(product_name);
    if(Stock::verify_stock(product_name)){
        cout<< "Quantity increase "<<"⇪ ";
        cin>> amount;
        while(amount<=0){
            clear_fail_state();
            cout<<'\t'<< "Invalid amount"<<endl;
            cout<< "Quantity increase "<<"⇪ ";
            cin>> amount;
        }
        stock[index].set_amount(stock[index].get_amount()+amount);
        over_write("stock.txt", stock);
    }
    else{
        cout<<'\t'<< "Product not found"<<endl;
        cout<<'\t'<<left<<setw(16)<< "1:Try again"<<setfill(' ')<<setw(21)<< "2:Add new product"<<setfill(' ')<< "3:Cancel"<<endl;
        Store::input_option(3, "Enter 1 to try again, 2 to add new product or 3 to cancel");
        switch(option){
            case 1:
                Stock::restock();
            break;
            case 2:
                Stock::add_product();
            break;
            case 3:
                Store::main_menu();
            break;
            default:
                throw e_option;
            break;
        }
    }
}

bool Stock::verify_stock(string product_name){
    stock = read_file("stock.txt");
    for(size_t i=0; i<stock.size();i++){
        if(product_name == stock[i].get_product_name()){ // Product already registered
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

vector<Product> Stock:: get_stock(){
    stock = read_file("stock.txt");
    return stock;
}

vector<Product> Stock::read_file(string file_name){
    vector<Product> objList;
    fstream file;
    file.open("./doc/"+file_name, ios::in|ios::app);
    if(!file.is_open())
        throw e_file;
    Product temp;
    while(file>>temp){
        objList.emplace_back(temp);
    }
    file.close();
    return objList;
}

void Stock::write_file(string file_name, Product product){
    fstream file;
    file.open("./doc/"+file_name, ios::app);
    if(!file.is_open())
        throw e_file;
    file<< product;
    file.close();
}

void Stock::over_write(string file_name, vector<Product> list){
    fstream file("./doc/"+file_name, ios::out);
    for(size_t i=0; i<list.size(); i++){
        file<<list[i];
    }
    file.close();  
}