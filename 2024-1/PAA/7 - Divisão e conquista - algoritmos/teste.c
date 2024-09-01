#include <stdio.h>
#include <limits.h>

void minMax(int A[], int esq, int dir, int *maior, int *menor){
    if (esq == dir) return;

    int meio = (esq + dir)/2;
    printf("Esq: %d - Dir: %d - Meio: %d\n", esq, dir, meio);

    if (A[meio] > *maior)
        *maior = A[meio];
    if (A[meio] < *menor)
        *menor = A[meio];


    minMax(A, esq, meio, maior, menor);
    minMax(A, meio+1, dir, maior, menor);
}

void encontrarMinMax(int A[], int n, int *maior, int *menor){
    *maior = INT_MIN;
    *menor = INT_MAX;

    minMax(A, 0, n-1, maior, menor);
}


int encontrarMaximo(int A[], int esq, int dir){
    if (esq == dir) return A[esq];

    int meio = (esq + dir) / 2;

    int proc_esq = encontrarMaximo(A, esq, meio);
    int proc_dir = encontrarMaximo(A, meio+1, dir);

    int maior = A[meio];
    if(maior < proc_esq)
        maior = proc_esq;
    if(maior < proc_dir)
        maior = proc_dir;

    return maior;

}


int main(){
    int A[] = {1,2,349,4,5,6,7,8,9,10,9,8,7,6,5,4,3,200,1};
    int n = 19;

    int maior = encontrarMaximo(A, 0, n-1);
    printf("maior: %d\n", maior);

    // int maior, menor;

    // encontrarMinMax(A, n, &maior, &menor);

    // printf("Maior: %d - Menor: %d\n", maior, menor);

}