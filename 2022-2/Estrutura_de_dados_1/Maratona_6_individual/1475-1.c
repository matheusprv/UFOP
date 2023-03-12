#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int posicao;
    int tampado;
}Furo;

void preencher_buracos(int i, int j, Furo * furos){
    for(; j <= i; j++)
        furos[j].tampado = 1;
}

void removerItens(int * n_furos, Furo * furos){
    for(int i = 0; i < *n_furos; i++){
        if(furos[i].tampado == 1){
            for(int j = i+1; j < *n_furos; j++)
                furos[j-1] = furos[j];

            *n_furos -= 1;
        }
    }
}

int calculaRemendos(int n_furos, int c_comprimento, int t1, int t2, Furo * furos){
    if(t1 > t2){
        int aux = t1;
        t1 = t2;
        t2 = aux;
    }

    int tamanho = 0;

    for(int i = n_furos - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(furos[i].posicao - furos[j].posicao <= t2){
                tamanho += t2;
                preencher_buracos(i, j, furos);
                
                if(j == 0 && i == n_furos-1)
                    return tamanho;

                i = j;
                break;
            }
        }
    }

    removerItens(&n_furos, furos);

    for(int i = n_furos - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(furos[i].posicao - furos[j].posicao <= t1){
                tamanho += t1;
                preencher_buracos(i, j, furos);
                i = j;
                break;
            }
        }
    }

    for(int i = 0; i < n_furos; i++){
        if(furos[i].tampado == 0)
            tamanho += t1;
    }
        

    return tamanho;

}

int main(){

    int n_furos, c_comprimento, t1, t2;

    while(scanf("%d%d%d%d", &n_furos, &c_comprimento, &t1, &t2) != EOF){
        Furo * furos = (Furo *) malloc(n_furos * sizeof(Furo));
        
        for(int i = 0; i < n_furos; i++){
            scanf("%d", &furos[i].posicao);
            furos[i].tampado = 0;
        }

        printf("%d\n", calculaRemendos(n_furos, c_comprimento, t1, t2, furos));

        free(furos);
    }

    return 0;
}