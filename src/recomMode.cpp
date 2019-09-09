#include "recomMode.hpp"
#include "Functions.hpp"

void recommendation(){
    int option = 0;
    cout<<"\t" "1:Login"<<"\t"<< "2:Cancel"<<endl;cout<< ">> ";
    cin>> option;
    while(option!=1&&option!=2){
        clear_fail_state();
        cout << "Invalid. Enter 1 to login, 2 to cancel: ";
        cin>> option;
    }
    switch(option){
        case 1:
            option = 0;
            login();
        break;

        case 2:
            start();
        break;

        default:
        break;
    }
    recommendation_list(*client);
    start();
}

void recommendation_list(Client& client){
    int cont = 1;
    vector<Product> productList = Stock::get_productList();
    map<string, int> shop_history = client.get_shop_history();
    vector<pair<string, int>> sorted_vector = order(shop_history);

    cout<<"\t" "*RECOMMENDED PRODUCTS*"<<endl;
    for (auto it = sorted_vector.crbegin(); it != sorted_vector.crend(); it++){
        for(size_t i=0; i<productList.size() ; i++){
            if(it->first == productList[i].get_category()){
                cout<<"\t"<<cont<<". ";productList[i].displayProduct();
                cont++;
                break;
            }
        }
        if(cont==10)
            break;
	}
    cout<<endl;
}