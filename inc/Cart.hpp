#include <string>
using namespace std;

class Cart{
    private:
        int items;
        double total;
    
    public:
        Cart();
        int get_items();
        double get_total();

        void add_product();
        void remove_product();
};
