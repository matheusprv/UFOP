//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#ifndef COMPUTADOR_H
#define COMPUTADOR_H

#include "structs.h"

int procurarVitoria(int *,int *, Partida *partida, char);

int melhorPosicao(int *, int*, Partida);

void jogadaComputador(Partida *partida);

#endif