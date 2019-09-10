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

bool Client:: registerClient(string name, string cpf){
    if(!verifyClient(cpf)){
        cout<< "Registering new client... ";
        Client client(name, cpf);
        clientList.push_back(client);
        write_file("clients.txt", client);
        return true;
    }
    else{
        cout<< "Client already registered."<< endl;
        return false;
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

Client Client:: login_client(string cpf){
    verifyClient(cpf);
    cout<<"\t" "Client: "; clientList[clientPostion].display_client();
    return clientList[clientPostion];
}

void Client::display_client(){
    cout<<" "<<this->name<<' '<<this->cpf<<endl;
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
        // else{
        //     aux = x;
        //     getline(infile, x);
        //     aux = aux+' '+x;
        //     temp.push_back(aux);
        // }
    }

    // fstream file;
    // file.open("temp.txt", ios::out);
    // ostream_iterator<string> output_iterator(file, "\n");
    // copy(temp.begin(), temp.end(), output_iterator);

    // file.close();
    // infile.close();
    // remove("record.txt");
    // rename("temp.txt", "record.txt");

//         temp.push_back(x);
//         line = split(x, '-');
//         if(line[0] == this->cpf){
//             temp.pop_back();
//             int len = line.size();
            // for(int i=1; i<=len/2; i++){
            //     shop_history[line[2*i-1]] = atoi(line[2*i].c_str());
            // }
//             if(getline(infile, x)){                
//                 temp.push_back(x);
//             }
//         }
//     }

    // fstream file;
    // file.open("temp.txt", ios::out);
    // ostream_iterator<string> output_iterator(file, "\n");
    // copy(temp.begin(), temp.end(), output_iterator);

    // file.close();
    // infile.close();
    // remove("record.txt");
    // rename("temp.txt", "record.txt");

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
