#include "Classes.h"

class Hash{
    private:
    //função hash que receberá um obj personagem da classe Personagem
    int FuncaoHash(Personagem personagem);
    int max_per; //máximo de personagens da tabela hash
    int max_posicoes; //máximo de posicoes da table hash
    int qtd_per; //quantos personagens ja inseri
    Personagem* estrutura; // vetor para guardar hash
    
    public:
    //construtora
    Hash(int tam_vetor, int max);
    //destrutora
    ~Hash();
    //cheio
    bool cheia();
    //quantos personagens ja inseri
    int tamanho();
    //inserir dados
    void inserir(Personagem personagem);
    //remover dados
    void remover(Personagem personagem);
    //busca dados
    void buscar(Personagem& personagem, bool& busca);
    void imprimir();
};
