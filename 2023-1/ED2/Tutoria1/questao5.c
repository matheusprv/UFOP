#include <stdio.h>
#include <stdlib.h>

#define M 4

typedef struct {
    int chave;
}Registro;

typedef struct No * nos;

typedef struct{
    nos filhos [2*M + 1];
    Registro items [2*M];
}No;

void iniciarArvore(No * arvore){
    arvore = NULL;
}

Registro * procura(No * arvore, int chavePesquisa){

    if (arvore == NULL) return NULL;

    int i;
    for (i = 0; i < 2*M && arvore->items[i].chave < chavePesquisa; i++)
        if(arvore->items[i].chave == chavePesquisa)
            return &(arvore->items[0]);
    
    return procura(&(arvore->items[i]), chavePesquisa);

}

