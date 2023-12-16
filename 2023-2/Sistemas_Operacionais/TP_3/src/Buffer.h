#ifndef BUFFER_H
#define BUFFER_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <pthread.h>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

using namespace std;

class Buffer{
    int capacidadeMaxima;
    queue<int> buffer;

    pthread_mutex_t mutex;
    pthread_cond_t condicaoProdutor;
    pthread_cond_t condicaoConsumidor;

    static int itensProduzidos;
    static int itensConsumidos;


public:
    Buffer(int capacidadeMaxima = 100);

    // Buffer
    void insertItem(int item);
    int removeItem();
    int bufferLen();
    
    // Mutex
    void down();
    void up();

    // Semáforos
    void downProdutor();
    void downConsumidor();
    void upProdutor();
    void upConsumidor();

    // Produtor e Consumidor
    void produzir(int item);
    void consumir(int & item);

    // Contadores
    int getItensProduzidos();
    int getItensConsumidos();

};


#endif