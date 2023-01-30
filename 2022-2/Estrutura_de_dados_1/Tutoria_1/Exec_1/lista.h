#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char caracter;
} TItem ;

typedef struct celula {
    struct celula * proxima;
    TItem item;
} TCelula ;

typedef struct {
    TCelula * primeira;
    TCelula * ultima;
} TLista ;

void TLista_Inicia ( TLista * pLista );
int TLista_EhVazia ( TLista * pLista );
int TLista_Insere_Fim ( TLista * pLista , char x);
int TLista_Insere_Inicio ( TLista * pLista , char x);
void TLista_Imprime ( TLista * pLista );
void TLista_Esvazia (TLista * pLista);

#endif