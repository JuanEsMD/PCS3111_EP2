/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: MemoriaRAM.cpp                                 **/
/**                                                           **/
/***************************************************************/


#include "MemoriaRAM.h"
#include <list>
#include <stdexcept>
using namespace std;

MemoriaRAM::MemoriaRAM(int tamanho){
	int i = 0;
	this->array = new Dado*[tamanho];
	this->tamanho = tamanho;

	while (i < tamanho){
		this->array[i] = NULL;
		i++;
	}
}

MemoriaRAM::~MemoriaRAM(){
	for(int i = 0; i < this->getTamanho(); i++)
		delete array[i];
	delete array;
}

int MemoriaRAM::getTamanho(){
	return this->tamanho;
}

void MemoriaRAM::escrever(list<Dado*>* dados){
	int i = 0;
	bool b = false;
	while(i < this->tamanho){
		if(this->array[i] != NULL){
			b = true;
			break;
		} 
		i++;
	}
	i = 0;
	if(int(dados->size()) > this->tamanho)
		throw new logic_error("Tamanho incompativel");
	
	if(b){
		while(i < this->tamanho){
			this->array[i] = NULL;
			i++;
		}
	}
	i = 0;
	while (!dados->empty()){
		this->array[i] = dados->front();
		dados->pop_front();
		i++;
	}
}

void MemoriaRAM::escrever(int posicao, Dado* d){
	if(posicao < 0 || posicao > this->tamanho)
		throw new logic_error("Posicao Invalida");
	else
		this->array[posicao] = d;
	
}

Dado* MemoriaRAM::ler(int posicao){
	if(posicao < 0 || posicao > this->tamanho)
		throw new logic_error("Posicao Invalida");
	else
		return this->array[posicao];
}


void MemoriaRAM::imprimir(){
	int i = 0;
	while (i < this->tamanho){
		Dado* a = this->array[i];
		if(a == NULL)
			cout << i << ": -" << endl;
		else if (dynamic_cast<Instrucao*>(array[i]) == NULL)
			cout << i << ": " << a->getValor() << endl;
		else
			cout << i << ": Instrucao " << a->getValor() << endl;
		i++;
	}
}