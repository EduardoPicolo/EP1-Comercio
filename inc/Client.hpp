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

        static vector<Client> clientList;

    public:
        Client();
        Client(string name, string cpf);

        static bool registerClient(string name, string cpf);
        static bool verifyClient(string cpf);
        static Client login_client(string cpf);
        void recover_shop_history();
        void update_shop_history();
        void display_shop_history();

        string get_name();
        void set_name(string name);

        string get_password();
        void set_password(string password);

        string get_cpf();
        void set_cpf(string cpf);

        bool get_vipStatus();
        void set_vipStatus(bool vip);

        void display_client();

        map<string, int> get_shop_history();
        static vector<Client> get_clientList();

        static vector<Client> read_file(string file_name);
        static void write_file(string file_name, Client client);
};

#endif