#include <iostream>
using namespace std;

class Personagem{
    private:
    int id;
    string nome;

    public:
    Personagem();
    Personagem(int id, string nome);
    int getId();
    string getNome();
};
