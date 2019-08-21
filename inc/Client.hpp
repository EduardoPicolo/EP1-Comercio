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
        bool get_vipStatus();

        void set_name(string name);
        void set_vipStatus(bool vip);
};