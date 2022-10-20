//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#ifndef RANKING_H
#define RANKING_H

#include "funcoes.h"
#include "structs.h"

void alinharAoMeioTabela(char *, int);

void exibirRanking(Ranking *ranking, int );

//void adicionarJogdorNoRanking(Ranking**, int*, char*);
void adicionarJogdorNoRanking(Ranking **, int*, char*);

int verificarJogadorEstaNoRanking(Ranking*, int*, char*);

int procurarPosicao(Ranking *ranking, char *, int);

void organizarRanking(Ranking **, int*, Partida, int);

#endif