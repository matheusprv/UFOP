#include "ordenacao_linear.h"

#include <stdio.h>
#include <stdlib.h>

// Manter como especificado
int char2int(char c) {
    /* Funcao auxiliar para converter um char em um inteiro */
    return (int) (c - '0');
}

// Manter como especificado
void le(Paciente* pacientes, int n) {
    // PREENCHER AQUI
    for(int i = 0; i < n; i++){
        scanf("%s", pacientes[i].senha);
        scanf("%s", pacientes[i].nome);
    }
}

// Manter como especificado
void imprime(Paciente* pacientes, int n){
    // PREENCHER AQUI
    for(int i = 0; i < n; i++){
        printf("%s %s\n", pacientes[i].senha, pacientes[i].nome);
    }
}


// Manter como especificado
void coutingSort(Paciente* A, Paciente* B, int n, int i) {
    // PREENCHER AQUI
    /*
     * A = vetor a ser ordenado
     * B = vetor auxiliar para armazenar o vetor A ordenado
     * n = tamanho do vetor A
     * i = digito a ser usado na ordenacao
     */
    
    int k = 10;

    int * C = calloc(k, sizeof(int));

    for(int j = 0; j < n; j++)
        C[char2int(A[j].senha[i])]++;

    for(int cont = 1; cont < k; cont++)
        C[cont] += C[cont-1];

    for(int j = n-1; j >= 0; j--){
        B[C[ char2int(A[j].senha[i]) ] - 1] = A[j];
        C[ char2int(A[j].senha[i]) ] --;
    }

    for(int cont = 0; cont < n; cont++)
        A[cont] = B[cont];

    free(C);

}

// Manter como especificado
void radixSort(Paciente* pacientes, int n, int m) {
    // Vetor auxiliar a ser usado no couting sort
    Paciente B[MAX_N];
    /*
     * pacientes = vetor a ser ordenado
     * n = tamanho do vetor A
     * m = quantidade de digitos
     */
    for(int i = m-1; i >=0 ; i--)
        coutingSort(pacientes, B, n, i);
        
}
