#include <iostream>
#include <cstdlib> // INCLUIR ESSA BIBILIOTECA NO MAIN

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

void lutarComInimigo() {
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
            lutarComInimigo();
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

    cout << "Bem-vindo à exploração da masmorra!" << endl;
    explorarMasmorra();

    return 0;
}

