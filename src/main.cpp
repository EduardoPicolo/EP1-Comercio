#include "Functions.hpp"
#include "Store.hpp"

int main(void) {
    try{
         cout<<"\t+++++++++++++++++++++++++++++++++++++++++"<<endl;
             cout<<"\t+++++++++++ Mercado da Victoria +++++++++"<<endl;
                 cout<<"\t+++++++++++++++++++++++++++++++++++++++++\n"<<endl;
                     cout<<"\t=========== (1) Modo Venda =============="<<endl;
                         cout<<"\t======== (2) Modo Recomendacao =========="<<endl;
                             cout<<"\t=========== (3) Modo estoque ============"<<endl;
                                 cout<<"\t=== (4) Consultar Historico de vendas ==="<<endl;
                                     cout<<"\t======== (5) Registrar Cliente =========="<<endl;
                                         cout<<"\t=============== (6) Sair ================"<<endl;
                                             cout<<"\nDigite a sua opcao: ";
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
