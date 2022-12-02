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