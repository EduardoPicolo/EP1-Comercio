#ifndef STOCK_HPP
#define STOCK_HPP

#include "Product.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Stock{
    private:
        static vector<Product> productList;

    public:
        static void register_product(string product_name, string category, double price, int amount);
        static bool verify_product(string product_name);
        static bool verify_amount(Product product, int amount);
        static void restock();
        static vector<Product> get_productList();

        static void add_product();
};

#endif