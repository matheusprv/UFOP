#include <stdio.h>
#include <stdlib.h>

#define MM 4

typedef long TipoChave;

typedef struct TipoRegistro{
    TipoChave Chave;
}TipoRegistro;

typedef struct TipoPagina * TipoApontador;

typedef struct TipoPagina{
    short n;
    TipoRegistro r[MM];
    TipoApontador p[MM + 1];
}TipoPagina;

void Minimo(TipoRegistro * x, TipoApontador Ap){
    if(Ap->p[0] != NULL)
        Minimo(x, Ap->p[0]);
    
    else
        x = &(Ap->r[0]);
}