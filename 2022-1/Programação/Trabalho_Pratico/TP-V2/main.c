//Matheus Peixoto Ribeiro Vieira - 22.1.4104
#include <stdio.h>
#include <stdlib.h>
#include "cores.c"

typedef struct{
    char **tabuleiro;
    char jogadores[2][66];
    int numJogadas;
    int numJogadores;
}Partida;

void limparTerminal();
void imprimeMenuPrincipal(int comandoValido);
void lerCaracter(char *);
void reiniciarTabuleiro(char ***);
void imprimeTabuleiro(char **);

int main(){

    //Inicializando o tabuleiro
    Partida partida;
    partida.tabuleiro = malloc(3*sizeof(int*));
    for(int i=0; i<3; i++){
        partida.tabuleiro[i] = malloc(3*sizeof(int));
    }

    reiniciarTabuleiro(&partida.tabuleiro);

    imprimeTabuleiro(partida.tabuleiro);
    int comandoValido=1, finalizarPrograma = 0;
    char opcaoMenu;

    //Menu do Jogo
    do{
        imprimeMenuPrincipal(comandoValido);
        comandoValido = 1;
        lerCaracter(&opcaoMenu);

        switch (opcaoMenu){
            case '0':
                finalizarPrograma = 1;
                break;
            //Novo Jogo
            case '1':
                break;
            
            //Continuar jogo salvo
            case '2':
                break;

            //Voltar para o jogo em andamento
            case '3':
                break;

            //Visualizar o ranking
            case '4':
                break;

            default:
                comandoValido = 0;
                break;
        }

    }while(!finalizarPrograma);

    for(int i=0; i<3;i++){
        free(partida.tabuleiro[i]);
    }
    free(partida.tabuleiro);

}

//Apaga tudo que está escrito no terminal
void limparTerminal(){
    printf("\e[1;1H\e[2J");
}

//Imprime na tela as opções de menu
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

//Lê um único caracter e limpa o buffer, evitando o erro do \n
void lerCaracter(char *variavel){
    scanf("%c", variavel);
    //Limpando o buffer
    while (getchar() != '\n');
}

//Coloca todas as posiçoes do tabuleiro como ' '
void reiniciarTabuleiro(char ***tabuleiro){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            (*tabuleiro)[i][j] = ' ';
        }
    }

}

//Imprime a situação atual do tabuleiro da struct partida
void imprimeTabuleiro(char **tabuleiro){

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
            printf("%-2c| ", tabuleiro[i][j]);
        }
        printf("\n%s", linhaHorizontal);
    }
    printf("\n");

}







