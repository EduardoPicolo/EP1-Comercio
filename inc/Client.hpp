#include <string>
using namespace std;

class Client {
    private:
        string name;
        bool vip = false;

    public:
        Client();
        Client(string name, bool vip);
        
        string get_name();
        void set_name(string name);

        bool get_vipStatus();
        void set_vipStatus(bool vip);

        bool verifyClient(string name);
        Client registerClient(string name);
        Client login();

        // Overload operator == 
        bool operator== (Client & obj);
        // Overload operator <<
        friend std::ostream & operator << (std::ostream &out, Client & obj);
        // Overload operator >>
        friend std::istream & operator >> (std::istream &in,  Client &obj);
};