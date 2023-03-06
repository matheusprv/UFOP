//IMPLEMENTE UTILIZANDO HEAPSORT
#include "ordenacao.h"


int main(){

    int n;
    scanf("%d",&n);

    while(n != 0){
        getchar();
        
        Aluno * alunos = malloc(n * sizeof(Aluno));

        for(int i=0; i<n; i++){
            fgets(alunos[i].nome, 30, stdin);
            alunos[i].nome[strlen(alunos[i].nome) - 1] = '\0';
            
            scanf("%s", alunos[i].cor);
            scanf("%c", &alunos[i].tamanho);
        }

        //ordenacao(alunos, n);

        printNome(alunos, n);

        free(alunos);

        scanf("%d",&n);
        break;
    }

    return 0;
}