#include "shopMode.hpp"

void shop(void){
    Cart cart;
    int product, amount, option = 0;
    vector<Product> productList = Stock::get_productList();
    
    cout<< "1:Login"<<"\t"<< "2:Register client"<<"\t"<< "3:Cancel"<<endl;cout<< ">> ";
    cin>> option;
    while(option!=1&&option!=2&&option!=3){
        if (cin.fail()){
            // get rid of failure state
            cin.clear();
            cin.ignore(1000, '\n');
        }
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
        cout<<"CATALOGUE"<<endl;
        cout<<"Index"<<"\t"<<"Product"<<"\t"<<"     Category"<<"\t"<<"Price"<<"\t"<<"Amount"<<endl;
        for(size_t i=0; i<productList.size(); i++){
            cout<<i<<"\t";productList[i].displayProduct();
        }
        cout<< "Product: ";
        cin>> product;
        cout<< "Amount: ";
        cin>> amount;
        cart.add_product(productList[product], amount);
        cout<< "1:Continue shoppping"<<"\t"<<"2:Confirm purchase"<<"\t"<<"3:Cancel"<<endl;cout<<">> ";
        cin>> option;
        while(option!=1&&option!=2&&option!=3){
            if (cin.fail()){
                // get rid of failure state
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cout << "Invalid. Enter 1 to continue shopping, 2 to confirm purchase or 3 to cancel: ";
            cin>>  option;
        }
        if(option==3){
            cart.cancel_purchase();
            start();
        }
        if(Stock:: verify_amount(productList[product], amount)){
            productList[product].set_amount(productList[product].get_amount()-amount);
        }
    } while(option==1);

    cout<<"Total: "<<cart.get_total()<<endl;
    cart.confirm_purchase();
    start();
}

void login(){
    int option = 0;
    string cpf;

    cout<<"Client CPF: ";
    getline(cin>>ws, cpf);
    if(Client:: verifyClient(cpf)){
        cout<< "OKOKOKOKOKOKOKOK!"<<endl;
    }
    else{
        cout<< "Client not found"<<endl;
        cout<< "1:Enter new CPF"<<"\t"<< "2:Register client"<<"\t"<< "3:Cancel"<<endl;cout<<">> ";
        cin>> option;
        while(option!=1 && option!=2 && option!=3){
            if (cin.fail()){
                // get rid of failure state
                cin.clear();
                cin.ignore(1000, '\n');
            }
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
    switch(Client::verifyClient(cpf)){
        case true:
            cout<< "Client already registered"<<endl;
            cout<< "1:Try again"<<"\t"<< "2:Login"<<"\t"<< "3:Cancel"<<endl;cout<< ">> ";
            cin>> option;
            while(option!=1 && option!=2 && option!=3){
                if (cin.fail()){
                    // get rid of failure state
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
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
        break;
    }
}