#include "recursividade.h"

void TLista_FazVazia ( TLista * pLista ) {

    pLista->ultimoItem = -1;
    
}

int TLista_Insere ( TLista * pLista , TItem x) {
    if(pLista->ultimoItem == MAXTAM - 1)
        return 0;

    pLista->ultimoItem++;
    pLista->listaItens[pLista->ultimoItem] = x;
    return 1;

}

int recursividade(TLista* pLista, int posicao){
    if(posicao != pLista->ultimoItem){

        return pLista->listaItens[posicao].num + recursividade(pLista, posicao + 1); 
        
    }

    return pLista->listaItens[posicao].num;
}