#include "fila.h"
#include "pilha.h"
#include <stdlib.h>

bool FilaInicia(Fila *pFila)
{
    return ListaInicia(pFila);
}

bool FilaEnfileira(Fila *pFila, Item item)
{
    return ListaInsereFinal(pFila, item);
}

bool FilaDesinfeleira(Fila *pFila, Item *pItem)
{
    return ListaRetiraPrimeiro(pFila, pItem);
}

bool FilaEhVazia(Fila *pFila)
{
    return ListaEhVazia(pFila);
}

void FilaLibera(Fila *pFila)
{
    ListaLibera(pFila);
}

bool FilaInverte(Fila *pFila)
{
    Celula *aux1;
    Item Titem;
    Pilha pilha;
    PilhaInicia(&pilha);

    //Transfere as células para a pilha
    aux1 = pFila->cabeca->prox;

    while (aux1 != NULL)
    {
        PilhaPush(&pilha, aux1->item);
        aux1 = aux1->prox;
    }
    //Remove as células da fila
    aux1 = pFila->cabeca->prox;

    while (aux1 != NULL)
    {  
        FilaDesinfeleira(pFila, &Titem);
        aux1 = pFila->cabeca->prox;
    }
    //ultimo da fila aponta para a cabeca da fila
    pFila->ultimo = pFila->cabeca;

    //dados saem do topo da pilha para a fila, invertendo a ordem, pois o ultimo da fila, originamente, será o primeiro na nova fila 
    aux1 = pilha.cabeca->prox;
    
    while (aux1 != NULL)
    {   
        FilaEnfileira(pFila, aux1->item);
        aux1 = aux1->prox;
    }
    //libera pilha
    PilhaLibera(&pilha);

    return true;
}
