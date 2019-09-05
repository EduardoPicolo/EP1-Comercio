#include "Stock.hpp"
#include "Functions.hpp"

vector<Product> Stock::productList;
int index;

void Stock:: register_product(string product_name, string category, double price, int amount){
    if(!verify_product(product_name)){
        Product product(product_name, category, price, amount);
        productList.push_back(product);
        write_file<Product>("stock.txt", product);
    }
    else{
        cout<<"Product already registered."<<endl;
    }
}

void Stock:: restock(string product_name,int amount){
    if(verify_product(product_name)){
        productList[index].set_amount(productList[index].get_amount()+amount);
        over_write<Product>("stock.txt", productList);
    }
    else{
        cout<<"Product not found."<<endl;
    }
}

bool Stock:: verify_product(string product_name){
    productList = read_file<Product>("stock.txt");
    for(size_t i =0; i<productList.size();i++){
        if(product_name == productList[i].get_product_name()){ // Product already registered
            index = i;
            return true;
        }
    }
    return false; // Product NOT registered
}

bool Stock:: verify_amount(Product product, int amount){
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


//***BUGGADO***//
// vector<Product> Stock:: read_file(string file_name){
//     vector<Product> list;
//     Product temp;
//     string name, category, price, amount;
//     double priceDouble; int amountInt;

//     fstream file;
//     file.open(file_name, ios::in);
//     // file.seekg(0);
//     while(getline(file, name)&&getline(file, category)&&getline(file, price)&&getline(file, amount)){
//         priceDouble = atof(price.c_str());
//         amountInt = atoi(amount.c_str());
//         temp.set_product_name(name);
//         temp.set_category(category);
//         temp.set_price(priceDouble);
//         temp.set_amount(amountInt);
//         list.push_back(temp);
//     }
//     file.close();

//     return list;
// }

// void Stock:: write_file(string file_name, Product new_product){
//     fstream file;
//     file.open(file_name, ios::out | ios::app);
//     file<<new_product.get_product_name()<< endl;
//     file<<new_product.get_category()<< endl;
//     file<<new_product.get_price()<<endl;
//     file<<new_product.get_amount()<< endl;
//     file.close();
// }

// void Stock:: overwrite_file(string file_name, vector<Product> list){
//     fstream file;
//     file.open(file_name, ios::out);
//     for(size_t i=0; i<list.size(); i++){
//         file<<list[i].get_product_name()<< endl;
//         file<<list[i].get_category()<< endl;
//         file<<list[i].get_price()<<endl;
//         file<<list[i].get_amount()<< endl;
//     }
//     file.close();

// }