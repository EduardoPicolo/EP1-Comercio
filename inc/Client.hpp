#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "BaseClass.hpp"
#include <string>
#include <vector>
using namespace std;

class Client: public BaseClass{
    private:
        string name;
        string password;
        bool vip = false;
        vector<Client> clientList;

    public:
        Client();
        Client(string name,string password, bool vip);
        
        string get_name();
        void set_name(string name);

        string get_password();
        void set_password(string password);

        bool get_vipStatus();
        void set_vipStatus(bool vip);

        bool verifyClient(string name);
        void registerClient(string name, string password);
        bool login(Client *client, string name, string password);

        // Overload operator == 
        bool operator== (Client & obj);
        // Overload operator <<
        friend std::ostream & operator << (std::ostream &out, Client & obj);
        // Overload operator >>
        friend std::istream & operator >> (std::istream &in,  Client &obj);

        void abstract(){}
};

#endif