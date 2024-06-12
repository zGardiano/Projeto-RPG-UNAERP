#include <iostream>
#include <cstdlib> // INCLUIR ESSA BIBILIOTECA NO MAIN PARA UTILIZAR RAND() E SRAND()
#include "hash.h"
#include "InicioJogo.h"

using namespace std;

char definirPorta() {
    int chance = rand() % 3;
    if (chance == 0) {
        return 'B'; // BAÚ
    } else {
        return 'I'; // INIMIGO
    }
}

void interagirComBau() {
    int chance = rand() % 2;
    if (chance == 0) {
        cout << "Você encontrou um baú! Recebeu um amuleto de vida! +5 status de vida." << endl;
        // setforca = getforca + 5 
    } else {
        cout << "Você encontrou um baú! Recebeu um amuleto de força! +5 status de força." << endl;
        // setvida = getvida + 5 
    }
}

void combateInimigo() {
    cout << "Você encontrou um inimigo! Prepare-se para a batalha." << endl;
    // SEGUE PARA BATALHA
}

void explorarMasmorra() {
    int portasAbertas = 0;
    while (portasAbertas < 5) {
        cout << "\nVocê está em uma masmorra com 3 portas. Escolha uma porta [ 1 | 2 | 3]: ";
        int escolha;
        cin >> escolha;

        if (escolha < 1 || escolha > 3) {
            cout << "Escolha inválida. Por favor, escolha uma porta entre 1 e 3." << endl;
            continue;
        }

        char resultado = definirPorta();
        if (resultado == 'B') {
            interagirComBau();
        } else {
            combateInimigo();
        }

        portasAbertas++;
        cout << "Você abriu " << portasAbertas << " portas." << endl;
    }

    cout << "\nVocê chegou ao final da masmorra e encontrou o Boss!" << endl;
    cout << "Prepare-se para o combate final!" << endl;
    // SEGUE PARA BATALHA COM O BOSS
}

// Função principal
int main(){
    srand(time(NULL)); 
    int opcaoPrincipal;

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
    
    cout << "Boa sorte na exploração da masmorra!" << endl;
    explorarMasmorra();
    
    return 0;
}
