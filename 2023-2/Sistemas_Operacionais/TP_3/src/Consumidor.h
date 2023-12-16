#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H

#include "Buffer.h"


class Consumidor{
    
    Buffer * buffer;
    int qtdItensConsumir;
    int consumoPorSegundo;

public:
    Consumidor(Buffer * buffer, int qtdItensConsumir, int consumoPorSegundo);

    void run();
};

#endif