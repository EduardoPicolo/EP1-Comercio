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

#endif