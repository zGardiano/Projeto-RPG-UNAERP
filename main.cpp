#include <iostream>
#include "hash.h"

using namespace std;

int main(){
    int tam_vetor=5, max=10;
    Hash personagemhash(tam_vetor, max);
    int op;
    int id;
    string nome;
    bool busca;
    
    do{
        cout << "Digite 1 para criar um personagem\n";
        cout << "Digite 2 para remover um personagem\n";
        cout << "Digite 3 para selecionar um personagem\n";
        cout << "Digite 4 para ver os personagem\n";
        cin >>op;
        
        if(op == 1){
            cout << "Informe id do seu personagem, em números: \n";
            cin >> id;
            cout << "Iforme o nome do seu personagem: \n";
            cin >> nome;
            
            Personagem personagem(id, nome);
            personagemhash.inserir(personagem);
            
        }else if (op == 2){
            cout << "Informe o id do personagema a ser removido:\n";
            cin >> id;
            Personagem personagem(id, " ");
            personagemhash.remover(personagem);
            
        }else if (op == 3){
            cout << "Inforem o id do persongem a ser selecionado:\n";
            cin >> id;
            Personagem personagem(id, " ");
            personagemhash.buscar(personagem, busca);
            
            if(busca){
                cout << "Personagem selecionado:\n";
                cout << "Nome: " << personagem.getNome();
                cout << "ID: " << personagem.getId();
                
            }else{
                cout << "Personagem não encontrado\n";
            }
        }else if(op == 4){
            personagemhash.imprimir();
        }
    }while(op != 0);
    
    return 0;
}
