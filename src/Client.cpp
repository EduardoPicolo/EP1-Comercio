#include "Client.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

vector<Client> Client::clientList = read_file("clients.txt");
int clientPostion;

Client:: Client(){
}

Client:: Client(string name, string cpf, bool vip=false)
:name(name), cpf(cpf), vip(vip){
    cout<< "New client successfully registered!"<<endl;
}

bool Client:: registerClient(string name, string cpf){
    if(!verifyClient(cpf)){
        cout<< "Registering new client... ";
        Client client(name, cpf);
        clientList.push_back(client);
        write_file("clients.txt", client);
        return true;
    }
    else{
        cout<< "Client already registered."<< endl;
        return false;
    }
}

bool Client:: verifyClient(string cpf){
    clientList = read_file("clients.txt");
    // Search client
    for(size_t i=0; i<clientList.size(); i++){
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

vector<Client> Client:: read_file(string file_name){
    fstream file;
    file.open(file_name, ios::in);
    vector<Client> list;
    Client temp;
    string name, cpf;
    // file.seekg(0);
    while(getline(file, name)&&getline(file, cpf)){
        temp.set_name(name);
        temp.set_cpf(cpf);
        temp.set_vipStatus(temp.get_vipStatus());
        list.push_back(temp);
    }
    file.close();

    return list;
}

void Client:: write_file(string file_name, Client newClient){
    fstream file;
    file.open(file_name, ios::out | ios::app);
    file<<newClient.get_name()<< endl;
    file<<newClient.get_cpf()<< endl;
    file<<newClient.get_vipStatus()<<endl;
    file.close();
}


void Client:: overwrite_file(string file_name, vector<Client> list){
    fstream file;
    file.open(file_name, ios::out);
    for(size_t i=0; i<list.size(); i++){
        file<<list[i].get_name()<< endl;
        file<<list[i].get_cpf()<< endl;
        file<<list[i].get_vipStatus()<<endl;
    }
    file.close();
}