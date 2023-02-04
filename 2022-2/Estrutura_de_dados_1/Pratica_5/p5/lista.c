#include "lista.h"
#include <stdlib.h>

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

bool ListaInsereFinal(Lista *pLista, Item item)
{
    pLista->ultimo->prox = (Celula *)malloc(sizeof(Celula));
    pLista->ultimo->prox->item = item;
    pLista->ultimo = pLista->ultimo->prox;
    pLista->ultimo->prox = NULL;
    return true;
}

bool ListaInsereInicio(Lista *pLista, Item item)
{
    Celula *new = (Celula *)malloc(sizeof(Celula));
    if (new == NULL)
        return false;
    new->prox = pLista->cabeca->prox;
    new->item = item;
    pLista->cabeca->prox = new;
    return true;
}

bool ListaRetiraPrimeiro(Lista *pLista, Item *pItem)
{
    if (ListaEhVazia(pLista))
        return false;
    Celula *aux;
    aux = pLista->cabeca->prox;
    *pItem = aux->item;
    pLista->cabeca->prox = aux->prox;
    free(aux);
    return true;
}

void ListaLibera(Lista *pLista)
{
    Celula *aux1, *aux2;
    aux1 = pLista->cabeca;
    while (aux1 != NULL)
    {
        aux2 = aux1;
        aux1 = aux1->prox;
        free(aux2);
    }
}