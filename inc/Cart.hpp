#ifndef CART_HPP
#define CART_HPP

#include "Product.hpp"
#include "Stock.hpp"
#include <vector>
#include <string>

using namespace std;

class Cart{
    private:
        float total;
        vector<Product> cart;

        bool verifyCart(Product product);
        void update_total();

    public:
        Cart();
        ~Cart();
        float get_total();

        void add_product(Product product, int amount);
        void confirm_purchase();
        void cancel_purchase();
        
        void display_cart();
        vector<Product> get_cart();
};

#endif