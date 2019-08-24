#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class BaseClass{
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
            out.close();
        }
        

        template<class myClass>
        bool verifyObject(string obj_name, vector<myClass> objList){
            for(int i =0; i<objList.size(); i++){
                if (obj_name== objList[i].get_name())// Object already registered
                    return true;
                else {
                    return false;
                }
            }
        }


        bool registerObject();

};