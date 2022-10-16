//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "funcoes.h"
#include "structs.h"
#include "cores.c"

//Apaga tudo que está escrito no terminal
void limparTerminal(){
    //printf("\e[1;1H\e[2J");
}

//Imprime na tela as opções de menu
void imprimeMenuPrincipal(int comandoValido){
    limparTerminal();
    if(comandoValido == 0)
        printf(RED("Comando inválido!\n"));
    else if(comandoValido == -1)
        printf(RED("Nenhum jogo foi iniciado para ser retornado.\n"));
    else if(comandoValido == -2)
        printf(RED("Arquivo não encontrado!\n"));
    else if(comandoValido == -3)
        printf(RED("Ainda não há jogadores no ranking"));

    printf("\n\t1 - Começar novo jogo.\n");
    printf("\t2 - Carregar um jogo salvo.\n");
    printf("\t3 - Voltar para o jogo em andamento.\n");
    printf("\t4 - Exibir ranking.\n");
    printf("\t0 - Sair\n\n");
    printf("Durante o jogo, digite \"voltar\" para retornar ao menu.\n");
    printf("Escolha uma opção: ");
}

//Lê uma string e retorna o primeiro caracter. Caso o usuário tenha escrito mais de um, retorna um valor inválido e limpa o buffer
void lerCaracter(char *variavel){
    char string[50];
    fgets(string, 50, stdin);
    if(string[1] != '\n')
        string[0] = '9';

    //Limpando o buffer
    if(strlen(string)>50)
        while (getchar() != '\n');

    //Como todas as leituras de caracteres são para números, caso receba uma letra, a verificação entrará no loop
    *variavel = string [0];
    //printf("\n\nVariavel: %c\n\n", *variavel);
}

void lerString(char *string){
    fgets(string, 266, stdin);
    
    int tamanhoString = strlen(string);
    
    //Limpando o buffer, caso tenha sido ultrapassado o limite máximo
    if(tamanhoString>266)
        while (getchar() != '\n');       
    

    //Verificando se a string contem o \n e removendo-o
    int posicaoBarraN = -1;
    for(int i=0; i<tamanhoString; i++){
        if(string[i] == '\n'){
            posicaoBarraN = i;
            break;
        }
    }
    if(posicaoBarraN >= 0)
        string[posicaoBarraN] = '\0';
}

//Reinicia todos os valores do struct para um valor padrao a fim de iniciar um novo jogo
void reiniciarPartida(Partida *partida){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ((*partida).tabuleiro)[i][j] = ' ';
        }
    }

    //Para exibir o jogador da vez, utiliza-se o módulo do número de jogadas por 2, pois os nomes estão em um vetor
    //A primeira jogada é a zero, pois o módulo de 0 por 2 é 0, portanto apresenta o nome do jogador 1
    partida->numJogadas = -1;

    //Alterando o nome do segundo jogador para computador
    //Caso o jogador seja humano, somente irá alterar o seu valor na variavel
    char computador[] = "Computador";
    strcpy(partida->nomeJogadores[1], computador);
}

//Imprime a situação atual do tabuleiro da struct partida
void imprimeTabuleiro(char **tabuleiro){

    printf("  \u2503 ");
    // Imprimindo o cabeçalho
    for(int i=1;i<=3; i++){
        printf("%-2d\u2503 ", i);
    }

    printf("\n%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR);

    // Imprimindo a disposição das jogadas
    for (int i = 0; i < 3; i++){
        printf("\n%-2d\u2503 ",i+1);
        for(int j=0; j <3; j++){
            printf("%-2c\u2503 ", tabuleiro[i][j]);
        }
        printf("\n%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR,TAB_HOR);
    }
    printf("\n");

}



