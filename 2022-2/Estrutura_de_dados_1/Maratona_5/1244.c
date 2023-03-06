#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char palavra[53];
    int tamPalavra;
}Palavra;

void merge(Palavra *v, int l, int m, int r){
    int size_l = (m-l+1);
    int size_r = (r-m);

    Palavra *vet_l = malloc(size_l * sizeof(Palavra));
    Palavra *vet_r = malloc(size_r * sizeof(Palavra));
    int i, j;

    for (i = 0; i < size_l; i++)
        vet_l[i] = v[i + l];

    for(j = 0; j < size_r; j++)
        vet_r[j] = v[m + j + 1];
    
    i = 0;
    j = 0;

    for (int k = l; k <= r; k++){
        if(i == size_l)
            v[k] = vet_r[j++];

        else if(j == size_r)
            v[k] = vet_l[i++];

        else if(vet_l[i].tamPalavra >= vet_r[j].tamPalavra)
            v[k] = vet_l[i++];

        else
            v[k] = vet_r[j++];
    }
    
    free(vet_l);
    free(vet_r);
}

void mergeSort(Palavra *v, int l, int r){
    int m;
    
    if(l<r){
        m = (l+r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}

void copiaVetor(int tamVetor, Palavra * orginal, Palavra * copy){
    for(int i=0; i<tamVetor; i++){
        copy[i].tamPalavra = orginal[i].tamPalavra;
        strcpy(copy[i].palavra, orginal[i].palavra);
    }
}


int main(){

    int casos_de_teste;
    scanf("%d",&casos_de_teste);
    getchar();

    char palavra[100000];
    int tamPalavra;
    for(int cont=0; cont<casos_de_teste; cont++){
        
        fgets(palavra, 100000, stdin);
        tamPalavra = strlen(palavra);
        if(palavra[tamPalavra-1] == '\n'){
            palavra[tamPalavra-1] = '\0';
            tamPalavra--;
        }

        Palavra* palavras = malloc(50  * sizeof(Palavra));

        char * token = strtok(palavra, " ");

        //Copiando as palavras para o vetor
        int qtdpalavras = 0;
        while(token != NULL){
            strcpy(palavras[qtdpalavras].palavra, token);
            palavras[qtdpalavras].tamPalavra = strlen(palavras[qtdpalavras].palavra);
            token = strtok(NULL, " ");
            qtdpalavras++;
        }

        mergeSort(palavras, 0, qtdpalavras-1);

        for(int i = 0; i < qtdpalavras; i++){

            printf("%s", palavras[i].palavra);
            if(i != qtdpalavras-1 )
                printf(" ");
            
        }
        // if(cont != casos_de_teste -1)
            printf("\n");

        free(palavras);

    }

    return 0;
}