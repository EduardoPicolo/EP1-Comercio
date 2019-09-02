#include "Functions.hpp"

// void add_product();
// void restock();
// void register_client();
// void login();
// void fill_string_spaces(string & str);

int start(void){
    int option = 0;
    cout<< "1:Shop"<<"\t"<< "2:Stock"<<endl;cout<< ">> ";
    cin>>  option;
    while(option!=1&&option!=2){
        if (cin.fail()){
            // get rid of failure state
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cout << "Invalid. Enter 1 for shop or 2 for stock: ";
        cin>>  option;
    }

    switch(option){
        case 1:
            shop();
        break;

        case 2:
            stock();
        break;

        default:
        break;
    }

    return 0;
}

// int shop(void){
//     Cart cart;
//     int product, amount, option = 0;
//     vector<Product> productList = Stock::get_productList();
    
//     cout<< "1:Login"<<"\t"<< "2:Register client"<<"\t"<< "3:Cancel"<<endl;cout<< ">> ";
//     cin>> option;
//     while(option!=1&&option!=2&&option!=3){
//         if (cin.fail()){
//             // get rid of failure state
//             cin.clear();
//             cin.ignore(1000, '\n');
//         }
//         cout << "Invalid. Enter 1 to login, 2 to register client or 3 to cancel: ";
//         cin>> option;
//     }
//     switch(option){
//         case 1:
//             option = 0;
//             login();
//         break;

//         case 2:
//             option = 0;
//             register_client();
//         break;

//         case 3:
//             option = 0;
//             start();
//         break;

//         default:
//         break;
//     }

//     do{
//         cout<<"CATALOGUE"<<endl;
//         cout<<"Index"<<"\t"<<"Product"<<"\t"<<"     Category"<<"\t"<<"Price"<<"\t"<<"Amount"<<endl;
//         for(size_t i=0; i<productList.size(); i++){
//             cout<<i<<"\t";productList[i].displayProduct();
//         }
//         cout<< "Product: ";
//         cin>> product;
//         cout<< "Amount: ";
//         cin>> amount;
//         cart.add_product(productList[product], amount);
//         cout<< "1:Continue shoppping"<<"\t"<<"2:Confirm purchase"<<"\t"<<"3:Cancel"<<endl;cout<<">> ";
//         cin>> option;
//         while(option!=1&&option!=2&&option!=3){
//             if (cin.fail()){
//                 // get rid of failure state
//                 cin.clear();
//                 cin.ignore(1000, '\n');
//             }
//             cout << "Invalid. Enter 1 to continue shopping, 2 to confirm purchase or 3 to cancel: ";
//             cin>>  option;
//         }
//         if(option==3){
//             cart.cancel_purchase();
//             start();
//         }
//         if(Stock:: verify_amount(productList[product], amount)){
//             productList[product].set_amount(productList[product].get_amount()-amount);
//         }
//     } while(option==1);

//     cout<<"Total: "<<cart.get_total()<<endl;
//     cart.confirm_purchase();
//     start();

//     return 0;
// }

// int stock(void){
//     int option;
//     cout<< "STOCK"<< endl;
//     cout<< "1:Add product"<< "\t"<< "2:Replenish stock"<< endl;cout<< ">> ";
//     cin >> option;
//     switch (option){
//         case 1: // Add product
//             add_product();
//         break;

//         case 2: //Increase product amount       
//             restock();    
//         break;

//         default:
//             start();
//         break;
//     }
//     return 0;
// }

// void add_product(){
//     int option = 0;
//     string product_name, category;
//     double price; int amount;

//     cout<< "Product name: ";
//     getline(cin>>ws, product_name);
//     fill_string_spaces(product_name);
//     while(Stock::verify_product(product_name)){
//         cout<< "Product already registered"<<endl;
//         cout<< "1:Add new product"<<"\t"<<"2:Cancel"<<endl;cout<< ">> ";
//         cin>> option;
//         while(option!=1&&option!=2){
//             if (cin.fail()){
//                 // get rid of failure state
//                 cin.clear();
//                 cin.ignore(1000, '\n');
//         }
//             cout<< "Invalid. Enter 1 to add a new product or 2 to cancel: ";
//             cin>>  option;
//         }
//         if(option==1){
//             add_product();
//         }
//         else if(option==2) {
//             start();
//         }
//     }
//     cout<< "Product category: ";
//     getline(cin>>ws, category);
//         fill_string_spaces(category);
//     cout<< "Price: ";
//     cin>> price;
//     price = price*100;
//     cout<< "Quantity: ";
//     cin>> amount;
//     Stock::register_product(product_name, category, price, amount);
//     start();
// }

// void restock(){
//     string product_name, category;
//     int amount;

//     cout<<"Product: ";
//     getline(cin>>ws, product_name);
//         fill_string_spaces(product_name);

//     while(!(Stock::verify_product(product_name))){
//         cout<< "Product not found"<<endl;
//         cout<< "Product: ";
//         getline(cin>>ws, product_name);
//             fill_string_spaces(product_name);
//     }

//     cout<< "Quantity increase "<<"⇪ ";
//     cin>> amount;
//     Stock::restock(product_name, amount);
//     start();
// }

// void login(){
//     int option = 0;
//     string cpf;

//     cout<<"Client CPF: ";
//     getline(cin>>ws, cpf);
//     if(Client:: verifyClient(cpf)){
//         cout<< "OKOKOKOKOKOKOKOK!"<<endl;
//     }
//     else{
//         cout<< "Client not found"<<endl;
//         cout<< "1:Enter new CPF"<<"\t"<< "2:Register client"<<"\t"<< "3:Cancel"<<endl;cout<<">> ";
//         cin>> option;
//         while(option!=1 && option!=2 && option!=3){
//             if (cin.fail()){
//                 // get rid of failure state
//                 cin.clear();
//                 cin.ignore(1000, '\n');
//             }
//             cout<< "Invalid. Enter 1 to try again, 2 to register client or 3 to cancel: ";
//             cin>>  option;
//         }
//         switch(option){
//             case 1:
//                 login();
//             break;

//             case 2:
//                 register_client();
//             break;

//             case 3:
//                 start();
//             break;

//             default:
//             break;
//         }
//     }
// }

// void register_client(){
//     int option = 0;
//     string name, cpf;

//     cout<< "Name: ";
//     getline(cin>>ws, name);
//     fill_string_spaces(name);
//     cout<< "CPF: ";
//     getline(cin>>ws, cpf);
//     switch(Client::verifyClient(cpf)){
//         case true:
//             cout<< "Client already registered"<<endl;
//             cout<< "1:Try again"<<"\t"<< "2:Login"<<"\t"<< "3:Cancel";cout<< ">> ";
//             cin>> option;
//             while(option!=1 && option!=2 && option!=3){
//                 if (cin.fail()){
//                     // get rid of failure state
//                     cin.clear();
//                     cin.ignore(1000, '\n');
//                 }
//                 cout<< "Invalid. Enter 1 to try again, 2 to login or 3 to cancel: ";
//                 cin>>  option;
//             }
//             switch(option){
//                 case 1:
//                     register_client();
//                 break;

//                 case 2:
//                     login();
//                 break;

//                 case 3:
//                     start();
//                 break;
                
//                 default:
//                 break;
//             }
//         break;

//         case false:
//             Client::registerClient(name, cpf);
//         break;
//     }
// }


void fill_string_spaces(string & str){
    for(size_t i=0; i<str.length(); i++){
        if(str[i] == ' ')
            str[i] = '-';
    }
}