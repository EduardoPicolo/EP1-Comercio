#include "Client.hpp"
#include "Product.hpp"
#include "Cart.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int login(void);
int stock(void);
int shop(void);

int main(void) {
    Client guest;
    string name, cpf, password;
    int option;

    cout<< "1:Sign in"<< "\t"<< "2:Register"<< endl;
    cin>>  option;
    switch(option){
        case 1: // Sign in
            do{
                cout<< "CPF: ";
                cin>> cpf;
                cout<< "Password: ";
                cin>> password;
            } while(guest.login(&guest,cpf, password)== false);
            cout<< "Welcome "<< guest.get_name()+"!"<< endl;
            shop();
        break;

        case 2: // Register
            do{
                cout<< "Name: ";
                cin>> name;
                cout<< "Cpf: ";
                cin>> cpf;
                cout<< "Password: ";
                cin>> password;  
            } while((guest.registerClient(name, cpf, password)));
            guest.login(&guest, cpf, password);
            shop();
        break;

        default:
            break;
    }

    return 0;
}

int shop(void){
    Cart cart;
    Product product;
    vector<Product> productList = product.get_productList();

    cart.add_product(productList[5], 15);
    cout<<cart.get_total()<<endl;


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
            while((product.verifyProduct(product_name))==true){
                cout<< "Product already registered"<<endl;
                cout<< "Product name: ";
                cin>>product_name;
            }
            cout<< "Product category: ";
            cin >> category;
            cout<< "Price: ";
            cin >> price;
            cout<< "Quantity: ";
            cin >> amount;
            product.registerProduct(product_name, category, price, amount);
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

