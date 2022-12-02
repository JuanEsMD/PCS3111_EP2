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

class TelaInicial{

public:
	void Ler(UnidadeDeControle* UC);
};

