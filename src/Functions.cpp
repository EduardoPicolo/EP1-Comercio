#include "Functions.hpp"

Client* client = new Client();

void start(){
    int option = 0;
    cout<<"\t" "1:Shop"<<"\t"<< "2:Stock"<<"\t"<< "3:Recommendation"<<endl;cout<< ">> ";
    cin>>  option;
    while(option!=1&&option!=2&&option!=3){
        clear_fail_state();
        cout << "Invalid. Enter 1 for shop, 2 for stock or 3 for recommendation mode: ";
        cin>>  option;
    }

    switch(option){
        case 1:
            shop();
        break;

        case 2:
            stock();
        break;

        case 3:
            recommendation();
        break;

        default:
        break;
    }
}

void fill_string_spaces(string & str){
    for(size_t i=0; i<str.length(); i++){
        if(str[i] == ' ')
            str[i] = '-';
    }
}

void lowercase(string & str){
    str[0]=toupper(str[0]);
    for(size_t i=1; i<str.length(); i++){
        str[i]=tolower(str[i]);
    }
}

void clear_fail_state(){
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }
    return result;
}

vector<pair<string, int>> order (map<string, int> records){
    vector<pair<string, int>> sorted_vector;
    copy(records.begin(), records.end(), back_inserter<vector<pair<string, int>>>(sorted_vector));
    sort(sorted_vector.begin(), sorted_vector.end(),[](const pair<string, int>& l, const pair<string, int>& r) {
        if (l.second != r.second)
            return l.second < r.second;
        return l.first < r.first;
    });
    // for (auto it = v.crbegin(); it != v.crend(); it++)
	// {
	// 	cout<< it->first <<" "<< it->second <<endl;
	// }
    
    return sorted_vector;
}
