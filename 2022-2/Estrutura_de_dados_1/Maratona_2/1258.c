#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[61];
    char cor[12];
    char tamanho;
}Pessoa;

Pessoa* alocaPessoa(Pessoa *p, int n){
    Pessoa *pe = (Pessoa*) malloc (n * sizeof(Pessoa));
    if(pe == NULL)
    {
        exit (1);
    }
    return pe;
}

int preenchePessoa(Pessoa *p, int n){
    for(int i = 0; i < n; i++)
    {
        fgets(p[i].nome, 61, stdin);
        int tam = strlen(p[i].nome);
        p[i].nome[tam - 1] = '\0';

        //printf("%s\n", p[i].nome);

        
        
        scanf("%s", p[i].cor);

        //printf("%s\n", p[i].cor);

        

        getchar();

        
        scanf("%c", &p[i].tamanho);

        //printf("%c\n", p[i].tamanho);

  
        
        getchar();
        
    }
    return 1;
}

void imprimePessoa(Pessoa* p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %c %s\n", p[i].cor, p[i].tamanho, p[i].nome);
    }
   
    
}

void liberaPessoa(Pessoa *p){
    free(p);
}

void trocaPosicao(Pessoa* pessoas, int * i, int * j){
    Pessoa auxiliar;

    auxiliar = pessoas[*i];
    pessoas[*i] = pessoas[*j];
    pessoas[*j] = auxiliar;
    *i += 1;
    *j -= 1;

}

void ordenaCor(Pessoa * pessoa, int inicio, int fim){
    int i, j;
    Pessoa pivo; 

    i = inicio;
    j = fim;
    pivo = pessoa[(inicio + fim) / 2];

    while (i <= j){
        while (strcmp(pessoa[i].cor, pivo.cor) < 0 && i < fim)
            i++;
        
        while (strcmp(pessoa[j].cor, pivo.cor) > 0 && j > inicio)
            j--;

        if (i <= j)
            trocaPosicao(pessoa, &i, &j);
    }

    if (j > inicio)
        ordenaCor(pessoa, inicio, j);

    if (i < fim)
        ordenaCor(pessoa, i, fim);
}


void ordenaTamanho(Pessoa * pessoas, int inicio, int fim){
    int i, j;
    Pessoa pivo; 

    i = inicio;
    j = fim;
    pivo = pessoas[(inicio + fim) / 2];

    while (i <= j){
        while (pessoas[i].tamanho > pivo.tamanho && i < fim)
            i++;
        
        while (pessoas[j].tamanho < pivo.tamanho && j > inicio)
            j--;

        if (i <= j)
            trocaPosicao(pessoas, &i, &j);
    }

    if (j > inicio)
        ordenaTamanho(pessoas, inicio, j);

    if (i < fim)
        ordenaTamanho(pessoas, i, fim);
}

void ordenaNome(Pessoa * pessoa, int inicio, int fim){
    int i, j;
    Pessoa pivo; 

    i = inicio;
    j = fim;
    pivo = pessoa[(inicio + fim) / 2];

    while (i <= j){
        while (strcmp(pessoa[i].nome, pivo.nome) < 0 && i < fim)
            i++;
        
        while (strcmp(pessoa[j].nome, pivo.nome) > 0 && j > inicio)
            j--;

        if (i <= j)
            trocaPosicao(pessoa, &i, &j);
    }

    if (j > inicio)
        ordenaNome(pessoa, inicio, j);

    if (i < fim)
        ordenaNome(pessoa, i, fim);
}


void ordernacao(Pessoa * pessoa, int qtdpessoa){

    ordenaCor(pessoa, 0, qtdpessoa - 1);

    for(int i = 0; i < qtdpessoa-1; i++){
        
        if(!strcmp(pessoa[i].cor, pessoa[i+1].cor)){
            int fim = i;
            while(!strcmp(pessoa[i].cor, pessoa[fim].cor)){
                fim++;
            }

            fim--;
            ordenaTamanho(pessoa, i, fim);
            i = fim;
        }

    }

    for(int i = 0; i < qtdpessoa-1; i++){
        
        if(!strcmp(pessoa[i].cor, pessoa[i+1].cor) && pessoa[i].tamanho == pessoa[i+1].tamanho){
            int fim = i;
            while(fim < qtdpessoa && !strcmp(pessoa[i].cor, pessoa[fim].cor) && pessoa[i].tamanho == pessoa[fim].tamanho){
                fim++;
            } 

            fim--;

            ordenaNome(pessoa, i, fim);
            i = fim;
        }

    }

}

int main(int argc, char const *argv[])
{
    int n;
    int qtdRepeticoes = 0;
    
    while(scanf("%d", &n), n)
    {
        if(qtdRepeticoes > 0)
            printf("\n");
        getchar();
        Pessoa *pessoas;
        pessoas = alocaPessoa(pessoas, n);
        preenchePessoa(pessoas, n);
        ordernacao(pessoas, n );
        imprimePessoa(pessoas, n);
        liberaPessoa(pessoas);
        qtdRepeticoes++;
    }
    return 0;
}