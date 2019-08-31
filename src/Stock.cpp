#include "Stock.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

vector<Product> Stock::productList = read_file("stock.txt");
int pos;

void Stock:: register_product(string product_name, string category, double price, int amount){
    if(!verify_product(product_name)){
        price = price/100;
        Product product(product_name, category, price, amount);
        productList.push_back(product);
        write_file("stock.txt", product);
    }
    else{
        cout<<"Product already registered."<<endl;
    }
}

bool Stock:: restock(string product_name,int amount){
    if(verify_product(product_name)){
        productList[pos].set_amount(productList[pos].get_amount()+amount);
        overwrite_file("stock.txt", productList);
        return true;
    }
    else{
        cout<<"Product not found."<<endl;
        return false;
    }
}

bool Stock:: verify_product(string product_name){
    productList = read_file("stock.txt");
    for(size_t i =0; i<productList.size();i++){
        if(product_name == productList[i].get_product_name()){ // Product already registered
            pos = i;
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
    return productList;
}


vector<Product> Stock:: read_file(string file_name){
    fstream file;
    file.open(file_name, ios::in);
    vector<Product> list;
    Product temp;
    string name, category, price, amount;
    double priceDouble; int amountInt;
    // file.seekg(0);
    while(getline(file, name)&&getline(file, category)&&getline(file, price)&&getline(file, amount)){
        priceDouble = atof(price.c_str());
        // priceDouble = priceDouble/100;
        amountInt = atoi(amount.c_str());
        temp.set_product_name(name);
        temp.set_category(category);
        temp.set_price(priceDouble);
        temp.set_amount(amountInt);
        // list.emplace_back(name, cat, pri, am);
        list.push_back(temp);
    }
    file.close();

    return list;
}

void Stock:: write_file(string file_name, Product new_product){
    fstream file;
    file.open(file_name, ios::out | ios::app);
    file<<new_product.get_product_name()<< endl;
    file<<new_product.get_category()<< endl;
    file<<new_product.get_price()<<endl;
    file<<new_product.get_amount()<< endl;
    file.close();
}

void Stock:: overwrite_file(string file_name, vector<Product> list){
    fstream file;
    file.open(file_name, ios::out);
    for(size_t i=0; i<list.size(); i++){
        file<<list[i].get_product_name()<< endl;
        file<<list[i].get_category()<< endl;
        file<<list[i].get_price()<<endl;
        file<<list[i].get_amount()<< endl;
    }
    file.close();

}