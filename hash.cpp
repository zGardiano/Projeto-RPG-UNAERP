#include <iostream>
#include "hash.h"

using namespace std;

    int Hash::FuncaoHash(Personagem personagem)
    {
        return (personagem.getId() % max_posicoes);
    }
    
    //construtora
    Hash::Hash(int tam_vetor, int max)
    {
        qtd_per = 0;
        max_per = max;
        max_posicoes = tam_vetor;
        estrutura = new Personagem[tam_vetor]; 
    }
    
    //destrutora
    Hash::~Hash()
    {
        //libera o espaço de memória do vetor estrutura
        delete [] estrutura;
    }
    
    //cheio
    bool Hash::cheia()
    {
        return (qtd_per == max_per);
    }
    
    //quantos personagens ja inseri
    int Hash::tamanho()
    {
        return (qtd_per);
    }
    
    //inserir dados
    void Hash::inserir(Personagem personagem)
    {
        int local = FuncaoHash(personagem);
        estrutura[local] = personagem;
        qtd_per ++;
    }
    
    //remover dados
    void Hash::remover(Personagem personagem)
    {
        int local = FuncaoHash(personagem);
        if (estrutura[local].getId() != -1){
            estrutura[local] = Personagem(-1, " ");
            qtd_per --;
        }
    }
    
    //busca dados
    void Hash::buscar(Personagem& personagem, bool& busca)
    {
        int local = FuncaoHash(personagem);
        Personagem aux = estrutura[local];
        if(personagem.getId() != aux.getId()){
            busca = false;
        } else{
            busca = true;
            personagem = aux;
        }
    }
    
    //imprime
    void Hash::imprimir()
    {
        cout << "Personagens:\n";
        for(int i=0; i < max_posicoes; i++){
            if(estrutura[i].getId() != -1){
                cout << i << ":" << estrutura[i].getId() << " ";
                cout << estrutura[i].getNome() << endl;
            }
        }
    }
