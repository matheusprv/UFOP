#include <stdio.h>
#include <stdlib.h>


void troca(int * n1, int* n2){
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

int selection(int * vetor, int n){

    int qtdTrocas = 0;
    int menor_valor_pos;
    
    for(int i = 0; i < n; i++){
        
        menor_valor_pos = i;
        for(int j = i+1; j < n; j++){
            if(vetor[j] < vetor[menor_valor_pos])
                menor_valor_pos = j;
        }

        if(i != menor_valor_pos){
            qtdTrocas++;
            troca(&vetor[i], &vetor[menor_valor_pos]);
        }

    }
    return qtdTrocas;
}


int main(){

    int casos_de_teste;
    scanf("%d",&casos_de_teste);
    int qtdItens;

    for(int cont=0; cont<casos_de_teste; cont++){
        
        scanf("%d",&qtdItens);

        int * valores = (int*) malloc(qtdItens*sizeof(int));

        for(int i = 0; i < qtdItens; i++)
            scanf("%d",&valores[i]);


        printf("%d\n", selection(valores, qtdItens));
            for(int i = 0; i < qtdItens; i++){
        }

        free(valores);

    }

    return 0;
}