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

//Retorna 0 caso o jogo esteja acontecendo, 1 caso o jogador 1 ganhe, 2 caso o jogador 2 ganhe ou 3 caso de velha
int jogoFinalziado(char **);

int jogo(char **, char [][TAM_MAX_NOMES]);

//1 para marcar, 2 para salvar, 3 para voltar, 0 caso inválido, -1 posicoes inválidas
int lerComandos(int *, int*);




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

    //Criando a posição das jogadas
    char **disposicaoJogadas = malloc(3 * sizeof(char));
    for(int i=0; i<3;i++){
        disposicaoJogadas[i] = malloc (3 * sizeof(char));
        
        //Preenchendo todas as posições com um valor nulo
        for(int j=0; j<3; j++){
            disposicaoJogadas[i][j] = ' ';
        }
    }

    int respostaJogo = jogo(disposicaoJogadas, nomeJogadores);

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

int jogo(char **disposicaoJogadas, char nomeJogadores[][TAM_MAX_NOMES]){
    
    int numeroJogadas = -1;

    do{
        numeroJogadas++;
        limparTerminal();
        imprimeTabuleiro(disposicaoJogadas);
        int linha, coluna, comando;

        printf("%s, digite o comando: ", nomeJogadores[numeroJogadas%2]);
        comando = lerComandos(&linha, &coluna);

        while(comando == 0 || comando == -1){
            printf("Comando inválido\n");
            printf("%s, digite o comando: ", nomeJogadores[numeroJogadas%2]);
            comando = lerComandos(&linha, &coluna);
        }

        switch(comando){
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;
        }

    }while(!jogoFinalziado(disposicaoJogadas));

    return 1;
}

//Retorna 0 caso o jogo esteja acontecendo, 1 caso o jogador 1 ganhe, 2 caso o jogador 2 ganhe ou 3 caso de velha
int jogoFinalziado(char **disposicaoJogadas){
    return 1;
}

//1 para marcar, 2 para salvar, 3 para voltar, 0 caso inválido, -1 posicoes inválidas
int lerComandos(int *linha, int *coluna){
    
    char comando[12];
    //Lendo o comando feito pelo usuário
    fgets(comando, 12, stdin);
    comando[strlen(comando)-1] = '\0';
    int tamanhoComando = strlen(comando);

    //Verificando se foi digitado um comando válido
    if (strstr(comando, "marcar") != NULL) {
        
        char charLinha = comando[tamanhoComando-2];
        char charColuna = comando[tamanhoComando-1];

        //Transforma o char em inteiro a partir da subtração do valor do inteiro na tabela ascii com o valor de zero também na tabela ascii
        *linha = charLinha - '0';
        *coluna = charColuna - '0';

        if(*linha<1 || *linha>3 || *coluna<1 || *coluna>3){
            if(*linha<1 || *linha>3){
                printf("Linha inválida.\n");
            }
            if(*coluna<1 || *coluna>3){
                printf("Coluna inválida.\n");
            }
            return -1;
        }

        return 1;
    }
    else if (strstr(comando, "salvar") != NULL) {
        return 2;
    }
    else if (strstr(comando, "voltar") != NULL) {
        return 3;
    }
    else{
        return 0;
    }
}