#include "Stock.hpp"
#include <iostream>
#include <fstream>
#include <string>

Stock:: Stock(){}

Stock:: Stock(string product_name, string category, double price, int amount)
:product_name(product_name), product_category(category),
product_price(price), product_amount(amount){
    cout<< "New product added."<< endl;
}

void Stock:: registerNewProduct(string product_name, string category, double price, int amount){
    if(verifyProduct(product_name)){
        cout<< "Adding new product..."<< endl;
        Stock product(product_name, category, price, amount);
        std::ofstream out("stock.txt", ios:: app);
        out<< product;
        out.close();
    }
    else{
        cout<< "Product alredy registered."<< endl;
    }
}

bool Stock:: verifyProduct(string product_name){
    std::ifstream in("stock.txt");
    Stock temp_p;
    in>> temp_p;
    while (in) {
        if(temp_p.get_product_name()== product_name){
            // cout<< "Product found."<< endl;
            in.close();
            return false;
        }
        in>> temp_p;
    }
    return true;
}

void  Stock:: displayProduct(){
    cout<< this-> product_name<< "\t"<< this-> product_category<< "\t"<< this-> product_price<<endl;
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



bool Stock:: operator== (const Stock & obj){
    return (product_name == obj.product_name)&& (product_category== obj.product_category)&& (product_price== obj.product_price)&& (product_amount== obj.product_amount);
}

ostream & operator << (std::ostream &out, const Stock & obj){
    out<< obj.product_name<< "\t"<< obj.product_category<< "\t"<< obj.product_price<< "\t"<< obj.product_amount<< std::endl;
    return out;
}

istream & operator >> (std::istream &in,  Stock &obj){
    in >> obj.product_name;
    in >> obj.product_category;
    in >> obj.product_price;
    in >> obj.product_amount;
    return in;
}