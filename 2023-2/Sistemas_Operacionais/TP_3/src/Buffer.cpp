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
    pthread_mutex_trylock(&mutex);
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
    downProdutor();           // Fica esperando enquanto o buffer não está vazio
    down();                   // Entra na região crítica
    insertItem(item);         // Insere um item no buffer
    up();                     // Sai da regiao crítica
    upConsumidor();           // Envia um sinal para o consumidor de que há itens no buffer
}

void Buffer :: consumir(int & item){
    downConsumidor();      // Fica esperando o buffer não estar vazio
    down();                // Entra na região crítica
    item = removeItem();   // Remove um item do buffer
    up();                  // Sai da região crítica
    upProdutor();          // Envia um sinal para o produtor que o buffer não está lotado
}

// Contadores
int Buffer :: getItensProduzidos(){
    return this->itensProduzidos;
}
int Buffer :: getItensConsumidos(){
    return this->itensConsumidos;
}