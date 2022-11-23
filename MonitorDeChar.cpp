#include "MonitorDeChar.h"

Monitor::Monitor(){}

Monitor::~Monitor(){}

void Monitor::escrever(Dado* d){
    char saida = static_cast<char>(d->getValor());
    cout << saida << endl;
}