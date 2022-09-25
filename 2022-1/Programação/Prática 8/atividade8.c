#include <stdio.h>
#include <string.h>

#define TAM_MAX 101

void censurar(char texto[], int tamanhotexto){
    for(int i=0; i<tamanhotexto; i++){
        switch(texto[i]){
            case 'a':
                texto[i] = '@';
                break;
            case 'e':
                texto[i]= '_';
                break;
            case 'i':
                texto[i] = '|';
                break;
            case 'o':
                texto[i] = '0';
                break;
            case 'u':
                texto[i] = '#';
                break;
            case 's':
                texto[i] = '$';
                break;                                                                
        }
    }
}

int main(){

    char texto[TAM_MAX];
    printf("Digite o texto para censurar: ");
    fgets(texto, TAM_MAX, stdin);

    texto[strlen(texto)-1] = '\0';
    int tamanhoTexto = strlen(texto);

    censurar(texto, tamanhoTexto);

    printf("%s\n", texto);

    return 0;
}