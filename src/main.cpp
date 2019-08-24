#include "Client.hpp"
#include "Product.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


int main() {
    Client client;
    Product product;
    string name, password;
    cout<< "Login\n"<< endl;
    cout<< "Username: ";
    cin>> name;
    cout<< "Password: ";
    cin>> password;

    product.registerProduct("Fuzz", "Buzz", 10, 99);
    product.registerProduct("Buzz", "Foo", 10, 99);

    // client.registerClient(name, password);
    // // LOGIN
    // while(client.login(&client,name, password)== false){
    //     cout<< "Username: ";
    //     cin>> name;
    //     cout<< "Password: ";
    //     cin>> password;
    // }











    // // Open the file and fill in vector with objects
    // std::ifstream in("clients.txt");
    // vector<Client> c;
    // Client t;
    // while(in){
    //     in>> t;
    //     c.push_back(t);
    // }
    // in.close();

    // // Change something in the vector
    // // for(int i =0; i<c.size();i++){
    // //     if("b"== c[i].get_name()){
    // //         c[i].set_name("PICOLO");
    // //     }
    // //     // cout<< c[i]<< endl;
    // // }
    
    // // Update the file with the vector
    // std::ofstream out("clients.txt");
    // for(int i=0;i<c.size()-1;i++){
    //     out<< c[i];
    //     cout<< i<< endl;
    // }
    // out.close();
 
	return 0;
}