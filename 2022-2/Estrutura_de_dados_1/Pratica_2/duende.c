//Matheus Peixoto Ribeiro Vieira - 22.1.4104
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duende.h"

#define TAM_NOME 22

struct duende { 
    char nome[TAM_NOME];
    int idade;
    ESCALADO escalado;
 };

struct time { 
    char nomeLider[TAM_NOME];
    char nomeConfeiteiro[TAM_NOME];
    char nomeEntregador[TAM_NOME];
    char nomeEmbrulhador[TAM_NOME];

    int idadeLider;
    int idadeConfeiteiro;
    int idadeEntregador;
    int idadeEmbrulhador;
 };

// Manter como especificado
void lerQuantidade(int *qtdDuendes){ 
    scanf("%d", qtdDuendes);
    getchar();
 }

// Manter como especificado
Duende *alocaDuendes(int qtdDuendes){ 
    
    Duende *vetor = malloc(qtdDuendes * sizeof(Duende));
    return vetor;

}

// Manter como especificado
Time *alocaTimes(int qtdTimes){ 
    
    Time *vetor = malloc(qtdTimes * sizeof(Time));
    return vetor;

 }

// Manter como especificado
void desalocaDuendes(Duende **duendes){ 
    
    free(*duendes);

 }

// Manter como especificado
void desalocaTimes(Time **times){ 
    
    free(*times);

}

// Manter como especificado
void lerDuendes(Duende *duendes, int qtdDuendes){ 
    
    for(int i = 0; i<qtdDuendes; i++){
        scanf("%s", duendes[i].nome);
        scanf("%d", &duendes[i].idade);
        getchar();
        duendes[i].escalado = NAO;
    }
    
 }

// Manter como especificado
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes){
    int i, index;
    int qtdTime = qtdDuendes/4;
    // Escalando os lideres
    for (i=0; i<qtdTime; i++) {
        // Bucar o proximo mais velho disponivel
        index = proximoMaisVelho(duendes, qtdDuendes);
        // Marca o duende como escalado
        duendes[index].escalado = SIM;
        // Copiar o nome do duende encontrado como lider de um time
        strcpy(times[i].nomeLider, duendes[index].nome);
        // Copiar a idade do duende encontrado como lider de um time
        times[i].idadeLider = duendes[index].idade;
    }

    // Escalando os confeiteiros
    for (i=0; i<qtdTime; i++) {
        // Bucar o proximo mais velho disponivel
        index = proximoMaisVelho(duendes, qtdDuendes);
        // Marca o duende como escalado
        duendes[index].escalado = SIM;
        // Copiar o nome do duende encontrado como confeiteiro de um time
        strcpy(times[i].nomeConfeiteiro, duendes[index].nome);
        // Copiar a idade do duende encontrado como confeiteiro de um time
        times[i].idadeConfeiteiro = duendes[index].idade;
    }

    // Escalando os entregador
    for (i=0; i<qtdTime; i++) {
        // Bucar o proximo mais velho disponivel
        index = proximoMaisVelho(duendes, qtdDuendes);
        // Marca o duende como escalado
        duendes[index].escalado = SIM;
        // Copiar o nome do duende encontrado como entregador de um time
        strcpy(times[i].nomeEntregador, duendes[index].nome);
        // Copiar a idade do duende encontrado como entregador de um time
        times[i].idadeEntregador = duendes[index].idade;
    }

    // Escalando os embrulhador
    for (i=0; i<qtdTime; i++) {
        // Bucar o proximo mais velho disponivel
        index = proximoMaisVelho(duendes, qtdDuendes);
        // Marca o duende como escalado
        duendes[index].escalado = SIM;
        // Copiar o nome do duende encontrado como embrulhador de um time
        strcpy(times[i].nomeEmbrulhador, duendes[index].nome);
        // Copiar a idade do duende encontrado como embrulhador de um time
        times[i].idadeEmbrulhador = duendes[index].idade;
    }
}

int proximoMaisVelho(Duende *duendes, int qtdDuendes){ 

    int idadeMaisvelho = 0;
    int posicaoMaisVelho = -1;

    for(int i=0; i<qtdDuendes; i++){
        if(duendes[i].idade > idadeMaisvelho && duendes[i].escalado == NAO){
            idadeMaisvelho = duendes[i].idade;
            posicaoMaisVelho = i;
        }
    }

    return posicaoMaisVelho;

 }

// Manter como especificado
void printTimes(Time *times, int qtdTimes){
    for (int i=0; i<qtdTimes; i++) {
        printf("Time %d\n", i+1);
        printf("PILOTO > %s %d\n", times[i].nomeLider, times[i].idadeLider);
        printf("CONFEI > %s %d\n", times[i].nomeConfeiteiro, times[i].idadeConfeiteiro);
        printf("ENTREG > %s %d\n", times[i].nomeEntregador, times[i].idadeEntregador);
        printf("EMBRUL > %s %d\n\n", times[i].nomeEmbrulhador, times[i].idadeEmbrulhador);
    }
}
