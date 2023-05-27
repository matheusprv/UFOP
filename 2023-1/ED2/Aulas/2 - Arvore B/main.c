#include "arvore_b.h"
#include <time.h>


int main(){
    TipoApontador arvore = iniciaArvore();

    srand(100);

    TipoRegistro registro;

    for(int i = 0; i < 100; i++){
        registro.chave = i;
        registro.valorArbitrario = rand()%1000000;
        Insere(registro, &arvore);
    }


    long pesquisar;
    while (1){
        printf("Digite o valor para pesquisar: ");
        scanf("%ld", &pesquisar);

        pesquisa(pesquisar, arvore);
    }
    

    return 0;
}