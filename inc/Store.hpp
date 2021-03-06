#ifndef STORE_HPP
#define STORE_HPP

#include "Functions.hpp"

class Store{
    virtual void abstract() = 0;
    public:
        static void start_session();
        static void main_menu();
        static void shop_mode();
        static void stock_mode();
        static void recommendation_mode();
        static void input_option(const int& n_options, const string& e_message);

};

#endif