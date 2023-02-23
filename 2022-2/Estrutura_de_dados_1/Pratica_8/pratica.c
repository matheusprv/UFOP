#include "ordenacao.h"
#include <stdio.h>

int main()
{
    int instancia = 0;
    //enquanto houver dados
    while (1) {
        int n;
        int time1, time2, pontos1, pontos2;
        int i, npartidas;
        Time *vetor;

        //leia o numero de times
        scanf("%d", &n);

        //se for zero, o programa acaba
        if(n == 0)
            return 0;
        else
            instancia++;

        //aloque o vetor
        vetor = alocaVetor(n);

        //calcula o numero de partidas
        npartidas = n * (n - 1) / 2;

        //para cada partida...
        for (i = 0; i < npartidas; ++i) {
            scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);

            // preencher o vetor de estruturas de acordo com os dados lidos
            preencherDados(time1, pontos1, time2, pontos2, vetor);

        }

        calcularSaldoCesta(vetor,n);

        /*for(int i =0; i<n;i++){
            printf("TIME: %d\n", vetor[i].identificador);
            printf("\tPontos: %d\n", vetor[i].pontos);
            printf("\tCestas feitas: %d\n", vetor[i].cestasFeitas);
            printf("\tCestas Levadas: %d\n", vetor[i].cestasLevadas);
            printf("\tSaldo cestas: %f\n", vetor[i].saldoDeCestas);
            printf("\tVitórias: %d\n", vetor[i].vitorias);
            printf("\tDerrotas: %d\n", vetor[i].derrotas);
            printf("\n");
        }*/

        // ordenar os times
        ordenacao(vetor, n);

        // imprima o resultado
        imprimerResultados(instancia, vetor, n);

        // desaloque o vetor
        desalocaVetor(&vetor);
    }

    return 0;
}