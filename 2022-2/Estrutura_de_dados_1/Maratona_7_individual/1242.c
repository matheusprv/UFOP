#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char rna[300];
    int n;
}RNAA;

bool verifica(char c1, char c2){
    if(c1 == 'B' && c2 == 'S')  return true;
    if(c1 == 'S' && c2 == 'B')  return true;

    if(c1 == 'C' && c2 == 'F')  return true;
    if(c1 == 'F' && c2 == 'C')  return true;
    return false;
}

void removeItem(RNAA * rnaa, int remover){
    for(int i = remover; i < rnaa->n; i++){
        rnaa->rna[i] = rnaa->rna[i+1];
    }
    rnaa->n-=1;
}

int main(){

    RNAA rnaa;
    rnaa.n = 0;

    while(scanf("%s", rnaa.rna) != EOF){
        rnaa.n = strlen(rnaa.rna);
        int soma = 0;

        //Verifica se as bases são as mesmas e se forem, remove-as e volta o contador do i em 2
        for(int i = 0; i < rnaa.n-1; i++){
            //if(i<0) i = 0;
            //printf("I: %d\n", i);
            if(verifica(rnaa.rna[i+1], rnaa.rna[i])){
                soma++;
                removeItem(&rnaa, i);
                removeItem(&rnaa, i);
                i-=2;
            }
        }

        rnaa.n = 0;
        
        printf("%d\n", soma);
    }

    return 0;
}