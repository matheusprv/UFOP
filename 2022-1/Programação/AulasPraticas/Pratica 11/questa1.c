//Matheus Peixoto Ribeiro vieira - 22.1.4104
#include <stdio.h>
#include <stdlib.h>

void ordenarVetor(int *vetor, int tamanho);

int main(){

    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int *vetor = malloc(n*sizeof(int));
    int somatorio=0;

    printf("Digite os valores do vetor: ");
    for(int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
        somatorio += vetor[i];
    }

    float media = somatorio/(float) n;

    printf("A média é: %.2g\n", media);

    int qtdAbaixoMedia = 0;
    int qtdAcimaDaMedia = 0;

    for(int i=0; i<n; i++){
        if(vetor[i] >= media){
            qtdAcimaDaMedia++;
        }
        else{
            qtdAbaixoMedia++;
        }
    }

    int *acimaMedia = malloc(qtdAcimaDaMedia * sizeof(int));
    int *abaixoMedia = malloc(qtdAbaixoMedia * sizeof(int));
    int indexAbaixo = 0, indexAcima = 0;
    
    for(int i=0; i<n; i++){
        if(vetor[i] >= media){
            acimaMedia[indexAcima] = vetor[i];
            indexAcima++;
        }
        else{
            abaixoMedia[indexAbaixo] = vetor[i];
            indexAbaixo++;
        }
    }

    printf("Vetor com os valores abaixo da média: [ ");
    ordenarVetor(abaixoMedia, indexAbaixo);
    for(int i=0; i<indexAbaixo;i++){
        printf("%d ", abaixoMedia[i]);
    }
    printf("]\n");

    ordenarVetor(acimaMedia, indexAcima);
    printf("Vetor com os valores iguais ou acima da média: [ ");
    for(int i=0; i<indexAcima;i++){
        printf("%d ", acimaMedia[i]);
    }
    printf("]\n");

    free(vetor);
    free(acimaMedia);
    free(abaixoMedia);

    return 0;
}

void ordenarVetor(int *vetor, int tamanho){
    int menor, aux, temp, troca;

    for(aux=0; aux < tamanho-1; aux++) {
        menor = aux; 
        for (temp=aux+1; temp < tamanho; temp++){
            if (vetor[temp] < vetor[menor]){
                menor = temp;
            }
        }

        if (menor != aux){
            troca = vetor[aux];
            vetor[aux] = vetor[menor];
            vetor[menor] = troca;
        }
    }
}