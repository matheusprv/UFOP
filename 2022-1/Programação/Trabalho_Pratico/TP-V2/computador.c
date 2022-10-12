//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "structs.h"
#include "funcoes.h"
#include "computador.h"
#include <time.h>

int procurarVitoria(int *linha, int *coluna, Partida *partida, char identificador){
    char identificadorOposto = identificador == 'X' ? 'O' : 'X';
    int pontuacaoLinha = 0, pontuacaoColuna = 0;
    int pontuacaoDiagonalPrinc = 0, pontuacaoDiagonalSec = 0;
    //Verificando vitorias nas linhas
    for(int i=0; i<3; i++){
        pontuacaoLinha = 0;
        pontuacaoColuna = 0;
        for(int j=0; j<3; j++){
            if(partida->tabuleiro[i][j] == identificador)
                pontuacaoLinha++;
            else if(partida->tabuleiro[i][j] == identificadorOposto)
                pontuacaoLinha -=3;

            if(partida->tabuleiro[j][i] == identificador)
                pontuacaoColuna++;
            else if(partida->tabuleiro[j][i] == identificadorOposto)
                pontuacaoColuna -=3;
        }      
        if(pontuacaoLinha == 2 || pontuacaoColuna == 2){
            for(int j=0; j<3; j++){
                if(partida->tabuleiro[i][j] == ' '){
                    *linha = i;
                    *coluna = j;
                    return 1;
                }
                if(partida->tabuleiro[j][i] == ' '){
                    *linha = j;
                    *coluna = i;
                    return 1;
                }
            }
        }
        if(partida->tabuleiro[i][i] == identificador)
            pontuacaoDiagonalPrinc ++;
        else if(partida->tabuleiro[i][i] == identificadorOposto)
            pontuacaoDiagonalPrinc -=3;

        if(partida->tabuleiro[3-i-1][3-i-1] == identificador)
            pontuacaoDiagonalSec ++;
        else if(partida->tabuleiro[3-i-1][3-i-1] == identificadorOposto)
            pontuacaoDiagonalSec -=3;
    }

    if(pontuacaoDiagonalPrinc == 2 || pontuacaoDiagonalSec == 2){
        for(int i=0; i<3;i++){
            if(partida->tabuleiro[i][i] == ' '){
                *linha = i;
                *coluna = i;
                return 1;
            }
            if(partida->tabuleiro[3-i-1][3-i-1] == ' '){
                *linha = i;
                *coluna = i;
                return 1;
            }

        }
    }
    return 0;
}

int melhorPosicao(int *, int*, Partida *partida){
    if(partida->tabuleiro[2][2] == ' '){
        *linha = 2;
        *coluna = 2;
        return 1;
    }
    //Escolhendo aleatoriamente uma quina do tabuleiro
    srand(time(NULL));
    while(1){
        int aleatorio = rand()%5;
    }


}

void jogadaComputador(Partida *partida){
    int linha=-1, coluna=-1;
    //Verificando as posições do jogador para procurar uma vitória
    if(procurarVitoria(&linha, &coluna, partida, 'X'))
        partida->tabuleiro[linha][coluna] = 'O';
    //Verificando as posições do computador para procurar uma vitória
    else if(procurarVitoria(&linha, &coluna, partida, 'O'))
        partida->tabuleiro[linha][coluna] = 'O';
    //Procurando a melhor posição para marcar
    else{

    }
}