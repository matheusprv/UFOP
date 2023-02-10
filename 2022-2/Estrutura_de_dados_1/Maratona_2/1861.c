#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int qtdCasos = 0;
    
    char ** assassinos = malloc(100000 * sizeof(char*));
    for(int i = 0; i< 100000; i++)
        assassinos[i] = malloc(21 * sizeof(char));

    char ** assassinados = malloc(100000 * sizeof(char*));
    for(int i = 0; i< 100000; i++)
        assassinados[i] = malloc(21 * sizeof(char));    

    while(scanf("%s%s", assassinos[qtdCasos], assassinados[qtdCasos++]));

    realloc(assassinos, qtdCasos);
    realloc(assassinados, qtdCasos);

    for(int i =0; i< qtdCasos; i++){
        
    }

    return 0;
}