#include "lista.h"

void TLista_Inicia (TLista * pLista ) {
    TCelula * nova = (TCelula*) malloc(sizeof(TCelula));
    pLista->primeira = nova;
    pLista->primeira->proxima = NULL;

    pLista->ultima = nova;
}

int TLista_EhVazia ( TLista * pLista ) {
    return pLista->primeira == pLista->ultima;
}

int TLista_Insere_Fim ( TLista * pLista , char x) {
    TCelula *novaCelula = (TCelula*) malloc(sizeof(TCelula));
    novaCelula->proxima = NULL;
    novaCelula->item.caracter = x;
    pLista->ultima->proxima = novaCelula;
    pLista->ultima = novaCelula;    
    return 1;
}

int TLista_Insere_Inicio ( TLista * pLista , char x){
    TCelula * novaCelula = (TCelula*) malloc(sizeof(TCelula));

    if(novaCelula == NULL) return 0;

    novaCelula->item.caracter = x;
    novaCelula->proxima = pLista->primeira->proxima;
    pLista->primeira->proxima = novaCelula;

    return 1;
}

void TLista_Esvazia (TLista * pLista){
    TCelula * atual = pLista->primeira;
    TCelula * proxima = atual->proxima;

    while(proxima != NULL){
        free(atual);
        atual = proxima;
        proxima = proxima->proxima;
    }
    free(atual);
}

void TLista_Imprime ( TLista * pLista ){
    TCelula * aux = pLista->primeira->proxima;
    
    while(aux != NULL){
        printf("%c", aux->item.caracter);
        aux = aux->proxima;
    }
    printf("\n");

}