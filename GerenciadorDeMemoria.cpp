
#include "MemoriaRAM.h"
#include "Instrucao.h"
#include "GerenciadorDeMemoria.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

GerenciadorDeMemoria::GerenciadorDeMemoria(){}

GerenciadorDeMemoria::~GerenciadorDeMemoria(){}

void GerenciadorDeMemoria::load(string arquivo, MemoriaRAM* m){
	ifstream input;
	int i = 0;
	input.open(arquivo);

	if(input.fail())
		throw new runtime_error("Arquivo nao encontrado");


	int tamanhoDaRandomAcessMemory;
	input >> tamanhoDaRandomAcessMemory;
	MemoriaRAM *randomAcessMemory = new MemoriaRAM(tamanhoDaRandomAcessMemory);
	while(input){
		if(i > m->getTamanho())
			throw new runtime_error("Arquivo nao cabe na memoria");

		string c;
		input >> c;
		if(c == "D") {
			int inteiro;
			input >> inteiro;
			Dado* odad = new Dado(inteiro);
		}
		else if(c == "LW"){
			int destino;
			int imediato;
			input >> destino;
			input >> imediato;

			Instrucao *nova_LW;
			nova_LW->criarLW(destino, imediato);
		}
		else if(c == "SW"){
			int destino;
			int imediato;
			input >> destino;
			input >> imediato;

			Instrucao *nova_SW;
			nova_SW->criarSW(destino, imediato);
		}

		else if(c == "J"){
			int imediato;
			input >> imediato;

			Instrucao *nova_J;
			nova_J->criarJ(imediato);
		}
	
		else if(c == "BNE"){
			int origem1;
			int origem2;
			int imediato;
			input >> origem1;
			input >> origem2;
			input >> imediato;

			Instrucao *nova_BNE;
			nova_BNE->criarBNE(origem1, origem2, imediato);
		}
				
		else if(c == "BEQ"){
			int origem1;
			int origem2;
			int imediato;
			input >> origem1;
			input >> origem2;
			input >> imediato;

			Instrucao *nova_BEQ;
			nova_BEQ->criarBEQ(origem1, origem2, imediato);
		}
				
		else if(c == "ADD"){		
			int destino;
			int origem1;
			int origem2;
			input >> destino;
			input >> origem1;
			input >> origem2;
	
			Instrucao *nova_ADD;
			nova_ADD->criarADD(destino, origem1, origem2);
		}
				
		else if(c == "SUB"){
			int destino;
			int origem1;
			int origem2;
			input >> destino;
			input >> origem1;
			input >> origem2;
	
			Instrucao *nova_SUB;
			nova_SUB->criarSUB(destino, origem1, origem2);
		}
				
		else if(c == "MULT"){
			int origem1;
			int origem2;

			input >> origem1;
			input >> origem2;
	
			Instrucao *nova_MULT;
			nova_MULT->criarMULT(origem1, origem2);
		}
				
		else if(c == "DIV"){
			int origem1;
			int origem2;

			input >> origem1;
			input >> origem2;
	
			Instrucao *nova_DIV;
			nova_DIV->criarDIV(origem1, origem2);
		}
		else
			throw new runtime_error("Intrucao nao reconhecida");
		i++;
	
	}
	if(!input.eof())
		throw new runtime_error("Erro de leitura");
	
	input.close();
}

void GerenciadorDeMemoria::dump(string arquivo, MemoriaRAM* m){
	ofstream output;
	output.open(arquivo);

	 if (!output)
	 	ofstream outfile (arquivo);

	if(output.fail())
		throw new runtime_error("Erro de Leitura");

	output << m->getTamanho() << "\n";
	for(int i = 0; i < m->getTamanho(); i++){
		if(dynamic_cast<Instrucao*>(m->ler(i)) == NULL)
			output << 'D' << m->ler(i)->getValor();
		else
			output << imprimirInstrucao(dynamic_cast<Instrucao*>(m->ler(i))) << "\n";
		if(output.fail())
			throw new runtime_error("Erro de Leitura");
	}
	output.close();
}

string GerenciadorDeMemoria::imprimirInstrucao(Instrucao* I){

	if(I->getOpcode() == I->TIPO_R){
		if(I->getFuncao() == I->ADD)
			return ( "ADD" + (I->getDestino()) + (I->getOrigem1()) + (I->getOrigem2()) );
		else if(I->getFuncao() == I->SUB)
			return ( "SUB" + (I->getDestino()) + (I->getOrigem1()) + (I->getOrigem2()) );
	}

	if(I->getOpcode() == I->J)
		return ( "J" + (I->getImediato()) );
	
	if(I->getOpcode() == I->SW)
		return ( "SW" + (I->getDestino()) + (I->getImediato()) );
	
	if(I->getOpcode() == I->LW)
		return ( "LW" + (I->getDestino()) + (I->getImediato()) );

	if(I->getOpcode() == I->BNE)
			return ( "BNE" + (I->getOrigem1()) + (I->getOrigem2()) + (I->getImediato()) );

	if(I->getOpcode() == I->BEQ)
			return ( "BEQ" + (I->getOrigem1()) + (I->getOrigem2()) + (I->getImediato()) );


	if(I->getOpcode() == I->MULT)
		return ( "MULT" + (I->getOrigem1()) + (I->getOrigem2()) );

	if(I->getOpcode() == I->DIV)
		return ( "DIV" + (I->getOrigem1()) + (I->getOrigem2()) );

	throw new runtime_error("Instrucao nao reconhecida");
}

