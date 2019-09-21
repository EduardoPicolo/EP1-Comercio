#include "Exception.hpp"

Exception::Exception(){}

Exception::Exception(const char* msg): message(msg){
}

const char* Exception::what(){
    return message;
}

Exception* e_option =  new Exception("ERROR: Failed to process option.");
Exception* e_file =  new Exception("ERROR: Failed to open file.");