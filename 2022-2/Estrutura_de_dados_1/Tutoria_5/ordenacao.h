#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    char cor[10];
    char tamanho;
}Aluno;

void lerDados(Aluno * alunos, int n);

void ordenacao(Aluno *vetor, int n);

void printNome(Aluno *alunos, int n);

int compare(const Aluno aluno1, const Aluno aluno2);

void heap_constroi(Aluno * vetor, int n);

void heap_refaz(Aluno * Alunos, int esquerda, int direita);