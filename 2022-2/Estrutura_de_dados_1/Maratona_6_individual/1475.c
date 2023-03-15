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

    //Testando com o menor valor
    int tamanhoMenorValor = 0;
    for(int i = 0; i < n_furos; i++){
        int j = i + 1, qtdFuros = 0;
        while(j < n_furos && furos[j].posicao - furos[i].posicao <= t1){
            j++;
            qtdFuros++;
        }
        tamanhoMenorValor += t1;
        i += qtdFuros;
    }


    int tamanhoComecaFinal = 0;
    for(int i = n_furos - 1; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(furos[i].posicao - furos[j].posicao <= t1){
                tamanhoComecaFinal += t1;
                i = j;
                break;
            }
            if(furos[i].posicao - furos[j].posicao <= t2){
                tamanhoComecaFinal += t2;
                i = j;
                break;
            }
        }
    }

    int tamanhoComecaInicio = 0;
    for(int i = 0 ; i < n_furos; i++){
        for(int j = n_furos - 1; j >=i ; j--){
            if(furos[j].posicao - furos[i].posicao <= t1){
                tamanhoComecaInicio += t1;
                i = j;
                break;
            }
            if(furos[j].posicao - furos[i].posicao <= t2){
                tamanhoComecaInicio += t2;
                i = j;
                break;
            }
        }
    }

    if(tamanhoMenorValor < tamanhoComecaFinal && tamanhoMenorValor < tamanhoComecaInicio)
        return tamanhoMenorValor;

    if(tamanhoComecaInicio < tamanhoComecaFinal)
        return tamanhoComecaInicio;
    return tamanhoComecaFinal;
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