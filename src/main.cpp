#include "Functions.hpp"
#include "Store.hpp"

int main(void) {
    try{
    Store::main_menu();
    }catch(Exception& e){
        cerr<<'\t'<< e.what() <<endl;
        return EXIT_FAILURE;
    }
    return 0;
}