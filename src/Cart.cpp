#include "Cart.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Cart:: Cart():total(0){

}

void Cart:: add_product(Product product){
    productList.push_back(product);
    for(size_t i=0; i<productList.size(); i++){
        total += product.get_price() * product.get_amount();
    }
}

vector<Product> Cart:: get_productList(){
    return productList;
}

void Cart:: cancel_purchase(){
    total = 0.0;
    productList.clear();
}