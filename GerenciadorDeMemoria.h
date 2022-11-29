
#include "MemoriaRAM.h"

class GerenciadorDeMemoria{

	GerenciadorDeMemoria();
	virtual ~GerenciadorDeMemoria();
	virtual void load(string arquivo, MemoriaRAM* m);
	virtual void dump(string arquivo, MemoriaRAM* m);

};
