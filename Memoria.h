#include "Dado.h"

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
