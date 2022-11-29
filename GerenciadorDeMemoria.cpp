
#include "MemoriaRAM.h"
#include "Instrucao.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;



GerenciadorDeMemoria::GerenciadorDeMemoria(){}

virtual GerenciadorDeMemoria::~GerenciadorDeMemoria(){}

virtual void GerenciadorDeMemoria::load(string arquivo, MemoriaRAM* m){
	
}

virtual void GerenciadorDeMemoria::dump(string arquivo, MemoriaRAM* m){
	ofstream output;
	int i = 0;
	output.open(arquivo);
	output << m->tamanho << \n;
	while(i < m->tamanho){
		if(dynamic_cast<Instrucao*>(m->array[i]) == NULL)
			output << 'D' << m->array[i]->valor;
		else
			output << imprimirInstrucao(dynamic_cast<Instrucao*>(m->array[i])) << \n;
		i++;
	}
		
}








string GerenciadorDeMemoria::imprimirInstrucao(Instrucao* I){

	if(I->getOpcode() == I->R){
		if(I->getFuncao() == I->ADD)
			return ( "ADD" + ((string) I->getDestino()) + ((string) I->getOrigem1()) + ((string) I->getOrigem2()) );
		else if(I->getFuncao() == I->SUB)
			return ( "SUB" + ((string) I->getDestino()) + ((string) I->getOrigem1()) + ((string) I->getOrigem2()) );
	}

	

	if(I->getOpcode() == I->J)
		return ( "J" + ((string) I->getImediato()) );
	


	if(I->getOpcode() == I->SW)
		return ( "SW" + ((string) I->getDestino()) + ((string) I->getImediato()) );
	
	if(I->getOpcode() == I->LW)
		return ( "LW" + ((string) I->getDestino()) + ((string) I->getImediato()) );
}



	if(I->getOpcode() == I-> I->BNE)
			return ( "BNE" + ((string) I->getOrigem1()) + ((string) I->getOrigem2()) + ((string)I->getImediato()) );

	if(I->getOpcode() == I-> I->BNQ)
			return ( "BNQ" + ((string) I->getOrigem1()) + ((string) I->getOrigem2()) + ((string)I->getImediato()) );

	


	if(I->getOpcode() == I-> I->MULT)
		return ( "MULT" + ((string) I->getOrigem1()) + ((string) I->getOrigem2()) );

	if(I->getOpcode() == I-> I->DIV)
		return ( "DIV" + ((string) I->getOrigem1()) + ((string) I->getOrigem2()) );
}
