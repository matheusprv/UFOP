#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMVOCABULARIO 127

typedef char* TipoTexto;
typedef char* TipoPadrao;


// i: Posição do final da janela
// j: Caminha sobre o padrao
// k: Caminha sobre o texto
void BMH (TipoTexto T, long n, TipoPadrao P, long m){
    int i, j, k, vocabulario [TAMVOCABULARIO]; 
    
    for(int cont = 0; cont < TAMVOCABULARIO; cont++ ) vocabulario[cont] = m;
    for(int cont = 1; cont < m; cont++ ) vocabulario[ (int) P[cont-1]] = m - cont;

    i = m;
    while(i <= n){
        j = m; // Padrao - Setado sempre para a ultima posicao do padrao, ou seja, seu tamamnho
        k = i; // Texto  - Setado sempre para onde a ultima posicao da janela estara

        while(T[k-1] == P[j-1]){
            k--; j--;
            
            if(j == 0){
                printf("Padrão encontrado na posicao %d do texto\n", k);
                break;
            }
        }

        i += vocabulario[ (int) T[i-1]];
    }
}

void BMHS (TipoTexto T, long n, TipoPadrao P, long m){
    int i, j, k, deslocamento[TAMVOCABULARIO];

    for(i = 0; i < TAMVOCABULARIO; i++) deslocamento[i] = m+1;
    for(i = 1; i <= m; i++) deslocamento[(int) P[i-1]] = m-i+1;

    i = m;

    while(i <= n){
        j = m; //Anda sobre o padrão
        k = i; //Anda sobre o texto

        while(T[k-1] == P[j-1] && j > 0){j--; k--;}

        if(j == 0) printf("Padrão encontrado na posição: %d\n", k);

        i += deslocamento[(int) T[i]];

    }
}

int main(){

    TipoTexto texto = "Texto de testes";
    TipoPadrao padrao = "tes";

    BMHS(texto, strlen(texto), padrao, strlen(padrao));

    return 0;
}

/*
e: 1
s: 3
t: 2
*/