#include "Stock.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

vector<Product> Stock::productList;
int pos;

void Stock:: register_product(string product_name, string category, double price, int amount){
    if(!verify_product(product_name)){
        cout<< "Adding new product..."<< endl;
        Product product (product_name, category, price, amount);
        productList.push_back(product);
        // Write new product
        writeFile<Product>("stock.txt", product);
    }
    else{
        cout<< "Product already registered."<< endl;
    }
}

bool Stock:: verify_product(string product_name){
    productList = readFile<Product>("stock.txt");
    for(size_t i =0; i<productList.size();i++){
        if(product_name== productList[i].get_product_name()){ // Product already registered
            pos = i;
            return true;
        }
    }
    return false; // Product NOT registered
}

bool Stock:: verify_amount(Product product, int amount){
    if(product.get_amount()>=amount){
        return true;
    }
    else {
        return false;
    }
}

bool Stock:: restock(string product_name,int amount){
    if(verify_product(product_name)){
        productList[pos].set_amount(productList[pos].get_amount()+amount);
        overWrite<Product>("stock.txt", productList);
        return true;
    }
    else{
        cout<<"Product not found."<<endl;
        return false;
    }
}

vector<Product> Stock:: get_productList(){
    return productList = readFile<Product>("stock.txt");
}

void Stock:: update_productList(){
}

