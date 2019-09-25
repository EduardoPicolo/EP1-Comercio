#ifndef STOCK_HPP
#define STOCK_HPP

#include "Functions.hpp"

class Stock{
    virtual void abstract() = 0;
    private:
        static vector<Product> stock;

    public:
        static void add_product();
        static void restock();
        static bool verify_stock(string product_name);
        static bool verify_amount(Product product, int amount);
        static vector<Product> get_stock();
        static vector<Product> read_file(string file_name);
        static void write_file(string file_name, Product product);
        static void over_write(string file_name, vector<Product> list);
};

#endif