#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    struct celula * proxima;
    int diversao;
}Celula;

typedef struct{
    Celula * primeiro;
    int min;
}Pilha;

void IniciaPilha(Pilha * pPilha){
    pPilha->primeiro = malloc(sizeof(Celula));
    pPilha->primeiro->proxima = NULL;
}

int pilhaEhVazia(Pilha * pPilha){
    return (pPilha->primeiro->proxima == NULL);
}

void push(Pilha * pPilha, int diversao){
    Celula * nova = (Celula*) malloc(sizeof(Celula));

    if(nova == NULL) return;

    nova->diversao = diversao;
    nova->proxima = pPilha->primeiro->proxima;
    
    pPilha->primeiro->proxima = nova;

}

int pop(Pilha * pPilha){
    if(pilhaEhVazia(pPilha)) return 0;

    Celula * aux = pPilha->primeiro->proxima;
    pPilha->primeiro->proxima = aux->proxima;
    free(aux);

    return 1;
}

int menosDivertido(Pilha * pPilha){

    if(pilhaEhVazia(pPilha)) return -1;

    int menosDivertido = 1000000000;

    Celula * atual = pPilha->primeiro->proxima;
    while(atual != NULL){
        if(atual->diversao < menosDivertido){
            menosDivertido = atual->diversao;
        }
        atual = atual->proxima;
    }

    return menosDivertido;
}

void pilhaLibera(Pilha * pPilha){
    Celula * atual = pPilha -> primeiro;
    Celula * proximo = atual->proxima;
    
    while (proximo != NULL){
        free(atual);
        atual = proximo;
        proximo = proximo -> proxima;
    }
    free(atual);

}

int main(){

    Pilha pPilha;
    IniciaPilha(&pPilha);

    int numOperacoes;
    scanf("%d", &numOperacoes);
    getchar();
    char operacao [10002];
    int diversao;

    for(int contador = 0; contador < numOperacoes; contador++){

        scanf("%s", operacao);

        if(!strcmp("PUSH", operacao)){
            scanf("%d", &diversao);
            getchar();

            push(&pPilha, diversao);
        }

        else if(!strcmp("POP", operacao)){
            if(!pop(&pPilha))
                printf("EMPTY\n");
        }
        else if(!strcmp("MIN", operacao)){
            int minimo = menosDivertido(&pPilha);
            if(minimo < 0)
                printf("EMPTY\n");
            else
                printf("%d\n", minimo);
        }

    }

    pilhaLibera(&pPilha);

    return 0;
}