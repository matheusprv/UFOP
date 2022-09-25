#include <stdio.h>

int main(){

    int vetor[15];
    int n;
    printf("Entre com os 15 valores: ");
    for (int i = 0; i < 15; i++){
        scanf("%d", &vetor[i]);
    }
    printf("Entre com o valor de n: ");
    scanf("%d", &n);


    for(int i=0; i<n; i++){
        int auxPrimeiraPosicao = vetor[0];
        for(int i=0; i<14;i++){
            vetor[i]=vetor[i+1];
        }
        vetor[14] = auxPrimeiraPosicao;
    }

    for(int i=0; i < 15; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}