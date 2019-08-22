#include "Client.hpp"
#include <iostream>
#include <fstream>
#include <string>
Client:: Client(){}

Client:: Client(string name, bool vip=false):name(name),vip(vip){
    cout<< "New client successfully created!"<<endl;
}

Client Client:: registerClient(string name){
    cout<< "Registering new client..."<< endl;
    Client client(name);
    // cout<< "New client successfully registed!"<< endl;
    std::ofstream out("clients.txt", ios:: app);
    out<< client;
    out.close();
    return client;
}

Client Client:: verifyClient(string name){
    std::ifstream in("clients.txt");
    Client temp;
    in>> temp;
    while (in) {
        if(temp.get_name()== name){
            cout<< "Client already registered."<< endl;
            in.close();
            return temp;
        }
        in>> temp;
    }
    cout<< "Client not found."<< endl;
    this-> registerClient(name);
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




bool Client::  operator== (const Client & obj){
    return (name == obj.name) && (vip == obj.vip);
}

ostream & operator << (std::ostream &out, const Client & obj){
    	out<< obj.name<< "\n"<< obj.vip<< "\n"<< std::endl;
		return out;
}

istream & operator >> (std::istream &in,  Client &obj){
    	in >> obj.name;
		in >> obj.vip;
		return in;
}


