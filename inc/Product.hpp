#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <vector>
using namespace std;

class Product{
    private:
        string product_name;
        string category;
        double price;
        int amount;
    
    public:
        Product();
        Product(string product_name, string category, double price, int amount);
        void displayProduct();

        string get_product_name();
        void set_product_name(string product_name);

        string get_category();
        void set_category(string category);

        double get_price();
        void set_price(double price);

        int get_amount();
        void set_amount(int amount);

        bool operator == (Product & obj);

};

#endif