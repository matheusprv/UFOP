//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "ranking.h"
#include "cores.c"

void alinharAoMeioTabela(char *strExibir, int maiorStringNome){
    //Verificar a quantidade de espaços para ser adicionado
    int qtdEspacos, tamanhoStr = strlen(strExibir);
    int caracteresImpressos = 0; //Verifica quantos caracteres já foram adicionados à esquerda e o nome para adicionar o que falta à direita

    //Somente entra no if quando não for a maior palavra, pois ela não precisa ter espaços adicionados
    if(maiorStringNome>tamanhoStr){

        qtdEspacos = (maiorStringNome-tamanhoStr);

        //Exibindo a palavra jogador com a quantidade de espaços necessário
        for(int i=0; i<(qtdEspacos)/2; i++){
            printf(" ");
            caracteresImpressos++;
        }
            
    }
    printf("%s", strExibir);
    caracteresImpressos += tamanhoStr;

    //Somente entra no if quando não for a maior palavra, pois ela não precisa ter espaços adicionados
    if(maiorStringNome>tamanhoStr){
        for(; caracteresImpressos<maiorStringNome; caracteresImpressos++){
            printf(" ");
        }
    }

    printf("\x1b[0m "TAB_VER);
    
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

    printf(BOLD(" Posição "TAB_VER));

    //Adicionando o BOLD antes da chamada da função, que faz uma impressão, e fecha o mesmo ao fim da função
    printf("\x1b[1m ");
    alinharAoMeioTabela(" Jogador ", maiorStringNome);
    printf("\x1b[0m");

    printf(BOLD(" Vitórias "TAB_VER " Empates "TAB_VER" Derrotas "TAB_VER"\n"));

    for(int i=0; i<qtdJogadores; i++){

        //Exibindo a posição do jogador
        printf("%7dº "TAB_VER" ", i+1);

        //Cores para o podium
        if(i==0){
            printf("\x1b[33m");
        }
        else if(i==1){
            printf("\x1b[37m");
        }
        else if(i==2){
            printf("\x1b[34m");
        }  

        alinharAoMeioTabela(ranking[i].nomeJogador, maiorStringNome);

        printf(" %8d "TAB_VER" %7d "TAB_VER" %8d "TAB_VER"\n", ranking[i].vitorias, ranking[i].empates, ranking[i].derrotas);
    
    }
    printf("\nDigite qualquer tecla para continuar: ");
    char lixo;
    lerCaracter(&lixo);
}

void exibirJogadoresPartida(Ranking *ranking, int qtdJogadoresRanking, Partida partida){
    int posJogador1 = procurarPosicao(ranking, partida.nomeJogadores[0], qtdJogadoresRanking);
    int posJogador2 = procurarPosicao(ranking, partida.nomeJogadores[1], qtdJogadoresRanking);

    //Altera a posição dos jogadores caso o jogador 2 esteja em um indíce menor, ou seja na frente
    if(posJogador2>posJogador1){
        int aux = posJogador2;
        posJogador2 = posJogador1;
        posJogador1 = aux;
    }

    int posJogadores[] = {posJogador1, posJogador2};

    //Procurando a maior string dos nomes para exibir os nomes coma a tabela formatada
    int tamanhoStrJogador = strlen("Jogador");
    int maiorStringNome = tamanhoStrJogador;
    for(int i=0; i<qtdJogadoresRanking; i++){
        int tamanhoStringAtual = strlen(partida.nomeJogadores[i]);
        if(tamanhoStringAtual > maiorStringNome)
            maiorStringNome = tamanhoStringAtual;
    }

    printf(BOLD(" Posição "TAB_VER));

    //Adicionando o BOLD antes da chamada da função, que faz uma impressão, e fecha o mesmo ao fim da função
    printf("\x1b[1m ");
    alinharAoMeioTabela(" Jogador ", maiorStringNome);
    printf("\x1b[0m");

    printf(BOLD(" Vitórias "TAB_VER " Empates "TAB_VER" Derrotas "TAB_VER"\n"));

    for(int i=0; i<2; i++){

        //Exibindo a posição do jogador
        printf("%7dº "TAB_VER" ", posJogadores[i] +1);

        alinharAoMeioTabela(partida.nomeJogadores[i], maiorStringNome);

        printf(" %8d "TAB_VER" %7d "TAB_VER" %8d "TAB_VER"\n", ranking[posJogadores[i]].vitorias, ranking[posJogadores[i]].empates, ranking[posJogadores[i]].derrotas);
    
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
