#include "Management.hpp"

vector<Client> Management::client_list;
int clientIndex;

vector<Client> Management::get_client_list(){
    return client_list;
}
void Management::register_client(){
    int option = 0;
    string name, cpf;

    cout<< "Name: ";
    getline(cin>>ws, name);
        lowercase(name);
    cout<< "CPF: ";
    getline(cin>>ws, cpf);
        fill_string_spaces(cpf);
    switch(verify_client(cpf)){
        case true:
            cout<< "Client already registered"<<endl;
            cout<<"\t" "1:Try again"<<"\t"<< "2:Login"<<"\t"<< "3:Cancel"<<endl;cout<< ">> ";
            cin>> option;
            validate_option(option, "Invalid. Enter 1 to try again, 2 to login or 3 to cancel.");
            switch(option){
                case 1:
                    Management::register_client();
                break;
                case 2:
                    Management::login();
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
            client = new Client(name, cpf); //Global variable 'client' = newly registered client
            client_list.push_back(*client);
            Management::write_file("clients.txt", *client);
        break;
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
void Management::login(){
    int option = 0;
    string cpf;

    cout<<"Client CPF: ";
    getline(cin>>ws, cpf);
    if(verify_client(cpf)){
        client_list[clientIndex].display_client();
        cout<<"\t" "1:Confirm"<<"\t"<<"2:Enter new CPF"<<"\t"<<"3:Cancel"<<endl;cout<< ">> ";
        cin>> option;
        validate_option(option, "Invalid. Enter 1 to confirm, 2 to enter a new cpf or 3 to cancel.");
        switch(option){
            case 1:
                *client = client_list[clientIndex];
            break;
            case 2:
                Management::login();
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
                Management::login();
            break;
            case 2:
                Management::register_client();
            break;
            case 3:
                Store::main_menu();
            break;
            default:
            break;
        }
    }
}
void Management::update_shop_history(){
    vector<string> line; string x;
    fstream infile, tempFile;
    infile.open("clients.txt", ios::in);
    tempFile.open("temp.txt", ios::out);
    /*Get lines from clients.txt and write them in temp.txt, except current signed in client*/
    while(getline(infile, x, ' ')){
        if(x == client->get_cpf()){
            getline(infile, x);
        }
        else{
            tempFile<<x+' ';
            getline(infile, x);
            tempFile<<x<<endl;
        }
    }
    infile.close();
    tempFile.close();
    remove("clients.txt");
    rename("temp.txt", "clients.txt");

    vector<Product> productList = Cart::get_cart();
    map<string, int> categoriesDict;

    /*Get each product category from products in cart and them adds to categoryDictionary*/
    for(size_t i=0; i<productList.size(); i++){
        categoriesDict[productList[i].get_category()] += (productList[i].get_amount());
    }
    /*Update signed in client shop_history category/number */
    for(auto mapIterator = begin(categoriesDict); mapIterator != end(categoriesDict); ++mapIterator){
        client->set_shop_history(mapIterator->first, mapIterator->second);
    }
    /*Write current client to file.txt*/
    Management::write_file("clients.txt", *client); 
}

vector<Client> Management::read_file(string file_name){
    fstream file;
    file.open(file_name, ios::in);
    vector<Client> list; vector<string> split_aux;
    Client temp;
    string name, cpf, aux;
    while(getline(file, cpf, ' ')&&getline(file, name, '#')&&getline(file, aux)){
        temp.set_cpf(cpf);
        temp.set_name(name);
        split_aux = split(aux, '-');
        for(size_t i=1; i<=split_aux.size()/2; i++){
            temp.set_shop_history(split_aux[2*i-1], atoi(split_aux[2*i].c_str()));
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
    file<<client.get_cpf()<<' ';
    file<<client.get_name()<<"#";
    file<<"SHOP_HISTORY";
    if(!client.get_shop_history().empty()){
        for(auto& key_value : client.get_shop_history()){
            file<<"-"<<key_value.first<<"-"<<key_value.second;
        }
    }
    file<<endl;
    file.close();
}