/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: Monitor.cpp                                    **/
/**                                                           **/
/***************************************************************/


#include "Monitor.h"

Monitor::Monitor(){}

Monitor::~Monitor(){}

Dado*  Monitor::ler(){
    throw new invalid_argument("Monitor nao eh dispositivo de entrada");
}

void Monitor::escrever(Dado *d){
    d->imprimir();
}