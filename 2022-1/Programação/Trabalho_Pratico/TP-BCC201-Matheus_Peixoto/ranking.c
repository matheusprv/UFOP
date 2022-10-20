//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "ranking.h"
#include "cores.c"

void alinharAoMeioTabela(char *nome, int maiorStringNome){

}


void exibirRanking(Ranking *ranking, int qtdJogadores){
    //Procurando a maior string dos nomes para exibir os nomes coma a tabela formatada
    int tamanhoStrJogador = strlen("Jogador");
    int maiorStringNome = tamanhoStrJogador;
    for(int i=0; i<qtdJogadores; i++){
        int tamanhoStringAtual = strlen(ranking[i].nomeJogador);
        if(tamanhoStringAtual > maiorStringNome)
            maiorStringNome = tamanhoStringAtual;
    }
    printf("Maior String: %d\n", maiorStringNome);
    //Verificar a quantidade de espaços para ser adicionado
    int qtdEspacos;
    if(maiorStringNome>tamanhoStrJogador){
        qtdEspacos = (maiorStringNome-tamanhoStrJogador);
    }
    
    printf(BOLD(" Posição "TAB_VER));

    //Exibindo a palavra jogador com a quantidade de espaços necessário
    for(int i=0; i<(qtdEspacos+1)/2; i++)
        printf(" ");
    printf(BOLD(" Jogador"));
    for(int i=0; i<(qtdEspacos+1)/2; i++)
        printf(" ");
    printf(TAB_VER);

    printf(BOLD(" Vitórias "TAB_VER " Empates "TAB_VER" Derrotas "TAB_VER"\n"));

    for(int i=0; i<qtdJogadores; i++){

        //Exibindo a posição do jogador
        printf("%7dº "TAB_VER, i+1);

        //Verificando a quantidade de espaços para o nome do jogador
        int tamanhoNomeJogador = strlen(ranking[i].nomeJogador);
        if(maiorStringNome>tamanhoNomeJogador)
            qtdEspacos = (maiorStringNome-tamanhoNomeJogador);
        else
            qtdEspacos = 0;

        //Cores para o podium
        if(i==0)
            printf(YELLOW(" %s"), ranking[i].nomeJogador);
        else if(i==1)
            printf(WHITE(" %s"), ranking[i].nomeJogador);
        else if(i==2)
            printf(BLUE(" %s"), ranking[i].nomeJogador);
        else
            printf(" %s", ranking[i].nomeJogador);
        //Imprimindo os espaços
        for(int j=0; j<qtdEspacos+1; j++)
            printf(" ");
        printf(TAB_VER);

        printf(" %8d "TAB_VER" %7d "TAB_VER" %8d "TAB_VER"\n", ranking[i].vitorias, ranking[i].empates, ranking[i].derrotas);
    
    }
    printf("\nDigite qualquer tecla para continuar: ");
    char lixo;
    lerCaracter(&lixo);
}

//Adiciona mais um jogador no vetor de ranking
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

//Retorna a posição de um jogador no vetor de ranking
int procurarPosicao(Ranking *ranking, char *nomeJogador, int qtdJogadores){
    for(int i=0; i<qtdJogadores; i++){
        if(strcmp(ranking[i].nomeJogador, nomeJogador) == 0)
            return i;
    }
    return -1;
}

//Recebe o resultado de uma partida, atualiza os resultados e ordena o ranking
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

    //Organizar o ranking por vitória
    Ranking aux;
    for(int i=0; i<*qtdJogadoresRanking; i++){
        for(int j=0; j<*qtdJogadoresRanking; j++){
            if((*ranking)[i].vitorias>(*ranking)[j].vitorias){
                aux = (*ranking)[j];
                (*ranking)[j] = (*ranking)[i];
                (*ranking)[i] = aux;
            }
        }
    }

    //Usando o número de empates como critéiro de desempate
    for(int i=0; i<*qtdJogadoresRanking; i++){
        for(int j=0; j<*qtdJogadoresRanking; j++){
            if(((*ranking)[i].vitorias == (*ranking)[j].vitorias) && ((*ranking)[i].empates > (*ranking)[j].empates)){
                aux = (*ranking)[j];
                (*ranking)[j] = (*ranking)[i];
                (*ranking)[i] = aux;
            }
        }
    }

    //Utilizando o menor número de derrotas como desempate 
    for(int i=0; i<*qtdJogadoresRanking; i++){
        for(int j=0; j<*qtdJogadoresRanking; j++){
            if(((*ranking)[i].vitorias == (*ranking)[j].vitorias) && ((*ranking)[i].empates == (*ranking)[j].empates) && ((*ranking)[i].derrotas < (*ranking)[j].derrotas)  ){
                aux = (*ranking)[j];
                (*ranking)[j] = (*ranking)[i];
                (*ranking)[i] = aux;
            }
        }
    }
}
