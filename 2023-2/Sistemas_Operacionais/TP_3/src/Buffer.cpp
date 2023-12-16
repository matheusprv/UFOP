#include "Buffer.h"

int Buffer :: itensProduzidos = 0;
int Buffer :: itensConsumidos = 0;

Buffer :: Buffer (int capacidadeMaxima){
    
    this->capacidadeMaxima = capacidadeMaxima;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condicaoProdutor, NULL);
    pthread_cond_init(&condicaoConsumidor, NULL);
}

//Buffer
void Buffer :: insertItem(int item){
    itensProduzidos++;
    buffer.push(item);
}
int Buffer :: removeItem(){
    int item = buffer.front();
    buffer.pop();
    itensConsumidos++;
    return item;
}
int Buffer :: bufferLen(){
    return buffer.size();
}

// Mutex
void Buffer :: down(){
    pthread_mutex_lock(&mutex);
}
void Buffer :: up(){
    pthread_mutex_unlock(&mutex);
}

// Semaforos
void Buffer :: downProdutor(){
    while(bufferLen() == capacidadeMaxima) {
        cout << "\t\t\tPRODUTOR BLOQUEADO" << endl;
        pthread_cond_wait(&condicaoProdutor, &mutex);
    }
}
void Buffer :: downConsumidor(){
    while(bufferLen() == 0) {
        cout << "\t\t\tCONSUMIDOR BLOQUEADO" << endl;
        pthread_cond_wait(&condicaoConsumidor, &mutex);
    }
}
void Buffer :: upProdutor(){
    pthread_cond_signal(&condicaoProdutor);
}
void Buffer :: upConsumidor(){
    pthread_cond_signal(&condicaoConsumidor);
}

// Produtor e Consumidor
void Buffer :: produzir(int item){
    down();                   // Entra na região crítica
    downProdutor();           // Fica esperando enquanto o buffer não está vazio
    insertItem(item);         // Insere um item no buffer
    upConsumidor();           // Envia um sinal para o consumidor de que há itens no buffer
    up();                     // Sai da regiao crítica
}

void Buffer :: consumir(int & item){
    down();                // Entra na região crítica
    downConsumidor();      // Fica esperando o buffer não estar vazio
    item = removeItem();   // Remove um item do buffer
    upProdutor();          // Envia um sinal para o produtor que o buffer não está lotado
    up();                  // Sai da região crítica
}

// Contadores
int Buffer :: getItensProduzidos(){
    return this->itensProduzidos;
}
int Buffer :: getItensConsumidos(){
    return this->itensConsumidos;
}