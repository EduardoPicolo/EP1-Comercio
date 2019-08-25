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
        vector<Product> cart;
        double total;

        void add_product(Product product);
        void cancel_purchase();

    public:
        Cart();
        double get_total();
        void set_total();

        vector<Product> get_cart();
};

#endif