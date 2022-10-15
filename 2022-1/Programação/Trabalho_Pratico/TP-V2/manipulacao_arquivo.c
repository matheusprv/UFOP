//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "structs.h"
#include "funcoes.h"
#include "ranking.h"

#define TAM_MAX_STRING 266

void salvarJogo(Partida partida, char *arquivoSalvarJogo){
    FILE *arquivo = fopen(arquivoSalvarJogo, "w");
    
    fprintf(arquivo, "%d\n", partida.numJogadores);
    
    //Imprimindo o nome dos jogadores
    for(int i=0; i<partida.numJogadores; i++){
        fprintf(arquivo, "%s\n",partida.nomeJogadores[i]);
    }

    //Imprimindo o tabuleiro
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            fprintf(arquivo, "%c", partida.tabuleiro[i][j] == ' ' ? '-' : partida.tabuleiro[i][j]);
            fprintf(arquivo, " ");
        }
        fprintf(arquivo, "\n");
    }

    //Imprimindo qual foi o último jogador
    fprintf(arquivo, "%d", (partida.numJogadas)%2 == 0 ? 1 : 2);

    fclose(arquivo);
}

int lerJogoSalvo(Partida *partida){
    char nomeArquivo[TAM_MAX_STRING];
    
    printf("Digite o nome do arquivo com o jogo salvo: ");
    lerString(nomeArquivo);

    //Verificando se o arquivo existe
    FILE *arquivo;
    if(!(arquivo = fopen(nomeArquivo, "r"))){
        return 0;
    }
    
    //Verificando se é humano X humano ou humano X maquina
    char qtdJogadores[3];
    fgets(qtdJogadores, 3, arquivo);
    partida->numJogadores = qtdJogadores[0] == '1' ? 1 : 2;

    //Lendo o nome do jogador e removendo o \n
    for(int i=0; i<partida->numJogadores; i++){
        fgets(partida->nomeJogadores[i], TAM_MAX_STRING+1, arquivo);
        int tamanhoString = strlen(partida->nomeJogadores[i]);
        partida->nomeJogadores[i][tamanhoString-1] = '\0';
    }

    //Preenchendo o tabuleiro com os parametros do arquivo de texto e contando o numero de jogadas
    char linha[8];
    partida->numJogadas = -1;
    
    for(int i=0; i<3; i++){
        fgets(linha, 8, arquivo);
        int coluna =0;
        for(int j=0; j<=4; j++){
            if(linha[j] != ' '){
                //Substituindo os '-' por espaços em branco e somando mais uma rodada para quando encontrar um 'X' ou 'O'
                if(linha[j] == '-')
                    partida->tabuleiro[i][coluna] = ' ';

                else{
                    partida->numJogadas += 1;
                    partida->tabuleiro[i][coluna] = linha[j];
                }
                coluna++;
            }
        }

    }
    //getchar();
    fclose(arquivo);

    return 1;
    
}

int lerArquivoConfiguracao(Ranking **ranking){
    FILE *arquivo;
    //Verificando se o arquivo existe
    if(!(arquivo = fopen("velha.ini", "rb"))){
        return -1;
    }

    //Verificando se o arquivo está vazio
    fseek (arquivo, 0, SEEK_END);
    int tamanhoArquivo = ftell(arquivo);
    if (tamanhoArquivo == 0) {
        return 0;
    }

    int qtdJogadores;
    fread(&qtdJogadores, sizeof(int), 1, arquivo);
    
    *ranking = malloc(qtdJogadores * sizeof(Ranking));
    
    fread(ranking, sizeof(Ranking), qtdJogadores, arquivo);
    
    fclose(arquivo);
    return qtdJogadores;

    return 1;
}