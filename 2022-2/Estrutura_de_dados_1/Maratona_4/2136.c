#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOME 10000

typedef struct {
    char nome[MAX_NOME];
    int tamanhoNome;
}Amigo;

typedef struct {
    char nome[MAX_NOME];
}NaoAmigo;


void ordenaAmigo(Amigo * amigos, int inicio, int fim){
    int i, j;
    Amigo pivo; 

    i = inicio;
    j = fim;
    pivo = amigos[(inicio + fim) / 2];

    while (i <= j){
        while (strcmp(amigos[i].nome, pivo.nome) < 0 && i < fim)
            i++;
        
        while (strcmp(amigos[j].nome, pivo.nome) > 0 && j > inicio)
            j--;

        if (i <= j){
            Amigo aux = amigos[i];
            amigos[i] = amigos[j];
            amigos[j] = aux;
            i++;
            j--;
        }
    }

    if (j > inicio)
        ordenaAmigo(amigos, inicio, j);

    if (i < fim)
        ordenaAmigo(amigos, i, fim);
}

void ordenaNaoAmigo(NaoAmigo * naoamigos, int inicio, int fim){
    int i, j;
    NaoAmigo pivo; 

    i = inicio;
    j = fim;
    pivo = naoamigos[(inicio + fim) / 2];

    while (i <= j){
        while (strcmp(naoamigos[i].nome, pivo.nome) < 0 && i < fim)
            i++;
        
        while (strcmp(naoamigos[j].nome, pivo.nome) > 0 && j > inicio)
            j--;

        if (i <= j){
            NaoAmigo aux = naoamigos[i];
            naoamigos[i] = naoamigos[j];
            naoamigos[j] = aux;
            i++;
            j--;
        }
    }

    if (j > inicio)
        ordenaNaoAmigo(naoamigos, inicio, j);

    if (i < fim)
        ordenaNaoAmigo(naoamigos, i, fim);
}

int main(){

    char nome[MAX_NOME];
    char amigo[5];

    int tamanhoAmigo = 0;
    int tamanhoNaoAmigo = 0;

    Amigo * amigos = malloc(sizeof(Amigo) * 0);
    NaoAmigo * naoAmigos = malloc(sizeof(naoAmigos) * 0);

    Amigo amigoEscolhido;
    amigoEscolhido.tamanhoNome = -1;

    scanf("%s", nome);
    
    int index;

    while (strcmp(nome, "FIM") != 0){
        scanf("%s", amigo);

        if(strcmp(amigo, "YES") == 0){
            tamanhoAmigo++;
            amigos = realloc(amigos, tamanhoAmigo * sizeof(Amigo));

            index = tamanhoAmigo-1;

            amigos[index].tamanhoNome = strlen(nome);
            strcpy(amigos[index].nome, nome);

            if(amigos[index].tamanhoNome > amigoEscolhido.tamanhoNome){
                amigoEscolhido.tamanhoNome = amigos[index].tamanhoNome;
                strcpy(amigoEscolhido.nome, nome);
            }
            
        }
        else{
            tamanhoNaoAmigo++;
            naoAmigos = realloc(naoAmigos, tamanhoNaoAmigo * sizeof(NaoAmigo));

            strcpy(naoAmigos[tamanhoNaoAmigo-1].nome, nome);
        }

        scanf("%s", nome);
    }
    
    ordenaAmigo(amigos, 0, tamanhoAmigo-1);
    ordenaNaoAmigo(naoAmigos, 0, tamanhoNaoAmigo-1);


    for(int i = 1; i < tamanhoAmigo; i++){
        if(strcmp(amigos[i].nome, amigos[i-1].nome) != 0)
            printf("%s\n", amigos[i-1].nome);
    }
    printf("%s\n", amigos[tamanhoAmigo-1].nome);


    for(int i = 1; i < tamanhoNaoAmigo; i++){
        if(strcmp(naoAmigos[i].nome, naoAmigos[i-1].nome) != 0)
            printf("%s\n", naoAmigos[i-1].nome);
    }
    printf("%s\n", naoAmigos[tamanhoNaoAmigo-1].nome);


    printf("\nAmigo do Habay:\n%s\n", amigoEscolhido.nome);

    free(amigos);
    free(naoAmigos);

    return 0;
}