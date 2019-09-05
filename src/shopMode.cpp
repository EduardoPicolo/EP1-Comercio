#include "shopMode.hpp"

Client *client = new Client();

void shop(void){
    Cart cart;
    unsigned int product, amount, option = 0;
    vector<Product> productList = Stock::get_productList();
    
    cout<<"\t" "1:Login"<<"\t"<< "2:Register client"<<"\t"<< "3:Cancel"<<endl;cout<< ">> ";
    cin>> option;
    while(option!=1&&option!=2&&option!=3){
        clear_fail_state();
        cout << "Invalid. Enter 1 to login, 2 to register client or 3 to cancel: ";
        cin>> option;
    }
    switch(option){
        case 1:
            option = 0;
            login();
        break;

        case 2:
            option = 0;
            register_client();
        break;

        case 3:
            option = 0;
            start();
        break;

        default:
        break;
    }

    do{
        // cout<< "TESTE: "<< client->get_name()<<endl;
        cout<<"\t\t\t" "*CATALOGUE*"<<endl;
        cout<<"\t" "Index"<<"\t"<< "Product"<<"\t\t"<< "Price"<<"\t"<< "Amount"<<endl;
        for(size_t i=0; i<productList.size(); i++){
            cout<<"\t"<<i<<"\t";productList[i].displayProduct();
        }

        cout<< "Product Index: ";
        cin>> product;
        while(product>productList.size()){
            clear_fail_state();
            cout<<"\t" "Invalid product index"<<endl;
            cout<< "Product Index: ";
            cin>> product;
        }
        cout<< "Amount: ";
        cin>> amount;
            clear_fail_state();
        cart.add_product(productList[product], amount);
        cout<<"\t" "1:Continue shoppping"<<"\t"<< "2:Confirm purchase"<<"\t"<< "3:Cancel"<<endl;cout<< ">> ";
        cin>> option;
        while(option!=1&&option!=2&&option!=3){
            clear_fail_state();
            cout<< "Invalid. Enter 1 to continue shopping, 2 to confirm purchase or 3 to cancel: ";
            cin>>  option;
        }
        switch(option){
            case 1:
            break;
            case 2:
                cart.confirm_purchase();
                start();
            break;
            case 3:
                cart.cancel_purchase();
                start();
            break;

            default:
            break;
        }
        if(Stock:: verify_amount(productList[product], amount)){
            productList[product].set_amount(productList[product].get_amount()-amount);
        }
    } while(option==1);
}


void login(){
    int option = 0;
    string cpf;

    cout<<"Client CPF: ";
    getline(cin>>ws, cpf);
    if(Client::verifyClient(cpf)){
        *client = Client::login_client(cpf);
        cout<<"\t" "1:Confirm"<<"\t"<<"2:Enter new CPF"<<"\t"<<"3:Cancel"<<endl;cout<< ">> ";
        cin>> option;
        while(option!=1&&option!=2&&option!=3){
            clear_fail_state();
            cout<< "Invalid. Enter 1 to confirm, 2 to enter a new cpf or 3 to cancel: ";
            cin>>  option;
        }
        switch(option){
            case 1:
            break;
            case 2:
                login();
            break;
            case 3:
                start();
            break;
        }
    }
    else{
        cout<< "Client not found"<<endl;
        cout<<"\t" "1:Enter new CPF"<<"\t"<< "2:Register client"<<"\t"<< "3:Cancel"<<endl;cout<<">> ";
        cin>> option;
        while(option!=1 && option!=2 && option!=3){
            clear_fail_state();
            cout<< "Invalid. Enter 1 to try again, 2 to register client or 3 to cancel: ";
            cin>>  option;
        }
        switch(option){
            case 1:
                login();
            break;
            case 2:
                register_client();
            break;
            case 3:
                start();
            break;
            default:
            break;
        }
    }
}

void register_client(){
    int option = 0;
    string name, cpf;

    cout<< "Name: ";
    getline(cin>>ws, name);
        fill_string_spaces(name);
    cout<< "CPF: ";
        getline(cin>>ws, cpf);
        fill_string_spaces(cpf);
    switch(Client::verifyClient(cpf)){
        case true:
            cout<< "Client already registered"<<endl;
            cout<<"\t" "1:Try again"<<"\t"<< "2:Login"<<"\t"<< "3:Cancel"<<endl;cout<< ">> ";
            cin>> option;
            while(option!=1 && option!=2 && option!=3){
                clear_fail_state();
                cout<< "Invalid. Enter 1 to try again, 2 to login or 3 to cancel: ";
                cin>>  option;
            }
            switch(option){
                case 1:
                    register_client();
                break;
                case 2:
                    login();
                break;
                case 3:
                    start();
                break;
                default:
                break;
            }
        break;

        case false:
            Client::registerClient(name, cpf);
            *client = Client::login_client(cpf);
        break;
    }
}