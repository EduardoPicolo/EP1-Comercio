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