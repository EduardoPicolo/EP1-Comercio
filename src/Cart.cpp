#include "Cart.hpp"
#include "Functions.hpp"

int productIndex;

Cart::Cart():total(0){
    cart.clear();
}
Cart::~Cart(){
}

void Cart::add_product(Product product, int amount){
    if(Stock::verify_amount(product, amount)){
        if(verifyCart(product)){ // Product already in cart, increase its amount
            // cout<<"\t" "Product amount in cart increased"<<endl;
            cout<<'\t'<< "["+product.get_product_name()+"] amount in cart increased." <<endl;
            cart[productIndex].set_amount(cart[productIndex].get_amount()+amount);
            update_total();
        }
        else{ //Product not in cart, add
            // cout<<"\t" "Product added to cart"<<endl;
            cout<<'\t'<< "["+product.get_product_name()+"] added to cart." <<endl;
            product.set_amount(amount);
            cart.push_back(product);
            update_total();
        }
    }
    else{
        cout<<'\t'<< "Invalid amount."<<endl;
    }
}

bool Cart::verifyCart(Product product){
    for(size_t i=0; i<cart.size();i++){
        if(product==cart[i]){
            productIndex = i;
            return true;
        }
    }
    return false;
}

void Cart::confirm_purchase(){
    vector<Product> productList = Stock::get_stock(); //vector with original product amount in stock
    for(size_t i=0; i<cart.size(); i++){
        for(size_t j=0; j<productList.size(); j++){
            if(cart[i]==productList[j])
                productList[j].set_amount(productList[j].get_amount()-cart[i].get_amount());
        }
    }
    display_cart();
    Stock::over_write("stock.txt", productList);
    client->update_shop_history(total, cart);
    cart.clear();
}

void Cart::cancel_purchase(){
    cart.clear();
    total = 0.0;
    cout<<"\t" "Purchase canceled"<<endl;
}

void Cart::update_total(){
    total = 0;
    for(size_t i=0; i<cart.size(); i++){
        total += cart[i].get_price()*cart[i].get_amount();
    }
}

void Cart::display_cart(){
    float discount=0;
    cout<<"\t\t" "*CART*"<<endl;
    cout<<'\t'<<left<<setw(18)<<"Product"<<setfill(' ')<<setw(11)<<"Price"<<setfill(' ')<<"Amount"<<endl;
    for(size_t i=0; i<cart.size();i++){
        cout<<'\t'; cart[i].displayProduct();
    }
    if(client->get_vip()==true){
        discount = (0.15*total);
    }
    cout<<'\t'<< "TOTAL: $"<< total <<endl;
    cout<<'\t'<< "DISCOUNT: $"<< discount <<endl;
    cout<<'\t'<< "FINAL: $"<< total-discount <<endl;
}

float Cart::get_total(){
    update_total();
    return total;
}

vector<Product> Cart::get_cart(){
    return cart;
}