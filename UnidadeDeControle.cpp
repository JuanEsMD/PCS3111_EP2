#include "UnidadeDeControle.h"

//---------------- constructors e destructors -----------------

UnidadeDeControle::UnidadeDeControle(BancoDeRegistradores* registradores, Memoria* memoria):
    registradores(registradores), memoria(memoria){
    }   

UnidadeDeControle::~UnidadeDeControle(){
	delete this->registradores;
    delete this->memoria;
}

//-------------------- getters e setters --------------------

BancoDeRegistradores* UnidadeDeControle::getBancoDeRegistradores(){
	return this->registradores;
}

Memoria* UnidadeDeControle::getMemoria(){
	return this->memoria;
}

int UnidadeDeControle::getPC(){
	return this->PC;
}

void UnidadeDeControle::setPC(int PC){
	this->PC = PC;
}
//------------ Instruções -----------

//ADD: Soma o conteúdo do registrador de origem 1 com o conteúdo do registrador de origem 2, colocando o resultado no registrador de destino. 
void UnidadeDeControle::FUNCAO_ADD(int destino, int origem1, int origem2){
	this->registradores->setValor(destino, (this->registradores->getValor(origem1)) + (this->registradores->getValor(origem2)) );
	this->PC++;
}

//SUB:  É feito o conteúdo do registrador de origem 1 menos o conteúdo do registrador de origem 2, colocando o resultado no registrador de destino. 
void UnidadeDeControle::FUNCAO_SUB(int destino, int origem1, int origem2){
	this->registradores->setValor(destino, (this->registradores->getValor(origem1)) - (this->registradores->getValor(origem2)) );
	this->PC++;
}

//MULT: O conteúdo do registrador de origem 1 é multiplicado pelo conteúdo do registrador de origem 2. O resultado da multiplicação é 
//colocado noregistrador 24.
void UnidadeDeControle::FUNCAO_MULT(int origem1, int origem2){
	this->registradores->setValor(24, (this->registradores->getValor(origem1)) * (this->registradores->getValor(origem2)));
	this->PC++;
}

//DIV:O conteúdo do registrador de origem 1 é dividido pelo conteúdo do registrador de origem 2. O resultado da divisão é colocado
// no registrador 24 ,enquanto que o resto da divisão é colocado no registrador 25. 
void UnidadeDeControle::FUNCAO_DIV(int origem1, int origem2){
	this->registradores->setValor(24, (this->registradores->getValor(origem1)) / (this->registradores->getValor(origem2)));
	this->registradores->setValor(25, (this->registradores->getValor(origem1)) % (this->registradores->getValor(origem2)));
	this->PC++;
}

//J: O PC (program counter) é alterado para o valor do imediato. 
void UnidadeDeControle::FUNCAO_J(int imediato){
	this->PC = imediato;
}

//BNE: O conteúdo do registrador origem 1 é comparado com o conteúdo do registrador origem2. Caso o valor seja diferente (not equal), 
//o PC é alterado para o valor do imediato. 
void UnidadeDeControle::FUNCAO_BNE(int origem1, int origem2, int imediato){
	if(this->registradores->getValor(origem1) != this->registradores->getValor(origem2) )
		this->PC = imediato;
	else this->PC++;
}

//BEQ: O conteúdo do registrador origem 1 é comparado com o conteúdo do registrador origem2. Caso o valor seja igual,
//o PC é alterado para o valor do imediato. 
void UnidadeDeControle::FUNCAO_BEQ(int origem1, int origem2, int imediato){
	if(this->registradores->getValor(origem1) == this->registradores->getValor(origem2))
		this->PC = imediato;
	else this->PC++;
}

//Carrega no registrador destino o valor apontado pelo endereço da memória de dados em imediato. Se a memória tiver nulo,
// deve-se carregar o valor 0 no registrador. 
void UnidadeDeControle::FUNCAO_LW(int destino, int imediato){
	if(this->memoria->ler(imediato) == NULL)
		this->registradores->setValor(destino, 0);
		//this->registradores->getValor(destino) = 0;
	else
		this->registradores->setValor(destino, this->memoria->ler(imediato)->getValor());
	this->PC++;
}

//SW: Armazena no endereço da memória de dados em imediato o valor do registrador em destino. 
void UnidadeDeControle::FUNCAO_SW(int destino, int imediato){
	this->memoria->escrever(imediato, new Dado(this->registradores->getValor(destino)));
	this->PC++;
}

//---------- executarInstrucao() ------------

//Verifica qual instrução será executada
void UnidadeDeControle::executarInstrucao(){
	//this->memoria->imprimir();
	//Se a instrucao estiver vazia
    Instrucao *instrucoes = dynamic_cast<Instrucao*>(this->memoria->ler(PC));
	instrucoes->imprimir();
	if(instrucoes == NULL){
		this->PC++;
	}

	
	else if(instrucoes->getOpcode() == 0){
			switch(instrucoes->getFuncao()){
		//ADD
				case 32:
					FUNCAO_ADD(instrucoes->getDestino(), instrucoes->getOrigem1(), instrucoes->getOrigem2());
					break;
		//SUB
				case 34:
					FUNCAO_SUB(instrucoes->getDestino(), instrucoes->getOrigem1(), instrucoes->getOrigem2());
					break;
		//MULT
				case 24:
					FUNCAO_MULT(instrucoes->getOrigem1(), instrucoes->getOrigem2());
					break;
		//DIV
				case 26:
					FUNCAO_DIV(instrucoes->getOrigem1(), instrucoes->getOrigem2());
					break;
			}
		}

//Instruções não-tipo R:
	else{
		switch(instrucoes->getOpcode()){
	//J
			case 2:
				FUNCAO_J(instrucoes->getImediato());
				break;
	//BNE
			case 5:
				FUNCAO_BNE(instrucoes->getOrigem1(), instrucoes->getOrigem2(), instrucoes->getImediato());
				break;
	//BEQ
			case 4:
				FUNCAO_BEQ(instrucoes->getOrigem1(), instrucoes->getOrigem2(), instrucoes->getImediato());
				break;
	//LW
			case 35:
				FUNCAO_LW(instrucoes->getDestino(), instrucoes->getImediato());
				break;
	//SW
			case 43:
				FUNCAO_SW(instrucoes->getDestino(), instrucoes->getImediato());
				break;
		}
	}
}