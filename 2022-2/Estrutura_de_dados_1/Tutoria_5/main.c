//IMPLEMENTE UTILIZANDO HEAPSORT
#include "ordenacao.h"


int main(){

    int n;
    while(scanf("%d",&n) && n != 0){
        getchar();
        
        Aluno * alunos = malloc(n * sizeof(Aluno));

        lerDados(alunos, n);

        ordenacao(alunos, n);

        printNome(alunos, n);

        free(alunos);

    }

    return 0;
}