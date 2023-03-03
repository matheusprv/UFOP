#include "ordenacao.h"

void quicksort(char * palavra, int comeco, int fim){
    int i, j;
    char pivo; 

    i = comeco;
    j = fim;
    pivo = palavra[(comeco + fim) / 2];

    while (i <= j){
        while (palavra[i] < pivo && i < fim)
            i++;
        
        while (palavra[j] > pivo && j > comeco)
            j--;

        if (i <= j){
            char aux = palavra[i];
            palavra[i] = palavra[j];
            palavra[j] = aux;
            i++;
            j--;
        }
    }

    if (j > comeco)
        quicksort(palavra, comeco, j);

    if (i < fim)
        quicksort(palavra, i, fim);
}

void ordenaPalavra(char * palavra){
    quicksort(palavra, 0, strlen(palavra) - 1);
}

int verificaOrdemAlfabetica(char * palavra, char * palavraOriginal){
    
    //printf("  Palavra: %s   ", palavra);

    if(strcmp(palavra, palavraOriginal) == 0){

        //Procurar duplicatas
        int size = strlen(palavra);

        for(int i = 0; i < size - 1; i++){
            if(palavra[i] == palavra[i+1])
                return 0;
        }

        return 1;

    }
    return 0;
}

void caixaBaixa(char* palavra){
    int tamanhoPalavra = strlen(palavra);
    
    for(int i = 0; i < tamanhoPalavra; i++){
        if(palavra[i] < 'a')
            palavra[i] += 32;
    }
}