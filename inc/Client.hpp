#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <map>
#include <string>
#include <vector>
using namespace std;

class Client{
    private:
        string name, cpf, password, email, phone_number;
        map<string, int> shop_history;

    public:
        Client();
        Client(string name, string cpf, string password, string email, string phone_number);
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
        void set_password(string password);
        const string get_password();
        void set_email(string email);
        const string get_email();
        void set_phone_number(string number);
        const string get_phone_number();


};

#endif