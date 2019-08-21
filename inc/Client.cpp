#include "Client.hpp"
#include <string>

Client:: Client(){
    this-> vip = false;
}

void Client:: registerClient(string name, bool vip){
    this-> name = name;
    this-> vip = vip;
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


