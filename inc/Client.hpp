#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "BaseClass.hpp"
#include <string>
#include <vector>
using namespace std;

class Client: public BaseClass{
    private:
        string name;
        string cpf;
        string password;
        bool vip = false;
        vector<Client> clientList;

    public:
        Client();
        Client(string name, string cpf, string password, bool vip);
        
        string get_name();
        void set_name(string name);

        string get_password();
        void set_password(string password);

        string get_cpf();
        void set_cpf(string cpf);

        bool get_vipStatus();
        void set_vipStatus(bool vip);

        bool registerClient(string name,string cpf, string password);
        bool login(Client *client, string cpf, string password);
        bool verifyClient(string cpf);

        // Overload operator == 
        bool operator== (Client & obj);
        // Overload operator <<
        friend ostream & operator << (ostream &out, Client & obj);
        // Overload operator >>
        friend istream & operator >> (istream &in,  Client &obj);

        void abstract(){}
};

#endif