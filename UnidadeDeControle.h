#ifndef UNIDADE_DE_CONTROLE_H
#define UNIDADE_DE_CONTROLE_H

#include <iostream>
#include "BancoDeRegistradores.h"
#include "Memoria.h"
#include "Instrucao.h"

using namespace std;

class UnidadeDeControle{
private:
    BancoDeRegistradores* registradores;
    Memoria* memoria;
    
    int PC;

    void FUNCAO_ADD(int destino, int origem1, int origem2);
    void FUNCAO_SUB(int destino, int origem1, int origem2);
    void FUNCAO_MULT(int origem1, int origem2);
    void FUNCAO_DIV(int origem1, int origem2);
    void FUNCAO_J(int imediato);
    void FUNCAO_BNE(int origem1, int origem2, int imediato);
    void FUNCAO_BEQ(int origem1, int origem2, int imediato);
    void FUNCAO_LW(int destino, int imediato);
    void FUNCAO_SW(int destino, int imediato);

public:
   UnidadeDeControle(BancoDeRegistradores* registradores, Memoria* memoria);
    virtual ~UnidadeDeControle();
    virtual BancoDeRegistradores* getBancoDeRegistradores();
    virtual Memoria* getMemoria();
    virtual int getPC();
    virtual void setPC(int pc);
    virtual void executarInstrucao(); 
};

#endif // UNIDADE_DE_CONTROLE_H