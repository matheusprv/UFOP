//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#ifndef COMPUTADOR_H
#define COMPUTADOR_H

#include "structs.h"

//Verifica se há alguma possibilidade do jogador ou comutador vencer
int procurarVitoria(int *,int *, char **, char);

//Procura a melhor posição para jogar quando a partida ainda está no começo
int melhorPosicao(char **);

//Chama as funções que procuram os locais em que o computador irá jogar
void jogadaComputador(Partida *partida);

#endif