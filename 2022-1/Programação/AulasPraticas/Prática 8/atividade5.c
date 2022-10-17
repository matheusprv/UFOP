#include <stdio.h>
#include <string.h>
#define TAM_MAX 10

void lerMatriz(int[TAM_MAX][TAM_MAX], int, int);

void printarMatriz(int[TAM_MAX][TAM_MAX], int, int);

int main(){

    int matrizA [TAM_MAX][TAM_MAX];
    int matrizB [TAM_MAX][TAM_MAX];
    int matrizProduto [TAM_MAX][TAM_MAX];

    int m, n, p, q;
    //Linhas:  m & q
    //Colunas: p & n

    printf("Entre com os valores de m, p, q, n: ");
    scanf("%d%d%d%d", &m,&p,&q,&n);

    while(m>10 || m<0 || n<0 || n>10 || p<0 || p>10 || q<0 || q>10 || p!=q){
        printf("Valores inválidos!\n");
        printf("Entre com os valores de m, p, q, n: ");
        scanf("%d%d%d%d", &m,&p,&q,&n);
    }

    lerMatriz(matrizA, m, p);
    lerMatriz(matrizB, q, n);
    
    int somatorio = 0;
    
    for(int i=0; i<m;i++){
        for (int j=0; j<n; j++){
            for(int k=0; k<p; k++){
                somatorio += matrizA[i][k] * matrizB[k][j];
            }
            matrizProduto[i][j] = somatorio;
            somatorio = 0;
        }
    }
    printarMatriz(matrizProduto, m, n);

    return 0;
}

void lerMatriz(int matriz[TAM_MAX][TAM_MAX], int x, int y){
    printf("Entre com os elementos da matriz: ");
    for(int i=0; i<x; i++){
        for(int j=0; j<y;j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}
void printarMatriz(int matriz[TAM_MAX][TAM_MAX], int x, int y){
    for(int i=0; i<x;i++){
        for(int j=0; j<y;j++){
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

}
/*
2 3 3 2 1 2 3 4 5 6 7 8 9 10 11 12
*/