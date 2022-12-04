#ifndef GERENCIADORDEMEMORIA_H
#define GERENCIADORDEMEMORIA_H

#include "MemoriaRAM.h"

class GerenciadorDeMemoria{
public:
	GerenciadorDeMemoria();
	virtual ~GerenciadorDeMemoria();
	virtual void load(string arquivo, MemoriaRAM* &m);
	virtual void dump(string arquivo, MemoriaRAM* m);
private:
	string imprimirInstrucao(Instrucao* I);

};

#endif //GERENCIADORDEMEMORIA_H
