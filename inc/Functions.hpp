#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Client.hpp"
#include "Product.hpp"
#include "Stock.hpp"
#include "Cart.hpp"
#include "stockMode.hpp"
#include "shopMode.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int start(void);
void fill_string_spaces(string & str);

template<typename myClass>
void over_write(string file_name, vector<myClass> list){
    fstream file(file_name, ios::out);
    for(size_t i=0; i<list.size(); i++){
        file<<list[i];
    }
    file.close();  
}

template<typename myClass>
vector<myClass> read_file(string file_name){
    vector<myClass> objList;
    fstream file;
    file.open(file_name, ios::in);
    myClass temp;
    while(file>>temp){
        objList.emplace_back(temp);
    }
    file.close();
    return objList;
}

template<typename myClass>
void write_file(string file_name, myClass obj){
    // Write new obj to file
    fstream file;
    file.open(file_name, ios::app);
    file<< obj;
    file.close();
}

#endif