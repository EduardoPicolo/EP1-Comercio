#include "Client.hpp"
#include "Functions.hpp"

vector<Client> Client::clientList;
int clientPostion;

Client:: Client(){
}

Client:: Client(string name, string cpf, bool vip=false)
:name(name), cpf(cpf), vip(vip){
    cout<< "New client successfully registered!"<<endl;
}

bool Client:: registerClient(string name, string cpf){
    if(!verifyClient(cpf)){
        cout<< "Registering new client... ";
        Client client(name, cpf);
        clientList.push_back(client);
        write_file<Client>("clients.txt", client);
        return true;
    }
    else{
        cout<< "Client already registered."<< endl;
        return false;
    }
}

bool Client:: verifyClient(string cpf){
    clientList = read_file<Client>("clients.txt");
    // Search client
    for(size_t i=0; i<clientList.size(); i++){
        if(cpf == clientList[i].get_cpf()){ // Client already registered
            clientPostion = i;
            return true;
        }
    }
    return false; // Client NOT registered
}

Client Client:: login_client(string cpf){
    verifyClient(cpf);
    cout<<"\t" "Client: "<< clientList[clientPostion];
    return clientList[clientPostion];
}

string Client:: get_name(){
    return name;
}

void Client:: set_name(string name){
    this-> name = name;
}

string Client:: get_cpf(){
    return cpf;
}

void Client:: set_cpf(string cpf){
    this->cpf = cpf;
}

bool Client:: get_vipStatus(){
    return vip;
}

void Client:: set_vipStatus(bool vip){
    this-> vip = vip;
}

vector<Client> Client:: get_clientList(){
    clientList = read_file<Client>("clients.txt");
    return clientList;
}

map<string, int> Client::get_shop_history(){
    update_shop_history();
    return shop_history;
}


void Client::recover_shop_history(){
    vector<string> line, temp;
    string x;

    fstream infile;
    infile.open("record.txt", ios::in);

    while(getline(infile, x)){
        temp.push_back(x);
        line = split(x, '-');
        if(line[0] == this->cpf){
            temp.pop_back();
            int len = line.size();
            for(int i=1; i<=len/2; i++){
                shop_history[line[2*i-1]] = atoi(line[2*i].c_str());
            }
            if(getline(infile, x)){                
                temp.push_back(x);
            }
        }
    }

    fstream file;
    file.open("temp.txt", ios::out);
    ostream_iterator<string> output_iterator(file, "\n");
    copy(temp.begin(), temp.end(), output_iterator);

    file.close();
    infile.close();
    remove("record.txt");
    rename("temp.txt", "record.txt");
}

void Client:: update_shop_history(){
    recover_shop_history();
    // int cont = 0;
    vector<Product> productList = Cart::get_cart();
    map<string, int> categoriesDict;

    for(size_t i=0; i<productList.size(); i++){
        categoriesDict[productList[i].get_category()] += (productList[i].get_amount());
    }
    for(auto mapIterator = begin(categoriesDict); mapIterator != end(categoriesDict); ++mapIterator){
        // cont = 0;
        // for(auto c : mapIterator->second){
        //     cont++;
        //     cont = cont+mapIterator->second;
        // }
        shop_history[mapIterator->first] += mapIterator->second;
    }

    fstream outfile("record.txt", ios::app);
    outfile<<this->cpf;
    for(auto& key_value : shop_history){
        outfile<<"-"<<key_value.first<<"-"<<key_value.second;
    }
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


bool Client:: operator == (Client & obj){
    return (name == obj.name) && (cpf == obj.cpf);
}

// Overload operator <<
ostream & operator << (ostream &out, const Client & obj){
	out << obj.name << " " << obj.cpf <<endl;
	return out;
}
// Overload operator >>
istream & operator >> (istream &in,  Client &obj){
	in >> obj.name;
	in >> obj.cpf;
	return in;
}