#include "Client.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int clientPostion;

Client:: Client():name(""){
}

Client:: Client(string name, string password, bool vip=false):name(name),password(password), vip(vip){
    cout<< "New client successfully registered!"<<endl;
}

void Client:: registerClient(string name, string password){
    if(!verifyClient(name)){
        cout<< "Registering new client... ";
        Client client(name, password);
        clientList.push_back(client);
        writeFile<Client>("clients.txt", client);
    }
    else{
        cout<< "Client already registered."<< endl;
    }
}

bool Client:: login(Client *client, string name, string password){
    if(verifyClient(name)){
        if(password== clientList[clientPostion].password){
            cout<< "Signing in..."<< endl;
            // client-> set_name(name);
            // client-> set_password(password);
            *client = clientList[clientPostion];
            return true;
        }
        else{
            cout<< "Wrong password."<< endl;
            return false;
        }
    }
    else{
        cout<< "Username not found."<< endl;
        return false;
    }
}

bool Client:: verifyClient(string name){
    clientList = readFile<Client>("clients.txt");
    // Search client
    for(size_t i =0; i<clientList.size();i++){
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


