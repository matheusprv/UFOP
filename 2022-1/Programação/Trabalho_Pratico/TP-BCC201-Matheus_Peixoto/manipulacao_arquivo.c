//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "structs.h"
#include "funcoes.h"
#include "ranking.h"
#include "cores.c"

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

    printf(GREEN("Jogo salvo com sucesso.\n"));
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
    //Verificando a primeira posição, pois ela 
    if(qtdJogadores[0] == '1'){
        partida->numJogadores = 1;
        strcpy(partida->nomeJogadores[1], "Computador");
    }
    else if(qtdJogadores[0] == '2'){
        partida->numJogadores = 2;
    }
    else{
        return -1;
    }

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
    
    fclose(arquivo);

    return 1;
    
}

int lerArquivoConfiguracao(Ranking **ranking){
    
    int qtdJogadores = 0;
    
    FILE *arquivo;
    arquivo = fopen("velha.ini", "r");

    //Verifica se o arquivo é nulo ou não
    int arquivoNulo = arquivo == NULL ? 1:0;
    int arquivoVazio;

    //Verificando se o arquivo está vazio, enviando o ponteiro para o final do arquivo e verificando a posição 
    if(!arquivoNulo){
        fseek(arquivo, 0, SEEK_END);
        int tamanhoArq = ftell(arquivo);
        arquivoVazio = tamanhoArq > 0 ? 0 : 1;
    }

    //Verificando se o arquivo é nulo ou está vazio
    if(arquivoNulo || arquivoVazio){
        //Criando um vetor somente com o Computador para caso não tenha ninguem no arquivo
        qtdJogadores = 1;
        
        *ranking =(Ranking *) malloc(qtdJogadores * sizeof(Ranking));
        
        strcpy((*ranking)[0].nomeJogador, "Computador");
        
        //Ajustando todas as estatísticas para zero
        (*ranking)[0].derrotas = 0;
        (*ranking)[0].empates = 0;
        (*ranking)[0].vitorias = 0;
        
        return qtdJogadores;
    }

    //Voltando o ponteiro para o incio do arquivo
    fseek(arquivo, 0, SEEK_SET);

    //Lendo a quantidade de jogadores e criando um vetor para esse número
    fscanf(arquivo, "%d\n", &qtdJogadores);
    *ranking =(Ranking *) malloc(qtdJogadores * sizeof(Ranking));

    //Lendo as informações de cada jogador
    int verificaComputadorNoArquivo = 0;
    for(int i=0; i<qtdJogadores; i++){
        fgets((*ranking)[i].nomeJogador, 266, arquivo);
        (*ranking)[i].nomeJogador[strlen((*ranking)[i].nomeJogador)-1] = '\0';

        //Verificando se o computador está no ranking, para adicioná-lo caso necessário
        if(strcmp((*ranking)[i].nomeJogador, "Computador") == 0)
            verificaComputadorNoArquivo = 1;

        fscanf(arquivo, "%d ", &(*ranking)[i].vitorias);
        fscanf(arquivo, "%d ", &(*ranking)[i].empates);
        fscanf(arquivo, "%d\n", &(*ranking)[i].derrotas);
    }

    fclose(arquivo);        

    //Adicionando o Computrador no ranking, caso necessário
    if(!verificaComputadorNoArquivo)
        adicionarJogdorNoRanking(ranking, &qtdJogadores, "Computador");

    return qtdJogadores;
}

void salvarArquivoConfiguracao(Ranking *ranking, int qtdJogadores){
    if(qtdJogadores>0){

        //Verifica se o computador está entre as 10 primeiras posições, se não estiver, coloca ele em décimo
        if(qtdJogadores>10){
            int posicaoComp = procurarPosicao(ranking, "Computador", qtdJogadores);
            ranking[9] = ranking[posicaoComp];
        }
        
        //Caso tenha mais de 10 jogadores, ajustar para exatamente 10
        qtdJogadores = qtdJogadores<=10 ? qtdJogadores : 10;

        //Escrevendo a quantidade de jogadores e os jogadores no arquivo
        FILE * arquivo = fopen("velha.ini", "w");

        fprintf(arquivo, "%d\n", qtdJogadores);

        for(int i=0; i<qtdJogadores; i++){
            fprintf(arquivo, "%s\n", ranking[i].nomeJogador);
            fprintf(arquivo, "%d %d %d\n", ranking[i].vitorias, ranking[i].empates, ranking[i].derrotas);
        }

        fclose(arquivo);
    }
}