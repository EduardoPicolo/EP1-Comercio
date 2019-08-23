#include "Product.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

vector<Product> productList;
int productPosition;

Product:: Product(){}
Product:: Product(string product_name, string category, double price, int amount)
:product_name(product_name), category(category), price(price), amount(amount) 
{
    cout<< "New product added!"<< endl;
}

void Product:: registerProduct(string product_name, string category, double price, int amount){
    if(!verifyProduct(product_name)){
        cout<< "Adding new product"<< endl;
        Product product(product_name, category, price, amount);
        productList.push_back(product);
        // Write new product
        std::ofstream out("stock.txt", ios:: app);
        out<< product;
        out.close();
    }
    else{
        cout<< "Product already registered."<< endl;
    }
}

bool Product:: verifyProduct(string product_name){
    // Open the file and fill in vector with objects
    std::ifstream in("stock.txt");
    Product temp;
    while(in){
        in>> temp;
        productList.push_back(temp);
    }
    in.close();

    //  Search client
    for(int i =0; i<productList.size();i++){
        if(product_name== productList[i].get_product_name()){ // Product already registered
            productPosition = i;
            return true;
        }
    }
    return false; // Product NOT registered
}

void  Product:: displayProduct(){
    cout<< this-> product_name<< "\t"<< this-> category<< "\t"<< this-> price<<endl;
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



bool Product:: operator== (Product & obj){
    return (product_name == obj.product_name) && (category == obj.category)&& (price== obj.price);
}

ostream & operator << (std::ostream &out, Product & obj){
    	out<< obj.product_name<< "\t"<< obj.category<< "\t"<< obj.price<< "\t"<< obj.amount<< std::endl;
		return out;
}

istream & operator >> (std::istream &in,  Product &obj){
    	in >> obj.product_name;
		in >> obj.category;
        in >> obj.price;
        in >> obj.amount;
		return in;
}