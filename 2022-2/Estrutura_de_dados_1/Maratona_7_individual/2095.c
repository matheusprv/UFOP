#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int poder;
    int vivo;
}Guerra;

void merge(Guerra *v, int l, int m, int r){
    int size_l = (m-l+1);
    int size_r = (r-m);

    Guerra *vet_l = malloc(size_l * sizeof(Guerra));
    Guerra *vet_r = malloc(size_r * sizeof(Guerra));
    int i, j;

    for (i = 0; i < size_l; i++)
        vet_l[i] = v[i + l];

    for(j = 0; j < size_r; j++)
        vet_r[j] = v[m + j + 1];
    
    i = 0;
    j = 0;

    for (int k = l; k <= r; k++){
        if(i == size_l)
            v[k] = vet_r[j++];

        else if(j == size_r)
            v[k] = vet_l[i++];

        else if(vet_l[i].poder > vet_r[j].poder)
            v[k] = vet_l[i++];

        else
            v[k] = vet_r[j++];
    }
    
    free(vet_l);
    free(vet_r);
}

void mergeSort(Guerra *v, int l, int r){
    int m;
    
    if(l<r){
        m = (l+r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}
int main(){

    int n;
    scanf("%d", &n);

    Guerra * quadradonia = malloc(sizeof(Guerra) * n);
    Guerra * noglonia = malloc(sizeof(Guerra) * n);

    //Lendo do pais Q
    for(int i = 0; i<n; i++){
        scanf("%d", &quadradonia[i].poder);
        quadradonia[i].vivo = 1;
    }

    //Lendo do pais n
    for(int i = 0; i<n; i++){
        scanf("%d", &noglonia[i].poder);
        noglonia[i].vivo = 1;
    }

    mergeSort(noglonia, 0, n-1);
    mergeSort(quadradonia, 0, n-1);

    int qtdVitorias = 0;
    int i = 0;
    for(int j = 0; j < n; j++){
        if(noglonia[i].poder > quadradonia[j].poder){
            qtdVitorias++;
            i++;
        }
    }

    printf("%d\n", qtdVitorias);


    return 0;
}