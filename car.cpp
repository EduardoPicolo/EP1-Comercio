#include "Carrinho.hpp"
#include "Estoque.hpp"
#include <vector>
#include <string>
#include <fstream>
#include "Loja.hpp"

using namespace std;
void Carrinho::adiciona_carrinho(string codigo,int quant,Cliente cliente){
        int posicao = Estoque::consulta_produto(codigo);
            fstream arquivo;
                string temp;
                    vector <string> vetor;
                        vector <string> carrinho;
                            vector <string> clientes;
                                arquivo.open("arq/Produtos.txt", ios::in);
                                while(getline(arquivo,temp)){
                                            vetor.push_back(temp);
                                                
                                }
                                    arquivo.close();
                                        arquivo.open("arq/Carrinho.txt", ios::in);
                                        while(getline(arquivo,temp)){
                                                        carrinho.push_back(temp);
                                                                
                                        }
                                            arquivo.close();
                                                carrinho.push_back(vetor[posicao]);
                                                    carrinho.push_back(vetor[posicao+1]);
                                                        carrinho.push_back(vetor[posicao+2]);
                                                            carrinho.push_back(to_string(quant));
                                                                carrinho.push_back(vetor[posicao+4]);
                                                                    cliente.set_historico(vetor[posicao+4]);
                                                                        int pos = Loja::consulta_cliente(cliente.get_cpf());
                                                                            arquivo.open("arq/Clientes.txt", ios::in);
                                                                            while(getline(arquivo,temp)){
                                                                                        clientes.push_back(temp);
                                                                                            
                                                                            }
                                                                                clientes[pos+4]+="/"+cliente.get_historico();
                                                                                    arquivo.close();

                                                                                        arquivo.open("arq/Clientes.txt", ios::out | ios::trunc);
                                                                                            for(auto cont=(clientes.begin());cont<(clientes.end());cont++)
                                                                                                        arquivo<<*cont<<endl;
                                                                                                arquivo.close();
                                                                                                    
                                                                                                    arquivo.open("arq/Carrinho.txt", ios::out | ios::trunc);
                                                                                                        for(auto cont=(carrinho.begin());cont<(carrinho.end());cont++)
                                                                                                                    arquivo<<*cont<<endl;
                                                                                                            arquivo.close();
                                                                                                            
}

void Carrinho::lista_carrinho(){
        fstream arquivo;
            string temp;
                vector <string> vetor;
                    vetor.clear();
                        arquivo.open("arq/Carrinho.txt", ios::in);
                        while(getline(arquivo,temp)){
                                    vetor.push_back(temp);
                                        
                        }
                            arquivo.close();
                                cout<<"\n\t@@@@@@@@@@@@@@ Carrinho @@@@@@@@@@@@@@"<<endl;
                                for(auto cont=(vetor.begin());cont<(vetor.end());cont+=5){
                                            cout<<"\nCodigo: "<<*cont<<endl;
                                                    cout<<"Nome: "<<*(cont+1)<<endl;
                                                            cout<<"Preco: "<<*(cont+2)<<endl;
                                                                    cout<<"Quantidade: "<<*(cont+3)<<endl;
                                                                            cout<<"Categoria(s): "<<*(cont+4)<<endl;
                                                                                
                                }
                                
}

float Carrinho::preco_carrinho(){
        float total=0;
            fstream arquivo;
                vector <string> vetor;
                    string temp;
                        arquivo.open("arq/Carrinho.txt", ios::in);
                        while(getline(arquivo,temp)){
                                    vetor.push_back(temp);
                                        
                        }
                            arquivo.close();
                            for(size_t cont=3;cont<(vetor.size());cont+=5){
                                        total+=(stof(vetor[cont])*stof(vetor[cont-1]));
                                            
                            }
                                //cout<<"o total eh: "<<total<<endl;
                                //    return total;
                                //    
}

void Carrinho::limpa_carrinho(){
        fstream arquivo;
            arquivo.open("arq/Carrinho.txt", ios::out | ios::trunc);
                arquivo.close();
                
}

int Carrinho::consulta_categorias(string txt){
        fstream arquivo;
            int cont=0;
                string temp;
                    vector <string> conteudo;
                        arquivo.open(txt,ios::in);
                            while(getline(arquivo,temp))
                                        conteudo.push_back(temp);
                                arquivo.close();

                                    for(;(size_t)cont<conteudo.size();cont+=5)
                                                cont++;
                                        
                                        return cont;
                                        
}
