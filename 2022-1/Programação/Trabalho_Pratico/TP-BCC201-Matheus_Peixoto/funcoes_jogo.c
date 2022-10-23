//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "funcoes.h"
#include "manipulacao_arquivo.h"
#include "computador.h"
#include "structs.h"
#include "ranking.h"
#include "cores.c"

#define TAM_MAX_STRING 266

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

        if(tabuleiro[i][2-i] == verificador)
            verificacoes[3]++;
    }
    //Verificando se ganhou nas diagonais
    if(verificacoes[2] == 3 || verificacoes[3] == 3)
        return jogador;

    //0 para caso o jogo ainda pode continuar ou 3 para caso seja velha
    return espacosEmBranco>=1 ? 0 : 3;

}

int lerComandos(int *linha, int *coluna, char **tabuleiro, char arquivoSalvarJogo[TAM_MAX_STRING]){
    
    char leitorComando [TAM_MAX_STRING]; //String responsavel por ler o comando do usuário
    char comando[2][TAM_MAX_STRING]; //A primeira posição indica se irá marcar ou salvar e a segunda indica o parametro

    lerString(leitorComando);
    int tamanhoLeitorComando = strlen(leitorComando);

    //O comando deve possuir, no máximo, duas substrings
    int qtdSubstring = 0;
    for(int i=0; i<=tamanhoLeitorComando; i++){
        if(leitorComando[i] == ' ' || leitorComando[i] == '\0')
            qtdSubstring++;
    }
        
    //Verificando se o comando é o de voltar, pois somente ele possui uma palavra
    if(qtdSubstring == 1 && strcmp(leitorComando, "voltar") == 0)
        return 3;//Volta ao menu principal
    else if(qtdSubstring == 1 && strcmp(leitorComando, "voltar") != 0)
        return 0;//Retorna uma mesangem de erro, pois não há comandos de um palavra que não seja o voltar

    //Retorna mensagem de erro por não haver nenhum comando com mais de duas palavras ou um comando diferente do voltar somente com uma substring
    if(qtdSubstring != 2)
        return 0;

    //Verifica se não está nulo após o primeiro espaço 
    if(qtdSubstring == 2 && tamanhoLeitorComando == 7){
        return 0;
    }

    //Salvando as substrings da string de comando
    strcpy(comando[0],strtok(leitorComando, " "));
    strcpy(comando[1],strtok(NULL, " "));
    
    //Verificando se foi digitado um comando válido
    if (strcmp(comando[0], "marcar") == 0) {

        int tamanhoParametro = strlen(comando[1]);
        //Retorna -1 para quando o usuário colocar uma quantidade diferente de uma linha e uma coluna. Ex: marcar 111
        if(tamanhoParametro != 2){
            return -1;
        }

        char charLinha = comando[1][0];
        char charColuna = comando[1][1];

        //Transforma o char em inteiro a partir da subtração do valor do inteiro na tabela ascii com o valor de zero também na tabela ascii
        *linha = charLinha - '0' - 1;
        *coluna = charColuna - '0' - 1;

        //Verificando se a linha e coluna são válidas
        if(*linha<0 || *linha>2 || *coluna<0 || *coluna>2){
            if(*linha<0 || *linha>2){
                printf(YELLOW("Linha inválida.\n"));
            }
            if(*coluna<0 || *coluna>2){
                printf(YELLOW("Coluna inválida.\n"));
            }
            return -1;
        }
        //Verificando se é possível utilizar o espaço solicitado
        if(tabuleiro[*linha][*coluna] != ' '){
            printf(YELLOW("Esse espaço já foi marcado!\n"));
            return -3; //Retorno genérico para sair da função
        }

        return 1;
    }
    //Salvar Jogo
    else if (strstr(comando[0], "salvar") != NULL) {
        strcpy(arquivoSalvarJogo, comando[1]);
        return 2;
    }
    //Mensagem de comando inválido
    else{
        return 0;
    }
}

int jogo(Partida *partida){
    int verificaJogoFinalizado = 0;
    int linha, coluna, comando;
    int *numJogadas = &partida->numJogadas;

    char arquivoSalvarJogo[TAM_MAX_STRING];

    //Loop para solicitar um comando
    do{
        *numJogadas+=1;
        
        //Só entra no if caso a partida seja para dois jogadores ou o jogador da vez é o jogador 1
        if(partida->numJogadores == 2 || (partida->numJogadas%2==0)){
            imprimeTabuleiro(partida->tabuleiro);
            
            //Lendo um comando e verificando se ele é válido
            do{
                printf(BOLD("%s, digite o comando: "), partida->nomeJogadores[*numJogadas%2]);
                comando = lerComandos(&linha, &coluna, partida->tabuleiro, arquivoSalvarJogo);
                
                if(comando == 0){
                    printf(RED("Comando inválido!\n"));
                }
                else if(comando==-1){
                    printf(YELLOW("Quantidade de linha e coluna supera o esperado.\n"));
                }
                else if(comando == 3){
                    //Sai do loop para voltar ao menu principal
                    break;
                }
            }while(comando <= 0);

            //Executando os comandos
            if(comando == 1){
                //Marca no tabuleiro
                //Jogador 1 é o X e o jogador 2 é o O
                partida->tabuleiro[linha][coluna] = *numJogadas%2 == 0 ? 'X' : 'O';

            }
            else if(comando == 2){
                *numJogadas-=1;//Diminui em 1 o número de jogadas pois o jogador ainda não realizou a sua jogada, somente salvou o jogo
                //Salva o jogo
                printf("Salvando arquivo \"%s\"\n", arquivoSalvarJogo);
                salvarJogo(*partida, arquivoSalvarJogo);
            }
            else{
                //Interrompe o jogo e volta para o menu principal
                partida->numJogadas -= 1;//Removendo a jogada atual
                break;
            }        

        }
        else{
            jogadaComputador(partida);
        }

        //Fazer a verificação de uma vitória somente caso o número mínimo de jogadas seja atendido, ou seja,5
        //É adicionado +1 na comparação pelo fato do número de jogadas começar em 0
        if(*numJogadas+1>=5)
        verificaJogoFinalizado = jogoFinalizado(partida->tabuleiro, *numJogadas);
        
    }while(verificaJogoFinalizado == 0);

    //Verificação para não exibir quando o usuário for para o menu principal
    if(verificaJogoFinalizado >= 1){
        imprimeTabuleiro(partida->tabuleiro);
        if(verificaJogoFinalizado == 3)
            printf(BLUE("Empate! Nenhum Jogador venceu!\n"));
        else
            printf(GREEN("%s venceu!\n\n"), partida->nomeJogadores[verificaJogoFinalizado-1]);

        /*printf("Digite uma tecla para prosseguir: ");
        char descarte;
        lerCaracter(&descarte);*/
    }
    return verificaJogoFinalizado;

}

int menuNovoJogo(Partida *partida, int novoJogo){

    if(novoJogo){

        printf(CYAN("NOVO JOGO\n"));

        reiniciarPartida(partida);

        printf(BOLD("Digite a quantidade de jogadores (1 ou 2): "));
        char qtdJogadoresChar;
        lerCaracter(&qtdJogadoresChar);

        //Verificação para que a quantidade de jogadores seja somente 1 ou 2
        while(qtdJogadoresChar != '1' && qtdJogadoresChar != '2'){
            printf(RED("Quantidade de jogadores inválida.\n"));
            printf(BOLD("Digite a quantidade de jogadores (1 ou 2): "));
            lerCaracter(&qtdJogadoresChar);
        }

        partida->numJogadores = qtdJogadoresChar == '1' ? 1 : 2;
        //Salvando nome dos jogadores
        for(int i=0; i<partida->numJogadores;i++){
            do{
                printf(BOLD("Digite o nome do Jogador %d: "), i+1);
                lerString(partida->nomeJogadores[i]);

                if(strlen(partida->nomeJogadores[i]) == 0)
                    printf(RED("O nome é muito curto\n"));

                if(i == 1 && strcmp(partida->nomeJogadores[0], partida->nomeJogadores[1]) == 0){
                    printf(RED("O nome do jogador 2 não pode ser o mesmo do jogador 1.\n"));
                    partida->nomeJogadores[1][0] = '\0';//Alterando o nome do usuário para um valor nulo para ele ficar preso no loop
                }
                if(strcmp(partida->nomeJogadores[i], "Computador") == 0){
                    printf(RED("O nome não pode ser \"Computador\"\n"));
                    partida->nomeJogadores[i][0] = '\0';//Alterando o nome do usuário para um valor nulo para ele ficar preso no loop
                }
            }while (strlen(partida->nomeJogadores[i]) == 0);
            
        }
        partida->partidaIniciada = 1;
    }
    int resultado = jogo(partida);
    return resultado;
}
