#include "Client.hpp"
#include "Functions.hpp"

vector<Client> Client::clientList;
int clientPostion;

Client:: Client(){
}

Client:: Client(string name, string cpf)
:name(name), cpf(cpf){
    cout<< "New client successfully registered!"<<endl;
}

void Client::register_client(){
    int option = 0;
    string name, cpf;

    cout<< "Name: ";
    getline(cin>>ws, name);
        lowercase(name);
    cout<< "CPF: ";
    getline(cin>>ws, cpf);
        fill_string_spaces(cpf);
    switch(verifyClient(cpf)){
        case true:
            cout<< "Client already registered"<<endl;
            cout<<"\t" "1:Try again"<<"\t"<< "2:Login"<<"\t"<< "3:Cancel"<<endl;cout<< ">> ";
            cin>> option;
            validate_option(option, "Invalid. Enter 1 to try again, 2 to login or 3 to cancel.");
            switch(option){
                case 1:
                    register_client();
                break;
                case 2:
                    login();
                break;
                case 3:
                    Store::main_menu();
                break;
                default:
                break;
            }
        break;

        case false:
            cout<< "Registering new client... ";
            Client c(name, cpf);
            clientList.push_back(c);
            write_file("clients.txt", c);
            *client = c;
        break;
    }

}

bool Client:: verifyClient(string cpf){
    clientList = read_file("clients.txt");
    // Search client
    for(size_t i=0; i<clientList.size(); i++){
        if(cpf == clientList[i].get_cpf()){ // Client already registered
            clientPostion = i;
            return true;
        }
    }
    return false; // Client NOT registered
}

void Client::login(){
    int option = 0;
    string cpf;

    cout<<"Client CPF: ";
    getline(cin>>ws, cpf);
    if(verifyClient(cpf)){
        // *client = clientList[clientPostion];
        cout<< "Client: "; clientList[clientPostion].display_client();
        cout<<"\t" "1:Confirm"<<"\t"<<"2:Enter new CPF"<<"\t"<<"3:Cancel"<<endl;cout<< ">> ";
        cin>> option;
        validate_option(option, "Invalid. Enter 1 to confirm, 2 to enter a new cpf or 3 to cancel.");
        switch(option){
            case 1:
                *client = clientList[clientPostion];
            break;
            case 2:
                login();
            break;
            case 3:
                Store::main_menu();
            break;
            default:
            break;
        }
    }
    else{
        cout<< "Client not found"<<endl;
        cout<<"\t" "1:Enter new CPF"<<"\t"<< "2:Register client"<<"\t"<< "3:Cancel"<<endl;cout<<">> ";
        cin>> option;
        validate_option(option,  "Invalid. Enter 1 to try again, 2 to register client or 3 to cancel.");
        switch(option){
            case 1:
                login();
            break;
            case 2:
                register_client();
            break;
            case 3:
                Store::main_menu();
            break;
            default:
            break;
        }
    }
}

void Client::display_client(){
    cout<<" "<<this->name<<' '<<this->cpf<<endl;
}

const string Client:: get_name(){
    return name;
}

void Client:: set_name(string name){
    this-> name = name;
}

const string Client:: get_cpf(){
    return cpf;
}

void Client:: set_cpf(string cpf){
    this->cpf = cpf;
}

vector<Client> Client:: get_clientList(){
    clientList = read_file("clients.txt");
    return clientList;
}

map<string, int> Client::get_shop_history(){
    recover_shop_history();
    return shop_history;
}


void Client::recover_shop_history(){
    vector<string> line, temp;
    string x;

    fstream infile;
    infile.open("clients.txt", ios::in);

    while(getline(infile, x, ' ')){
        if(x == this->cpf){
            getline(infile, x, '#');
            getline(infile, x);
            line = split(x, '-');
            int len = line.size();
            for(int i=1; i<=len/2; i++){
                shop_history[line[2*i-1]] = atoi(line[2*i].c_str());
            }
            break;
        }
        else{
            getline(infile, x);
        }
    }
}

void Client:: update_shop_history(){
    recover_shop_history();
    vector<string> line, temp;
    string x, aux;
    fstream infile, file;
    infile.open("clients.txt", ios::in);
    file.open("temp.txt", ios::out);
    while(getline(infile, x, ' ')){
        if(x == this->cpf){
            aux = x+' ';
            getline(infile, x, '#');
            aux = aux+x;
            getline(infile, x);
        }
        else{
            file<<x+' ';
            getline(infile, x);
            file<<x<<endl;
        }
    }
    infile.close();
    file.close();
    remove("clients.txt");
    rename("temp.txt", "clients.txt");

    vector<Product> productList = Cart::get_cart();
    map<string, int> categoriesDict;

    for(size_t i=0; i<productList.size(); i++){
        categoriesDict[productList[i].get_category()] += (productList[i].get_amount());
    }
    for(auto mapIterator = begin(categoriesDict); mapIterator != end(categoriesDict); ++mapIterator){
        shop_history[mapIterator->first] += mapIterator->second;
    }
    // write_file("clients.txt", *this);
    fstream outfile("clients.txt", ios::app);
    outfile<<aux<<'#'<<"SHOP_HISTORY";
    for(auto& key_value : shop_history){
        outfile<<"-"<<key_value.first<<"-"<<key_value.second;
    }
    outfile<<endl;
    outfile.close();
}

void Client:: display_shop_history(){
    update_shop_history();
    vector<pair<string, int>> sorted_vector = order(shop_history);
    cout<<"\t" "Product category" <<"\t" "Bought" <<endl;
    for (auto it = sorted_vector.crbegin(); it != sorted_vector.crend(); it++){
		cout<< it->first <<"\t\t\t"<< it->second <<endl;
	}
}

vector<Client> Client::read_file(string file_name){
    fstream file;
    file.open(file_name, ios::in);
    vector<Client> list;
    Client temp;
    string name, cpf, aux;
    while(getline(file, cpf, ' ')&&getline(file, name, '#')){
        temp.set_cpf(cpf);
        temp.set_name(name);
        list.push_back(temp);
        getline(file, aux);
    }
    file.close();
    return list;
}

void Client::write_file(string file_name, Client client){
    fstream file;
    file.open(file_name, ios::app);
    file<<client.get_cpf()<<' ';
    file<<client.get_name()<<"#";
    file<<"SHOP_HISTORY";
    if(!client.shop_history.empty()){
        for(auto& key_value : client.shop_history){
            file<<"-"<<key_value.first<<"-"<<key_value.second;
        }
    }
    file<<endl;
}
