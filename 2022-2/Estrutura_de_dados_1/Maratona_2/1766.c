#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[102];
    int peso;
    int idade;
    float altura;
}Renas;

void trocaPosicao(Renas* renas, int * i, int * j){
    Renas auxiliar;

    auxiliar = renas[*i];
    renas[*i] = renas[*j];
    renas[*j] = auxiliar;
    *i += 1;
    *j -= 1;

}

//Decrescente por peso
void ordenaPeso(Renas * renas, int inicio, int fim){
    int i, j;
    Renas pivo; 

    i = inicio;
    j = fim;
    pivo = renas[(inicio + fim) / 2];

    while (i <= j){
        while (renas[i].peso > pivo.peso && i < fim)
            i++;
        
        while (renas[j].peso < pivo.peso && j > inicio)
            j--;

        if (i <= j)
            trocaPosicao(renas, &i, &j);
    }

    if (j > inicio)
        ordenaPeso(renas, inicio, j);

    if (i < fim)
        ordenaPeso(renas, i, fim);
}

//Ascendente de idade
void ordenaIdade(Renas * renas, int inicio, int fim){
    int i, j;
    Renas pivo; 

    i = inicio;
    j = fim;
    pivo = renas[(inicio + fim) / 2];

    while (i <= j){
        while (renas[i].idade < pivo.idade && i < fim)
            i++;
        
        while (renas[j].idade > pivo.idade && j > inicio)
            j--;

        if (i <= j)
            trocaPosicao(renas, &i, &j);
    }

    if (j > inicio)
        ordenaIdade(renas, inicio, j);

    if (i < fim)
        ordenaIdade(renas, i, fim);
}

//Nome
void ordenaNome(Renas * renas, int inicio, int fim){
    int i, j;
    Renas pivo; 

    i = inicio;
    j = fim;
    pivo = renas[(inicio + fim) / 2];

    while (i <= j){
        while (strcmp(renas[i].nome, pivo.nome) < 0 && i < fim)
            i++;
        
        while (strcmp(renas[j].nome, pivo.nome) > 0 && j > inicio)
            j--;

        if (i <= j)
            trocaPosicao(renas, &i, &j);
    }

    if (j > inicio)
        ordenaNome(renas, inicio, j);

    if (i < fim)
        ordenaNome(renas, i, fim);
}

void ordernacao(Renas * renas, int qtdrenas){

    ordenaPeso(renas, 0, qtdrenas - 1);

    for(int i = 0; i < qtdrenas-1; i++){
        
        if(renas[i].peso == renas[i+1].peso){
            int fim = i;
            while(fim < qtdrenas && renas[i].peso == renas[fim].peso){
                fim++;
            }

            fim--;
            ordenaIdade(renas, i, fim);
            i = fim;
        }

    }

    for(int i = 0; i < qtdrenas-1; i++){
        
        if(renas[i].peso == renas[i+1].peso && renas[i].idade == renas[i+1].idade){
            int fim = i;
            while(fim < qtdrenas && renas[i].peso == renas[fim].peso && renas[i].idade == renas[fim].idade){
                fim++;
            } 

            fim--;

            ordenaNome(renas, i, fim);
            i = fim;
        }

    }

}

int main(){

    int casosDeTeste;
    scanf("%d", &casosDeTeste);

    for(int contador = 0; contador < casosDeTeste; contador++){
        int totalRenas, qtdPuxadoras;

        scanf("%d%d", &totalRenas, &qtdPuxadoras);
        getchar();

        Renas * renas = malloc(totalRenas * sizeof(Renas));

        for(int i = 0; i<totalRenas; i++){
            scanf("%s", renas[i].nome);
            scanf("%d", &renas[i].peso);
            scanf("%d", &renas[i].idade);
            scanf("%f", &renas[i].altura);
            getchar();
        }

        ordernacao(renas, totalRenas);

        printf("CENARIO {%d}\n", contador+1);
        for(int i = 0; i < qtdPuxadoras; i++){
            printf("%d - %s\n", i+1, renas[i].nome);
        }

        free(renas);
    }

    return 0;
}