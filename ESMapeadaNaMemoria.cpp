#include "ESMapeadaNaMemoria.h"

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m):
    memoriaRam(m){
        //Pode ser getTamanho+1, não sei se o tamanho da RAM é 63 ou 64....
        this->tamanho = m->getTamanho();
    }

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos):
    memoriaRam(m), dispositivos(dispositivos){
        //Pode ser getTamanho+1, não sei se o tamanho da RAM é 63 ou 64....
        this->tamanho = m->getTamanho() + dispositivos->size();
    }

int ESMapeadaNaMemoria::getTamanho(){
    return this->tamanho;
}

ESMapeadaNaMemoria::~ESMapeadaNaMemoria(){
    delete memoriaRam;
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

    if(posicao > this->memoriaRam->getTamanho())
        return (*dispositivos)[posicao]->ler();
   
    return this->memoriaRam->ler(posicao);
}

void ESMapeadaNaMemoria::escrever(int posicao, Dado* d){
    if(posicao < 0 || posicao > this->tamanho)
        throw new logic_error("posicao invalida");

    if(posicao > this->memoriaRam->getTamanho())
        (*dispositivos)[posicao]->escrever(d);
    else
        this->memoriaRam->escrever(posicao, d); 

}

void ESMapeadaNaMemoria::imprimir(){
    memoriaRam->imprimir();
}
