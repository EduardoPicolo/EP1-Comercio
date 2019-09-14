#ifndef MANAGEMENT_HPP
#define MANAGEMENT_HPP

#include "Functions.hpp"

class Management {
    virtual void abstract() = 0;
    private:
        static vector<Client> client_list;

    public:
        static void register_client();
        static void login();
        static bool verify_client(string cpf);
        vector<Client> get_client_list();
        static void update_shop_history();
        static vector<Client> read_file(string file_name);
        static void write_file(string file_name, Client client);
};

#endif