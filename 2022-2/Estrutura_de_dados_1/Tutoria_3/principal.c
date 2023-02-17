#include <stdio.h>
#include "ordenacao.h"

int main(){
    TADupa * upas;

    int qtdUpas;
    scanf("%d", &qtdUpas);

    if(!alocarUpa(&upas, qtdUpas))
        return 0;

    preencheVetor(upas, qtdUpas);

    ordenaUpas(upas, qtdUpas);

    imprimeUpas(upas, qtdUpas);

    desalocaUpas(&upas);

    return 0;

}

