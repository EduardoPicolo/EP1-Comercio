#include "Client.cpp"
#include "Stock.cpp"
#include "Cart.cpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Client registerClient(string name){
//     Client client(name);
//     cout<< "New client successfully registed!"<< endl;
//     std::ofstream out("clients.txt", ios:: app);
//     out<< client;
//     out.close();
//     return client;
// }

// Client verifyClient(string name){
//     std::ifstream in("clients.txt");
//     Client temp;
//     in>> temp;
//     while (in) {
//         if(temp.get_name()== name){
//             // cout<< "Client already registered."<< endl;
//             in.close();
//             return temp;
//         }
//         in>> temp;
//     }
//     cout<< "Signing up new client..."<< endl;
//     registerClient(name);
// }

int main() {
    Client client;
    Stock product;
    string name;
    cout<< "Login\n"<< endl;
    cout<< "Username: ";
    cin>> name;
    client = client.verifyClient(name);

    product = product.registerNewProduct("Foo", "Bar", 99.99, 99);
    // product.displayProduct();
 
	return 0;
}