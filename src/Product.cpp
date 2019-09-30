#include "Product.hpp"
#include "Functions.hpp"
#include <iostream>
#include <iomanip>
#include <string>

Product::Product():product_name(""), category(""), price(0.0), amount(0){
}
Product::Product(string product_name, string category, double price, int amount)
:product_name(product_name), category(category), price(price), amount(amount) 
{
    if(product_name.length()==0||category.length()==0)
        throw Exception("Product's name/category cannot be empty.");
    cout<< "New product added!"<< endl;
}
Product::~Product(){
}

void  Product::displayProduct(){
    cout<<left<<setw(21)<<product_name<<setfill(' ')<<"$"<<setw(11)<<price<<setfill(' ')<<amount<<endl;
}

string Product::get_product_name(){
    return product_name;
}

string Product::get_category(){
    return category;
}

double Product::get_price(){
    return price;
}

int Product::get_amount(){
    return amount;
}

void Product::set_product_name(string name){
    this-> product_name = name;
}

void Product::set_category(string category){
    this-> category = category;
}

void Product::set_price(double price){
    if(price<0)
        throw new Exception("Invalid price.");
    else
        this-> price = price;
}

void Product::set_amount(int amount){
    if(amount<0)
        throw new Exception("Invalid amount.");
    this-> amount = amount;
}


bool Product::operator == (Product & obj){
    return (product_name == obj.product_name) && (category == obj.category)&& (price== obj.price);
}

// Overload operator <<
ostream & operator << (ostream &out, const Product & obj){
	out << obj.product_name << "\t" << obj.category << "\t" << obj.price << "\t" << obj.amount <<endl;
	return out;
}
// Overload operator >>
istream & operator >> (istream &in,  Product &obj){
	in >> obj.product_name;
	in >> obj.category;
	in >> obj.price;
    in >> obj.amount;
	return in;
}

