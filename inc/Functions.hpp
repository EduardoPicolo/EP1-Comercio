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
#include <sstream>
#include <vector>
#include <iterator>
#include <string>
#include <limits>
using namespace std;

void start();
void fill_string_spaces(string & str);
void clear_fail_state();

template<class myClass>
void over_write(string file_name, vector<myClass> list);

template<class myClass>
vector<myClass> read_file(string file_name);

template<class myClass>
void write_file(string file_name, myClass obj);


vector<string> split (const string &s, char delim);

#include "Functions.tpp"
#endif