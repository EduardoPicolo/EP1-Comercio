#ifndef CART_HPP
#define CART_HPP

#include "Product.hpp"
#include "Stock.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Cart{
    private:
        double total;
        static vector<Product> cart;

        bool verifyCart(Product product);
        void update_total();

    public:
        Cart();
        double get_total();

        void add_product(Product product, int amount);
        void confirm_purchase();
        void cancel_purchase();

        void display_cart();
        static vector<Product> get_cart();
        void abstract(){};
};

#endif