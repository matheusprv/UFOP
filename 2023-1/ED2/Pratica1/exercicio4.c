#include "struct.h"
#include <stdbool.h>

typedef struct cel{
    struct cel * prox;
    Aluno aluno;
}Celula;

typedef struct{
    Celula * cabeca;
    Celula * fim;
}Lista;


Lista * iniciaLista(){
    Lista * lista = malloc(sizeof(Lista));
    lista->cabeca = malloc(sizeof(Celula));
    lista->cabeca->prox = NULL;
    lista->fim = lista->cabeca;
    return lista;
}

void liberaLista(Lista **lista){
    Celula * atual = (*lista)->cabeca;
    Celula * proxima = atual->prox;

    while(proxima != NULL){
        free(atual);
        atual = proxima;
        proxima = proxima->prox;
    }

    free(atual);
    free(*lista);
}

void insereFinal(Lista * lista, Aluno aluno){
    Celula * nova = malloc(sizeof(Celula));
    nova->aluno = aluno;
    nova->prox = NULL;

    lista->fim->prox = nova;
    lista->fim = nova;
}

bool removerMatricula(Lista * lista, int matricula){
    Celula * atual = lista->cabeca;
    Celula * proxima = atual->prox;

    while(proxima != NULL){
        if(proxima->aluno.matricula == matricula){
            atual->prox = proxima->prox;
            free(proxima);
            return true;
        }
        atual = proxima;
        proxima = proxima->prox;
    }
    return false;
}

void escreverArquivo(Lista * lista){
    FILE * arquivo = abrirArquivo("alunos.bin", "wb");
    if(arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo para escrever\n");
        exit(1);
    }
        
    Celula * atual = lista->cabeca;
    Celula * proxima = atual->prox;

    int qtd = 0;

    while(proxima != NULL){
        fwrite(&(proxima->aluno), sizeof(Aluno), 1, arquivo);
        atual = proxima;
        proxima = atual->prox;
        qtd++;
    }

    printf("qtd: %d\n", qtd);

    fclose(arquivo);
}

int main(){

    FILE * arquivo = abrirArquivo("alunos.bin", "rb");
    if(arquivo == NULL)
        return 0;

    Lista * listaAlunos = iniciaLista();
    Aluno temp;
    int qtdLeitura = 0;
    
    while(fread(&temp, sizeof(Aluno), 1, arquivo) == 1){
        insereFinal(listaAlunos, temp);
        qtdLeitura++;
    }

    printf("Dados lidos: %d\n", qtdLeitura);

    fclose(arquivo);



    int matriculaRemover;
    printf("Digite a matricula para remover: ");
    scanf("%d", &matriculaRemover);

    if(removerMatricula(listaAlunos, matriculaRemover))
        printf("Removido com sucesso!\n");    
    else
        printf("Erro ao remover\n");
    
    escreverArquivo(listaAlunos);

    liberaLista(&listaAlunos);
    
    return 0;
}