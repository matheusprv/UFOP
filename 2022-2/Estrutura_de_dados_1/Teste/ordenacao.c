#include <stdio.h>
#include <stdlib.h>

void quicksort(int * v, int comeco, int fim){

    int l = comeco;
    int r = fim;
    int pivo = v[(l+r)/2];

    while(l<=r){
        while(v[l] < pivo) l++;
        while(v[r] > pivo) r--;

        if(l <= r){

            int aux = v[l];
            v[l] = v[r];
            v[r] = aux;

            l++;
            r--;
        }
    }

    if(r > comeco) quicksort(v, comeco, r);
    if(l < fim) quicksort(v, l, fim);
}


void selectionSort(int * v, int n){
    
    int menor_valor_pos;
    for(int i = 0; i < n-1; i++){
        
        menor_valor_pos = i;
        
        for(int j = i+1; j < n; j++){
        
            if(v[j] < v[menor_valor_pos]){
                menor_valor_pos = j;
            }
        
        }

        int aux = v[i];
        v[i] = v[menor_valor_pos];
        v[menor_valor_pos] = aux;

    }
}

void insertionSort(int *v, int n){
    for(int i = 1; i<n; i++){
        
        int aux = v[i];
        int j;
        for(j = i-1; j >=0 && aux < v[j]; j--){
            v[j+1] = v[j];
        }
        v[j+1] = aux;
    }
}

void bubbleSort(int * v, int n){

    for(int i = 0; i < n-1; i++){

        for(int j = 1; j < n - i; j++){

            if(v[j-1] > v[j]){
                int aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }

        }

    }
}

int main(){
    int vetor [] = {1,8,6,9,7,5,3,10,15,18};

    //quicksort(vetor, 0, 9);
    // selectionSort(vetor, 10);
    // insertionSort(vetor, 10);
    bubbleSort(vetor, 10);

    for(int i =0; i < 10; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}