#include "Produtor.h"

Produtor :: Produtor(Buffer * buffer,  int qtdItensProduzir, int itensPorSegundo){
    this->buffer = buffer;
    this->qtdItensProduzir = qtdItensProduzir;
    this->itensPorSegundo = itensPorSegundo;
    srand(time(NULL));
}


void Produtor :: run(){
    
    int item;

    int sleepTempo = 1000 / itensPorSegundo;
    cout << "Sleep do produtor: " << sleepTempo << endl;

    for(int i = 0; i < qtdItensProduzir; i++){
        item = rand();          // Gera um novo item
        buffer->produzir(item); // Adiciona no buffer
        cout << i+1 << " - Produzido: " << item << endl;
        this_thread::sleep_for(chrono::milliseconds(sleepTempo));
    }


}
