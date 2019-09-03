#include "Functions.hpp"

int start(void){
    int option = 0;
    cout<<"\t" "1:Shop"<<"\t"<< "2:Stock"<<endl;cout<< ">> ";
    cin>>  option;
    while(option!=1&&option!=2){
        if (cin.fail()){
            // get rid of failure state
            cin.clear();
            cin.ignore(1000, '\n');
        }
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

    return 0;
}


void fill_string_spaces(string & str){
    for(size_t i=0; i<str.length(); i++){
        if(str[i] == ' ')
            str[i] = '-';
    }
}