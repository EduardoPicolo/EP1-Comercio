#include "Management.hpp"
#include "Store.hpp"

vector<Client> Management::client_list;
int clientIndex;

void Management::register_client(){
    string name, cpf, password, email, phone_number;

    cout<< "CPF: ";
    getline(cin>>ws, cpf);
    if(Management::validate_cpf(cpf)){
        switch(verify_client(cpf)){
        case true:
            cout<<'\t'<< "Client already registered"<<endl;
            cout<<'\t'<<left<<setw(15)<< "1:Try again"<<setfill(' ')<<setw(11)<< "2:Login"<<setfill(' ')<< "3:Cancel"<<endl;
            Store::input_option(3, "Enter 1 to try again, 2 to login or 3 to cancel.");
            switch(option){
                case 1:
                    Management::register_client();
                break;
                case 2:
                    Management::login();
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
            client = new Client(name, cpf, password, email, phone_number); //Global variable 'client' = newly registered client
            client_list.push_back(*client);
            Management::write_file("clients.txt", *client);
        break;
        }
    }
    else{
        cout<<'\t'<<left<<setw(15)<< "1:Try again"<<setfill(' ')<< "2:Cancel"<<endl;
        Store::input_option(2, "Enter 1 to try again or 2 to cancel.");
        switch(option){
            case 1:
                Management::register_client();
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

bool Management::verify_client(string cpf){
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
bool Management::validate_cpf(const string& cpf){
    if(cpf.size()<11)
        return false;
    for(size_t i=0; i<cpf.size(); i++){
        if(!isdigit(cpf[i])){
            cout<< "Invalid CPF"<<endl;
            return false;
        }
    }
    return true;
}

void Management::login(){
    string cpf, password;

    cout<<"Client's CPF: ";
    getline(cin>>ws, cpf);
    if(validate_cpf(cpf)){
        switch(verify_client(cpf)){
        case true:
            cout<< "Password: ";
            getline(cin>>ws, password);
            if(password == client_list[clientIndex].get_password()){
                cout<<'\t'<< "Logging in as "<< client_list[clientIndex].get_name()<<"..."<<endl;
                *client = client_list[clientIndex];
            }
            else{
                cout<< "Wrong password" <<endl;
                cout<<'\t'<<left<<setw(15)<< "1:Try again"<<setfill(' ')<< "2:Cancel" <<endl;
                Store::input_option(2, "Enter 1 to try again or 2 to cancel.");
                switch(option){
                    case 1:
                        Management::login();
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
            cout<< "CPF not found" <<endl;
            cout<<'\t'<<left<<setw(15)<< "1:Try again"<<setfill(' ')<< "2:Register" <<endl;
            Store::input_option(2, "Enter 1 to try again or 2 to cancel.");
                switch(option){
                    case 1:
                        Management::login();
                    break;
                    case 2:
                        Management::register_client();
                    break;
                    default:
                        throw e_option;
                    break;
                }
        break;
        }
    }
    else{
        cout<<'\t'<<left<<setw(15)<< "1:Try again"<<setfill(' ')<< "2:Cancel"<<endl;
        Store::input_option(2, "Enter 1 to try again or 2 to cancel.");
        switch(option){
            case 1:
                Management::login();
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
void Management::update_shop_history(){
    vector<Product> productList = Cart::get_cart();
    map<string, int> categoriesDict;

    /*Get each product category from products in cart and them adds to categoryDictionary*/
    for(size_t i=0; i<productList.size(); i++){
        categoriesDict[productList[i].get_category()] += (productList[i].get_amount());
    }
    /*Update signed in client's shop_history category/number */
    for(auto mapIterator = begin(categoriesDict); mapIterator != end(categoriesDict); ++mapIterator){
        client->set_shop_history(mapIterator->first, mapIterator->second);
    }

    vector<string> line; string data;
    fstream infile, tempFile;
    infile.open("clients.txt", ios::in);
    tempFile.open("temp.txt", ios::out);
    /*Get lines from clients.txt and write them in temp.txt, except current signed in client*/
    while(getline(infile, data, ' ')){
        if(data == client->get_cpf()){
            getline(infile, data); //If current signed in client, skip this line.
        }
        else{
            tempFile<<data+' ';
            getline(infile, data);
            tempFile<<data<<endl;
        }
    }
    infile.close();
    tempFile.close();
    remove("clients.txt");
    rename("temp.txt", "clients.txt");
    /*Write current client to file.txt*/
    Management::write_file("clients.txt", *client); 
}

vector<Client> Management::read_file(string file_name){
    fstream file;
    file.open(file_name, ios::in|ios::app);
    if(!file.is_open())
        throw e_file;
    Client temp; string name, cpf, password, email, phone, shop_history;
    vector<Client> list; vector<string> parsed_shop_history;

    while(getline(file, cpf, ' ')&&getline(file, name, ';')&&getline(file, password, ';')&&getline(file, email, ';')&&getline(file, phone, ';')&&getline(file, shop_history)){
        temp.set_cpf(cpf);
        temp.set_name(name);
        temp.set_password(password);
        temp.set_email(email);
        temp.set_phone_number(phone);
        parsed_shop_history = split(shop_history, '-');
        for(size_t i=1; i<=parsed_shop_history.size()/2; i++){
            temp.set_shop_history(parsed_shop_history[2*i-1], atoi(parsed_shop_history[2*i].c_str()));
        }
        list.push_back(temp);
        temp.clear_shop_history();
    }
    file.close();
    return list;
}

void Management::write_file(string file_name, Client client){
    fstream file;
    file.open(file_name, ios::app);
    if(!file.is_open())
        throw e_file;
    file<<client.get_cpf()<<' ';
    file<<client.get_name()<<';';
    file<<client.get_password()<<';';
    file<<client.get_email()<<';';
    file<<client.get_phone_number()<<';';
    file<<"SHOP_HISTORY";
    if(!client.get_shop_history().empty()){
        for(auto& key_value : client.get_shop_history()){
            file<<"-"<<key_value.first<<"-"<<key_value.second;
        }
    }
    file<<endl;
    file.close();
}
vector<Client> Management::get_client_list(){
    return client_list;
}
