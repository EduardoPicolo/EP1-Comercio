#include "Functions.hpp"
#include "Store.hpp"

int main(void) {
    try{
        Store::start_session();
    }catch(Exception& e){
        cerr<<'\t'<< e.what() <<endl;
        cout<<"Returning to start session..."<<endl;
        Store::start_session();
    }
    catch(...){
        cerr<< "An unknown error has ocurred, closing program..."<<endl;
        return EXIT_FAILURE;
    }
    return 0;
}