#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int x;
    int y;
}Ponto;

typedef struct{
    Ponto centro;
    double raio;
}Circunferencia;

int main(){

    int repeticoes;
    printf("Digite a quantidade de circunferências: ");
    scanf("%d", &repeticoes);
    
    Circunferencia *circunferencias = (Circunferencia *) malloc(repeticoes *sizeof(Circunferencia));
    
    FILE * arquivo = fopen("circulos.txt", "r");

    //Pegando a primeira circunferência para ser considerada a maior
    fscanf(arquivo, "%d %d %lf", &circunferencias[0].centro.x, &circunferencias[0].centro.y, &circunferencias[0].raio);
    
    Circunferencia maior = circunferencias[0];
    int indiceMaiorCirc = 0;

    for(int i=1; i<repeticoes; i++){
        fscanf(arquivo, "%d %d %lf", &circunferencias[i].centro.x, &circunferencias[i].centro.y, &circunferencias[i].raio);
        if(circunferencias[i].raio > maior.raio){
            maior = circunferencias[i];
            indiceMaiorCirc = i;
        }
    }

    printf("Maior circunferência: C%d\n", indiceMaiorCirc+1);
    printf("Coordenadas:\n\tX = %d\n\tY = %d\n", circunferencias[indiceMaiorCirc].centro.x, circunferencias[indiceMaiorCirc].centro.y);

    //Verificando quantas circunferencias estão inscritas nela
    int qtdCircunferenciasInscritas = 0;
    for(int i=0; i<repeticoes; i++){
        int distCentro = sqrt(pow(maior.centro.x - circunferencias[i].centro.x, 2) + pow(maior.centro.y - circunferencias[i].centro.y, 2));
        int difRaios = maior.raio - circunferencias[i].raio;

        if(distCentro < difRaios)
            qtdCircunferenciasInscritas++;    
    }

    printf("Quantidade de circunferencias inscritas: %d circunferencias\n", qtdCircunferenciasInscritas);

    fclose(arquivo);
    free(circunferencias);

    return 0;
}