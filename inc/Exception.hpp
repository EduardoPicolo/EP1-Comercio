#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <Functions.hpp>

class Exception: public exception {
    private:
        Exception();
        const char* message;
    
    public:
        Exception(const char* msg);
        const char* what();
};

extern Exception* e_option;
extern Exception* e_file;

#endif