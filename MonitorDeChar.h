/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: MonitorDeChar.h                                **/
/**                                                           **/
/***************************************************************/


#ifndef MONITORDECHAR_H
#define MONITORDECHAR_H

#include "Monitor.h"

class MonitorDeChar : public Monitor{
public:
    MonitorDeChar();
    virtual ~MonitorDeChar(); 

    virtual void escrever(Dado* d); 
};

#endif