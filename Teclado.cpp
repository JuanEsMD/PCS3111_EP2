/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: Teclado.cpp                                    **/
/**                                                           **/
/***************************************************************/


#include "Teclado.h"

Teclado::Teclado(){}

Teclado::~Teclado(){}

void Teclado::escrever(Dado *d){
    throw new logic_error("Teclado nao eh dispositivo de saida");
}

Dado* Teclado::ler(){
    int entrada;

    cout << "Digite um numero: ";
    cin >> entrada;

    Dado* LeituraTeclado = new Dado(entrada);

    return LeituraTeclado;
}