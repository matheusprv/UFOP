#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[21];
    int validade;
}Carne;


void quicksort(Carne * carnes, int start, int end){
    int l = start;
    int r = end;

    Carne pivo = carnes[(l+r)/2];

    while(l<r){
        while(carnes[l].validade < pivo.validade ) l++;
        while(carnes[r].validade > pivo.validade ) r--;

        if(l<=r){
            Carne aux = carnes[l];
            carnes[l] = carnes[r];
            carnes[r] = aux;
            l++;
            r--;
        }
    }

    if(r>start) quicksort(carnes, start, r);
    if(l<end) quicksort(carnes, l, end);
}


int main(){

    int casos_de_teste;
    while(scanf("%d",&casos_de_teste) != EOF){

        Carne * carnes = (Carne *) malloc(sizeof(Carne)*casos_de_teste);

        for(int i = 0; i < casos_de_teste; i++){
            scanf("%s",carnes[i].nome);
            scanf("%d", &carnes[i].validade);
        }

        quicksort(carnes, 0, casos_de_teste-1);

        for(int i = 0; i < casos_de_teste; i++){
            printf("%s", carnes[i].nome);
            if(i != casos_de_teste-1)
                printf(" ");
        }
        printf("\n");
            

        free(carnes);
    }

    return 0;
}