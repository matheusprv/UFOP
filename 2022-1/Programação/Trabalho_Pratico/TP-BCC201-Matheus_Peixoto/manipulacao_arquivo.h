//Matheus Peixoto Ribeiro Vieira
#ifndef MANIPULACAO_ARQUIVO_H
#define MANIPULACAO_ARQUIVO_H

#include "structs.h"

void salvarJogo(Partida partida, char *arquivoSalvarJogo);

int lerJogoSalvo(Partida *partida);

int lerArquivoConfiguracao(Ranking **ranking);

void salvarArquivoConfiguracao(Ranking *, int );


#endif