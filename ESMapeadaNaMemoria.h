#ifndef ESMAPEADANAMEMORIA_H
#define ESMAPEADANAMEMORIA_H

#include "Memoria.h"
#include "MemoriaRAM.h"
#include "Dispositivo.h"
#include <vector>

class ESMapeadaNaMemoria : public Memoria{
private:

public:
    ESMapeadaNaMemoria(MemoriaRAM* m);
    ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos);
    virtual ~ESMapeadaNaMemoria();
    virtual MemoriaRAM* getMemoriaSubjacente();
    virtual void adicionar(Dispositivo* d);
    virtual vector<Dispositivo*>* getDispositivos(); 

    virtual Dado* ler(int posicao);
	virtual void escrever(int posicao, Dado* d);
    virtual void imprimir();
private:
    MemoriaRAM* memoriaRam;
    vector<Dispositivo*>* dispositivos;
};

#endif // ESMAPEADANAMEMORIA_H