#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 10001

typedef struct{
    char japones[TAM_MAX];
    char portugues[TAM_MAX]; 
}Dicionario;

typedef struct{
    char palavra[1000];
}Palavra;

int verificaQtdPalavras(char * palavra){
    int tamPalavra = strlen(palavra);
    int qtdPalavras = 1;
    for(int i = 0; i < tamPalavra; i++){
        if(palavra[i] == ' ')
            qtdPalavras++;
    }
    return qtdPalavras;
}

int main(){

    int instancias, m, n;
    scanf("%d", &instancias);
    getchar();
    for(int cont = 0; cont < instancias; cont++){

        scanf("%d%d", &m, &n);
        while( getchar() != '\n' );

        Dicionario * dicionarios = malloc(m * sizeof(Dicionario));

        for(int i = 0; i < m; i++){
            fgets(dicionarios[i].japones, TAM_MAX, stdin);
            dicionarios[i].japones[strlen(dicionarios[i].japones) - 1] = '\0';

            fgets(dicionarios[i].portugues, TAM_MAX, stdin);
            dicionarios[i].portugues[strlen(dicionarios[i].portugues) - 1] = '\0';
        }

        //Traduzir
        char pesquisa[TAM_MAX];
        for(int pesquisas = 0; pesquisas < n; pesquisas++){
            fgets(pesquisa, TAM_MAX, stdin);
            pesquisa[strlen(pesquisa) - 1] = '\0';

            int qtdPalavras = verificaQtdPalavras(pesquisa);

            //Salvando cada palavra em uma struct de palavras
            Palavra * palavras = malloc(qtdPalavras * sizeof(Palavra));
            char * token = strtok(pesquisa, " ");
            int i = 0;
            while(token != NULL){
                strcpy(palavras[i].palavra, token);
                i++;
            }

            //Fazendo a pesquisa concatenando as palavras
            for(i = 0; i < qtdPalavras; i++){
                if(strlen(palavras[i].palavra) == 1){
                    printf("%s", palavras[i].palavra);
                    continue;
                }
                    
                int encontrado = 0;
                int palavraAtual = i;
                char string_pesquisar [ TAM_MAX ];
                while(encontrado == 0){
                    strcat(string_pesquisar, palavras[palavraAtual].palavra);
                    for(int j = 0; j < m; j++){
                        if(strcmp(string_pesquisar, dicionarios[j].japones) == 0){
                            printf("%s ", dicionarios[j].portugues);
                        }
                    }
                }
                
            }

            free(palavras);

            printf("\n");
        }

        printf("\n");

        free(dicionarios);

    }

    return 0;
}