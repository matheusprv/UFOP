#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

#define TAM_NOME 102

struct upa{
    int qtdEmergencia;
    int qtdUrgencia;
    int qtdSemUrgencia;
    int medicosEmPlantao;
    char nomeUPA[TAM_NOME];
};

int alocarUpa (TADupa **aux,int n){
    *aux = malloc(n * sizeof(TADupa));
    if(*aux != NULL)
        return 1;
    return 0;
}

void preencheVetor(TADupa *upas, int n){
    for(int i = 0; i<n; i++){
        getchar();
        scanf("%s", upas[i].nomeUPA);
        scanf("%d", &upas[i].qtdEmergencia);
        scanf("%d", &upas[i].qtdUrgencia);
        scanf("%d", &upas[i].qtdSemUrgencia);
        scanf("%d", &upas[i].medicosEmPlantao);
    }
}

void ordenaUpas(TADupa *upas, int n){
    int min;
    for(int i = 0; i < n; i++){
        min = i;
        for(int j = i+1; j < n; j++){
            if(upas[j].qtdEmergencia > upas[min].qtdEmergencia)
                min = j;
            
            else if((upas[j].qtdEmergencia == upas[min].qtdEmergencia) && (upas[j].qtdUrgencia > upas[min].qtdUrgencia))
                min = j;
            
            else if((upas[j].qtdEmergencia == upas[min].qtdEmergencia) && (upas[j].qtdUrgencia == upas[min].qtdUrgencia) && (upas[j].qtdSemUrgencia > upas[min].qtdSemUrgencia))
                min = j;
        
            else if((upas[j].qtdEmergencia == upas[min].qtdEmergencia) && (upas[j].qtdUrgencia == upas[min].qtdUrgencia) && (upas[j].qtdSemUrgencia == upas[min].qtdSemUrgencia) && (upas[j].medicosEmPlantao > upas[min].medicosEmPlantao))
                min = j;

            else if((upas[j].qtdEmergencia == upas[min].qtdEmergencia) && (upas[j].qtdUrgencia == upas[min].qtdUrgencia) && (upas[j].qtdSemUrgencia == upas[min].qtdSemUrgencia) && (upas[j].medicosEmPlantao == upas[min].medicosEmPlantao) && (strcmp(upas[j].nomeUPA, upas[min].nomeUPA) < 0))
                min = j;
        }
        TADupa aux = upas[i];
        upas[i] = upas[min];
        upas[min] = aux;
    }
}

void imprimeUpas(TADupa *upas, int n){
    for(int i = 0; i<n; i++){
        printf("%s ", upas[i].nomeUPA);
        printf("%d ", upas[i].qtdEmergencia);
        printf("%d ", upas[i].qtdUrgencia);
        printf("%d ", upas[i].qtdSemUrgencia);
        printf("%d\n", upas[i].medicosEmPlantao);
    }
}

void desalocaUpas(TADupa **aux){
    free(*aux);
}
