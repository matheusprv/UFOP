//Matheus Peixoto Ribeiro Vieira - 22.1.4104
#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

void imprimeMenuPrincipal(int comandoValido);

void lerCaracter(char *);

void lerString(char *);

//Reinicia todos os valores do struct para um valor padrao a fim de iniciar um novo jogo
void reiniciarPartida(Partida *partida);

void imprimeTabuleiro(char **);

#endif