#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Client.hpp"
#include "Product.hpp"
#include "Stock.hpp"
#include "Management.hpp"
#include "Cart.hpp"
#include "Exception.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <cctype>
#include <map>
#include <algorithm>
#include <limits>
using namespace std;

extern Client* client; //Global 'client'
extern int option;

void fill_string_spaces(string & str);
void lowercase(string& str);
void clear_fail_state();
void validate_option(int& option,const string message);

vector<string> split(const string &s, char delim);
vector<pair<string, int>> order(map<string, int> records);

#endif