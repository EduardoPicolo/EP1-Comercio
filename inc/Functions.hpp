#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Client.hpp"
#include "Product.hpp"
#include "Stock.hpp"
#include "Logon.hpp"
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
#include <numeric>
#include <time.h>
#include <map>
#include <algorithm>
#include <limits>
using namespace std;

extern Client* client; //Global 'client'
extern int option;

template<typename type>
type get_input(const string& msg);
void fill_string_spaces(string & str);
void lowercase(string& str);
void clear_fail_state();
vector<string> split(const string &s, char delim);
vector<pair<string, float>> order(map<string, float> records);

#include "Functions.tpp"
#endif