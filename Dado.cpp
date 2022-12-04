/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                 13681248        **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: Dado.cpp                                       **/
/**                                                           **/
/***************************************************************/

#include "Dado.h"
#include <iostream>
using namespace std;


Dado::Dado(int valor){
	this->valor = valor;
}

Dado::~Dado(){
}

int Dado::getValor(){
	return this->valor;
}

void Dado::imprimir(){
	cout << this->valor << endl;
}
