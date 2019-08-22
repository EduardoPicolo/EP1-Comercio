#include "Client.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

vector<Client> clientList;
int clientPostion;

Client:: Client(){
}

Client:: Client(string name, bool vip=false):name(name),vip(vip){
    cout<< "New client successfully registered!"<<endl;
}

Client Client:: registerClient(string name){
    cout<< "Registering new client..."<< endl;
    Client client(name);
    clientList.push_back(client);
    // Write new client
    std::ofstream out("clients.txt", ios:: app);
    out<< client;
    out.close();
    return client;
}

Client Client:: login(){
    return clientList[clientPostion];
}

bool Client:: verifyClient(string name){
    // Open the file and fill in vector with objects
    std::ifstream in("clients.txt");
    Client temp;
    while(in){
        in>> temp;
        clientList.push_back(temp);
    }
    in.close();

    //  Search client
    for(int i =0; i<clientList.size();i++){
        if(name== clientList[i].get_name()){
            clientPostion = i;
            return true;
        }
    }
    return false;
}

string Client:: get_name(){
    return name;
}

void Client:: set_name(string name){
    this-> name = name;
}

bool Client:: get_vipStatus(){
    return vip;
}

void Client:: set_vipStatus(bool vip){
    this-> vip = vip;
}




bool Client::  operator== (Client & obj){
    return (name == obj.name) && (vip == obj.vip);
}

ostream & operator << (std::ostream &out, Client & obj){
    	out<< obj.name<< "\t"<< obj.vip<< std::endl;
		return out;
}

istream & operator >> (std::istream &in,  Client &obj){
    	in >> obj.name;
		in >> obj.vip;
		return in;
}


