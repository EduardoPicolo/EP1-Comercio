#include "Client.hpp"
#include "Product.hpp"
#include "Cart.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string name, password;

int stock(void);
int shop(void);

int main(void) {
    Client guest;
    int option;

    stock();
    // shop();

    cout<< "1:Sign in"<< "\t"<< "2:Register"<< endl;
    cin>>  option;
    switch(option){
        case 1: // Sign in
            do{
                cout<< "Username: ";
                cin>> name;
                cout<< "Password: ";
                cin>> password;
            } while(guest.login(&guest,name, password)== false);
            cout<< "Welcome "<< guest.get_name()+"!"<< endl;
            break;

        case 2: // Register
            cin>> name>> password;
            guest.registerClient(name, password);
            guest.login(&guest, name, password);
            break;

        case 3:// Add products/replenish stock
            // cin>> product_name;
            break;

        default:
            break;
    }

    return 0;
}

int stock(void){
    string product_name, category;
    double price;
    int option, amount;
    Product product;
    cout<< "STOCK"<< endl;
    cout<< "1: Add product"<< "\t"<< "2: Replenish stock"<< endl;
    cin >> option;
    switch (option){
        case 1: // Add product
            cout<< "Product name: ";
            cin>> product_name;
            if(product.verifyProduct(product_name)){
                cout<< "Product already registered"<< endl;
            }
            else{
                cout<< "Product category: ";
                cin >> category;
                cout<< "Price: ";
                cin >> price;
                cout<< "Quantity: ";
                cin >> amount;
                product.registerProduct(product_name, category, price, amount);
            }
        break;

        case 2: //Increase product amount
            cout<< "Product: "<< endl;
            cin>> product_name;
            while(product.verifyProduct(product_name)==false){
                cout<< "Product not found."<<"\n"<<"Product: ";
                cin>> product_name;
            }
            cout<< "Quantity increase "<<"⇪ ";
            cin>> amount;
            product.restock(amount);
        break;

    default:
        break;
    }

    return 0;
}


int shop(void){
    string name, password;

    return 0;

}