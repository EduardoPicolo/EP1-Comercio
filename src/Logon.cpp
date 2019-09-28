#include "Logon.hpp"
#include "Store.hpp"

vector<Client> Logon::client_list;
int clientIndex;

void Logon::sign_up(){
    system("clear");
    cout<< "================================= Register =================================" <<endl;
    string name, cpf, password, email, phone_number;

    cout<< "CPF (Only numbers): ";
    getline(cin>>ws, cpf);
    if(Logon::validate_cpf(cpf)){
        switch(verify_client(cpf)){
        case true:
            cout<<'\t'<< "Client already registered"<<endl;
            cout<<'\t'<<left<<setw(17)<< "[1]:Try again"<<setfill(' ')<<setw(15)<< "[2]:Sign in"<<setfill(' ')<< "[3]:Cancel"<<endl;
            Store::input_option(3, "Enter [1] to try again, [2] to sign in or [3] to cancel.");
            switch(option){
                case 1:
                    Logon::sign_up();
                break;
                case 2:
                    Logon::sign_in();
                break;
                case 3:
                    Store::start_session();
                break;
                default:
                    throw e_option;
                break;
            }
        break;
        case false:
            cout<< "Name: ";
            getline(cin>>ws, name);
                lowercase(name);
            cout<< "Password: ";
            getline(cin>>ws, password);
            cout<< "Email: ";
            getline(cin>>ws, email);
            cout<< "Phone: ";
            getline(cin>>ws, phone_number);
            cout<< "Registering new client... ";
            Client c(name, cpf, password, email, phone_number);
            client_list.push_back(c);
            client = &client_list.back();  //Global variable 'client' = newly registered client
            Logon::write_file("clients.txt", *client);
        break;
        }
    }
    else{
        cout<<'\t'<<left<<setw(17)<< "[1]:Try again"<<setfill(' ')<< "[2]:Cancel"<<endl;
        Store::input_option(2, "Enter [1] to try again or [2] to cancel.");
        switch(option){
            case 1:
                Logon::sign_up();
            break;
            case 2:
                Store::start_session();
            break;
            default:
                throw e_option;
            break;
        }
    }
}

bool Logon::verify_client(string cpf){
    client_list = read_file("clients.txt");
    // Search client
    for(size_t i=0; i<client_list.size(); i++){
        if(cpf == client_list[i].get_cpf()){ // Client already registered
            clientIndex = i;
            return true;
        }
    }
    return false; // Client NOT registered
}
bool Logon::validate_cpf(const string& cpf){
    if(cpf.size()<11){
        cout<<'\t'<< "CPF must have 11 digits (only numbers)." <<endl;
        return false;
    }
    for(size_t i=0; i<cpf.size(); i++){
        if(!isdigit(cpf[i])){
            cout<<'\t'<< "Invalid CPF"<<endl;
            return false;
        }
    }
    return true;
}

void Logon::sign_in(){
    system("clear");
    cout<< "================================= Sign in =================================" <<endl;
    string cpf, password;

    cout<<"CPF (Only numbers): ";
    getline(cin>>ws, cpf);
    if(validate_cpf(cpf)){
        switch(verify_client(cpf)){
        case true:
            cout<< "Password: ";
            getline(cin>>ws, password);
            if(password == client_list[clientIndex].get_password()){
                cout<<'\t'<< "Logging in as "<< client_list[clientIndex].get_name()<<"..."<<endl;
                client = &client_list[clientIndex];
            }
            else{
                cout<<'\t'<< "Wrong password" <<endl;
                cout<<'\t'<<left<<setw(17)<< "[1]:Try again"<<setfill(' ')<< "[2]:Cancel" <<endl;
                Store::input_option(2, "Enter [1] to try again or [2] to cancel.");
                switch(option){
                    case 1:
                        Logon::sign_in();
                    break;
                    case 2:
                        Store::start_session();
                    break;
                    default:
                        throw e_option;
                    break;
                }
            }
        break;
        case false:
            cout<< '\t'<< "CPF not found." <<endl;
            cout<<'\t'<<left<<setw(17)<< "[1]:Try again"<<setfill(' ')<< "[2]:Register" <<endl;
            Store::input_option(2, "Enter [1] to try again or [2] to register.");
                switch(option){
                    case 1:
                        Logon::sign_in();
                    break;
                    case 2:
                        Logon::sign_up();
                    break;
                    default:
                        throw e_option;
                    break;
                }
        break;
        }
    }
    else{
        cout<<'\t'<<left<<setw(17)<< "[1]:Try again"<<setfill(' ')<< "[2]:Cancel"<<endl;
        Store::input_option(2, "Enter [1] to try again or [2] to cancel.");
        switch(option){
            case 1:
                Logon::sign_in();
            break;
            case 2:
                Store::start_session();
            break;
            default:
                throw e_option;
            break;
        }
    }
}
vector<Client> Logon::read_file(string file_name){
    fstream file;
    file.open("./doc/"+file_name, ios::in|ios::app);
    if(!file.is_open())
        throw e_file;
    Client temp; string name, cpf, password, email, phone, shop_history, vip;
    vector<Client> list; vector<string> parsed_shop_history;

    while(getline(file, cpf, ' ')&&getline(file, name, ';')&&getline(file, password, ';')&&getline(file, email, ';')&&getline(file, phone, ';')&&getline(file, vip, ';')&&getline(file, shop_history)){
        temp.set_cpf(cpf);
        temp.set_name(name);
        temp.set_password(password);
        temp.set_email(email);
        temp.set_phone_number(phone);
        temp.set_vip(atoi(vip.c_str()));
        parsed_shop_history = split(shop_history, '-');
        for(size_t i=1; i<=parsed_shop_history.size()/2; i++){
            temp.set_shop_history(parsed_shop_history[2*i-1], atof(parsed_shop_history[2*i].c_str()));
        }
        list.push_back(temp);
        temp.clear_shop_history();
    }
    file.close();
    return list;
}

void Logon::write_file(string file_name, Client client){
    fstream file;
    file.open("./doc/"+file_name, ios::app);
    if(!file.is_open())
        throw e_file;
    file<<client.get_cpf()<<' ';
    file<<client.get_name()<<';';
    file<<client.get_password()<<';';
    file<<client.get_email()<<';';
    file<<client.get_phone_number()<<';';
    file<<client.get_vip()<<';';
    file<<"SHOP_HISTORY";
    if(!client.get_shop_history().empty()){
        for(auto& key_value : client.get_shop_history()){
            file<<"-"<<key_value.first<<"-"<<key_value.second;
        }
    }
    file<<endl;
    file.close();
}
void Logon::overWrite_file(string file_name, vector<Client> list){
    fstream file;
    file.open("./doc/"+file_name, ios::out);
    if(!file.is_open())
        throw e_file;
    for(size_t i=0; i<list.size(); i++){
        file<<list[i].get_cpf()<<' ';
        file<<list[i].get_name()<<';';
        file<<list[i].get_password()<<';';
        file<<list[i].get_email()<<';';
        file<<list[i].get_phone_number()<<';';
        file<<list[i].get_vip()<<';';
        file<<"SHOP_HISTORY";
        if(!list[i].get_shop_history().empty()){
            for(auto& key_value : list[i].get_shop_history()){
                file<<"-"<<key_value.first<<"-"<<key_value.second;
            }
        }
        file<<endl;
    }
    file.close();
}

vector<Client> Logon::get_client_list(){
    return client_list;
}
