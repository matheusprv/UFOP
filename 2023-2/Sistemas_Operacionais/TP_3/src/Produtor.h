#ifndef PRODUTOR_H
#define PRODUTOR_H

#include "Buffer.h"

class Produtor{
    
    Buffer * buffer;
    int qtdItensProduzir;
    int itensPorSegundo;

public:
    Produtor(Buffer * buffer, int qtdItensProduzir, int itensPorSegundo);

    void run();
};

#endif