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
    char nomeJogador[266];
    int vitorias;
    int empates;
    int derrotas;
}Ranking;

#endif