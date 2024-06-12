#include <iostream>
using namespace std;

class Personagem{
    private:
        int id;
        string nome;
        int vida;
        int forca;
        int classe;
    

    public:
        Personagem();
        Personagem(int id, string nome, int vida, int forca, int classe);
        
        int getId();
        string getNome();
        int getVida();
        int getForca();
        int getClasse();
};
