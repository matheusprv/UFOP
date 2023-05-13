#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_ALUNOS 4 

typedef struct{
    int matricula;
    char nome[30];
    float nota1, nota2, nota3;
    int faltas;
    
    float notaMedia;
    char conceito;
    int dadoExistente;

}Aluno;


void trim_string(char * string){
    int ultima_posicao = strlen(string) - 1;

    for(int i = ultima_posicao; string[i] == ' '; i--)
        string[i] = '\0';
}

FILE * abrirArquivo(char * nome_arquivo, char * modo){
    FILE * arquivo = fopen(nome_arquivo, modo);

    if(arquivo == NULL){
        printf("Não foi possível abrir o arquivo %s\n", nome_arquivo);
    }

    return arquivo;
}