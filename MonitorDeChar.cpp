#include "MonitorDeChar.h"

MonitorDeChar::MonitorDeChar(){}

MonitorDeChar::~MonitorDeChar(){}

void MonitorDeChar::escrever(Dado* d){
    char saida = static_cast<char>(d->getValor());
    cout << saida << endl;
}