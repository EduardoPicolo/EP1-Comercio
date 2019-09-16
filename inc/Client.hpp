#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <map>
#include <string>
#include <vector>
using namespace std;

class Client{
    private:
        string name, cpf;
        map<string, int> shop_history;

    public:
        Client();
        Client(string name, string cpf);
        ~Client();
        void display_client();
        void display_shop_history();
        const map<string, int> get_shop_history();
        void set_shop_history(string category, int num);
        void clear_shop_history();
        void set_name(string name);
        const string get_name();
        void set_cpf(string cpf);
        const string get_cpf();
};

#endif