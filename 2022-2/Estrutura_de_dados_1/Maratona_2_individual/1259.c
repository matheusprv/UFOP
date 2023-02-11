#include <stdio.h>
#include <stdlib.h>

void merge(int* v, int l, int m, int r) {
    int size_l = m - l + 1;
    int size_r = r - m;
    int vet_l[size_l];
    int vet_r[size_r];
    int i, j, k;
    for (i = 0; i < size_l; i++) {
        vet_l[i] = v[i + l];
    }
    for (j = 0; j < size_r; j++) {
        vet_r[j] = v[m + j + 1];
    }
    i = 0;
    j = 0;
    for (k = l; k <= r; k++) {
        if (i == size_l) {
            v[k] = vet_r[j++];
        } else if (j == size_r) {
            v[k] = vet_l[i++];
        } else if (vet_l[i] <= vet_r[j]) {
            v[k] = vet_l[i++];
        } else {
            v[k] = vet_r[j++];
        }
    }
}


void mergeSort(int * v, int l, int r){
    int m;

    if(l<r){
        m = (l+r)/2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}

int main(){

    int qtd;
    scanf("%d", &qtd);
    
    int * pares = malloc(qtd * sizeof(pares));
    int * impares = malloc(qtd * sizeof(impares));

    int qtdPares = 0;
    int qtdImpares = 0;

    int numAtual;

    for(int cont = 0; cont < qtd; cont++){
        scanf("%d", &numAtual);
        
        if(numAtual % 2 == 0){
            pares[qtdPares] = numAtual;
            qtdPares += 1;
        }
        else{
            impares[qtdImpares] = numAtual;
            qtdImpares += 1;
        }
    }

    mergeSort(pares, 0, qtdPares-1);
    mergeSort(impares, 0, qtdImpares-1);

    for(int i = 0; i < qtdPares; i++){
        printf("%d\n", pares[i]);
    }
    for(int i = qtdImpares-1; i >= 0; i--){
        printf("%d\n", impares[i]);
    }

    free(pares);
    free(impares);

    return 0;
}