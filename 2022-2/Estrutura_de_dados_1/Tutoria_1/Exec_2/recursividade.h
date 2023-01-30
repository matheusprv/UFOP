#ifndef RECURSIVIDADE
#define RECURSIVIDADE

# define MAXTAM 1000
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
} TItem ;

typedef struct {
    TItem listaItens[MAXTAM];
    int ultimoItem;

} TLista ;

void TLista_FazVazia ( TLista * pLista );
int recursividade(TLista *plista, int posicao);
int TLista_Insere ( TLista * pLista , TItem x);

#endif