#include "Exception.hpp"

Exception::Exception(){}

Exception::Exception(const char* msg): message(msg){
}

const char* Exception::what(){
    return message;
}

const Exception e_option("ERROR: Failed to process option.");
// Exception e_file =  Exception("ERROR: Failed to open file.");
const Exception e_file("ERROR: Failed to open file.");