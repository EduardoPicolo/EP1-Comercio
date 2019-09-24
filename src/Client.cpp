#include "Client.hpp"
#include "Functions.hpp"
#include "Store.hpp"

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
void Client::update_shop_history(float total){
    vector<Product> productList = Cart::get_cart();

    for(size_t i=0; i<productList.size(); i++){
        this->shop_history[productList[i].get_category()] += (productList[i].get_amount());
    }
    if(this->vip==true){
        this->shop_history["TOTAL"] += total-(total*0.15);
    }
    else this->shop_history["TOTAL"] += total;
    Logon::overWrite_file("clients.txt", Logon::get_client_list());
}
void Client::edit_data(){
    string name, password, email, phone;map<string, float> shop_history;
    cout<<'\t'<<left<<setw(15)<< "1:Edit name"<<setfill(' ')<<setw(21)<< "2:Change password"<<setfill(' ')<<setw(16)<<"3:Edit email"<<setfill(' ')<<setw(16)<< "4:Edit phone"<<setfill(' ')<< "5:Become VIP"<<endl;
    Store::input_option(5, "Enter 1 to edit name, 2 to change password, 3 to edit email or 4 to become VIP.");
    switch(option){
        case 1:
            cout<< "New name: ";
            cin>> name;
            if(cin.fail()){
                clear_fail_state();
                cout<< "Failed to edit name"<<endl;
            }
            else{
                // client->set_name(name);
                lowercase(name);
                this->name = name;
                Logon::overWrite_file("clients.txt", Logon::get_client_list());
                cout<< "Name successfuly edited."<<endl;
            }
        break;
        case 2:
            cout<< "Enter current password";
            cin>> password;
            if(client->get_password()==password){
                cout<< "New password: ";
                cin>> password;
                // client->set_password(password);
                this->password = password;
                Logon::overWrite_file("clients.txt", Logon::get_client_list());
                cout<< "Password successfuly changed."<<endl;
            }
            else
                cout<< "Wrong password."<<endl;
        break;
        case 3:
            cout<< "New email: ";
            cin>> email;
            if(cin.fail()){
                clear_fail_state();
                cout<< "Failed to edit email"<<endl;
            }
            else{
                // client->set_email(email);
                this->email = email;
                Logon::overWrite_file("clients.txt", Logon::get_client_list());
                cout<< "Email successfuly edited."<<endl;
            }
        break;
        case 4:
            cout<< "New phone number: ";
            cin>> phone;
            if(cin.fail()){
                clear_fail_state();
                cout<< "Failed to edit phone number"<<endl;
            }
            else{
                this->phone_number = phone;
                Logon::overWrite_file("clients.txt", Logon::get_client_list());
                cout<< "Phone number successfuly edited."<<endl;
            }
        break;
        case 5:
            cout<< "A VIP client has a special discount of 15%% in every purchase."<<endl;
            if(this->shop_history["TOTAL"]<200.0){
                cout<< "To become a VIP client, one must have bought at least $200 in products"<<endl;
            }
            else{
                this->vip = true;
                cout<< "You are now a VIP client!"<<endl;
                Logon::overWrite_file("clients.txt", Logon::get_client_list());
            }
        break;
        default:
            throw e_option;
        break;
    }
}

void Client::display_shop_history(){
    vector<pair<string, float>> sorted_vector = order(shop_history);
    cout<<'\t'<< "Product category" <<'\t'<< "Bought" <<endl;
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
void Client::display_client(){
    cout<< "Client: "<<this->name<<' '<<this->cpf<<endl;
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