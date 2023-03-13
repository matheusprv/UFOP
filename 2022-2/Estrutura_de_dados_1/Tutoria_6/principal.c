#include "busca.h"

int main(){

    int * vetor = malloc(sizeof(int) * 1000);
    int pesquisa;

    for(int i = 0; i < 1000; i++){
        scanf("%d", &vetor[i]);
    }

    mergeSort(vetor, 0, 999);

    scanf("%d", &pesquisa);

    free(vetor);

    int resultado = pesquisaBinaria(vetor, 0, 999, pesquisa);

    printf("chave %d na posicao %d\n", pesquisa, resultado);

    return 0;
}