#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

bool ListaInicia(Lista *pLista)
{
    pLista->cabeca = (Celula *)malloc(sizeof(Celula));
    if (pLista->cabeca == NULL)
        return false;
    pLista->ultimo = pLista->cabeca;
    pLista->cabeca->prox = NULL;
    return true;
}

bool ListaEhVazia(Lista *pLista)
{
    if (pLista->cabeca == pLista->ultimo)
        return true;
    return false;
}

bool ListaInsereFinal(Lista *pLista, Item item){

    Celula * nova = malloc(sizeof(Celula));
    if(nova == NULL){
        printf("NOVA CÉLULA É NULL\n");
        return false;
    }

    nova->item = item;
    nova->prox = NULL;
    
    pLista->ultimo->prox = nova;
    pLista->ultimo = nova;

    return true;

}

bool ListaInsereInicio(Lista *pLista, Item item)
{
    Celula * nova = malloc (sizeof(Celula));
    if(nova == NULL){
        printf("NOVA CÉLULA INSERE INÍCIO É NULL\n");
        return false;
    }

    nova->item = item;
    nova->prox = pLista->cabeca->prox;
    pLista->cabeca->prox = nova;

    return true;
}

bool ListaRetiraPrimeiro(Lista *pLista, Item *pItem)
{
    if(ListaEhVazia(pLista))
        return false;

    Celula * remover = pLista->cabeca->prox;
    pLista->cabeca->prox = remover->prox;
    *pItem = remover->item;
    free(remover);
    return true;
}

void ListaLibera(Lista *pLista){

    Celula * atual = pLista->cabeca;
    Celula * proxima = atual->prox;

    while(proxima != NULL){
        free(atual);
        atual = proxima;
        proxima = atual->prox;
    }
    free(atual);

}