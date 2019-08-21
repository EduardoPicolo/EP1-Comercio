#include "Stock.hpp"
#include "iostream"
#include <string>

Stock:: Stock(){

}

void Stock:: registerNewProduct(string name, string category, double price, int amount){
    this-> product_name = name;
    this-> product_category = category;
    this-> product_price = price;
    this-> product_amount = amount;
}

void  Stock:: displayProduct(){
    cout<< this-> product_name+"-"<< this-> product_category+" "+"$"<< this-> product_price<< endl;
}

string Stock:: get_product_name(){
    return product_name;
}

string Stock:: get_product_category(){
    return product_category;
}

double Stock:: get_product_price(){
    return product_price;
}

int Stock:: get_product_amount(){
    return product_amount;
}

void Stock:: set_product_name(string name){
    this-> product_name = name;
}

void Stock:: set_product_category(string category){
    this-> product_category = category;
}

void Stock:: set_product_price(double price){
    this-> product_price = price;
}

void Stock:: set_product_amount(int amount){
    this-> product_amount = amount;
}