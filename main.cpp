#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;

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

int main(){

	BancoDeRegistradores* registradores = new BancoDeRegistradores()
	MemoriaRAM* MemRAM = new MemoriaRAM(64);
	ESMapeadaNaMemoria* ESMap = new ESMapeadaNaMemoria(MRAM);

	Teclado* tec = new Teclado();
	TecladoDeChar* tecChar = new TecladoDeChar();
	Monitor* mon = new Monitor();
	MonitorDeChar* monChar = new MonitorDeChar();

	ESMap->adicionar(tec);
	ESMap->adicionar(tecChar);
	ESMap->adicionar(mon);
	ESMap->adicionar(monChar);

//  uso de ESMapeadaNaMemoria como Memoria: possivel fonte de erro
	UnidadeDeControle* UC = new UnidadeDeControle(registradores, ESMap);

	












}
