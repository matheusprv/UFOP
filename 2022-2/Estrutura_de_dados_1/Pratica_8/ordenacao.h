# ifndef ordenacao_h
# define ordenacao_h

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    // preencher com os dados de cada time
    int identificador;
    int pontos;
    int cestasFeitas;
    int cestasLevadas;
    float saldoDeCestas; // ((float)cestasFeitas)/cestasLevadas
} Time;

void heap_refaz(Time * vetor, int esquerda, int direita);

// Manter como especificado
void ordenacao(Time *vetor, int n);

// Manter como especificado
Time *alocaVetor(int n);

// Manter como especificado
void desalocaVetor(Time **vetor);

// faz a comparacao utilizada para ordenar os times
int compare(Time t1, Time t2);

void preencherDados(int time1, int pontos1, int time2, int pontos2, Time * times);

void calcularSaldoCesta(Time * vetor, int n);

void imprimerResultados(int instancia, Time * times, int qtdTimes);

# endif
