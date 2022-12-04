/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: TecladoDeChar.cpp                              **/
/**                                                           **/
/***************************************************************/

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