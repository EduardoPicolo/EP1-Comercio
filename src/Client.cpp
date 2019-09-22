#include "Client.hpp"
#include "Functions.hpp"

Client::Client():name(""), cpf(""), password(""), email(""), phone_number(""), vip(false){
}
Client::Client(string name, string cpf, string password, string email, string phone_number)
:name(name), cpf(cpf), password(password), email(email), phone_number(phone_number), vip(false){
    if(name.length()==0)
        throw Exception("Client's name must not be empty.");
    else if(cpf.length()<11)
        throw Exception("Client must have a valid CPF.");
    else if(password.length()==0)
        throw Exception("Invalid password.");
    shop_history["TOTAL"] = 0.0;
    cout<< "New client successfully registered!"<<endl;
}
Client::~Client(){
}

void Client::display_client(){
    cout<< "Client: "<<this->name<<' '<<this->cpf<<endl;
}
void Client::display_shop_history(){
    vector<pair<string, float>> sorted_vector = order(shop_history);
    cout<<"\t" "Product category" <<"\t" "Bought" <<endl;
    for (auto it = sorted_vector.cbegin(); it != sorted_vector.cend(); it++){
		cout<< it->first <<"\t\t\t"<< it->second <<endl;
	}
}
const map<string, float> Client::get_shop_history(){
    return shop_history;
}
void Client::set_shop_history(string category, float num){
    this->shop_history[category] += num;
}
void Client::clear_shop_history(){
    this->shop_history.clear();
}

const string Client::get_name(){
    return name;
}
void Client::set_name(string name){
    if(name.length()==0)
        throw new Exception("Client's name must not be empty.");
    else
        this-> name = name;
}
const string Client::get_cpf(){
    return cpf;
}
void Client::set_cpf(string cpf){
    this->cpf = cpf;
}
void Client::set_password(string password){
    this->password = password;
}
const string Client::get_password(){
    return password;
}
void Client::set_email(string email){
    this->email = email;
}
const string Client::get_email(){
    return email;
}
void Client::set_phone_number(string number){
    this->phone_number = number;
}
const string Client::get_phone_number(){
    return phone_number;
}
void Client::set_vip(bool status){
    this->vip = status;
}
bool Client::get_vip(){
    return vip;
}