/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: MonitorDeChar.cpp                              **/
/**                                                           **/
/***************************************************************/

#include "MonitorDeChar.h"

MonitorDeChar::MonitorDeChar(){}

MonitorDeChar::~MonitorDeChar(){}

void MonitorDeChar::escrever(Dado* d){
    char saida = static_cast<char>(d->getValor());
    cout << saida;
}