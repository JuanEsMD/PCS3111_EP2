#include "BancoDeRegistradores.h"
#include <iostream>
using namespace std;

BancoDeRegistradores::BancoDeRegistradores(){
	int i = 0;
	while(i < 32){
		this->array[i] = 0;
		i++;
	}
}
BancoDeRegistradores::~BancoDeRegistradores(){
}
int BancoDeRegistradores::getValor(int registrador){
	return this->array[registrador];
}
void BancoDeRegistradores::setValor(int registrador, int valor){
	this->array[registrador] = valor;
}

void BancoDeRegistradores::imprimir(){
	int i = 0;
	while(i < 32){
		cout << array[i] << endl;
		i++;
	}
}
