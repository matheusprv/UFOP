#include "busca.h"

void merge(int *vetor, int l, int m, int r){
    int size_l = (m - l + 1);
    int size_r = (r - m);

    int *vet_l = malloc(size_l * sizeof(int));
    int *vet_r = malloc(size_r * sizeof(int));
    int i, j;

    for (i = 0; i < size_l; i++)
        vet_l[i] = vetor[i + l];

    for (j = 0; j < size_r; j++)
        vet_r[j] = vetor[m + j + 1];

    i = 0;
    j = 0;

    for (int k = l; k <= r; k++)
    {
        if (i == size_l)
            vetor[k] = vet_r[j++];

        else if (j == size_r)
            vetor[k] = vet_l[i++];

        else if (vet_l[i] <= vet_r[j])
            vetor[k] = vet_l[i++];

        else
            vetor[k] = vet_r[j++];
    }

    free(vet_l);
    free(vet_r);
}

void mergeSort(int *vetor, int l, int r){
    int m;

    if (l < r){
        m = (l + r) / 2;
        mergeSort(vetor, l, m);
        mergeSort(vetor, m + 1, r);
        merge(vetor, l, m, r);
    }
}

int pesquisaBinaria(int *vetor, int esq, int dir, int pesquisa){
    int meio = (esq + dir) / 2;

    if (vetor[meio] != pesquisa && esq == dir)
        return -1;
    else if (pesquisa > vetor[meio])
        return pesquisaBinaria(vetor, meio + 1, dir, pesquisa);
    else if (pesquisa < vetor[meio])
        return pesquisaBinaria(vetor, esq, meio - 1, pesquisa);
    else
        return meio;
}