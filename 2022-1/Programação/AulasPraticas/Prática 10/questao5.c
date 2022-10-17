#include <stdio.h>
#include <string.h>
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

    //printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    FILE * arquivo = fopen(nomeArquivo, "r");
    int qtdAlunos;
    fscanf(arquivo, "%d", &qtdAlunos);

    for(int i=0; i<qtdAlunos; i++){
        fscanf(arquivo, "%s %f %d", alunos[i].nome, &alunos[i].nota, &alunos[i].frequencia);
    }

    fclose(arquivo);

    //Criando o arquivo binário
    nomeArquivo[strlen(nomeArquivo)-3] = '\0';
    strcat(nomeArquivo, "dat");

    FILE * arquivoBinario = fopen(nomeArquivo, "wb");
    fwrite(&qtdAlunos, sizeof(int), 1, arquivoBinario);
    for(int i=0; i<qtdAlunos;i++){
        fwrite(alunos[i].nome,sizeof(char), 1, arquivoBinario);
        fwrite(&alunos[i].nota,sizeof(float), 1, arquivoBinario);
        fwrite(&alunos[i].frequencia, sizeof(int),1,arquivoBinario);
    }
    //printf("Arquivo %s criado com sucesso!\n", nomeArquivo);
    fclose(arquivoBinario);

    //Lendo o arquivo binário
    arquivo = fopen(nomeArquivo, "rb");
    fread(&qtdAlunos, sizeof(int), 1, arquivo);

    float somatorioNota = 0;
    int somatorioFrequencia = 0;
    int qtdAprovados = 0;

    for(int i=0; i<qtdAlunos; i++){
        fread(alunos[i].nome, sizeof(char), 1, arquivo);
        fread(&alunos[i].nota, sizeof(float), 1, arquivo);
        fread(&alunos[i].frequencia, sizeof(int), 1, arquivo);
        somatorioFrequencia += alunos[i].frequencia;
        somatorioNota += alunos[i].nota;
        if(alunos[i].nota>=6) qtdAprovados++;
    }

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