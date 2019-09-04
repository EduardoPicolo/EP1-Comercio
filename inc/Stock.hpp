#ifndef STOCK_HPP
#define STOCK_HPP

#include "Product.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Stock{
    private:
        static vector<Product> productList;

    public:
        static void register_product(string product_name, string category, double price, int amount);
        static bool verify_product(string product_name);
        static bool verify_amount(Product product, int amount);
        static bool restock(string product_name, int amount);
        static vector<Product> get_productList();

        // static vector<Product> read_file(string file_name);
        // static void write_file(string file_name, Product new_product);
        // static void overwrite_file(string file_name, vector<Product> list);

};

#endif