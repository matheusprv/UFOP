#include <stdio.h>

#define TAM_MAX 50
#define MAX_ALUNOS 30

typedef struct{
    char nome[TAM_MAX];
    float nota;
    int frequencia;
}Aluno;

int main(){

    char nomeArquivo[TAM_MAX];
    
    Aluno alunos[MAX_ALUNOS];
    float somatorioNota = 0;
    int somatorioFrequencia = 0;
    int qtdAprovados = 0;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    FILE * arquivo = fopen(nomeArquivo, "r");
    int qtdAlunos;
    fscanf(arquivo, "%d", &qtdAlunos);

    for(int i=0; i<qtdAlunos; i++){
        fscanf(arquivo, "%s %f %d", alunos[i].nome, &alunos[i].nota, &alunos[i].frequencia);
        somatorioFrequencia += alunos[i].frequencia;
        somatorioNota += alunos[i].nota;
        if(alunos[i].nota>=6) qtdAprovados++;

    }
    
    fclose(arquivo);

    float notaMedia = somatorioNota/(float)qtdAlunos;
    printf("Nota média: %.1f\n", notaMedia);
    printf("Frequência média: %d%%\n", somatorioFrequencia/qtdAlunos);
    printf("Percentual de aprovação: %.f%%\n", (qtdAprovados/(float)qtdAlunos)*100);
    printf("Nome dos alunos com nota acima da nota média:\n");
    
    for(int i=0; i<qtdAlunos;i++){
        if(alunos[i].nota >= notaMedia){
            printf("%s\n", alunos[i].nome);
        }
    }


    return 0;
}