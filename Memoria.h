/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: Memoria.h                                      **/
/**                                                           **/
/***************************************************************/


#ifndef MEMORIA_H
#define MEMORIA_H

#include "Dado.h"
#include "Instrucao.h"
#include <iostream>
using namespace std;

class Memoria{
public:
	Memoria();
	virtual ~Memoria();
	virtual int getTamanho() = 0;
	virtual Dado* ler(int posicao) = 0;
	virtual void escrever(int posicao, Dado* d) = 0;
	virtual void imprimir() = 0;

protected:
	Dado** array;
	long tamanho;

};

#endif // MEMORIA_H
