#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string[1002];
    int qtdParentesesAberto;
    int qtdParentesesFechado;
    int tamanhoString; 

    while(scanf("%s", string) != EOF){
        qtdParentesesAberto = 0;
        qtdParentesesFechado = 0;

        tamanhoString = strlen(string);

        for(int i=0; i<tamanhoString; i++){
            if(string[i] == '(')
                qtdParentesesAberto++;
            
            else if(string[i] == ')')
                qtdParentesesFechado++;


            //Implica que um parentesis foi fechado antes de ser aberto, o que gerará um erro
            if(qtdParentesesFechado > qtdParentesesAberto){
                break;
            }
            
        }

        if(qtdParentesesAberto != qtdParentesesFechado){
            printf("incorrect\n");
        }
        else{
            printf("correct\n");
        }

    }

    return 0;
}