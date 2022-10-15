//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "funcoes.h"
#include "funcoes_jogo.h"
#include "manipulacao_arquivo.h"
#include "structs.h"
#include "ranking.h"


int main(){

    //Incializando o ranking
    Ranking *ranking = NULL;
    int qtdJogadoresRanking = lerArquivoConfiguracao(&ranking);

    //Inicializando o tabuleiro
    Partida partida;
    partida.tabuleiro = malloc(3*sizeof(int*));
    for(int i=0; i<3; i++){
        partida.tabuleiro[i] = malloc(3*sizeof(int));
    }
    partida.numJogadas = -1;

    int comandoValido=1, finalizarPrograma = 0;
    char opcaoMenu;

    //Menu do Jogo
    do{
        imprimeMenuPrincipal(comandoValido);
        comandoValido = 1;
        lerCaracter(&opcaoMenu);

        switch (opcaoMenu){
            //Finalizar Jogo
            case '0':
                finalizarPrograma = 1;
                break;
            //Novo Jogo
            case '1':
                menuNovoJogo(&partida, 1, ranking, &qtdJogadoresRanking);
                break;
            
            //Continuar jogo salvo
            case '2':
                if(lerJogoSalvo(&partida)){

                    printf("Número jogadores: %d",partida.numJogadores);

                    menuNovoJogo(&partida, 0, ranking, &qtdJogadoresRanking);
                }
                else
                    comandoValido = -2;
                break;

            //Voltar para o jogo em andamento
            case '3':
                if(partida.numJogadas == -1){
                    comandoValido =-1;
                }
                else{
                    menuNovoJogo(&partida, 0, ranking, &qtdJogadoresRanking);
                }
                break;

            //Visualizar o ranking
            case '4':
                if(qtdJogadoresRanking == -1 || qtdJogadoresRanking == 0)
                    comandoValido = -3;
                else{
                   exibirRanking(ranking, qtdJogadoresRanking);
                }
                break;

            default:
                comandoValido = 0;
                break;
        }

    }while(!finalizarPrograma);

    for(int i=0; i<3;i++){
        free(partida.tabuleiro[i]);
    }
    free(partida.tabuleiro);
    free(ranking);

    return 0;

}