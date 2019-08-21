#include "Client.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Client:: Client(){
    this-> name= "";
    this-> vip = false;
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


