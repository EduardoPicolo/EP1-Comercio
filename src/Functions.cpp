#include "Functions.hpp"

Client* client = new Client();
int option = 0;

void fill_string_spaces(string & str){
    for(size_t i=0; i<str.length(); i++){
        if(str[i] == ' ')
            str[i] = '_';
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
    string word;

    while (getline (ss, word, delim)) {
        result.push_back (word);
    }
    return result;
}

vector<pair<string, int>> order (map<string, int> records){
    vector<pair<string, int>> sorted_vector;
    copy(records.begin(), records.end(), back_inserter<vector<pair<string, int>>>(sorted_vector));
    sort(sorted_vector.begin(), sorted_vector.end(),[](const pair<string, int>& l, const pair<string, int>& r) {
        if (l.second != r.second)
            return l.second > r.second;
        return l.first > r.first;
    });
    return sorted_vector;
}
