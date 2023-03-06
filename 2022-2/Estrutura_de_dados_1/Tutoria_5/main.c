//IMPLEMENTE UTILIZANDO HEAPSORT
#include "ordenacao.h"

void limpaBuffer(){
    while( getchar() != '\n' );
}

int main(){

    int n;
    scanf("%d",&n);

    while(n != 0){
        limpaBuffer();

        Aluno * alunos = malloc(n * sizeof(Aluno));

        lerNomes(alunos, n);

        ordenacao(alunos, n);

        printNome(alunos, n);

        free(alunos);
        scanf("%d",&n);
        if(n != 0)
            printf("\n");
    }

    return 0;
}