#include <stdio.h>
#include <string.h>

#define NUM_ALUNOS 4 

typedef struct{
    char matricula [5];
    char nome[30];
    float nota1, nota2, nota3;
    int faltas;
}Aluno;

int main(){
    Aluno alunos[NUM_ALUNOS];

    int index = 0;
    strcpy(alunos[index].matricula, "1234");
    strcpy(alunos[index].nome, "Matheus Peixoto");
    alunos[index].nota1 = 10;
    alunos[index].nota2 = 10;
    alunos[index].nota3 = 10;
    alunos[index].faltas = 0;
    index++;

    strcpy(alunos[index].matricula, "1235");
    strcpy(alunos[index].nome, "Matheus");
    alunos[index].nota1 = 9;
    alunos[index].nota2 = 9;
    alunos[index].nota3 = 8;
    alunos[index].faltas = 1;
    index++;

    strcpy(alunos[index].matricula, "1236");
    strcpy(alunos[index].nome, "Camila Ribeiro");
    alunos[index].nota1 = 7;
    alunos[index].nota2 = 7;
    alunos[index].nota3 = 7;
    alunos[index].faltas = 19;
    index++;

    strcpy(alunos[index].matricula, "1237");
    strcpy(alunos[index].nome, "Camila");
    alunos[index].nota1 = 7;
    alunos[index].nota2 = 7;
    alunos[index].nota3 = 7;
    alunos[index].faltas = 19;
    index++;

    FILE * arquivo = fopen("alunos.txt", "w");
    
    for(int i = 0; i < NUM_ALUNOS; i++){
        fprintf(arquivo, "%4s %29s %4.1f %4.1f %4.1f %d\n", alunos[i].matricula, alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].nota3, alunos[i].faltas );
    }

    fclose(arquivo);

    return 0;

}