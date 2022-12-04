/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: MemoriaRAM.h                                   **/
/**                                                           **/
/***************************************************************/


#ifndef MEMORIARAM_H
#define MEMORIARAM_H

#include "Memoria.h"
#include <list>
using namespace std;

class MemoriaRAM : public Memoria{

public:
	MemoriaRAM(int tamanho);
	virtual ~MemoriaRAM();
	virtual int getTamanho();
	virtual void escrever(list<Dado*>* dados);
	virtual void escrever(int posicao, Dado* d);
	virtual Dado* ler(int posicao);
	virtual void imprimir();
private:
	int quantidade;

};

#endif // MEMORIARAM_H
