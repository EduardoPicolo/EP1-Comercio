#ifndef STORE_HPP
#define STORE_HPP

#include "Functions.hpp"

class Store{
    private:
        virtual void abstract() = 0;

    public:
        static void main_menu();
        static void shop_mode();
        static void stock_mode();
        static void recommendation_mode();
};

#endif