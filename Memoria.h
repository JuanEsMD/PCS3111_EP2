#ifndef MEMORIA_H
#define MEMORIA_H

#include "Dado.h"
#include <iostream>
using namespace std;

class Memoria{
public:
	Memoria();
	virtual ~Memoria();
	virtual int getTamanho();
	virtual Dado* ler(int posicao);
	virtual void escrever(int posicao, Dado* d);
	virtual void imprimir();

protected:
	Dado** array;
	long tamanho;

};

#endif // MEMORIA_H
