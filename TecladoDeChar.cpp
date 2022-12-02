#include "TecladoDeChar.h"

TecladoDeChar::TecladoDeChar(){}

TecladoDeChar::~TecladoDeChar(){}

Dado* TecladoDeChar::ler(){
    char entrada;
    cout << "“Digite um caractere: ";
    cin >> entrada;

    Dado* LeituraTeclado = new Dado(static_cast<int>(entrada));
    return LeituraTeclado;
}