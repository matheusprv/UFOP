#include "ordenacao.h"

void lerNomes(Aluno * alunos, int n){
    for(int i = 0; i<n; i++){
        fgets(alunos[i].nome, 100, stdin);
        alunos[i].nome[strlen(alunos[i].nome) - 1] = '\0';

        char temp[100];
        fgets(temp, 100, stdin);

        char * token = strtok(temp, " ");
        strcpy(alunos[i].cor, token);
        token = strtok(NULL, " ");
        alunos[i].tamanho = token[0];

    }
}

void ordenacao(Aluno *vetor, int n) {
    heap_constroi(vetor, n);
    while(n>1){
        Aluno aux = vetor[n-1];
        vetor[n-1] = vetor[0];
        vetor[0] = aux;
        n--;
        heap_refaz(vetor, 0, n-1);
    }
}

void heap_refaz(Aluno * Alunos, int esquerda, int direita){
    int i = esquerda;
    int j = i*2 + 1;
    Aluno aux = Alunos[i];
    
    while(j <= direita){
        // if(j < direita && Alunos[j] < Alunos[j+1] )
        if(j < direita && !compare(Alunos[j], Alunos[j+1]))
            j++;
        
        //aux >= Alunos[j]
        if(compare(aux, Alunos[j]))
            break;
        
        Alunos[i] = Alunos[j];
        i = j;
        j = i*2 +1;
    }
    Alunos[i] = aux;
}

void heap_constroi(Aluno * vetor, int n){
    int esquerda = (n/2)-1;
    while(esquerda >= 0 ){
        heap_refaz(vetor, esquerda, n-1);
        esquerda--;
    }
}

int compare(const Aluno aluno1, const Aluno aluno2) {
        
    //Cor ascendente
    if(strcmp(aluno1.cor, aluno2.cor) > 0)
        return 1;
    else if(strcmp(aluno1.cor, aluno2.cor) < 0)
        return 0;

    //tamanho descendente
    if(aluno1.tamanho < aluno2.tamanho)
        return 1;

    else if(aluno1.tamanho > aluno2.tamanho)
        return 0;

    //Nome ascendente
    if(strcmp(aluno1.nome, aluno2.nome) > 0)
        return 1;
    else
        return 0;

}

void printNome(Aluno *alunos, int n){
    for(int i = 0; i < n; i++){
        printf("%s %c %s\n", alunos[i].cor, alunos[i].tamanho, alunos[i].nome);
    }
}
