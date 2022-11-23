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