#include <stdio.h>
#include <stdlib.h>

void exibeQuestoes(){
    printf("      QUESTÕES\n      ");

    for(int i = 1; i<=10; i++){
        printf("%-3d", i);
    }
    printf("\n");
    for(int i = 0; i< 36; i++){
        printf("=");
    }
    printf("\n");
}

int main(){
    printf("\n\n");

    int qtdRespostas;
    scanf("%d", &qtdRespostas);

    int ** respostas = (int **)malloc(qtdRespostas*sizeof(int*));
    
    for(int i = 0; i < qtdRespostas; i++){
        respostas[i] = (int *) malloc(10 * sizeof(int));
    }

    float somaTotal = 0;

    exibeQuestoes();

    for(int i = 0; i < qtdRespostas; i++){
        printf("%-3d | ", i+1);
        for(int j = 0; j < 10; j++){
            scanf("%d", &respostas[i][j]);

            printf("%-3d", respostas[i][j]);

            if((j+1) % 2 == 1){
                respostas[i][j]--;
            }
            else{
                respostas[i][j] = 5 - respostas[i][j];
            }

            somaTotal += respostas[i][j];
        }
        printf("\n");
    }

    somaTotal /= qtdRespostas;

    somaTotal*= 2.5;

    printf("\nResultado final: %f\n", somaTotal);

    for(int i = 0; i < qtdRespostas; i++){
        free(respostas[i]);
    }
    free(respostas);


    printf("\n\n");
    return 0;
}