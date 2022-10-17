#include <stdio.h>
#include <string.h>
#define TAM_MAX 16

int main(){

    char palavra[TAM_MAX];

    printf("Digite uma palavra ou FIM para sair: ");
    fgets(palavra, TAM_MAX, stdin);
    palavra[strlen(palavra)-1] = '\0';
    int tamanhoPalavra = strlen(palavra);

    while(strcmp(palavra, "FIM")){
        char palavraInvertida[TAM_MAX];
        
        int cont = 0;
        for(int i=tamanhoPalavra-1; i>=0; i--){
            palavraInvertida[cont] = palavra[i];
            cont++;
        }
        //Caso a palavra antiga seja maior do que a nova, os caracteres ainda ficarão na string, prejudicando a verificação
        palavraInvertida[tamanhoPalavra] = '\0';

        if(!strcmp(palavra, palavraInvertida)){
            printf("%s é um palíndromo\n", palavra);
        }
        else{
            printf("%s não é um palíndromo\n", palavra);
        }
        
        printf("Digite uma palavra ou FIM para sair: ");
        fgets(palavra, TAM_MAX, stdin);
        palavra[strlen(palavra)-1] = '\0';//Removendo o \n
        tamanhoPalavra = strlen(palavra);
        
    }

    return 0;
}