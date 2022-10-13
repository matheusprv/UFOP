//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "structs.h"
#include "funcoes.h"
#include "computador.h"
#include <time.h>
#include <unistd.h>

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

        if(partida->tabuleiro[2-i][2-i] == identificador)
            pontuacaoDiagonalSec ++;
        else if(partida->tabuleiro[2-i][2-i] == identificadorOposto)
            pontuacaoDiagonalSec -=3;
    }

    if(pontuacaoDiagonalPrinc == 2 || pontuacaoDiagonalSec == 2){
        for(int i=0; i<3;i++){
            if(partida->tabuleiro[i][i] == ' '){
                *linha = i;
                *coluna = i;
                return 1;
            }
            if(partida->tabuleiro[2-i][2-i] == ' '){
                *linha = i;
                *coluna = i;
                return 1;
            }

        }
    }
    return 0;
}

int melhorPosicao(int *linha, int *coluna, Partida *partida){
    
    if(partida->tabuleiro[1][1] == ' '){
        *linha = 1;
        *coluna = 1;
        return 1;
    }
    //Escolhendo uma quina do tabuleiro
    for(int i = 0; i<2; i+=2){
        if(partida->tabuleiro[i][0] == ' '){
            *linha = i;
            *coluna = 0;
            return 1;
        }
        if(partida->tabuleiro[i][0] == ' '){
            *linha = i;
            *coluna = 2;
            return 1;
        }

    }
    

    return 0;
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
        melhorPosicao(&linha, &coluna, partida);
        partida->tabuleiro[linha][coluna] = 'O';
    }
    printf("marcar %d%d\n", linha+1, coluna+1);
    sleep(0.7);
    
}