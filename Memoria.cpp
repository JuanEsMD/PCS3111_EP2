#include "Memoria.h"
#include <iostream>
using namespace std;

Memoria::Memoria(){
}

Memoria::~Memoria(){
}

int Memoria::getTamanho(){
	return this->tamanho;
}

Dado* Memoria::ler(int posicao){
	if(posicao < 0 || posicao > this->tamanho)
		throw new logic_error("Posicao Invalida");
	else
		return this->array[posicao];
}

void Memoria::escrever(int posicao, Dado* d){
	if(posicao < 0 || posicao > this->tamanho)
		throw new logic_error("Posicao Invalida");
	else
		this->array[posicao] = d;
	
}

void Memoria::imprimir(){
	int i = 0;
	while (i < tamanho){
		Dado* a = this->array[i];
		if(a == NULL)
			cout << i << ": -";
		else
			cout << i << ": " << a->getValor();
		i++;
	}
}

