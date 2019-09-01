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

        template<class myClass>
        static void over_write(string file_name, vector<myClass> list){
            fstream file(file_name, ios::out);
            for(size_t i=0; i<list.size(); i++){
                file<<list[i];
            }
            file.close();  
        }
    protected:
        template<class myClass>
        static vector<myClass> read_file(string file_name){
            vector<myClass> objList;
            fstream file;
            file.open(file_name, ios::in);
            // if(!file){
            //     cerr<<"ERROR OPENING FILE."<<endl;
            // }
            myClass temp;
            while(file>>temp){
                objList.emplace_back(temp);
            }
            file.close();
            return objList;
        }

        template<class myClass>
        static void write_file(string file_name, myClass obj){
            // Write new obj to file
            fstream file;
            file.open(file_name, ios::app);
            file<< obj;
            file.close();
        }

        // template<class myClass>
        // static void overWrite(string file_name, vector<myClass> list){
        //     fstream file(file_name, ios::out);
        //     for(size_t i=0; i<list.size(); i++){
        //         file<<list[i];
        //     }
        //     file.close();  
        // }
};

#endif
