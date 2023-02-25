#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[1000];
    char regiao;
    int custo;
} Aluno;

void ordenaCusto(Aluno *alunos, int inicio, int fim)
{
    int i, j;
    Aluno pivo;

    i = inicio;
    j = fim;
    pivo = alunos[(inicio + fim) / 2];

    while (i <= j)
    {
        while (alunos[i].custo < pivo.custo && i < fim)
            i++;

        while (alunos[j].custo > pivo.custo && j > inicio)
            j--;

        if (i <= j)
        {
            Aluno aux = alunos[i];
            alunos[i] = alunos[j];
            alunos[j] = aux;
            i++;
            j--;
        }
    }

    if (j > inicio)
        ordenaCusto(alunos, inicio, j);

    if (i < fim)
        ordenaCusto(alunos, i, fim);
}

void ordenaRegiao(Aluno *alunos, int inicio, int fim)
{
    int i, j;
    Aluno pivo;

    i = inicio;
    j = fim;
    pivo = alunos[(inicio + fim) / 2];

    while (i <= j)
    {
        while (alunos[i].regiao < pivo.regiao && i < fim)
            i++;

        while (alunos[j].regiao > pivo.regiao && j > inicio)
            j--;

        if (i <= j)
        {
            Aluno aux = alunos[i];
            alunos[i] = alunos[j];
            alunos[j] = aux;
            i++;
            j--;
        }
    }

    if (j > inicio)
        ordenaRegiao(alunos, inicio, j);

    if (i < fim)
        ordenaRegiao(alunos, i, fim);
}

void ordenaNome(Aluno *alunos, int inicio, int fim)
{
    int i, j;
    Aluno pivo;

    i = inicio;
    j = fim;
    pivo = alunos[(inicio + fim) / 2];

    while (i <= j)
    {
        while (strcmp(alunos[i].nome, pivo.nome) < 0 && i < fim)
            i++;

        while (strcmp(alunos[j].nome, pivo.nome) > 0 && j > inicio)
            j--;

        if (i <= j)
        {
            Aluno aux = alunos[i];
            alunos[i] = alunos[j];
            alunos[j] = aux;
            i++;
            j--;
        }
    }

    if (j > inicio)
        ordenaNome(alunos, inicio, j);

    if (i < fim)
        ordenaNome(alunos, i, fim);
}

void ordenacao(Aluno * alunos, int qtdAlunos){

    ordenaCusto(alunos, 0, qtdAlunos - 1);

    //Verificando se ha distancias iguais e ordenando o deslocamento
    for(int i = 0; i < qtdAlunos-1; i++){
        
        if(alunos[i].custo == alunos[i+1].custo){
            //Verificando ate qual trajeto vai essa igualdade
            int fim = i;
            while(fim < qtdAlunos && alunos[i].custo == alunos[fim].custo){
                fim++;
            }

            fim--;

            //Ordenando pelo deslocamento
            ordenaRegiao(alunos, i, fim);
            i = fim;
        }

    }

   //Verificando o deslocamento e distancia para ordenar pelo nome
    for(int i = 0; i < qtdAlunos-1; i++){
        
        if(alunos[i].custo == alunos[i+1].custo && alunos[i].regiao == alunos[i+1].regiao){
            //Verificando até qual trajeto vai essa igualdade
            int fim = i;
            while(fim < qtdAlunos && alunos[i].custo == alunos[fim].custo && alunos[i].regiao == alunos[fim].regiao){
                fim++;
            } 

            fim--;

            //Ordenando pelo deslocamento
            ordenaNome(alunos, i, fim);
            i = fim;
        }

    }
}

int main()
{

    int qtdAlunos;
    while (scanf("%d", &qtdAlunos) != EOF)
    {
        getchar();

        Aluno *alunos = (Aluno *)malloc(sizeof(Aluno) * qtdAlunos);

        for (int i = 0; i < qtdAlunos; i++)
        {
            scanf("%s", alunos[i].nome);getchar();
            scanf("%c", &alunos[i].regiao);getchar();
            scanf("%d", &alunos[i].custo);getchar();
        }

        ordenacao(alunos, qtdAlunos);        

        for (int i = 0; i < qtdAlunos; i++)
            printf("%s\n", alunos[i].nome);

        free(alunos);
    }

    return 0;
}