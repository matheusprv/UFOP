#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 32

typedef struct{
    char arvore[MAX_NOME];
}Arvore;

int main(){

    int qtdCasosDeTeste;
    scanf("%d", &qtdCasosDeTeste);
    getchar();
    
    Arvore * arvores = malloc (1000000 * sizeof(Arvore));
    char leitura[32];
    int tamanhoString;
    
    for(int contador = 0; contador<qtdCasosDeTeste; contador++){
        fgets(leitura, MAX_NOME, stdin);
        tamanhoString = strlen(leitura);
        leitura[tamanhoString-1] = '\0';
        tamanhoString--;
        
        if(!strcmp(leitura, "")){
            continue;
        }
        

        
    }


    free(arvores);
    return 0;
}
