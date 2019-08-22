#include "Client.cpp"
#include "Stock.cpp"
#include "Cart.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    Client client;
    Stock product;
    string name;
    cout<< "Login\n"<< endl;
    cout<< "Username: ";
    cin>> name;
    client.verifyClient(name);

    
    std::ifstream in("clients.txt");
    vector<Client> c;
    Client t;
    while(in){
        in>> t;
        c.push_back(t);
    }
    in.close();
    
    // for(int i =0; i<c.size();i++){
    //     if("b"== c[i].get_name()){
    //         c[i].set_name("PICOLO");
    //     }
    //     // cout<< c[i]<< endl;
    // }
    
    std::ofstream out("clients.txt");
    for(int i=0;i<c.size()-1;i++){
        out<< c[i];
        cout<< i<< endl;
    }
    out.close();

    




    // cout<< client.get_vipStatus()<< endl;

    product.registerNewProduct("OBELIXO", "LIXO", 1.5, 999);
    // product.displayProduct();
 
	return 0;
}