#include <iostream>
#include "Classes.h"

using namespace std;

/*-----------------------------------------Personagens-----------------------------------------------*/

Personagem::Personagem()
{  
    id = -1;
    nome = " ";
    forca = 0;
    vida = 0;
    classe = 0;
}

Personagem::Personagem (int id, string nome, int vida, int forca, int classe)
{
    this->id = id;
    this->nome = nome;
    this->vida = vida;
    this->forca = forca;
    this->classe = classe;
}

int Personagem::getId()
{
    return id;
}
string Personagem::getNome()
{
    return nome;
}
int Personagem::getVida(){
    return vida;
}
int Personagem::getForca(){
    return forca;
}
int Personagem::getClasse(){
    return classe;
}
