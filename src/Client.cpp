#include "Client.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

vector<Client> Client::clientList = readFile<Client>("clients.txt");
int clientPostion;

Client:: Client(){
}

Client:: Client(string name, string cpf, string password, bool vip=false):name(name), cpf(cpf), password(password), vip(vip){
    cout<< "New client successfully registered!"<<endl;
}

bool Client:: registerClient(string name, string cpf, string password){
    if(!verifyClient(cpf)){
        cout<< "Registering new client... ";
        Client client(name, cpf, password);
        clientList.push_back(client);
        writeFile<Client>("clients.txt", client);
        return true;
    }
    else{
        cout<< "Client already registered."<< endl;
        return false;
    }
}

bool Client:: login(Client *client, string cpf, string password){
    if(verifyClient(cpf)){
        if(password == clientList[clientPostion].password){
            cout<< "Signing in..."<< endl;
            *client = clientList[clientPostion];
            return true;
        }
        else{
            cout<< "Wrong password."<< endl;
            return false;
        }
    }
    else{
        cout<< "Client not found."<< endl;
        return false;
    }
}

bool Client:: verifyClient(string cpf){
    // clientList = readFile<Client>("clients.txt");
    // Search client
    for(size_t i=0; i<clientList.size();i++){
        if(cpf == clientList[i].get_cpf()){ // Client already registered
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

string Client:: get_cpf(){
    return cpf;
}

void Client:: set_cpf(string cpf){
    this->cpf = cpf;
}

bool Client:: get_vipStatus(){
    return vip;
}

void Client:: set_vipStatus(bool vip){
    this-> vip = vip;
}

vector<Client> Client:: get_clientList(){
    return clientList;
}



bool Client::  operator == (Client & obj){
    return (name == obj.name) && (vip == obj.vip) && (password== obj.password) && (cpf == obj.cpf);
    // return cpf == obj.cpf;
}

ostream & operator << (ostream &out, Client & obj){
    	out<< obj.name <<"\t"<< obj.cpf <<"\t"<< obj.password <<"\t"<< obj.vip <<std::endl;
		return out;
}

istream & operator >> (istream &in,  Client &obj){
    	in>> obj.name;
        in>> obj.cpf;
        in>> obj.password;
		in>> obj.vip;
		return in;
}


