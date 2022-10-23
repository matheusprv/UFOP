//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#ifndef MANIPULACAO_ARQUIVO_H
#define MANIPULACAO_ARQUIVO_H

#include "structs.h"

//Salva o jogo em um arquivo de texto definido pelo usuário
void salvarJogo(Partida partida, char *arquivoSalvarJogo);

//Lê um caminho de jogo salvo e retorna se foi possível abrí-lo ou não
int lerJogoSalvo(Partida *partida);

//Lê o arquivo de configuração e gera a struct do ranking
int lerArquivoConfiguracao(Ranking **ranking);

//Salva todos os dados do Ranking no arquivo de configuração
void salvarArquivoConfiguracao(Ranking *, int );


#endif