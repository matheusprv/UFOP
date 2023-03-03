#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    struct celula * prox;
    int item;
}Celula;

typedef struct {
    Celula * cabeca;
    Celula * fim;
}Lista;

void listaInicia (Lista * lista){
    lista->cabeca = malloc(sizeof(Celula));
    lista->cabeca->prox = NULL;
    lista->fim = lista->cabeca;
}

int ehVazia(Lista * lista){
    return (lista->cabeca == lista->fim);
}

void adicionaFim(Lista * lista, int item){
    Celula * nova = malloc(sizeof(Celula));
    nova->item = item;
    nova->prox = NULL;
    lista->fim->prox = nova;
    lista->fim = nova;
}

void printaLista(Lista * lista){
    Celula * aux = lista->cabeca->prox;

    while(aux != NULL){
        printf("%d ", aux->item);
        aux = aux -> prox;
    }
    printf("\n");
}

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

void troca(Lista * lista, int i){

    Celula * comeco = lista->cabeca;
    Celula * atual = lista->cabeca->prox;
    Celula * prox = atual -> prox;

    for(int cont = 0; cont < i && prox != NULL; cont++){
        comeco = atual;
        atual = prox;
        prox = atual->prox;
    }

    Celula auxProx = *prox;

    comeco->prox = prox;
    prox->prox = atual;
    atual->prox = auxProx.prox;
}

void liberaLista(Lista * lista){
    Celula * aux = lista->cabeca;
    Celula * aux2;
    
    while(aux->prox != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(aux);
}

int main(){
    
    Lista lista;

    listaInicia(&lista);
    adicionaFim(&lista, 1);
    adicionaFim(&lista, 2);
    adicionaFim(&lista, 6);
    adicionaFim(&lista, 3);
    adicionaFim(&lista, 4);
    adicionaFim(&lista, 5);
    

    printaLista(&lista);

    //troca(&lista, 2);

    voidMoveMaior(&lista);

    printaLista(&lista);
    
    liberaLista(&lista);

    return 0;
}