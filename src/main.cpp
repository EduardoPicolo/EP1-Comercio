#include "Client.hpp"
#include "Product.hpp"
#include "Stock.hpp"
#include "Cart.hpp"
#include "Functions.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// int start(void);
// int stock(void);
// int shop(void);
// void add_product(void);

int main(void) {
    start();
    return 0;
}

// int start(void){
//     int option = 0;
//     cout<< "1:Shop"<<"\t"<< "2:Stock"<<endl;
//     cin>>  option;
    // while(option!=1&&option!=2){
    //     if (cin.fail()){
    //         // get rid of failure state
    //         cin.clear();
    //         cin.ignore(1000, '\n');
    //     }
    //     cout << "Invalid. Enter 1 for shop or 2 for stock: ";
    //     cin>>  option;
    // }

//     switch(option){
//         case 1:
//             shop();
//         break;

//         case 2:
//             stock();
//         break;

//         default:
//         break;
//     }

//     return 0;
// }

// int shop(void){
//     Cart cart;
//     int product, amount, option;
//     vector<Product> productList = Stock::get_productList();


//     do{
//         cout<<"CATALOGUE"<<endl;
//         cout<<"Index"<<"\t"<<"Product"<<"\t\t"<<"Category"<<"\t"<<"Price"<<"\t"<<"Amount"<<endl;
//         for(size_t i=0; i<productList.size(); i++){
//             cout<<i<<"\t";productList[i].displayProduct();
//         }
//         cout<< "Product: ";
//         cin>> product;
//         cout<< "Amount: ";
//         cin>> amount;
//         cart.add_product(productList[product], amount);
//         cout<< "1:Continue shoppping"<<"\t"<<"2:Confirm purchase"<<endl;
//         cin>> option;

//         if(Stock:: verify_amount(productList[product], amount)){
//             productList[product].set_amount(productList[product].get_amount()-amount);
//         }
//     } while(option==1);

//     cout<<"Total: "<<cart.get_total()<<endl;
//     cart.confirm_purchase();
//     start();

//     return 0;
// }

// int stock(void){
//     string product_name, category;
//     int option = 0, amount;
//     Product product;
//     cout<< "STOCK"<< endl;
//     cout<< "1: Add product"<< "\t"<< "2: Replenish stock"<< endl;
//     cin >> option;
//     switch (option){
//         case 1: // Add product
//             add_product();
//         break;

//         case 2: //Increase product amount
//             cout<<"Product: ";
//             getline(cin>>ws, product_name);
//             while(!(Stock::verify_product(product_name))){
//                 cout<<"Product: ";
//                 getline(cin>>ws, product_name);
//             }
//             cout<< "Quantity increase "<<"⇪ ";
//             cin>> amount;
//             Stock::restock(product_name, amount);
//             start();
//         break;

//     default:
//         break;
//     }

//     return 0;
// }

// void add_product(void){
//     char option = 'a';
//     string product_name, category;
//     double price;
//     int amount;

//     cout<< "Product name: ";
//     getline(cin>>ws, product_name);
//     while(Stock::verify_product(product_name)){
//         cout<< "Product already registered"<<endl;
//         cout<< "Add a new product? "<<endl;
//         cin>> option;
//         if(option=='y'||option=='Y'){
//             add_product();
//         }
//         else if(option =='n'||option=='N') {
//             start();
//         }
//     }
//     cout<< "Product category: ";
//     getline(cin>>ws, category);
//     cout<< "Price: ";
//     cin>> price;
//     price = price*100;
//     cout<< "Quantity: ";
//     cin>> amount;
//     Stock::register_product(product_name, category, price, amount);
//     start();
// }

// void login(){
//     Client guest;
//     string name, cpf, username, password;
//     int option;

//     cout<< "1:Sign in"<< "\t"<< "2:Register"<< endl;
//     cin>>  option;
//     while(option!=1&&option!=2){
//         if (cin.fail()){
//             // get rid of failure state
//             cin.clear();
//             cin.ignore(1000, '\n');
//         }
//         cout << "Invalid: ";
//         cin>>  option;

//     }

//     switch(option){

//         case 1: // Sign in
//             do{
//                 cout<< "CPF: ";
//                 cin>> cpf;
//                 cout<< "Password: ";
//                 cin>> password;
//             } while(guest.login(&guest,cpf, password)== false);
//             cout<< "Welcome "<< guest.get_name()+"!"<< endl;
//             shop();
//         break;

//         case 2: // Register
//             do{
//                 cout<< "Name: ";
//                 cin>> name;
//                 cout<< "Cpf: ";
//                 cin>> cpf;
//                 cout<< "Password: ";
//                 cin>> password;  
//             } while((guest.registerClient(name, cpf, password)));
//             guest.login(&guest, cpf, password);
//             shop();
//         break;

//         default:
//             break;
//     }
// }