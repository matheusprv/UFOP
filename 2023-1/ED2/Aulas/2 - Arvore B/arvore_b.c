#include "arvore_b.h"


TipoPagina * iniciaArvore(){
    return NULL;
}

void pesquisa(TipoChave chavePesquisa, TipoApontador pagina){
    
    if(pagina == NULL){
        printf("Item não encontrado\n");
        return;
    }

    int index = 1;

    while(chavePesquisa > pagina->registros[index-1].chave && index < pagina->numElementos) 
        index++;

    if(chavePesquisa == pagina->registros[index-1].chave){
        printf("Valor encontrado:\n\tChave: %ld\n\tValor Arbitrário: %d", pagina->registros[index-1].chave, pagina->registros[index-1].valorArbitrario);
        return;
    }

    if(chavePesquisa > pagina->registros[index-1].chave)
        pesquisa(chavePesquisa, pagina->paginas[index]);
    else
        pesquisa(chavePesquisa, pagina->paginas[index-1]);

}
