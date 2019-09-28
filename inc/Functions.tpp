#pragma once

template <typename type>
type get_input(const string& msg){
    while(true){
        type valor;
        cout<< msg;
        cin>> valor;
        if(cin.fail()){
            clear_fail_state();
            cout<<'\t'<< "Invalid input" <<endl;
        }
        else{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}