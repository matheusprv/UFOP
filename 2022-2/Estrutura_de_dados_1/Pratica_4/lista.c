#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) {
    //Lista com cabeca - Primeira Celula com itens vazios
    pLista -> pPrimeiro = ( TCelula *) malloc ( sizeof ( TCelula )) ;
    pLista -> pPrimeiro -> pProx = NULL ;
    
    pLista -> pUltimo = pLista -> pPrimeiro ;
}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {
    return pLista->pPrimeiro == pLista->pUltimo;
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {
    TCelula *novaCelula = (TCelula*) malloc(sizeof(TCelula));
    novaCelula->pProx = NULL;
    novaCelula->item = x;
    pLista->pUltimo->pProx = novaCelula;
    pLista->pUltimo = novaCelula;    
    return 1;
}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
    if ( TLista_EhVazia ( pLista ))
        return 0;
    TCelula * pAux ;
    pAux = pLista -> pPrimeiro -> pProx ;
    *pX = pAux -> item ;
    pLista -> pPrimeiro -> pProx = pAux -> pProx ;
    free (pAux);
    return 1;
}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {
    TCelula * aux = pLista->pPrimeiro->pProx;
    while (aux != NULL)
    {
        printf("%s ", aux->item.nome);
        aux = aux->pProx;
    }

    printf("\n");
    
}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {
    TCelula * atual = pLista -> pPrimeiro;
    TCelula * proximo = atual->pProx;
    
    while (proximo != NULL){
        free(atual);
        atual = proximo;
        proximo = proximo -> pProx;
    }
    free(atual);

}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2){
    pLista1->pUltimo->pProx = pLista2->pPrimeiro->pProx;
    pLista1->pUltimo = pLista2->pUltimo;
    free(pLista2->pPrimeiro);
}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str){
    
    TCelula * aux = pLista1->pPrimeiro;
    //Procurando a posicao onde ira ser inserido
    while(aux->pProx != NULL){
        if(strcmp(aux->pProx->item.nome, str) == 0){
            TCelula *proxLista1 = aux->pProx;
            aux->pProx = pLista2->pPrimeiro->pProx;
            pLista2->pUltimo->pProx = proxLista1;
            free(pLista2->pPrimeiro);
            break;
        }
        aux = aux->pProx;
    }
    

}
