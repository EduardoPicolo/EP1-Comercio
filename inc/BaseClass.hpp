#ifndef BASECLASS_HPP
#define BASECLASS_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <type_traits>
using namespace std;

class BaseClass{
    public:
        virtual void abstract() = 0;
    protected:
        template<class myClass>
        static vector<myClass> readFile(string file){

        }

        template<class myClass>
        static void writeFile(string file, myClass obj){
            // Write new obj to file
            std::ofstream out(file, ios:: app);
            out<< obj;
            out.flush();
            out.close();
        }

        template<class myClass>
        static void overWrite(string file, vector<myClass> list){
            std::ofstream out(file);
            for(size_t i=0; i<list.size(); i++){
                out<<list[i];
            }
            out.close();  
        }

};

#endif