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

void jogo(char **, char [][TAM_MAX_NOMES]);

//1 para marcar, 2 para salvar, 3 para voltar, 0 caso inválido, -1 posicoes inválidas
int lerComandos(int *, int*, char**);



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

    jogo(disposicaoJogadas, nomeJogadores);

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

void jogo(char **disposicaoJogadas, char nomeJogadores[][TAM_MAX_NOMES]){
    
    int numeroJogadas = -1;
    int verificaJogoFinalizado;
    //Loop para solicitar o usuário um comando
    do{
        numeroJogadas++;
        limparTerminal();
        imprimeTabuleiro(disposicaoJogadas);
        int linha, coluna, comando;

        //Lendo um comando e verificando se ele é válido
        printf("%s, digite o comando: ", nomeJogadores[numeroJogadas%2]);
        comando = lerComandos(&linha, &coluna, disposicaoJogadas);

        while(comando == 0 || comando == -1){
            printf("Comando inválido\n");
            printf("%s, digite o comando: ", nomeJogadores[numeroJogadas%2]);
            comando = lerComandos(&linha, &coluna, disposicaoJogadas);
        }

        //Executando os comandos
        if(comando == 1){
            //Jogador 1 é o X e o jogador 2 é o O
            disposicaoJogadas[linha][coluna] = numeroJogadas%2 == 0 ? 'X' : 'O';

        }
        else if(comando == 2){

        }
        else{
            //Interrompe o jogo e volta para o menu principal
            break;
        }

        verificaJogoFinalizado = jogoFinalziado(disposicaoJogadas);

    }while( verificaJogoFinalizado == 0);

    //Exibe o tabuleiro e quem venceu.
    limparTerminal();
    imprimeTabuleiro(disposicaoJogadas);

    switch (verificaJogoFinalizado){
        case 1:
            printf("%s venceu!\n", nomeJogadores[0]);
            break;
        case 2:
            printf("%s venceu!\n", nomeJogadores[1]);
            break;
        default:
            printf("Empate! Nenhum Jogador venceu!\n");
    }
}


//1 para marcar, 2 para salvar, 3 para voltar, 0 caso inválido, -1 posicoes inválidas
int lerComandos(int *linha, int *coluna, char ** disposicaoJogadas){
    
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
        *linha = charLinha - '0' - 1;
        *coluna = charColuna - '0' - 1;

        //Verificando se a linha e coluna são válidas
        if(*linha<0 || *linha>2 || *coluna<0 || *coluna>2){
            if(*linha<0 || *linha>2){
                printf("Linha inválida.\n");
            }
            if(*coluna<0 || *coluna>2){
                printf("Coluna inválida.\n");
            }
            return -1;
        }
        //Verificando se é possível utilizar o espaço solicitado
        if(disposicaoJogadas[*linha][*coluna] != ' '){
            printf("Esse espaço já foi marcado!\n");
            return -1;
        }

        return 1;
    }
    //Salvar Jogo
    else if (strstr(comando, "salvar") != NULL) {
        return 2;
    }
    //Voltar para o menu principal
    else if (strstr(comando, "voltar") != NULL) {
        return 3;
    }
    //Mensagem de comando inválido
    else{
        return 0;
    }
}


//Retorna 0 caso o jogo esteja acontecendo, 1 caso o jogador 1 ganhe, 2 caso o jogador 2 ganhe ou 3 caso de velha
int jogoFinalziado(char **disposicaoJogadas){
    char vitoriaJogador1[] = "XXX"; 
    char vitoriaJogador2[] = "OOO";
    
    char posicoesDoTabuleiro[4];
    posicoesDoTabuleiro[4] = '\0';
    
    //Verificando as linhas do tabuleiro
    for(int l=0; l<3; l++){
        for(int c=0; c<3;c++){
            posicoesDoTabuleiro[c] = disposicaoJogadas[l][c];
        }
        
        if(strcmp(posicoesDoTabuleiro, vitoriaJogador1) == 0){
            return 1;
        }
        else if(strcmp(posicoesDoTabuleiro, vitoriaJogador2) == 0){
            return 2;
        }
    }

    //Verificando as colunas do tabuleiro
    for(int c = 0; c<3; c++){
        for(int l=0; l<3; l++){
            posicoesDoTabuleiro[c] = disposicaoJogadas[l][c];
        }

        if(strcmp(posicoesDoTabuleiro, vitoriaJogador1) == 0){
            return 1;
        }
        else if(strcmp(posicoesDoTabuleiro, vitoriaJogador2) == 0){
            return 2;
        }
    }

    //Verificando na diagonal
    for(int i=0; i<3; i++){
        posicoesDoTabuleiro[i] = disposicaoJogadas[i][i];
    }
    if(strcmp(posicoesDoTabuleiro, vitoriaJogador1) == 0){
        return 1;
    }
    else if(strcmp(posicoesDoTabuleiro, vitoriaJogador2) == 0){
        return 2;
    }

    // Verificando na outra diagonal
    for(int i=2; i>=0; i--){
        posicoesDoTabuleiro[i] = disposicaoJogadas[i][2-i];
    }
    if(strcmp(posicoesDoTabuleiro, vitoriaJogador1) == 0){
        return 1;
    }
    else if(strcmp(posicoesDoTabuleiro, vitoriaJogador2) == 0){
        return 2;
    }

    //Verifica se ainda há espaços em branco, se houver, retorna 0 e o jogo continua, caso contrario, retorna 3, pois deu velha
    int contemEspacoEmBranco = 0;
    for(int i =0; i<3; i++){
        for(int j=0;j<3;j++){
            if(disposicaoJogadas[i][j] == ' '){
                contemEspacoEmBranco = 1;
            }
        }
    }

    return contemEspacoEmBranco == 1 ? 0 : 3;
}
