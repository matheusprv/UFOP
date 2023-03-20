#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
    int poder;
    int matados;
    int morridos;
    char nome[101];
}Deuses;

int compara(Deuses d1, Deuses d2){

    if(d1.poder > d2.poder)
        return 1;

    if(d1.poder < d2.poder)
        return 0;

    if(d1.matados >  d2.matados)
        return 1;
    if(d1.matados <  d2.matados)
        return 0;

    if(d1.morridos < d2.morridos)
        return 1;
    if(d1.morridos > d2.morridos)
        return 0;
    
    if(strcmp(d1.nome, d2.nome) < 0)
        return 1;
    
    return 0;

}

void merge(Deuses *v, int l, int m, int r){
    int size_l = (m-l+1);
    int size_r = (r-m);

    Deuses *vet_l = malloc(size_l * sizeof(Deuses));
    Deuses *vet_r = malloc(size_r * sizeof(Deuses));
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

        else if(compara(vet_l[i], vet_r[j]))
            v[k] = vet_l[i++];

        else
            v[k] = vet_r[j++];
    }
    
    free(vet_l);
    free(vet_r);
}

void mergeSort(Deuses *v, int l, int r){
    int m;
    
    if(l<r){
        m = (l+r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d\n", &n);
    Deuses *deuses = (Deuses *) malloc(n * sizeof(Deuses));
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d\n", deuses[i].nome, &deuses[i].poder, &deuses[i].matados, &deuses[i].morridos);
    }
    mergeSort(deuses, 0, n-1);
    printf("%s\n", deuses[0].nome);
    free(deuses);
    return 0;
}