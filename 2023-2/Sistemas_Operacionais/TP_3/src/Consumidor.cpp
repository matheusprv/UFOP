#include "Consumidor.h"

Consumidor :: Consumidor(Buffer * buffer, int qtdItensConsumir, int consumoPorSegundo){
    this->buffer = buffer;
    this->qtdItensConsumir = qtdItensConsumir;
    this->consumoPorSegundo = consumoPorSegundo;
    srand(time(NULL));
}


void Consumidor :: run(){
    
    int item;

    double sleepTempo = 1000.0 / consumoPorSegundo;
    cout << "Sleep do consumidor: " << sleepTempo << endl;

    for(int i = 0; i < qtdItensConsumir; i++){
        buffer->consumir(item); // Remove no buffer
        cout << i+1 << " - Item removido: " << item << endl;
        usleep(sleepTempo);      // Espera um tempo para remover o proximo
    }


}
