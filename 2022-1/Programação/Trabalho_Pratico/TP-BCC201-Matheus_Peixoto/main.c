//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TAM_MAX_NOMES 31

void limparTerminal();

void lerCaracter(char *variavel);

void liberarMatrizesChar(char **matriz);

void imprimeMenuPrincipal(int comandoValido);

void menuNovoJogo();

void imprimeTabuleiro(char **);

int main(){

    char opcao;
    int comandoValido = 1;
    
    imprimeMenuPrincipal(comandoValido);
    lerCaracter(&opcao);

    while (opcao !='0' ){
        switch (opcao){
            case '1':
                menuNovoJogo();
                break;
            
            case '2':

                break;

            case '3':

                break;

            case '4':

                break;

            default:
                comandoValido = 0;
                break;
        }

        imprimeMenuPrincipal(comandoValido);
        lerCaracter(&opcao);
    }
    

    return 0;
}

void limparTerminal(){
    printf("\e[1;1H\e[2J");
}

void lerCaracter(char *variavel){
    scanf("%c", variavel);
    getchar();
    //fflush(stdin);
}

void liberarMatrizeChar(char **matriz){
    for(int i=0; i<3; i++)
        free(matriz[i]);
    free(matriz);
}

void imprimeMenuPrincipal(int comandoValido){
    limparTerminal();
    if(!comandoValido)
    printf("Comando inválido!\n");
    printf("Bem vindo(a) ao Jogo da Velha\n");
    printf("\t1 - Começar novo jogo.\n");
    printf("\t2 - Carregar um jogo salvo.\n");
    printf("\t3 - Voltar para o jogo em andamento.\n");
    printf("\t4 - Exibir ranking.\n");
    printf("\t0 - Sair\n");
    printf("Durante o jogo, digite \"voltar\" para retornar ao menu.\n");
    printf("Escolha uma opção: ");
}



void menuNovoJogo(){
    limparTerminal();
    //Verificando quantos jogadores farão parte da partida
    printf("Digite a quantidade de jogadores (1 ou 2): ");
    char qtdJogadoresChar;
    lerCaracter(&qtdJogadoresChar);

    while(qtdJogadoresChar != '1' && qtdJogadoresChar != '2'){
        limparTerminal();
        printf("Quantidade de jogadores inválida.\n");
        printf("Digite a quantidade de jogadores (1 ou 2): ");
        lerCaracter(&qtdJogadoresChar);
    }

    int qtdJogadores = qtdJogadoresChar == '1' ? 1 : 2;

    //Salvando nome dos jogadores
    char nomeJogadores[2][TAM_MAX_NOMES];
    for(int i=0; i<qtdJogadores;i++){
        printf("Digite o nome do Jogador %d: ", i+1);
        fgets(nomeJogadores[i], TAM_MAX_NOMES+1, stdin);
        nomeJogadores[i][strlen(nomeJogadores[i]) -1] = '\0' ;
    }

    char **disposicaoJogadas = malloc(3 * sizeof(char));
    for(int i=0; i<3;i++){
        disposicaoJogadas[i] = malloc (3 * sizeof(char));
        
        //Preenchendo todas as posições com um valor nulo
        for(int j=0; j<3; j++){
            disposicaoJogadas[i][j] = ' ';
        }
    }

    imprimeTabuleiro(disposicaoJogadas);
    liberarMatrizeChar(disposicaoJogadas);

    //Somente durante a produção, paa evitar que o jogo saia para o menu sem exibir o que foi modificado
    //char lixo;
    //scanf("%c", &lixo);
    getchar();
}



void imprimeTabuleiro(char **disposicaoJogadas){

    char linhaHorizontal[] = "---------------";
    printf("  | ");
    // Imprimindo o cabeçalho
    for(int i=1;i<=3; i++){
        printf("%-2d| ", i);
    }
    printf("\n%s", linhaHorizontal);

    // Imprimindo a disposição das jogadas
    for (int i = 0; i < 3; i++){
        printf("\n%-2d| ",i+1);
        for(int j=0; j <3; j++){
            printf("%-2c| ", disposicaoJogadas[i][j]);
        }
        printf("\n%s", linhaHorizontal);
    }
    printf("\n");

}