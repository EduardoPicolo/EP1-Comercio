#include <string>
using namespace std;

class Client {
    private:
        string name;
        bool vip = false;

    public:
        Client();
        string get_name();
        bool get_vipStatus();

        void set_name(string name);
        void set_vipStatus(bool vip);
        void registerClient(string name, bool vip);
};