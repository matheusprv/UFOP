//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#ifndef RANKING_H
#define RANKING_H

#include "funcoes.h"
#include "structs.h"

//Alinha o texto no meio da tabela de exibição do ranking
void alinharAoMeioTabela(char *, int);

//Exibe todas as posições do ranking que está na memória
void exibirRanking(Ranking *ranking, int );

//void adicionarJogdorNoRanking(Ranking**, int*, char*);
void adicionarJogdorNoRanking(Ranking **, int*, char*);

//Retorna a posição do jogador no vetor. Retorna -1 caso não encotre o jogador
int procurarPosicao(Ranking *ranking, char *, int);

//Recebe o resultado de uma partida e organiza o ranking
void organizarRanking(Ranking **, int*, Partida, int);

#endif