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

template<class myClass>
void over_write(string file_name, vector<myClass> list);

template<typename myClass>
vector<myClass> read_file(string file_name);

template<typename myClass>
void write_file(string file_name, myClass obj);

#include "Functions.tpp"
#endif