#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char palavra[52];
    int tamPalavra;
}Palavra;

void quicksort(Palavra *p, int start, int end){

    int l = start;
    int r = end;
    Palavra pivot = p[(l+r)/2];

    while(l<=r){

        while(p[l].tamPalavra > pivot.tamPalavra ) l++;
        while(p[r].tamPalavra < pivot.tamPalavra ) r--;

        if(l<=r){
            Palavra aux = p[l];
            p[l] = p[r];
            p[r] = aux;
            l++;
            r--;
        }

    }

    if(r > start) quicksort(p, start, r);
    if(l < end) quicksort(p, l, end);
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

    char palavra[52];
    int tamPalavra;
    for(int cont=0; cont<casos_de_teste; cont++){
        
        fgets(palavra, 52, stdin);
        tamPalavra = strlen(palavra);
        palavra[tamPalavra-1] = '\0';
        tamPalavra--;

        //Verifica a quantidade de espaços a string e, conqsequentemente, a quantidade de palavras
        int qtdEspacos = 1;
        for(int i=0; i<tamPalavra; i++){
            if(palavra[i]==' ')
                qtdEspacos++;
        }


        Palavra* palavras = malloc(qtdEspacos  * sizeof(Palavra));

        char * token = strtok(palavra, " ");

        //Copiando as palavras para o vetor
        int i = 0;
        while(token != NULL){
            strcpy(palavras[i].palavra, token);
            palavras[i].tamPalavra = strlen(palavras[i].palavra);
            token = strtok(NULL, " ");
            i++;
        }

        Palavra* palavrasOriginal = malloc(qtdEspacos  * sizeof(Palavra));
        copiaVetor(qtdEspacos, palavras, palavrasOriginal);

        quicksort(palavras, 0, qtdEspacos-1);

        for(int i=1; i<qtdEspacos; i++){
            if(palavras[i].tamPalavra == palavras[i-1].tamPalavra){
                //Verificando quantas palavras com o mesmo tamanho
                int mesmoTamanho = 0;
                for(int j = 0; j < qtdEspacos; j++){
                    
                }
            }
            else{
                printf("%s ", palavras[i].palavra);
            }
            
        }
        printf("\n");

        free(palavras);
        free(palavrasOriginal);

    }

    return 0;
}