//#include "Dado.h"
#include "Instrucao.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int Instrucao::getOpcode(){
	return this->opcode;
}


//int Instrucao::getValor(){return this->valor;}

int Instrucao::getOrigem1(){
	return this->origem1;
}

int Instrucao::getOrigem2(){
	return this->origem2;
}

int Instrucao::getDestino(){
	return this->destino;
}

int Instrucao::getImediato(){
	return this->imediato;
}

int Instrucao::getFuncao(){
	return this->funcao;
}

Instrucao::Instrucao(int opcode, int ori1, int ori2, int dest, int imed, int funct) : Dado(opcode){
	this-> opcode = opcode;
	this-> origem1 = ori1;
	this-> origem2 = ori2;
	this-> destino = dest;
	this-> imediato = imed;
	this-> funcao = funct;
}

Instrucao::~Instrucao(){
}

//void Instrucao::imprimir(){cout << this->opcode;}

Instrucao* Instrucao::criarLW(int destino, int imediato){
		return new Instrucao(LW, 0, 0, destino, imediato, 0);
}
Instrucao* Instrucao::criarSW(int destino, int imediato){
		return new Instrucao(SW, 0, 0, destino, imediato, 0);
}
Instrucao* Instrucao::criarJ(int imediato){
		return new Instrucao(J, 0, 0, 0, imediato, 0);
}

Instrucao* Instrucao::criarBNE(int origem1, int origem2, int imediato){
		return new Instrucao(BNE, origem1, origem2, 0, imediato, 0);
}

Instrucao* Instrucao::criarBEQ(int origem1, int origem2, int imediato){
		return new Instrucao(BEQ, origem1, origem2, 0, imediato, 0);
}

Instrucao* Instrucao::criarADD(int destino, int origem1, int origem2){
		return new Instrucao(TIPO_R, origem1, origem2, destino, 0, ADD);
}

Instrucao* Instrucao::criarSUB(int destino, int origem1, int origem2){
		return new Instrucao(TIPO_R, origem1, origem2, destino, 0, SUB);
}

Instrucao* Instrucao::criarMULT(int origem1, int origem2){
		return new Instrucao(TIPO_R, origem1, origem2, 0, 0, MULT);
}

Instrucao* Instrucao::criarDIV(int origem1, int origem2){
		return new Instrucao(TIPO_R, origem1, origem2, 0, 0, DIV);
}

