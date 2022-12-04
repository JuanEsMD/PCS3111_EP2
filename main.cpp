/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: main.cpp                                       **/
/**                                                           **/
/***************************************************************/

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;

#include "BancoDeRegistradores.h"
#include "Dado.h"
#include "Dispositivo.h"
#include "esmapeadaNaMemoria.h"
#include "Instrucao.h"
#include "Memoria.h"
#include "MemoriaRAM.h"
#include "MonitorDeChar.h"
#include "Monitor.h"
#include "TecladoDeChar.h"
#include "Teclado.h"
#include "UnidadeDeControle.h"
#include "GerenciadorDeMemoria.h"

int main(){
	BancoDeRegistradores* registradores = new BancoDeRegistradores();
	MemoriaRAM* MemRAM = new MemoriaRAM(64);
	ESMapeadaNaMemoria* esmap = new ESMapeadaNaMemoria(MemRAM);
	Teclado* tec = new Teclado();
	TecladoDeChar* tecChar = new TecladoDeChar();
	Monitor* mon = new Monitor();
	MonitorDeChar* monChar = new MonitorDeChar();


	esmap->adicionar(tec); //64
	esmap->adicionar(tecChar); //65
	esmap->adicionar(mon); //66
	esmap->adicionar(monChar); //67
//  uso de esmapeadaNaMemoria como Memoria: possivel fonte de erro
	UnidadeDeControle* UC = new UnidadeDeControle(registradores, esmap);
	UC->setPC(0);
	GerenciadorDeMemoria* GM = new GerenciadorDeMemoria();


	while(true){
		int opcao = -1;
		string arquivo;
		cout << endl;

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

		cout << endl;
	
		//Sair
		if(opcao == 0)
			return 0;
		
		//Load
		if(opcao == 5){
			try{
				cout << "Arquivo de origem: ";
				cin >> arquivo;

				MemoriaRAM* m = new MemoriaRAM(UC->getMemoria()->getTamanho()); 

				GM->load(arquivo, m);
				ESMapeadaNaMemoria* tempMem = new ESMapeadaNaMemoria(m, 
											dynamic_cast<ESMapeadaNaMemoria*>(UC->getMemoria())->getDispositivos());
				UnidadeDeControle* temp = new UnidadeDeControle(UC->getBancoDeRegistradores(), tempMem);
				UC = temp;
				continue;
			} catch(runtime_error *e){
				cout << e->what() << endl; 
				delete e;
				continue;
			}
			
		
		}

		//Dump
		if(opcao == 6){
			try{
				cout << "Arquivo de destino: ";
				cin >> arquivo;

				GM->dump(arquivo, dynamic_cast<ESMapeadaNaMemoria*>(UC->getMemoria())->getMemoriaSubjacente());
				continue;
			}catch(runtime_error *e){
				cout << e->what() << endl;
				delete e;
				continue;
			}
		}

		//Memoria
		if(opcao == 1){
			int segundaOpcao = -1;
			do{
				cout << endl << "Memoria\n" <<
				"1) Alterar dado\n" <<
				"2) Imprimir\n" <<
				"0) Voltar\n" <<
				"Escolha uma opcao: ";
				cin >> segundaOpcao;

				if(segundaOpcao == 0)
					continue;

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
					UC->getMemoria()->imprimir();
				}
			} while(segundaOpcao != 0);
			continue;
		}

		//Registradores
		if(opcao == 2){

			int segundaOpcao = -1;
			do{
				cout << endl << "Registradores\n" <<
				"1) Alterar valor\n" <<
				"2) Imprimir\n" <<
				"0) Voltar\n" <<
				"Escolha uma opcao: ";
				cin >> segundaOpcao;

				if(segundaOpcao == 0)
					continue;

				if(segundaOpcao == 1){	
					int posicao = -1;
					int valor = -1;
					cout << "Posicao a ser alterada: ";
					cin >> posicao;
					cout << "Novo valor: ";
					cin >> valor;
					UC->getBancoDeRegistradores()->setValor(posicao, valor);
				}
				else if(segundaOpcao == 2){
					UC->getBancoDeRegistradores()->imprimir();
				}

			} while (segundaOpcao != 0);
			continue;
		}

		//Executar Instrucão
		if(opcao == 3){
			try{
				cout << "PC: " << UC->getPC() << "\n";
					if(dynamic_cast<ESMapeadaNaMemoria*>(UC->getMemoria())->getMemoriaSubjacente()->getTamanho() == UC->getPC()) 
						throw new runtime_error("Memoria acabou de ser lida");
				UC->executarInstrucao();
				cout << "Instrucao executada\n";
				cout << "PC: " << UC->getPC() << "\n";
				continue;
			}catch(invalid_argument *e){
				cout << e->what() << endl;
				delete e;
				continue;
			}catch(logic_error *e){
				cout << e->what() << endl;
				delete e;
				continue;
			}catch(runtime_error *e){
				cout << e->what() << endl;
				delete e;
				continue;
			}
		}

		//Executar até PC = 0
		if(opcao == 4)
			do{
				try{
					if(dynamic_cast<ESMapeadaNaMemoria*>(UC->getMemoria())->getMemoriaSubjacente()->getTamanho() == UC->getPC()) 
						throw new runtime_error("Memoria acabou de ser lida");
					UC->executarInstrucao();	
				} catch(invalid_argument *e){
					cout << e->what() << endl;
					delete e;
					break;
				} catch(logic_error *e){
					cout << e->what() << endl;
					delete e;
					break;
				}catch(runtime_error *e){
					cout << e->what() << endl;
					delete e;
					break;
				}
			} while(UC->getPC() != 0);
	}
}


