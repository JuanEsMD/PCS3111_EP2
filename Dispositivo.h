/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: Dispositvo.h                                   **/
/**                                                           **/
/***************************************************************/


#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include "Dado.h"

class Dispositivo{
    public:
    Dispositivo();
    virtual ~Dispositivo();
    virtual Dado* ler() = 0;
    virtual void escrever(Dado* d) = 0; 
};

#endif // DISPOSITIVO_H