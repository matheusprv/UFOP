#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(char * n1, char* n2){
    char aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}


int selectionSort(char arr[], int n) {
    int i, j, min_idx;

    int swaps = 0;

    for (i = 0; i < n; i++) {
        min_idx = i;

        for (j = i+1; j < n; j++) {
            if (arr[j] <  arr[min_idx]) 
                min_idx = j;
        }

        if(i != min_idx){
            troca(&arr[i], &arr[min_idx]);
            swaps++;
        }

        if(swaps > 1){
            return 0;
        }

    }

    return 1;
}

int main(){

    int n, qtdCaracteres;
    scanf("%d", &n);

    for(int cont = 0; cont < n; cont ++){
        scanf("%d", &qtdCaracteres);
        getchar();
        char * letrasDadas = malloc(qtdCaracteres * sizeof(char));

        for(int i = 0; i < qtdCaracteres; i++)
            scanf("%c", &letrasDadas[i]);
        
        int ha_chances = selectionSort(letrasDadas, qtdCaracteres);
        
        if(ha_chances){
            printf("There are the chance.\n");
        }
        else{
            printf("There aren't the chance.\n");
        }

        free(letrasDadas);
    }

    return 0;
}