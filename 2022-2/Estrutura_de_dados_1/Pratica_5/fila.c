#include "fila.h"
#include "pilha.h"
#include <stdio.h>

bool FilaInicia(Fila* pFila) {
    return ListaInicia(pFila);
}

bool FilaEnfileira(Fila* pFila, Item item) {
    return ListaInsereFinal(pFila, item);
}

bool FilaDesinfeleira(Fila* pFila, Item* pItem) {
    return ListaRetiraPrimeiro(pFila, pItem);
}

bool FilaEhVazia(Fila* pFila) {
    return ListaEhVazia(pFila);
}

void FilaLibera(Fila* pFila) {
    ListaLibera(pFila);
}

bool FilaInverte(Fila* pFila) {

    Celula * aux;
    Pilha pilha;
    PilhaInicia(&pilha);

    //Colocando os dados da fila na pilha
    
    //Removendo os dados da Fila
    
    //Transferir dados da pilha para a fila


    return true;
}