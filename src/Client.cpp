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

void Client::set_rec(){
    map<string, int> rec;
    vector<string> temp;
    vector<string> line;
    string x;

    fstream infile;
    fstream file;
    infile.open("test.txt", ios::in);
    file.open("temp.txt", ios::app);

    while(getline(infile, x)){
        temp.push_back(x);
        line = split(x, '-');
        if(line[0] == this->cpf){
            temp.pop_back();
            int len = line.size();
            for(int i=1; i<=len/2; i++){
                rec[line[2*i-1]] = atoi(line[2*i].c_str());
            }
            if(getline(infile, x)){                
                temp.push_back(x);
            }
        }
    }
    
    ostream_iterator<string> output_iterator(file, "\n");
    copy(temp.begin(), temp.end(), output_iterator);

    file.close();
    infile.close();
    remove("test.txt");
    rename("temp.txt", "test.txt");

    int cont = 0;
    vector<Product> productList = Cart::get_cart();
    map<string, vector<Product>> categoriesDict;
    for(size_t i=0; i<productList.size(); i++){
        categoriesDict[productList[i].get_category()].push_back(productList[i]);
    }
    for(auto mapIterator = begin(categoriesDict); mapIterator != end(categoriesDict); ++mapIterator){
        cont = 0;
        for(auto c : mapIterator->second){
            cont++;
        }
        rec[mapIterator->first] += cont;
    }

    fstream outfile("test.txt", ios::app);
    outfile<<this->cpf;
    for(auto& kv : rec){
        outfile<<"-"<<kv.first<<"-"<<kv.second;
    }
    outfile.close();
}