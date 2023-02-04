#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int n;
}Item;

typedef struct celula{
    struct celula * prox;
    Item item;
}Celula;

typedef struct{
    Celula * primeira;
    Celula * ultima;
}Lista;

void iniciaLista(Lista * pLista){
    pLista->primeira = malloc(sizeof(Celula));
    pLista->ultima = pLista->primeira;
}

void listaLibera(Lista* pLista){

    Celula * atual = pLista -> primeira;
    Celula * proximo = atual->prox;
    
    while (proximo != NULL){
        free(atual);
        atual = proximo;
        proximo = proximo -> prox;
    }
    free(atual);
}

void listaInsereFinal(Lista* pLista, Item item){
    pLista -> ultima -> prox =( Celula *) malloc ( sizeof ( Celula )) ;
    pLista -> ultima = pLista -> ultima -> prox ;
    pLista -> ultima -> item = item;
    pLista -> ultima -> prox = NULL ;
}

void listaRemoveInicio(Lista * pLista, int *item){
    if(pLista->primeira == pLista->ultima) return;
    
    Celula * pAux ;
    pAux = pLista -> primeira -> prox;
    *item = pAux -> item.n ;
    pLista -> primeira -> prox = pAux -> prox;
    free ( pAux );
}

void levarParaFim(Lista * pLista){

    pLista->ultima->prox = pLista->primeira->prox;
    pLista->ultima = pLista->primeira->prox;

    pLista->primeira->prox = pLista->primeira->prox->prox;

    pLista->ultima->prox = NULL;

}


int main(){
    
    Lista lista;
    Item item;
    
    int n;
    scanf("%d", &n);
    while (n != 0){
        int * cartasRemovidas = malloc((n-1) * sizeof(int));

        iniciaLista(&lista);

        for(int i = 1; i <= n; i++){
            item.n = i;
            listaInsereFinal(&lista, item);
        }

        //Removendo as cartas e salvando quais foram removidas
        for(int i = 1; i < n; i++){
            listaRemoveInicio(&lista, &cartasRemovidas[i-1]);
            levarParaFim(&lista);
        }

        printf("Discarded cards: %d", cartasRemovidas[0]);
        for(int i = 1; i<n-1; i++)
            printf(", %d", cartasRemovidas[i]);
        printf("\n");
        printf("Remaining card: %d\n", lista.primeira->prox->item.n);

        listaLibera(&lista);
        free(cartasRemovidas);

        scanf("%d", &n);

    }

    return 0;

}