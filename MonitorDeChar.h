#ifndef MONITORDECHAR_H
#define MONITORDECHAR_H

#include "Monitor.h"

class MonitorDeChar : public Monitor{
    MonitorDeChar();
    virtual ~MonitorDeChar(); 

    virtual void escrever(Dado* d); 
};

#endif