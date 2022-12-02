
#include "MemoriaRAM.h"

class GerenciadorDeMemoria{
public:
	GerenciadorDeMemoria();
	virtual ~GerenciadorDeMemoria();
	virtual void load(string arquivo, MemoriaRAM* m);
	virtual void dump(string arquivo, MemoriaRAM* m);
private:
	void load(string arquivo, MemoriaRAM* m);
	void dump(string arquivo, MemoriaRAM* m);
	string imprimirInstrucao(Instrucao* I);

};
