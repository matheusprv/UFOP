#include "fila.h"
#include "pilha.h"
#include <stdlib.h>
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

bool FilaInverte(Fila *pFila)
{
    Pilha pilha;
    PilhaInicia(&pilha);

    Celula * aux = pFila->cabeca->prox;
    //Copiando os valores da FILA para a PILHA  
    while (aux != NULL)
    {
        PilhaPush(&pilha, aux->item);
        aux = aux->prox;
    }

    //Liberando a FILA
    FilaLibera(pFila);
    FilaInicia(pFila);

    //Passando os dados da pilha para a lista
    aux = pilha.cabeca->prox;
    while(aux != NULL){
        FilaEnfileira(pFila, aux->item);
        aux = aux->prox;
    }

    PilhaLibera(&pilha);

    return true;
}