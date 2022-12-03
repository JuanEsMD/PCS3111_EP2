#include "Interface.h"
#include "BancoDeRegistradores.h"
#include "Dado.h"
#include "Dispositivo.h"
#include "ESMapeadaNaMemoria.h"
#include "Instrucao.h"
#include "Memoria.h"
#include "MemoriaRAM.h"
#include "MonitorDeChar.h"
#include "Monitor.h"
#include "TecladoDeChar.h"
#include "Teclado.h"
#include "UnidadeDeControle.h"
#include "GerenciadorDeMemoria.h"



#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

void TelaInicial::ler(UnidadeDeControle* UC, int& fim){

	int opcao = -1;
	string arquivo;

	fim = 0;

	cout << "Emulador de MIPS\n" <<
	"1) Memoria\n" <<
	"2) Registradores\n" <<
	"3) Executar proxima instrucao\n" <<
	"4) Executar ate PC = 0\n" <<
	"5) Load\n" <<
	"6) Dump\n" <<
	"0) Sair\n" <<
	"Escolha uma opcao: ";

	cin >> opcao;
	
	//Sair
	if(opcao == 0){
		fim = 1;
		return;
	}



	//Load
	if(opcao == 5){
		cout << "Arquivo de origem: ";
		cin >> arquivo;

		GerenciadorDeMemoria::load(arquivo, dynamic_cast<ESMapeadaNaMemoria*>(UC->getMemoria())->getMemoriaSubjacente());
	}



	//Dump
	if(opcao == 6){
		cout << "Arquivo de destino: ";
		cin >> arquivo;

		GerenciadorDeMemoria::dump(arquivo, dynamic_cast<ESMapeadaNaMemoria*>(UC->getMemoria())->getMemoriaSubjacente());
	}



	//Memoria
	if(opcao == 1){
		int segundaOpcao = -1;

		cout << "Memoria\n" <<
		"1) Alterar dado\n" <<
		"2) Imprimir\n" <<
		"0) Voltar\n" <<
		"Escolha uma opcao: ";
		cin >> segundaOpcao;

		if(segundaOpcao == 0)
			return;

		else if(segundaOpcao == 1){
			int posicao = -1;
			int valor = -1;
			cout << "Posicao a ser alterada: ";
			cin >> posicao;
			cout << "Novo valor: ";
			cin >> valor;
			UC->getMemoria()->escrever(posicao, new Dado(valor));
		}
		else if(segundaOpcao == 2){
//			dynamic_cast<ESMapeadaNaMemoria*>(UC->getMemoria())->imprimir();
			UC->getMemoria()->imprimir();
		}
	}




	//Registradores
	if(opcao == 2){

		int segundaOpcao = -1;
		
		cout << "Registradores\n" <<
		"1) Alterar valor\n" <<
		"2) Imprimir\n" <<
		"0) Voltar\n" <<
		"Escolha uma opcao: ";
		cin >> segundaOpcao;

		if(segundaOpcao == 0)
			return;

		if(segundaOpcao == 1){	
			int posicao = -1;
			int valor = -1;
			cout << "Posicao a ser alterada: ";
			cin >> posicao;
			cout << "Novo valor: ";
			cin >> valor;
			UC->getBancoDeRegistradores()->setValor(posicao, valor);
		}
		else if(segundaOpcao == 2)
			UC->getBancoDeRegistradores()->imprimir();
	}



	//Executar Instrucão
	if(opcao == 3){
		cout << "PC: " << UC->getPC() << "\n";
		UC->executarInstrucao();
		cout << "Instrucao executada\n";
		cout << "PC: " << UC->getPC() << "\n";
	}

	//Executar até PC = 0
	if(opcao == 4)

	
		do{
			try{

				UC->executarInstrucao();	

			} catch(logic_error *e){
				cout << e->what();
				delete e;
			} catch(invalid_argument *e){
				cout << e->what();
				delete e;
			}
		}while(UC->getPC() != 0);
	
}
