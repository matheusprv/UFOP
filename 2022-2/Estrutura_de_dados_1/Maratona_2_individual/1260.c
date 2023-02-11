#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 32

typedef struct{
    char arvore[MAX_NOME];
    int tamString;
    int qtdIguais;
}Arvore;


void trocaPosicao(Arvore* arvores, int * i, int * j){
    Arvore auxiliar;

    auxiliar = arvores[*i];
    arvores[*i] = arvores[*j];
    arvores[*j] = auxiliar;
    *i += 1;
    *j -= 1;

}


void quicksort(Arvore * Arvores, int inicio, int fim){
    int i, j;
    Arvore pivo; 

    i = inicio;
    j = fim;
    pivo = Arvores[(inicio + fim) / 2];

    while (i <= j){
        while (strcmp(Arvores[i].arvore, pivo.arvore) < 0 && i < fim)
            i++;
        
        while (strcmp(Arvores[j].arvore, pivo.arvore) > 0 && j > inicio)
            j--;

        if (i <= j)
            trocaPosicao(Arvores, &i, &j);
    }

    if (j > inicio)
        quicksort(Arvores, inicio, j);

    if (i < fim)
        quicksort(Arvores, i, fim);
}


int main(){

    int qtdCasosDeTeste;
    scanf("%d", &qtdCasosDeTeste);
    getchar();getchar();

    for(int contador = 0; contador < qtdCasosDeTeste; contador++){
        
        Arvore * arvores = malloc(1000000 * sizeof(Arvore));
        int qtdArvores = -1;
        char leitura[MAX_NOME];

        //Lendo todas as árvores
        do{
            leitura[0] = '\0'; 
            fgets(leitura, MAX_NOME, stdin);
            int tamString = strlen(leitura);

            if(leitura[tamString - 1] == '\n'){
                leitura[tamString - 1] = '\0';
                tamString--;
            }

            qtdArvores++;
            arvores[qtdArvores].tamString = tamString;
            strcpy(arvores[qtdArvores].arvore, leitura);

        }while(leitura[0] != '\0');

        //Ordenando
        quicksort(arvores, 0, qtdArvores-1);


        /*for(int i = 0; i<qtdArvores; i++){
            printf("%s\n", arvores[i].arvore);
        }*/

        int repeticoes;
        for(int i = 0; i<qtdArvores; i++){
            repeticoes = 1;

            int j;
            for(j = i + 1; j<qtdArvores && strcmp(arvores[i].arvore, arvores[j].arvore) == 0 ;j++)
                repeticoes++;

            printf("%s %.4lf\n", arvores[i].arvore, ((double) repeticoes/qtdArvores) * 100.0000 );

            i = j-1;
        }

        if(contador != qtdCasosDeTeste-1)
            printf("\n");

        free(arvores);

    }
    
    return 0;
}
