#include <stdio.h>
#include "ordenacao.h"

int main(){
    TADupa *upas;
    int n;

    //lendo a quantidade de upas
    scanf("%d", &n);

    //alocando memoria para o vetor de upas
    alocarUpa(&upas, n);

    //preenchendo o vetor de upas
    preencheVetor(upas, n);

    //ordenando o vetor de upas
    ordenaUpas(upas, n);

    //imprimindo as upas
    imprimeUpas(upas, n);

    desalocaUpas(&upas);

    return 0;
}

