#include "Client.cpp"
#include "Stock.cpp"
#include "Cart.cpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    Client c1;
    c1.registerClient("Eduardo", true);
    cout<< c1.get_name()<< endl;
    cout<< c1.get_vipStatus()<< endl;

    Stock product1;
    product1.registerNewProduct("Hay", "Food", 5.25, 99);
    product1.displayProduct();

    // fstream clients;
    // clients.open("clientList.dat",ios::in|ios::out|ios::binary|iostream:: app);
    // clients.write((char*)&c1, sizeof(c1));
    // clients.close();   
}