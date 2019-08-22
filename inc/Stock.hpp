#include <string>
using namespace std;

class Stock{
    private:
        string product_name;
        string product_category;
        double product_price;
        int product_amount;
    
    public:
        Stock();
        Stock(string product_name, string category, double price, int amount);
        string get_product_name();
        string get_product_category();
        double get_product_price();
        int get_product_amount();
        void set_product_name(string name);
        void set_product_category(string category);
        void set_product_price(double price);
        void set_product_amount(int amount);
        void registerNewProduct(string name, string category, double price, int amount);
        void displayProduct();


        bool operator== (const Stock & obj);
        friend ostream & operator << (std::ostream &out, const Stock & obj);
        friend istream & operator >> (std::istream &in,  Stock &obj);

};