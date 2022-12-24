#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duende.h"

typedef enum { NAO=0, SIM } ESCALADO;

struct duende {
    char nome[20];
    int idade;
    ESCALADO escalado;
};

// Manter como especificado
void lerQuantidade(int *qtd) { 
    scanf("%d", qtd);
    getchar();
}

// Manter como especificado
Duende *alocaDuendes(int n) { 
    Duende* duendes = malloc(n*sizeof(Duende));
    return duendes;
}

// Manter como especificado
Duende *copiaDuende(Duende *duendes, int i) {
    /* Aloca um novo duende baseado nos dados de um outro duende */ 
    Duende* copia = malloc(sizeof(Duende)) ;
    *copia = duendes[i];
    return copia;
}

// Manter como especificado
void desalocaDuendes(Duende **duendes){
    /* Desaloca um vetor ou um unico duende alocado dinamicamente */
    free(*duendes);
}

// Manter como especificado
void lerDuendes(Duende *duendes, int n) {
    /* Lê os dados de n de Duendes */
    for(int i=0; i<n; i++){
        scanf("%s", duendes[i].nome);
        scanf("%d", &duendes[i].idade);
        getchar();
        duendes[i].escalado = NAO;
    } 
}

// Manter como especificado
int proximoMaisVelho(Duende *duendes, int n) {
    /* Pega o próximo duende mais velho que ainda nao foi escalado */
    int idadeMaisVelho = 0;
    int posicaoMaisVelho = -1;

    for(int i=0; i<n; i++){
        if(duendes[i].idade > idadeMaisVelho && duendes[i].escalado == NAO){
            posicaoMaisVelho = i;
            idadeMaisVelho = duendes[i].idade;
        }
    }
    return posicaoMaisVelho;
}

// Manter como especificado
void escalarDuende(Duende *duendes, int index) {
    /* Dado um vetor de duendes, "seta" como escalado um duende */
    duendes[index].escalado = SIM;
}

// Manter como especificado
void printDuende(Duende *duende) {
    /* Imprime os dados de um duende e um \n no final */
    printf("%s %d\n", duende->nome, duende->idade);
}