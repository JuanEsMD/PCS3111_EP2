/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: Teclado.h                                      **/
/**                                                           **/
/***************************************************************/

#ifndef TECLADO_H
#define TECLADO_H

#include <iostream>
#include "Dispositivo.h"

using namespace std;

class Teclado : public Dispositivo{
public:
    Teclado();
    virtual ~Teclado(); 
    virtual Dado* ler();
    virtual void escrever(Dado* d); 

};

#endif