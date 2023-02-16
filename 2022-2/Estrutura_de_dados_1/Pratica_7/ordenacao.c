#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void ordena(Aluno *alunos, int n) {
	int h, i, j;

    for(h = 1; h < n; h = 3*h + 1);
    do{

        h = (h-1)/3;

        for(i = h; i<n; i++){
            Aluno aux = alunos[i];
            j = i;

            while(compare(alunos[j-h].nome, aux.nome) > 0){
                alunos[j] = alunos[j-h];
                
                j = j-h;
                
                if(j<h)
                    break;
            }
            alunos[j] = aux;
        }

    } while (h != 1);
    
}

// Manter como especificado
int compare(const char* aluno1, const char* aluno2) {
    return strcmp(aluno1, aluno2);
}

/* Manter como especificado */
void imprimeResposta(Aluno* alunos, int n, int k) {
    printf("%s\n", alunos[k-1].nome);
}

/* Manter como especificado */
Aluno* alocaAlunos(int n) {
    Aluno * alunos = malloc(sizeof(Aluno) * n);
    return alunos;
}

/* Manter como especificado */
void liberaAlunos(Aluno** alunos) {
    free(*alunos);
}

/* Manter como especificado */
void leAlunos(Aluno* alunos, int n) {
    for(int i = 0; i < n; i++){
        scanf("%s",alunos[i].nome);
    }
}

/* Manter como especificado */
void leQuantidades(int* n, int* k) {
    scanf("%d", n);
    getchar();
    scanf("%d", k);
    getchar();
}

