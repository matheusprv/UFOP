#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int posicao;
    int tampado;
}Furo;

typedef struct {
    int qtd;
    int * posicoes;
    
}Remendo;

bool tem_buracos_destampados(Furo * furos, int n){
    for(int i = 0; i< n; i++){
        if(furos[i].tampado == 0){
            return true;
        }
    }
    return false;
}

void tampar_buracos(int i, int j, Furo * furos){

}

int tamanhoRemendo(int n, int tamRemendos[2], Furo * furos){

    //Verificando se somente o primeiro ou o segundo já é suficiente
    for(int i = 0; i < n; i++){
        if(furos[n-1].posicao - furos[0].posicao <= tamRemendos[i])
            return tamRemendos[i];
    }

    int totalRemendo = 0;

    Remendo remendos[2];
    remendos[0].posicoes = malloc(n * sizeof(int));
    remendos[0].qtd = 0;
    remendos[1].posicoes = malloc(n * sizeof(int));
    remendos[1].qtd = 0;

    while(tem_buracos_destampados(furos, n)){
        //Verificando quantos furos o maior tampa
        for(int cont = 0; cont < 2; cont++){
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n ;j++){
                    if(furos[j].posicao - furos[i].posicao <= tamRemendos[cont]){
                        remendos[cont].qtd++;
                    }
                }
            }
        }



    }

    free(remendos[0].posicoes);
    free(remendos[1].posicoes);

}


int main(){

    int n, c, tamRemendos[2];

    while(scanf("%d%d%d%d", &n, &c, &tamRemendos[0], &tamRemendos[1]) != EOF){

        if(tamRemendos[0] > tamRemendos[1]){
            int aux = tamRemendos[0];
            tamRemendos[0] = tamRemendos[1];
            tamRemendos[1] = aux;
        }

        Furo * furos = malloc(n * sizeof(Furo));

        for(int i = 0; i < n; i++){
            scanf("%d", &furos[i].posicao);
            furos[i].tampado = 0;
        }


    }

    return 0;
}