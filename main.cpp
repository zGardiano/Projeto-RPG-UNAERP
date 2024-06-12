#include <iostream>
#include "hash.h"

using namespace std;

int main(){
    int tam_vetor=5, max=11;
    Hash personagemhash(tam_vetor, max);
    int op;
    int id;
    string nome;
    int vida;
    int forca;
    int classe;
    bool busca;
    
    do{
        
        /*----------------------------------------------MENU PERSONAGENS-----------------------------------------------*/
        
        cout << "\n\n\n\n-------------------------------Menu de Personagem-------------------------------\n\n\n\n";
        cout << "Digite 1 para criar um personagem\n";
        cout << "Digite 2 para remover um personagem\n";
        cout << "Digite 3 para selecionar um personagem\n";
        cout << "Digite 4 para ver os personagem\n";
        cin >>op;
        
        if(op == 1){
            do{
                cout << "\n\n\n\n-------------------------------Crie seu Personagem-------------------------------\n\n\n\n";
                cout << "Informe o número da classe do personagem: \n";
                cout << "1 - Guerreiro\n";
                cout << "2 - Arqueiro\n";
                cout << "3 - Assassino\n";
                cin >> classe;
                
                if(classe == 1){
                    vida = 50;
                    forca = 20;
                    break;
                    
                }else if(classe == 2){
                    vida = 30;
                    forca = 50;
                    break;
                    
                }else if(classe == 3){
                    vida = 25;
                    forca = 55;
                    break;
                    
                }else{
                    cout << "Esta classe não existe!\n";
                    cout << "Informe a classe novamente!" << endl;
                }
                
            }while(classe > 0 && classe <4);
            
            cout << "Informe id do seu personagem, em números: \n";
            cin >> id;
            
            cout << "Iforme o nome do seu personagem: \n";
            cin >> nome;
            
            Personagem personagem(id, nome, vida, forca, classe);
            personagemhash.inserir(personagem);
            
        }else if (op == 2){
            cout << "Informe o id do personagema a ser removido:\n";
            cin >> id;
            
            Personagem personagem(id, " ", 0, 0, 0);
            personagemhash.remover(personagem);
            
        }else if (op == 3){
            cout << "Informe o id do persongem a ser selecionado:\n";
            cin >> id;
            Personagem personagem(id, " ", forca, vida, classe);
            personagemhash.buscar(personagem, busca);
            
            if(busca){
                cout << "Personagem selecionado:\n";
                cout << "Nome: " << personagem.getNome();
                cout << " ID: " << personagem.getId();
                cout << " Vida: " << personagem.getVida();
                cout << " Forca: " << personagem.getForca() << endl;
                op=0;
                
            }else{
                cout << "Personagem não encontrado\n";
            }
        }else if(op == 4){
            cout << "\n\n\n\n-------------------------------Personagens-------------------------------\n\n\n\n";
            personagemhash.imprimir();
            
    }while(op != 0);
    
    cout << "O jogo ja vai começar............" << endl;
    
    return 0;
}
