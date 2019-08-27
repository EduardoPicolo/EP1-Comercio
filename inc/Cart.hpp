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

        void cancel_purchase();
        void update_total();

    public:
        Cart();
        double get_total();

        void add_product(Product product, int amount);
        vector<Product> get_cart();

        void abstract(){};
};

#endif