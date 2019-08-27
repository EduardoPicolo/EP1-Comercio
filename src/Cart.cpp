#include "Cart.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Cart:: Cart():total(0){

}

void Cart:: add_product(Product product, int amount){
    product.set_amount(amount);
    cart.push_back(product);
    update_total();
    // total += product.get_price()*product.get_amount();
}

void Cart:: update_total(){
    total = 0;
    for(size_t i=0; i<cart.size(); i++){
        total += cart[i].get_price()*cart[i].get_amount();
    }
}

double Cart:: get_total(){
    return total;
}

vector<Product> Cart:: get_cart(){

}

void Cart:: cancel_purchase(){
    total = 0.0;
}