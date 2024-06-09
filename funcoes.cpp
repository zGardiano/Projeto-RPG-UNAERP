#include <iostream>
#include "Classes.h"

using namespace std;

/*-----------------------------------------Personagens-----------------------------------------------*/

Personagem::Personagem()
{  
    id = -1;
    nome = " ";
}

Personagem::Personagem (int id, string nome)
{
    this->id = id;
    this->nome = nome;
}

int Personagem::getId()
{
    return id;
}

string Personagem::getNome()
{
    return nome;
}
