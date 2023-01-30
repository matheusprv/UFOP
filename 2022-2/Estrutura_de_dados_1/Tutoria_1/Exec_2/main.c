#include "recursividade.h"

int main(){
    
    TLista * lista = (TLista*) malloc(sizeof(TLista));
    TLista_FazVazia(lista);

    TItem item;
    while(scanf("%d", &(item.num)) != EOF){
        TLista_Insere(lista, item);
    }

    int soma = recursividade(lista, 0);

    printf("%d\n", soma);

    free(lista);

    return 0;
    
}