#include <iostream>
#include "hash.h"
#include "InicioJogo.h"

using namespace std;


// Função principal
int main() 
{   int opcaoPrincipal;

    // Loop principal
    do
    {
        exibirMenuPrincipal();
        cin >> opcaoPrincipal;

        switch (opcaoPrincipal) {
            case 1:
                cout << "Iniciando o jogo..." << endl;
                break;
            case 2:
                exibeDevs();
                break;
            case 3:
                cout << "Saindo do jogo..." << endl;
                return 0;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    }while(opcaoPrincipal == 2);
    

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
        
        exibeMenuPer();
        cin >>op;
        
        if(op == 1){
            do{
                criePer();
                cin >> classe;
                
                if(classe == 1){
                    vida = 180;
                    forca = 10;
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
        }    
    }while(op != 0);
    
    cout << "O jogo ja vai começar............" << endl;
    
    return 0;
}
