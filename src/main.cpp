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
    string name, password;
    cout<< "Login\n"<< endl;
    cout<< "Username: ";
    cin>> name;
    cout<< "Password: ";
    cin>> password;


    // client.registerClient(name, password);
    // LOGIN
    while(client.login(&client,name, password)== false){
        cout<< "Username: ";
        cin>> name;
        cout<< "Password: ";
        cin>> password;
    }



    // if(!client.verifyClient(name)){
    //     client = client.registerClient(name);
    // }
    // else{
    //     cout<< "Client already registered."<< endl;
    // }

    // if(client.verifyClient(name)){
    //     client = client.login(name);
    // }
    // else{
    //     cout<< "Client not found."<< endl;
    // }

    // cout<< client.get_name()<< endl;









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

    




    // product.registerNewProduct("OBELIXO", "LIXO", 1.5, 999);
    // product.displayProduct();
 
	return 0;
}