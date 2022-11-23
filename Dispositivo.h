#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include "Dado.h"

class Dispositivo{
    public:
    Dispositivo();
    virtual ~Dispositivo();
    virtual Dado* ler();
    virtual void escrever(Dado* d); 
};

#endif // DISPOSITIVO_H