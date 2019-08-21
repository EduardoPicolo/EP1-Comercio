#include "Client.cpp"
#include "Stock.cpp"
#include "Cart.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void registerClient(string name){
    Client client;
    client.set_name(name);
    ofstream file("clientList.txt", ios::app);
    if(file.is_open())
    {
        file<< client.get_name()<< endl;
        file.close();
    }
    cout<< "New client successfully registered."<< endl;
}

bool verifyClient(string name){
    string clients;
    ifstream getFromFile("clientList.txt");
    if(getFromFile.is_open())
    {
        while(getFromFile.good())
        {
            getline(getFromFile, clients);
            if(name ==  clients){
                cout<< "Client already registered."<< endl;
                return false;
            }
        }
        return true;
    }
}

int main() {
    string name;
    cout<< "Login:\n"<< endl;
    cout<< "Username: ";
    cin>> name;
    if(verifyClient(name)){
        cout<< "..."<< endl;
        registerClient(name);
    }
}