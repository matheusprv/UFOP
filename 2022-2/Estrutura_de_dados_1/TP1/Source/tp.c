//Felipe Braz Marques - Matheus Peixoto Ribeiro Vieira - Pedro Henrique Rabelo Leao de Oliveira
#include "automato.h"
//#include <time.h>

int main(){
    //clock_t begin = clock();

    AutomatoCelular automato;

    scanf("%d", &automato.dimensoes);

    alocarReticulado(&automato.reticulado, automato.dimensoes);

    preencherReticulado(&automato);

    evoluirReticulado(&automato);

    imprimeReticulado(automato);

    desalocarReticulado(&automato.reticulado, automato.dimensoes);

    /*clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %lf segundos\n", time_spent);*/

    return 0;
}