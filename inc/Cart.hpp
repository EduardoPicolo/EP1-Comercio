#ifndef CART_HPP
#define CART_HPP

#include "Product.hpp"
#include "BaseClass.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Cart : public BaseClass{
    private:
        double total;
        vector<Product> cart;

        bool verifyCart(Product product);
        void update_total();

    public:
        Cart();
        double get_total();

        void add_product(Product product, int amount);
        void confirm_purchase();
        void cancel_purchase();

        vector<Product> display_cart();
        
        void abstract(){};
};

#endif