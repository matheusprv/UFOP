#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>

void lerOrdem(int *ordem) {
    scanf("%d", ordem);
}

//manter como especificado
double **alocaMatriz(int ordem) {

    double **matriz = malloc(ordem * sizeof(double*)) ;
    for(int i=0; i<ordem; i++){
        matriz[i] = malloc(ordem * sizeof(double));
    }
    return matriz;

}

//manter como especificado
void desalocaMatriz(double ***M, int ordem) {
    for(int i=0; i < ordem; i++){
        free((*M)[i]);
    }
    free(*M);
}

//manter como especificado
void lerOperacao(char *operacao) {
    getchar();
    scanf("%c", operacao);
}

void lerMatriz(double **M, int ordem) {
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            scanf("%lf", &M[i][j]);
        }
    }
}

double somaMatriz(double **M, int ordem) {
    // double soma = 0;
    // int linhaParada = ordem/2;
    // for(int i = 0; i < linhaParada-1; i++){
    //     for(int j=i+1; j<ordem-(i+1); j++){
    //         soma += M[i][j];
    //     }
    // }
    // return soma;
    double soma = 0;
    int inicio = 0;
    int final = ordem-1;

    for(int linha = 0; (inicio != final) && (inicio+1 != final); linha++){
        for(int coluna = linha + 1; coluna < ordem - (linha+1); coluna++){
            soma+= M[linha][coluna];
        }
        inicio++;
        final--;
    }
    return soma;

}

double media(double resultado, int ordem) {

    int qtdItensSomados = 0;
    int inicio = 0;
    int final = ordem-1;

    for(int linha = 0; (inicio != final) && (inicio+1 != final); linha++){
        for(int coluna = linha + 1; coluna < ordem - (linha+1); coluna++){
            qtdItensSomados++;
        }
        inicio++;
        final--;
    }
    return resultado/qtdItensSomados;
}

void printResultado(double resultado) {
    printf("%.1lf\n", resultado);
}
