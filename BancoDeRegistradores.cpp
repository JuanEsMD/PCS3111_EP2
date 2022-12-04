/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: BancoDeRegistradores.cpp                       **/
/**                                                           **/
/***************************************************************/

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
	if(registrador < 0 || registrador > 31)
		throw new logic_error("Registrador invalido.");
	else{
		return this->array[registrador];
	}
}

void BancoDeRegistradores::setValor(int registrador, int valor){
	if(registrador < 0 || registrador > 31)
		throw new logic_error("Registrador invalido.");
	else if(registrador == 0)
			return;
	else
		this->array[registrador] = valor;
}

void BancoDeRegistradores::imprimir(){
	for(int i = 0; i < 32; i++)
		cout << i << ": " << array[i] << endl;

}
