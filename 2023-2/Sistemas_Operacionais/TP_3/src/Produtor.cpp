#include "Produtor.h"

Produtor :: Produtor(Buffer * buffer,  int qtdItensProduzir, int itensPorSegundo){
    this->buffer = buffer;
    this->qtdItensProduzir = qtdItensProduzir;
    this->itensPorSegundo = itensPorSegundo;
    srand(time(NULL));
}


void Produtor :: run(){
    
    int item;

    double sleepTempo = 1 / itensPorSegundo;

    for(int i = 0; i < qtdItensProduzir; i++){
        item = rand();          // Gera um novo item
        buffer->produzir(item); // Adiciona no buffer
        cout << i+1 << " - Produzido: " << item << endl;
        sleep(sleepTempo);      // Espera um tempo para inserir o proximo
    }


}
