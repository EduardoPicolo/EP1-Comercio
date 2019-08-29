#ifndef STOCK_HPP
#define STOCK_HPP

#include "Product.hpp"
#include "BaseClass.hpp"
#include <string>
#include <vector>
using namespace std;

class Stock: public BaseClass{
    virtual void abstract() = 0;
    private:
        static vector<Product> productList;

    public:
        static void register_product(string product_name, string category, double price, int amount);
        static bool verify_product(string product_name);
        static bool verify_amount(Product product);
        static bool restock(string product_name, int amount);
        static vector<Product> get_productList();

};

#endif