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
	}
}


MemoriaRAM::~MemoriaRAM(){
	delete array;
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

