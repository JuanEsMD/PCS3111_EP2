#include "Monitor.h"

Monitor::Monitor(){}

Monitor::~Monitor(){}

Dado*  Monitor::ler(){
    throw new invalid_argument("Monitor nao eh dispositivo de entrada");
}

void Monitor::escrever(Dado *d){
    cout << d << endl;
}