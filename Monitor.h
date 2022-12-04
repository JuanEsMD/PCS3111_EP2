/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: Monitor.h                                      **/
/**                                                           **/
/***************************************************************/

#ifndef MONITOR_H
#define MONITOR_H

#include <iostream>
#include "Dispositivo.h"

using namespace std;

class Monitor : public Dispositivo{
public:
    Monitor();
    virtual ~Monitor();
    virtual Dado* ler();
    virtual void escrever(Dado* d); 

};

#endif