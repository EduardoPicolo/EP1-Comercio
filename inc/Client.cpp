#include "Client.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

vector<Client> clientList;
int clientPostion;

Client:: Client(){
}

Client:: Client(string name, string password, bool vip=false):name(name),password(password), vip(vip){
    cout<< "New client successfully registered!"<<endl;
}

void Client:: registerClient(string name, string password){
    if(!verifyClient(name)){
        cout<< "Registering new client..."<< endl;
        Client client(name, password);
        clientList.push_back(client);
        // Write new client
        std::ofstream out("clients.txt", ios:: app);
        out<< client;
        out.close();
    }
    else{
        cout<< "Client already registered."<< endl;
    }
}

bool Client:: login(Client *client, string name, string password){
    if(verifyClient(name)){
        if(password== clientList[clientPostion].password){
            cout<< "Signing in..."<< endl;
            client-> set_name(name);
            client-> set_password(password);
            return true;
        }
        else{
            cout<< "Wrong password."<< endl;
        }
    }
    else if(!verifyClient(name)){
        cout<< "Username not found."<< endl;
        return false;
    }
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
        if(name== clientList[i].get_name()){ // Client already registered
            clientPostion = i;
            return true;
        }
    }
    return false; // Client NOT registered
}

string Client:: get_name(){
    return name;
}

void Client:: set_name(string name){
    this-> name = name;
}

string Client:: get_password(){
    return password;
}

void Client:: set_password(string password){
    this-> password = password;
}

bool Client:: get_vipStatus(){
    return vip;
}

void Client:: set_vipStatus(bool vip){
    this-> vip = vip;
}




bool Client::  operator== (Client & obj){
    return (name == obj.name) && (vip == obj.vip)&& (password== obj.password);
}

ostream & operator << (std::ostream &out, Client & obj){
    	out<< obj.name<< "\t"<< obj.vip<< "\t"<< obj.password<< std::endl;
		return out;
}

istream & operator >> (std::istream &in,  Client &obj){
    	in >> obj.name;
		in >> obj.vip;
        in >> obj.password;
		return in;
}


