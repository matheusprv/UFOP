//ORDENE CADA PALAVRA UTILIZANDO METODOS DE ORDENACAO
//SE NENHUM METODO FOR APLICADO DURANTE A RESOLUCAO, A QUESTAO SERA INVALIDADA

#include "ordenacao.h"

int main(){

    int casos_de_teste;
    scanf("%d",&casos_de_teste);
    getchar();

    char palavra[43];
    char palavra_original[43];
    char palavra_original_caixa_baixa[43];

    for(int cont=0; cont<casos_de_teste; cont++){

        scanf("%s", palavra);

        strcpy(palavra_original, palavra);    

        caixaBaixa(palavra);

        strcpy(palavra_original_caixa_baixa, palavra);    

        ordenaPalavra(palavra);

        printf("%s: %c\n", palavra_original, verificaOrdemAlfabetica(palavra, palavra_original_caixa_baixa) ? 'O' : 'N');
        
    }

    return 0;
}