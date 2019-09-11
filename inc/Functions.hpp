#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Store.hpp"
#include "Client.hpp"
#include "Product.hpp"
#include "Stock.hpp"
#include "Cart.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>
#include <limits>
using namespace std;

extern Client* client;

void fill_string_spaces(string & str);
void lowercase(string& str);
void clear_fail_state();
void validate_option(int& option,const string message);

vector<string> split(const string &s, char delim);
vector<pair<string, int>> order(map<string, int> records);

template<class myClass>
vector<myClass> read_file(string file_name);

template<class myClass>
void write_file(string file_name, myClass obj);

template<class myClass>
void over_write(string file_name, vector<myClass> list);

#include "Functions.tpp"
#endif