#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Product.hpp"
#include <vector>
#include <map>
#include <string>
using namespace std;

class Client{
    private:
        string name, cpf, password, email, phone_number;
        map<string, float> shop_history;
        bool vip;

    public:
        Client();
        Client(string name, string cpf, string password, string email, string phone_number);
        ~Client();
        void display_client();
        void display_shop_history();
        void update_shop_history(float total, vector<Product> cart);
        map<string, float> get_shop_history() const;
        void set_shop_history(string category, float num);
        void clear_shop_history();
        void edit_data();

        void set_name(string name);
        string get_name() const;
        void set_cpf(string cpf);
        string get_cpf() const;
        void set_password(string password);
        string get_password() const;
        void set_email(string email);
        string get_email() const;
        void set_phone_number(string number);
        string get_phone_number() const;
        void set_vip(bool status);
        bool get_vip() const;

};

#endif