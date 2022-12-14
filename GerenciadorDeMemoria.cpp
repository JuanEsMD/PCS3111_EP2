/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: GerenciadorDeMemoria.cpp                       **/
/**                                                           **/
/***************************************************************/

#include "MemoriaRAM.h"
#include "Instrucao.h"
#include "GerenciadorDeMemoria.h"
#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std;

GerenciadorDeMemoria::GerenciadorDeMemoria(){}

GerenciadorDeMemoria::~GerenciadorDeMemoria(){}

void GerenciadorDeMemoria::load(string arquivo, MemoriaRAM* &m){
	ifstream input;
	input.open(arquivo);

	if(input.fail())
		throw new runtime_error("Arquivo nao encontrado");

	int tamanhoDaRandomAcessMemory;
	input >> tamanhoDaRandomAcessMemory;
	MemoriaRAM *randomAcessMemory = new MemoriaRAM(tamanhoDaRandomAcessMemory);
	for(int posicao = 0; input; posicao++){
		if(posicao > randomAcessMemory->getTamanho() + 1)
			throw new runtime_error("Arquivo nao cabe na memoria");
		string c;
		input >> c;
		//if(posicao != 0)
			//randomAcessMemory->imprimir();
		if(c == "D") {
			int inteiro;
			input >> inteiro;
			Dado* odad = new Dado(inteiro);
			randomAcessMemory->escrever(posicao, odad);
			continue;
		}
		else if(c == "LW"){
			int destino;
			int imediato;
			input >> destino;
			input >> imediato;

			Instrucao *nova_LW;
			randomAcessMemory->escrever(posicao, nova_LW->criarLW(destino, imediato));
			continue;
		}
		else if(c == "SW"){
			int destino;
			int imediato;
			input >> destino;
			input >> imediato;

			Instrucao *nova_SW;
			randomAcessMemory->escrever(posicao, nova_SW->criarSW(destino, imediato));
			continue;
		}

		else if(c == "J"){
			int imediato;
			input >> imediato;

			Instrucao *nova_J;
			randomAcessMemory->escrever(posicao, nova_J->criarJ(imediato));
			continue;
		}
	
		else if(c == "BNE"){
			int origem1;
			int origem2;
			int imediato;
			input >> origem1;
			input >> origem2;
			input >> imediato;

			Instrucao *nova_BNE;
			randomAcessMemory->escrever(posicao, nova_BNE->criarBNE(origem1, origem2, imediato));
			continue;
		}
				
		else if(c == "BEQ"){
			int origem1;
			int origem2;
			int imediato;
			input >> origem1;
			input >> origem2;
			input >> imediato;

			Instrucao *nova_BEQ;
			randomAcessMemory->escrever(posicao, nova_BEQ->criarBEQ(origem1, origem2, imediato));
			continue;
		}
				
		else if(c == "ADD"){		
			int destino;
			int origem1;
			int origem2;
			input >> destino;
			input >> origem1;
			input >> origem2;
	
			Instrucao *nova_ADD;
			randomAcessMemory->escrever(posicao, nova_ADD->criarADD(destino, origem1, origem2));
			continue;
		}
				
		else if(c == "SUB"){
			int destino;
			int origem1;
			int origem2;
			input >> destino;
			input >> origem1;
			input >> origem2;
	
			Instrucao *nova_SUB;
			randomAcessMemory->escrever(posicao, nova_SUB->criarSUB(destino, origem1, origem2));
			continue;
		}
				
		else if(c == "MULT"){
			int origem1;
			int origem2;

			input >> origem1;
			input >> origem2;
	
			Instrucao *nova_MULT;
			randomAcessMemory->escrever(posicao, nova_MULT->criarMULT(origem1, origem2));
			continue;
		}
				
		else if(c == "DIV"){
			int origem1;
			int origem2;

			input >> origem1;
			input >> origem2;
	
			Instrucao *nova_DIV;
			randomAcessMemory->escrever(posicao, nova_DIV->criarDIV(origem1, origem2));
			continue;
			
		}
		else if (c == "-"){
			randomAcessMemory->escrever(posicao, NULL);
			continue;
		}
		else if(c.empty())
			break;
		else{
			throw new runtime_error("Intrucao nao reconhecida");
		}
	}
	if(!input.eof()){
		throw new runtime_error("Erro de leitura");
	}
	m = randomAcessMemory;
	//m->imprimir();
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
		if(m->ler(i) == NULL)
			output << "-" << endl;
		else if(dynamic_cast<Instrucao*>(m->ler(i)) == NULL){
			output << "D " << m->ler(i)->getValor() << endl;
		}
		else{
			Instrucao* I = dynamic_cast<Instrucao*>(m->ler(i));
			if(I->getOpcode() == I->TIPO_R){
				if(I->getFuncao() == I->ADD)
					output << "ADD " << (I->getDestino()) << " "  << (I->getOrigem1())  << " " << (I->getOrigem2()) << endl;
				else if(I->getFuncao() == I->SUB)
					output << "SUB " << (I->getDestino())<< " "  <<  (I->getOrigem1()) << " "  << (I->getOrigem2()) << endl;
			}

			else if(I->getOpcode() == I->J)
				output << "J " <<  (I->getImediato()) << endl;
	
			else if(I->getOpcode() == I->SW)
				output <<  "SW "  <<  (I->getDestino()) << " " <<  (I->getImediato()) << endl;
	
			else if(I->getOpcode() == I->LW)
				output <<  "LW " << (I->getDestino()) << " " << (I->getImediato()) << endl;

			else if(I->getOpcode() == I->BNE)
				output <<  "BNE " << (I->getOrigem1()) << " " << (I->getOrigem2()) << " " <<  (I->getImediato()) << endl;

			else if(I->getOpcode() == I->BEQ)
				output << "BEQ " << (I->getOrigem1())  << " " << (I->getOrigem2())  << " " << (I->getImediato()) << endl;

			else if(I->getOpcode() == I->MULT)
				output << "MULT " << (I->getOrigem1())  << " " << (I->getOrigem2()) << endl;

			else if(I->getOpcode() == I->DIV)
				output << "DIV " << (I->getOrigem1())  << " " << (I->getOrigem2()) << endl;

			else throw new runtime_error("Instrucao nao reconhecida");
		}

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

