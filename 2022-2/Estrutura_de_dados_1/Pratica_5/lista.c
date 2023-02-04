#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

bool ListaInicia(Lista* pLista) {
    pLista->cabeca = (Celula*) malloc(sizeof(Celula));
    if (pLista->cabeca == NULL)
        return false;
    pLista->ultimo = pLista->cabeca;
    return true;
}

bool ListaEhVazia(Lista* pLista) {
    if(pLista->cabeca == pLista->ultimo)
        return true;
    return false;
}

bool ListaInsereFinal(Lista* pLista, Item item) {
    pLista -> ultimo -> prox =( Celula *) malloc ( sizeof ( Celula )) ;
    pLista -> ultimo = pLista -> ultimo -> prox ;
    pLista -> ultimo -> item = item;
    pLista -> ultimo -> prox = NULL ;
    return true;

}

bool ListaInsereInicio(Lista* pLista, Item item) {
    pLista -> ultimo -> prox =( Celula *) malloc ( sizeof ( Celula )) ;
    pLista -> ultimo = pLista -> ultimo -> prox ;
    pLista -> ultimo -> item = item;
    pLista -> ultimo -> prox = NULL ;
    return true;
}

bool ListaRetiraPrimeiro(Lista* pLista, Item* pItem) {
    if (ListaEhVazia(pLista)) 
        return false;
    Celula * pAux ;
    pAux = pLista -> cabeca -> prox;
    *pItem = pAux -> item ;
    pLista -> cabeca -> prox = pAux -> prox;
    free ( pAux );
    return true;

}

void ListaLibera(Lista* pLista) {
    if(ListaEhVazia(pLista)) return;

    Celula * atual = pLista -> cabeca;
    Celula * proximo = atual->prox;
    
    while (proximo != NULL){
        free(atual);
        atual = proximo;
        proximo = proximo -> prox;
    }
    free(atual);

}