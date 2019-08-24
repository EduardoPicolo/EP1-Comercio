#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "BaseClass.hpp"
#include <string>
#include <vector>
using namespace std;

class Product : public BaseClass{
    private:
        string product_name;
        string category;
        double price;
        int amount;
        vector<Product> productList;

    
    public:
        Product();
        Product(string product_name, string category, double price, int amount);
        void registerProduct(string product_name, string category, double price, int amount);
        bool verifyProduct(string product_name);

        string get_product_name();
        void set_product_name(string product_name);

        string get_category();
        void set_category(string category);

        double get_price();
        void set_price(double price);

        int get_amount();
        void set_amount(int amount);

        void displayProduct();

        // Overload operator == 
        bool operator== (Product & obj);
        // Overload operator <<
        friend std::ostream & operator << (std::ostream &out, Product & obj);
        // Overload operator >>
        friend std::istream & operator >> (std::istream &in,  Product &obj);

        void abstract(){}
};

#endif