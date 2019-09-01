#include "Product.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int productPosition;

Product:: Product(){}
Product:: Product(string product_name, string category, double price, int amount)
:product_name(product_name), category(category), price(price), amount(amount) 
{
    cout<< "New product added!"<< endl;
}

void  Product:: displayProduct(){
    cout<< product_name <<"\t"<< category <<"\t"<< price <<"\t"<< amount<<endl;
}

string Product:: get_product_name(){
    return product_name;
}

string Product:: get_category(){
    return category;
}

double Product:: get_price(){
    return price;
}

int Product:: get_amount(){
    return amount;
}

void Product:: set_product_name(string name){
    this-> product_name = name;
}

void Product:: set_category(string category){
    this-> category = category;
}

void Product:: set_price(double price){
    this-> price = price;
}

void Product:: set_amount(int amount){
    this-> amount = amount;
}


bool Product:: operator == (Product & obj){
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

