#include <stdio.h>
#include <stdlib.h>


int main(){

    int casos_de_teste;
    scanf("%d", &casos_de_teste);

    for(int cont = 0; cont < casos_de_teste; cont++){
        
        int qtdVagoes;
        scanf("%d", &qtdVagoes);

        int * ordemVagoes = malloc(qtdVagoes * sizeof(int));

        for(int i = 0; i < qtdVagoes; i++)
            scanf("%d", &ordemVagoes[i]);

        int qtdTrocas = 0;
        for(int i = 0; i<qtdVagoes; i++){
            int troca = 0;
            for(int j = 1; j < qtdVagoes-i; j++){
                if(ordemVagoes[j] < ordemVagoes[j-1]){

                    int aux = ordemVagoes[j];
                    ordemVagoes[j] = ordemVagoes[j-1];
                    ordemVagoes[j-1] = aux;

                    troca++;
                    qtdTrocas++;
                }
            }
            if(troca == 0)
                break;
        }

        printf("Optimal train swapping takes %d swaps.\n", qtdTrocas);

        free(ordemVagoes);

    }

    return 0;
}