//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct{
    char **tabuleiro;
    char nomeJogadores[2][266];
    int numJogadas;
    int numJogadores;
}Partida;

typedef struct{
    int linha[3];
    int coluna[3];
    int somatorio;
}Vitoria;

#endif