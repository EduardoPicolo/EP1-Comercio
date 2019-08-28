#include "Cart.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int productIndex;

Cart:: Cart():total(0){
}

void Cart:: add_product(Product product, int amount){
    if(verifyCart(product)){ // Product already in cart, increase its amount
        // cout<<"Increasing amount..."<<endl;
        cart[productIndex].set_amount(cart[productIndex].get_amount()+amount);
        update_total();
    }
    else{
        cout<<"Adding product to cart..."<<endl;
        product.set_amount(amount);
        cart.push_back(product);
        update_total();
    }
}

bool Cart:: verifyCart(Product product){
    for(size_t i=0; i<cart.size();i++){
        if(product==cart[i]){
            productIndex = i;
            return true;
        }
    }
    return false;
}

void Cart::confirm_purchase(){
    Product product; vector<Product> productList = product.get_productList();
    for(size_t i=0; i<cart.size(); i++){
        for(size_t j=0; j<productList.size(); j++){
            if(cart[i]==productList[j])
                productList[j].set_amount(productList[j].get_amount()-cart[i].get_amount());
        }
    }
    product.update_productList(productList);
}

void Cart:: cancel_purchase(){
    cart.clear();
    total = 0.0;
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

vector<Product> Cart:: display_cart(){
    return cart;
}
