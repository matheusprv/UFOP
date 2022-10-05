#include <stdio.h>
#include <stdlib.h>

int main(){

    char operacao;
    int n;
    int **matriz;

    printf("Digite a operação (S)Soma ou (M)Média: ");
    scanf("%c", &operacao);
    
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);

    matriz = malloc(n*sizeof(int*));


    printf("Digite os valores da matriz: ");
    for(int i=0; i<n;i++){
        matriz[i] = malloc(n*sizeof(int));

        for(int j=0; j<n;j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    int somatorio = 0;
    int quantidade =0;
    for(int i=0; i<n;i++){
        for(int j=0; j<i; j++){
            somatorio+=matriz[i][j];
            quantidade++;
        }
    }

    printf("%.0f\n", operacao == 'S' ? somatorio : somatorio/(float)quantidade);

    return 0;
}