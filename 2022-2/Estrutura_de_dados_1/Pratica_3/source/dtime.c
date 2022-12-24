#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dtime.h"

typedef enum { NAO=0, SIM } ESCALADO;

struct duende {
    char nome[20];
    int idade;
    ESCALADO escalado;
};

struct time {
    Duende* lider;
    Duende* piloto;
    Duende* entregador;
};


// Manter como especificado
Time *alocaTimes(int n) {
    Time* times = malloc(n * sizeof(Time));
    for(int i=0; i<n;i++){
        times[i].entregador = malloc(sizeof(Duende));
        times[i].lider = malloc(sizeof(Duende));
        times[i].piloto = malloc(sizeof(Duende));
    }
    return times;
}

// Manter como especificado
void desalocaTimes(Time **times, int n) {
    for(int i=0; i<n; i++){
        desalocaDuendes(&(*times)[i].lider);
        desalocaDuendes(&(*times)[i].piloto);
        desalocaDuendes(&(*times)[i].entregador);
    }
    free(*times);
}

//Manter como especificado
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes) {
    int i, index;
    int qtdTime = qtdDuendes/3;
    
    // Escalando os lideres
    for (i=0; i<qtdTime; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].lider->nome, duendes[index].nome);
        times[i].lider->idade = duendes[index].idade;
    }

    // Escalando os pilotos
    for (i=0; i<qtdTime; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].piloto->nome, duendes[index].nome);
        times[i].piloto->idade = duendes[index].idade;
    }

    // Escalando os entregadores
    for (i=0; i<qtdTime; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].entregador->nome, duendes[index].nome);
        times[i].entregador->idade = duendes[index].idade;
    }
}

// Manter como especificado
void printTimes(Time *times, int qtd){
    for (int i=0; i<qtd; i++) {
        printf("Time %d\n", i+1);
        printf("[L] ");
        printDuende(times[i].lider);
        printf("[P] ");
        printDuende(times[i].piloto);
        printf("[E] ");
        printDuende(times[i].entregador);
        printf("\n");
    }
}
