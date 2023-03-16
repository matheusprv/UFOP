#include "ordenacao_linear.h"

#include <stdio.h>

int main() {
    int n, m;
    Paciente pacientes[MAX_N];

    // Ler os valores de n e m
    scanf("%d %d", &n, &m);
    
    // Ler os dados dos jogadores
    le(pacientes, n);
    
    // Ordenar o vetor com o radixSort
    radixSort(pacientes, n, m);
    
    // Imprimir a resposta
    imprime(pacientes, n);
    
    return 0;
}