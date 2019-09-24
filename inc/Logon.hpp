#ifndef Logon_HPP
#define Logon_HPP

#include "Functions.hpp"

class Logon {
    virtual void abstract() = 0;
    private:
        static vector<Client> client_list;

    public:
        static void sign_in();
        static void sign_up();
        static bool verify_client(string cpf);
        static bool validate_cpf(const string& cpf);
        static vector<Client> get_client_list();
        
        static vector<Client> read_file(string file_name);
        static void write_file(string file_name, Client client);
        static void overWrite_file(string file_name, vector<Client> list);
};

#endif