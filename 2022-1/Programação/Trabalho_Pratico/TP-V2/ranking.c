//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "ranking.h"
#include "cores.c"

void exibirRanking(Ranking *ranking, int qtdJogadores){

    for(int i=0; i<qtdJogadores; i++){
        if(i==0)
            printf(YELLOW("%s"), ranking[i].nomeJogador);
        else
            printf("%s ", ranking[i].nomeJogador);
        printf("\n\tVitórias: %d - Empates: %d - Derrotas: %d\n", ranking[i].vitorias, ranking[i].empates, ranking[i].derrotas);
    }
    printf("Digite qualquer tecla para continuar: ");
    getchar();
}

void adicionarJogdorNoRanking(Ranking **ranking, int *qtdJogadores, char * nomeJogador){
    //Aumentando a quantidade de jogadores da variavel e no vetor de jogadores no ranking
    *qtdJogadores += 1;
    *ranking = (Ranking *) realloc(*ranking, (*qtdJogadores)*sizeof(Ranking));
    strcpy((*ranking)[*qtdJogadores-1].nomeJogador, nomeJogador);

    //Ajustando todas as estatísticas para zero
    (*ranking)[*qtdJogadores-1].derrotas = 0;
    (*ranking)[*qtdJogadores-1].empates = 0;
    (*ranking)[*qtdJogadores-1].vitorias = 0;
}

int procurarPosicao(Ranking *ranking, char *nomeJogador, int qtdJogadores){
    for(int i=0; i<qtdJogadores; i++){
        if(strcmp(ranking[i].nomeJogador, nomeJogador) == 0)
            return i;
    }
    return -1;
}


void organizarRanking(Ranking **ranking, int *qtdJogadoresRanking, Partida partida, int resultado){
    //Verificando se os jogadores já estão no ranking
    for(int cont = 0; cont<2; cont++){
        int jogadorNoRanking = 0;
        for(int i=0; i<*qtdJogadoresRanking; i++){
            if(strcmp(partida.nomeJogadores[cont], (*ranking)[i].nomeJogador) == 0){
                jogadorNoRanking = 1;
                break;
            }
        }
        if(!jogadorNoRanking){
            adicionarJogdorNoRanking(ranking, qtdJogadoresRanking, partida.nomeJogadores[cont]);
        }
    }

    //Adicionando a vitória, empate ou derrota no ranking do jogador
    int posicaoJ1 = procurarPosicao(*ranking, partida.nomeJogadores[0], *qtdJogadoresRanking);
    int posicaoJ2 = procurarPosicao(*ranking, partida.nomeJogadores[1], *qtdJogadoresRanking);
    
    if(resultado == 1){
        (*ranking)[posicaoJ1].vitorias += 1;
        (*ranking)[posicaoJ2].derrotas += 1;    
    }
    else if(resultado == 2){
        (*ranking)[posicaoJ2].vitorias += 1;
        (*ranking)[posicaoJ1].derrotas += 1;    
    }
    else{
        (*ranking)[posicaoJ1].empates += 1;
        (*ranking)[posicaoJ2].empates += 1;   
    }

    // printf("Quantidade de jogadores = %d\n", *qtdJogadoresRanking);
    // for(int i=0; i<*qtdJogadoresRanking; i++){
    //     //printf("I = %d\n", i);
    //     // if(i==0)
    //     //     printf(YELLOW("%s"), ranking[i].nomeJogador);
    //     // else
    //     printf("%s ", (*ranking)[i].nomeJogador);
    //     printf("\nVitórias: %d - Empates: %d - Derrotas: %d\n", (*ranking)[i].vitorias, (*ranking)[i].empates, (*ranking)[i].derrotas);
    // }
    // printf("Digite qualquer tecla para continuar: ");
    // getchar();
    //Organizar o ranking por vitória
}
