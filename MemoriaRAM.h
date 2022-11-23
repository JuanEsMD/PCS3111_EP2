#ifndef MEMORIARAM_H
#define MEMORIARAM_H

#include "Memoria.h"
#include <list>
using namespace std;

class MemoriaRAM : public Memoria{

public:
	MemoriaRAM(int tamanho);
	virtual ~MemoriaRAM();
	virtual void escrever(list<Dado*>* dados);

private:
	int quantidade;

};

#endif // MEMORIARAM_H
