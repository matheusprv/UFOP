#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    struct celula *prox;
    int item;
}Celula;

typedef struct{
    Celula * cabeca;
}Lista;


void voidMoveMaior(Lista * lista){

    //Verifica que a lista não é vazia para continuar

    Celula * maior = lista->cabeca->prox;
    Celula * aux = lista->cabeca->prox;

    //Procurando qual a célula com o maior valor
    while (aux != NULL){
        if(aux->item > maior->item)
            maior = aux;

        aux = aux->prox;
    }
    
    aux = lista->cabeca->prox;

    //Indo até o final da lista
    while(aux->prox != NULL){
        //Procurando onde está a posição com o maior valor
        if(aux->prox->item == maior->item){
            //Linkando sua anterior à próxima
            aux->prox = aux->prox->prox;
        }
        aux = aux->prox;
    }
    //Colocando a maior no final da lista
    aux->prox = maior;
    maior->prox = NULL;

}

int main(){

}