/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                  13681248       **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: ESMapeadaNaMemoria.cpp                         **/
/**                                                           **/
/***************************************************************/


#include "ESMapeadaNaMemoria.h"

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m):
    memoriaRam(m){
        this->tamanho = m->getTamanho();
    }

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos):
    memoriaRam(m), dispositivos(dispositivos){
        this->tamanho = m->getTamanho() + dispositivos->size();
    }

int ESMapeadaNaMemoria::getTamanho(){
    return this->tamanho;
}

ESMapeadaNaMemoria::~ESMapeadaNaMemoria(){
    delete memoriaRam;
    for(int i = 0; i < this->tamanho - this->getMemoriaSubjacente()->getTamanho(); i++)
        delete dispositivos->at(i);
    delete dispositivos;
}

MemoriaRAM* ESMapeadaNaMemoria::getMemoriaSubjacente(){
    return this->memoriaRam;
}

void ESMapeadaNaMemoria::adicionar(Dispositivo* d){
    dispositivos->push_back(d);
    this->tamanho++;
}

 vector<Dispositivo*>* ESMapeadaNaMemoria::getDispositivos(){
    return dispositivos;
 }

Dado* ESMapeadaNaMemoria::ler(int posicao){
    if(posicao < 0 || posicao > this->tamanho)
        throw new logic_error("posicao invalida");

    if(posicao >= this->memoriaRam->getTamanho())
        return (*dispositivos)[posicao - this->memoriaRam->getTamanho()]->ler();
   
    return this->memoriaRam->ler(posicao);
}

void ESMapeadaNaMemoria::escrever(int posicao, Dado* d){
    if(posicao < 0 || posicao > this->tamanho)
        throw new logic_error("posicao invalida");

    if(posicao >= this->memoriaRam->getTamanho())
        (*dispositivos)[posicao - this->memoriaRam->getTamanho()]->escrever(d);
    else
        this->memoriaRam->escrever(posicao, d); 

}

void ESMapeadaNaMemoria::imprimir(){
    memoriaRam->imprimir();
}
