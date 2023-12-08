#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

#ifndef USEFUL_FUNCTIONS_H
#define USEFUL_FUNCTIONS_H

void linha_separacao();

void menu_opcoes();

char ler_opcao_menu();

#endif