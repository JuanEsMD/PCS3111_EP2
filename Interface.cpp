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

void TelaInicial::ler(UnidadeDeControle* UC){

	int opcao = -1;
	string arquivo;

	cout << "Emulador de MIPS\n" <<
	"1) Memoria\n" <<
	"2) Registradores\n" <<
	"3) Executar proxima instrucao\n" <<
	"4) Executar ate PC = 0\n" <<
	"5) Load\n" <<
	"6) Dump\n" <<
	"0) Sair\n" <<
	"Escolha uma opcao:\n";

	cin >> opcao;
	
	//Sair
	if(opcao == 0)
		return;

	//Load
	if(opcao == 5){
		cout << "Arquivo de Origem:";
		cin >> arquivo;
		GerenciadorDeMemoria::ler(arquivo, UC->me)
	}

}
