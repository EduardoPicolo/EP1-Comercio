#include "Functions.hpp"
#include <map>

void start(){
    int option = 0;
    cout<<"\t" "1:Shop"<<"\t"<< "2:Stock"<<endl;cout<< ">> ";
    cin>>  option;
    while(option!=1&&option!=2){
        clear_fail_state();
        cout << "Invalid. Enter 1 for shop or 2 for stock: ";
        cin>>  option;
    }

    switch(option){
        case 1:
            shop();
        break;

        case 2:
            stock();
        break;

        default:
        break;
    }
}

void fill_string_spaces(string & str){
    for(size_t i=0; i<str.length(); i++){
        if(str[i] == ' ')
            str[i] = '-';
    }
}

void clear_fail_state(){
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}