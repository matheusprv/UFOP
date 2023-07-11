#include <stdio.h>
#include <stdlib.h>

#define M 2
#define MM 4

typedef long TipoChave;

typedef struct TipoRegistro{
    TipoChave Chave;
    long dado1;
    char dado2[26];
    char dado3[101];
} TipoRegistro;

typedef struct TipoPagina* TipoApontador;

typedef struct TipoPagina {
    short n;
    TipoRegistro r[MM];
    TipoApontador p[MM + 1];
} TipoPagina;

TipoRegistro * procura(TipoApontador arvore, long chavePesquisa){

    if(arvore == NULL) return NULL;

    int i = 1;

    while(i < arvore->n && chavePesquisa > arvore->r[i-1].Chave) i++;

    if(chavePesquisa == arvore->r[i-1].Chave) return &arvore->r[i-1];

    if(chavePesquisa > arvore->r[i-1].Chave) return procura(arvore->p[i], chavePesquisa);

    return procura(arvore->p[i-1], chavePesquisa);

}

