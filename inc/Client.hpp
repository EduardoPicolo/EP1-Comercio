#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "BaseClass.hpp"
#include <string>
#include <vector>
using namespace std;

class Client{
    private:
        string name;
        string cpf;
        bool vip = false;
        static vector<Client> clientList;

    public:
        Client();
        Client(string name, string cpf, bool vip);

        static bool registerClient(string name, string cpf);
        static bool verifyClient(string cpf);
        static vector<Client> read_file(string file_name);
        static void write_file(string file_name, Client newClient);
        static void overwrite_file(string file_name, vector<Client> list);
        
        string get_name();
        void set_name(string name);

        string get_password();
        void set_password(string password);

        string get_cpf();
        void set_cpf(string cpf);

        bool get_vipStatus();
        void set_vipStatus(bool vip);

        static vector<Client> get_clientList();
};

#endif