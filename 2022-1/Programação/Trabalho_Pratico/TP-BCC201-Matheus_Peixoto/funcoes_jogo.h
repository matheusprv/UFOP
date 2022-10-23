//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#ifndef FUNCOES_JOGO_H
#define FUNCOES_JOGO_H

#include "structs.h"

#define TAM_MAX_STRING 266


//Retorna 0 caso o jogo esteja acontecendo, 1 caso o jogador 1 ganhe, 2 caso o jogador 2 ganhe ou 3 caso de velha
int jogoFinalizado(char **, int);

//Lê o comando dos jogadore e retorna 1 para marcar posicao,
//2 para salvar, ou 3 para ir ao menu principal 
int lerComandos(int *, int*, char**, char[TAM_MAX_STRING]);

//Exibe o menu de jogo
int jogo(Partida *partida);

//Exibie o formulário a ser preenchido para iniciar um novo jogo
int menuNovoJogo(Partida *partida, int novoJogo);

#endif