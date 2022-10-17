// -*- coding: utf-8 -*-
#include <stdio.h>
#define TAM_MAX 50
#define MAX_ALUNOS 30
 
typedef struct{
    char nome[TAM_MAX];
    float nota;
    int frequencia;
}Aluno;

int main(){

    Aluno alunos[MAX_ALUNOS];

    int cont = -1;
    int operacao = 1;
    
    while(operacao == 1 && cont<30){
        cont++;
        printf("Digite 1 para entrar um aluno ou 0 para encerrar: ");
        scanf("%d", &operacao);

        if(operacao == 1){
            scanf("%s %f %d", alunos[cont].nome, &alunos[cont].nota, &alunos[cont].frequencia);
        }
    }

    FILE *arquivo = fopen("alunos.txt", "w");
    fprintf(arquivo, "%d\n", cont);
    for(int i=0; i<cont; i++){
        fprintf(arquivo, "%s %.1f %d\n", alunos[i].nome, alunos[i].nota, alunos[i].frequencia);  
    }
    fclose(arquivo);

    return 0;

}