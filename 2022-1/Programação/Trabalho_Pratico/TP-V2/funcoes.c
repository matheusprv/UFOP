//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "funcoes.h"
#include "structs.h"

//Apaga tudo que está escrito no terminal
void limparTerminal(){
    printf("\e[1;1H\e[2J");
}

//Imprime na tela as opções de menu
void imprimeMenuPrincipal(int comandoValido){
    limparTerminal();
    if(comandoValido == 0)
        printf("Comando inválido!\n");
    else if(comandoValido == -1)
        printf("Nenhum jogo foi iniciado para ser retornado.\n");
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



//Reinicia todos os valores do struct para um valor padrao a fim de iniciar um novo jogo
void reiniciarPartida(Partida *partida){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ((*partida).tabuleiro)[i][j] = ' ';
        }
    }
    partida->numJogadas = -1;
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



