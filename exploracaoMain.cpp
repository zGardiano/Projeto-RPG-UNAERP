#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Personagem {
private:
    int id;
    string nome;
    int vida;
    int forca;
    int classe;

public:
    Personagem() {
        id = -1;
        nome = " ";
        forca = 0;
        vida = 0;
        classe = 0;
    };
    Personagem(int id, string nome, int vida, int forca, int classe) {
        this->id = id;
        this->nome = nome;
        this->vida = vida;
        this->forca = forca;
        this->classe = classe;
    };

    int getId() {
        return id;
    };
    string getNome() {
        return nome;
    };
    int getVida() {
        return vida;
    };
    int getForca() {
        return forca;
    };
    int getClasse() {
        return classe;
    };

    void aumentarVida(int valor) {
        vida += valor; // Incrementa a vida existente
    }

    void aumentarForca(int valor) {
        forca += valor; // Incrementa a força existente
    }
};

class Hash {
private:
    int max_per; 
    int max_posicoes; 
    int qtd_per; 
    Personagem* estrutura;

public:
    Hash(int tam_vetor, int max) {
        qtd_per = 0;
        max_per = max;
        max_posicoes = tam_vetor;
        estrutura = new Personagem[tam_vetor];
    };

    ~Hash() {
        delete[] estrutura;
    };

    int FuncaoHash(Personagem personagem) {
        return (personagem.getId() % max_posicoes);
    };

    bool cheia() {
        return (qtd_per == max_per);
    };

    int tamanho() {
        return (qtd_per);
    };

    void inserir(Personagem personagem) {
        int local = FuncaoHash(personagem);
        estrutura[local] = personagem;
        qtd_per++;
    };

    void remover(Personagem personagem) {
        int local = FuncaoHash(personagem);
        if (estrutura[local].getId() != -1) {
            estrutura[local] = Personagem(-1, " ", 0, 0, 0);
            qtd_per--;
        }
    };

    void buscar(Personagem& personagem, bool& busca) {
        int local = FuncaoHash(personagem);
        Personagem aux = estrutura[local];
        if (personagem.getId() != aux.getId()) {
            busca = false;
        }
        else {
            busca = true;
            personagem = aux;
        }
    };

    void imprimir() {
        cout << "Personagens:\n";
        for (int i = 0; i < max_posicoes; i++) {
            if (estrutura[i].getId() != -1) {
                cout << i << ":";
                cout << "Nome: " << estrutura[i].getNome();
                cout << "|ID: " << estrutura[i].getId();
                cout << "|Vida: " << estrutura[i].getVida();
                cout << "|Forca: " << estrutura[i].getForca();

                if (estrutura[i].getClasse() == 1)
                    cout << "|Classe: Guerreiro\n\n";

                else if (estrutura[i].getClasse() == 2)
                    cout << "|Classe: Arqueiro\n\n";

                else if (estrutura[i].getClasse() == 3)
                    cout << "|Classe: Assassino\n\n";
            }
        }
    };
};

void exibirMenuPrincipal() {
    cout << "\n========================================" << endl;
    cout << "✵•.¸,✵°✵.｡.✰ ℂℝ𝕆ℕ𝕀ℂ𝔸𝕊 ✰.｡.✵°✵,¸. •✵´" << endl;
    cout << "✵•.¸,✵°✵.｡.✰   𝔻𝕆 ✰.｡.✵°✵,¸.•✵´" << endl;
    cout << "`•.¸,✵°✵.｡.✰ 𝕀ℕ𝔽𝕀ℕ𝕀𝕋𝕆  ✰.｡.✵°✵,¸.•✵\n" << endl;
    cout << "Escolha uma opção: " << endl;
    cout << "1. Jogar" << endl;
    cout << "2. Sobre" << endl;
    cout << "3. Sair" << endl;
    cout << "========================================" << endl;
}

void exibeDevs() {
    cout << "======================================== \n" << endl;
    cout << "𝕊𝕆𝔹ℝ𝔼 𝕆𝕊 𝔻𝔼𝕊𝔼ℕ𝕍𝕆𝕃𝕍𝔼𝔻𝕆ℝ𝔼𝕊\n\n";
    cout << "ℕ𝕆𝕄𝔼𝕊:\n\n";
    cout << "Felipe Arosti       | Cod. 839913 | Criador do Menu Inicial\n";
    cout << "Leone Carpine       | Cod. 840588 | Criador da Seleção de Personagens\n";
    cout << "João Vitor Gardiano | Cod. 839588 | Criador da Exploração\n";
    cout << "João Otávio Rufino  | Cod. 839753 | Criador do Comabate\n";
    cout << "Enzo Ricky Ferrari  | Cod. 839753 | Criador do Comabate\n";
}

void exibeMenuPer() {
    cout << "\n\n\n\n-------------------------------Menu de Personagem-------------------------------\n\n\n\n";
    cout << "Digite 1 para criar um personagem\n";
    cout << "Digite 2 para remover um personagem\n";
    cout << "Digite 3 para selecionar um personagem\n";
    cout << "Digite 4 para ver os personagem\n";
}

void criePer() {
    cout << "\n\n\n\n-------------------------------Crie seu Personagem-------------------------------\n\n\n\n";
    cout << "Informe o número da classe do personagem: \n";
    cout << "1 - Guerreiro\n";
    cout << "2 - Arqueiro\n";
    cout << "3 - Assassino\n";
}

char definirPorta() {
    int chance = rand() % 3;
    if (chance == 0) {
        return 'I'; // BAÚ
    } else {
        return 'B'; // INIMIGO
    }
}

void interagirComBau(Personagem& personagem) {
    int chance = rand() % 2;
    if (chance == 0) {
        cout << "Você encontrou um baú! Recebeu um amuleto de vida! +5 status de vida." << endl;
        personagem.aumentarVida(5); // Aumentando a vida em 5
        cout << "Vida: " << personagem.getVida() << endl;
    } else {
        cout << "Você encontrou um baú! Recebeu um amuleto de força! +5 status de força." << endl;
        personagem.aumentarForca(5); // Aumentando a força em 5
        cout << "Força: " << personagem.getForca() << endl;
    }
}

void combateInimigo() {
    cout << "Você encontrou um inimigo! Prepare-se para a batalha." << endl;
    // SEGUE PARA BATALHA
}

void explorarMasmorra(Personagem& personagem) {
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
            interagirComBau(personagem); // Passando o objeto Personagem como argumento
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

int main() {
    srand(time(NULL)); 
    int opcaoPrincipal;
    Personagem personagem;

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
    explorarMasmorra(personagem); // Aqui está o erro corrigido
    
    return 0;
}
