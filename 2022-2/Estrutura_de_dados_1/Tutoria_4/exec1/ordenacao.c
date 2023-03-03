#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

struct upa{
    int emergencia;
    int urgencia;
    int semUrgencia;
    int medicos;
    char nome[20];
};

int alocarUpa (TADupa **aux,int n){
    TADupa * upas = (TADupa*) malloc(n * sizeof(TADupa));
    if(upas == NULL) return 0;

    *aux = upas;
    return 1;
}

void preencheVetor(TADupa *upas, int n){
    for(int i = 0; i < n; i++){
        getchar();
        scanf("%s", upas[i].nome);
        scanf("%d", &upas[i].emergencia);
        scanf("%d", &upas[i].urgencia);
        scanf("%d", &upas[i].semUrgencia);
        scanf("%d", &upas[i].medicos);
    }
}

void ordenaUpas(TADupa *upas, int n){
    //shellsort
    int h, i, j;
    TADupa aux;
    for (h = 1; h < n; h = 3*h+1); //definindo o h inicial

    do{
        h = (h-1)/3;

        for (i = h; i < n; i++){
            aux = upas[i];
            j = i;

            while (!verifica(aux, upas[j-h])){
                upas[j] = upas[j-h];
                j = j - h;

                if (j < h)
                    break;
            }

            upas[j] = aux;
        }
    } while (h > 1);
}

int verifica(TADupa upa1, TADupa upa2){
    
    if(upa1.emergencia < upa2.emergencia){
        return 1;
    }
    
    else if((upa1.emergencia == upa2.emergencia) && (upa1.urgencia < upa2.urgencia)){
        return 1;
    }
    
    else if((upa1.emergencia == upa2.emergencia) && (upa1.urgencia == upa2.urgencia) && (upa1.semUrgencia < upa2.semUrgencia)){
        return 1;
    }

    else if((upa1.emergencia == upa2.emergencia) && (upa1.urgencia == upa2.urgencia) && (upa1.semUrgencia == upa2.semUrgencia) && (upa1.medicos < upa2.medicos)){
        return 1;
    }

    else if((upa1.emergencia == upa2.emergencia) && (upa1.urgencia == upa2.urgencia) && (upa1.semUrgencia == upa2.semUrgencia) && (upa1.medicos == upa2.medicos) && (strcmp(upa1.nome, upa2.nome) > 0)){
        return 1;
    }
    
    return 0;
}

void imprimeUpas(TADupa *upas, int n){
    for(int i = 0; i < n; i++){
        printf("%s ", upas[i].nome);
        printf("%d ", upas[i].emergencia);
        printf("%d ", upas[i].urgencia);
        printf("%d ", upas[i].semUrgencia);
        printf("%d\n", upas[i].medicos);
    }
}

void desalocaUpas(TADupa **aux){
    free(*aux);
}
