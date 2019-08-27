#ifndef BASECLASS_HPP
#define BASECLASS_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class BaseClass{
    public:
        virtual void abstract() = 0;
    protected:
        template<class myClass>
        vector<myClass> readFile(string file){
            vector<myClass> objList;
            // Open the file and fill in vector with objects
            std::ifstream in(file);    
            myClass temp;
            while(in){
                in>> temp;
                objList.push_back(temp);
            }
            in.close();
            return objList;
        }

        template<class myClass>
        void writeFile(string file, myClass obj){
            // Write new obj to file
            std::ofstream out(file, ios:: app);
            out<< obj;
            out.flush();
            out.close();
        }

        template<class myClass>
        void overWrite(string file, vector<myClass> list){
            std::ofstream out(file, ios::trunc);
            for(size_t i=0; i<list.size()-1; i++){
                out<<list[i];
            }
            out.close();  
        }

};

#endif