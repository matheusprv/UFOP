//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "funcoes.h"
#include "structs.h"

#define TAM_MAX_NOMES 66

//Retorna 0 caso o jogo esteja acontecendo, 1 caso o jogador 1 ganhe, 2 caso o jogador 2 ganhe ou 3 caso de velha
int jogoFinalizado(char **tabuleiro, int numJogadas){
    //Cria-se um vetor para salvar as quatro formas de ganhar (horizontal, vertical, diagonais)
    //Com o verificador sendo X ou O, varre todo o tabuleiro e soma +1 no verificacoes toda vez que houver uma correspondencia
    //Reinicia em todas as repeticoes exteriores as verificacoes da linha e coluna, já que sempre serão as mesmas dentro da verificação interna
    //Compara se a soma feita é igual a 3. Se for, retorna o jogador vencedor

    //Como só há dois jogadores, para saber o atual, basta fazer o módulode dois no número de jogadas e somar mais um
    int jogador = numJogadas%2 + 1;
    char verificador = jogador == 1 ? 'X' : 'O';
    
    //verificacoes[0] - horizontal  |  verificacoes[1] - Vertical  |  verificacoes[2] - Diagonal princ|  verificacoes[3] - Diagonal sec
    int verificacoes[4];
    for(int i=0; i<4; i++)
        verificacoes[i] = 0;

    int espacosEmBranco = 0;
    
    for(int i=0; i<3; i++){
        verificacoes[0] = 0;
        verificacoes[1] = 0;
        
        //Verificando as linhas, colunas e se há espaços em branco no tabuleiro
        for(int j=0; j<3; j++){
            if(tabuleiro[i][j] == ' ')
                espacosEmBranco++;

            if(tabuleiro[i][j] == verificador)
                verificacoes[0] ++;

            if(tabuleiro[j][i] == verificador)
                verificacoes[1]++;
        }

        //Verificando se ganhou na horizontal ou vertical
        if(verificacoes[0] == 3 || verificacoes[1] == 3)
            return jogador;

        if(tabuleiro[i][i] == verificador)
            verificacoes[2]++;
        if(tabuleiro[3-i-1][3-i-1] == verificador)
            verificacoes[3]++;
    }

    //Verificando se ganhou nas diagonais
    if(verificacoes[2] == 3 || verificacoes[3] == 3)
        return jogador;

    //0 para caso o jogo ainda pode continuar ou 3 para caso seja velha
    return espacosEmBranco>=1 ? 0 : 3;

}

int lerComandos(int *linha, int *coluna, char **tabuleiro){
    
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
        if(tabuleiro[*linha][*coluna] != ' '){
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

void jogo(Partida *partida){
    int verificaJogoFinalizado = 0;
    int linha, coluna, comando;
    int *numJogadas = &partida->numJogadas;

    //Loop para solicitar um comando
    do{
        *numJogadas+=1;
        limparTerminal();
        imprimeTabuleiro(partida->tabuleiro);

        //Lendo um comando e verificando se ele é válido
        do{
            printf("%s, digite o comando: ", partida->nomeJogadores[*numJogadas%2]);
            comando = lerComandos(&linha, &coluna, partida->tabuleiro);
            if(comando == 0 || comando == -1)
                printf("Comando inválido\n");
            else
                break;
        }while(1);

        //Executando os comandos
        if(comando == 1){
            //Marca no tabuleiro
            //Jogador 1 é o X e o jogador 2 é o O
            partida->tabuleiro[linha][coluna] = *numJogadas%2 == 0 ? 'X' : 'O';

        }
        else if(comando == 2){
            //Salva o jogo
        }
        else{
            //Interrompe o jogo e volta para o menu principal
            partida->numJogadas -= 1;
            break;
        }

        //Fazer a verificação de uma vitória somente caso o número mínimo de jogadas seja atendido, ou seja,5
        //É adicionado +1 na comparação pelo fato do número de jogadas começar em 0
        if(*numJogadas+1>=5)
        verificaJogoFinalizado = jogoFinalizado(partida->tabuleiro, *numJogadas);
    }while(verificaJogoFinalizado == 0);

    //Verificação para não exibir quando o usuário for para o menu principal
    if(verificaJogoFinalizado >= 1){
        limparTerminal();
        imprimeTabuleiro(partida->tabuleiro);
        if(verificaJogoFinalizado == 3)
            printf("Empate! Nenhum Jogador venceu!\n");
        else
            printf("%s venceu!\n", partida->nomeJogadores[verificaJogoFinalizado-1]);

        printf("Digite uma tecla para prosseguir: ");
        char descarte;
        lerCaracter(&descarte);
    }

}

void menuNovoJogo(Partida *partida, int novoJogo){

    limparTerminal();
    if(novoJogo){

        reiniciarPartida(partida);

        printf("Digite a quantidade de jogadores (1 ou 2): ");
        char qtdJogadoresChar;
        lerCaracter(&qtdJogadoresChar);

        //Verificação para que a quantidade de jogadores seja somente 1 ou 2
        while(qtdJogadoresChar != '1' && qtdJogadoresChar != '2'){
            limparTerminal();
            printf("Quantidade de jogadores inválida.\n");
            printf("Digite a quantidade de jogadores (1 ou 2): ");
            lerCaracter(&qtdJogadoresChar);
        }

        partida->numJogadores = qtdJogadoresChar == '1' ? 1 : 2;
        //Salvando nome dos jogadores
        for(int i=0; i<partida->numJogadores;i++){
            printf("Digite o nome do Jogador %d: ", i+1);
            fgets(partida->nomeJogadores[i], TAM_MAX_NOMES+1, stdin);
            partida->nomeJogadores[i][strlen(partida->nomeJogadores[i]) -1] = '\0' ;
        }
        
    }
    jogo(partida);
}
