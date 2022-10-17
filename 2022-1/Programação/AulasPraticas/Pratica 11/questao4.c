#include <stdio.h>
#include <stdlib.h>

int verificaQuadradoMagico(int **, int);

int main(){

    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int **matriz = malloc(n*sizeof(int *));
    for(int i=0; i<n; i++)
        matriz[i] = malloc(n*sizeof(int));

    printf("Digite os valores da matriz n x n:");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    if(verificaQuadradoMagico(matriz, n)){
        printf("Esta matriz é um quadrado mágico!\n");
    }
    else{
        printf("Esta matriz NÃO é um quadrado mágico!\n");
    }

    for(int i=0; i<n; i++)
        free(matriz[i]);
    free(matriz);

    return 0;
}

int verificaQuadradoMagico(int **matriz, int n){
    int somatorioPrincipal = 0;
    int somatorioControle = 0;
    int somatorioControleColunas = 0;
    int somatorioDiagonalPrincipal = 0;
    int somatorioDiagonalSecundaria = 0;
    
    for(int j=0; j<n; j++){
        somatorioPrincipal += matriz[0][j];
    }

    //Verificando linhas e colunas
    for(int i=0; i<n;i++){

        somatorioControle = 0;
        somatorioControleColunas = 0;

        for(int j=0; j<n;j++){
            somatorioControle += matriz[i][j];
            somatorioControleColunas += matriz[j][i];
        }
        if(somatorioControle != somatorioPrincipal || somatorioControleColunas != somatorioPrincipal){
            return 0;
        }
        somatorioDiagonalPrincipal += matriz[i][i];
        somatorioDiagonalSecundaria += matriz[n-i-1][n-i-1];
    }

    if(somatorioDiagonalPrincipal != somatorioPrincipal || somatorioDiagonalSecundaria != somatorioPrincipal){
        return 0;
    }
    else{
        return 1;
    }
    
}

/*
16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 47

*/