/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: TecladoDeChar.h                                **/
/**                                                           **/
/***************************************************************/

#ifndef TECLADODECHAR_H
#define TECLADODECHAR_H

#include "Teclado.h"

class TecladoDeChar : public Teclado{
public:
    TecladoDeChar();
    virtual ~TecladoDeChar();
    virtual Dado* ler(); 
};

#endif