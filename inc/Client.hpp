#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <map>
#include <string>
#include <vector>
using namespace std;

class Client{
    private:
        string name, cpf, email;
        bool vip = false;

        map<string, int> shop_record;

        static vector<Client> clientList;

    public:
        Client();
        Client(string name, string cpf, bool vip);

        static bool registerClient(string name, string cpf);
        static bool verifyClient(string cpf);
        static Client login_client(string cpf);
        void recover_shop_record();
        void update_shop_record();
        void display_shop_record();

        string get_name();
        void set_name(string name);

        string get_password();
        void set_password(string password);

        string get_cpf();
        void set_cpf(string cpf);

        bool get_vipStatus();
        void set_vipStatus(bool vip);

        static vector<Client> get_clientList();


        bool operator == (Client & obj);
        // Overload operator <<
        friend ostream & operator << (ostream &out, const Client & obj);
        // Overload operator >>
        friend istream & operator >> (istream &in,  Client &obj);
};

#endif