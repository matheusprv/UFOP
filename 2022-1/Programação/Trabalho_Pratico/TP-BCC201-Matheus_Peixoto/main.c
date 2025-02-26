//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "funcoes.h"
#include "funcoes_jogo.h"
#include "manipulacao_arquivo.h"
#include "structs.h"
#include "ranking.h"


int main(){

    //Incializando o ranking
    Ranking *ranking;
    int qtdJogadoresRanking = lerArquivoConfiguracao(&ranking);

    //Inicializando o tabuleiro
    Partida partida;
    partida.tabuleiro = malloc(3*sizeof(int*));
    for(int i=0; i<3; i++){
        partida.tabuleiro[i] = malloc(3*sizeof(int));
    }
    reiniciarPartida(&partida);

    int comandoValido=1, finalizarPrograma = 0, resultadoPartida = 0;
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
                resultadoPartida = menuNovoJogo(&partida, 1);
                break;
            
            //Continuar jogo salvo
            case '2':
                int leitura = lerJogoSalvo(&partida);
                if(leitura == 1){
                    resultadoPartida = menuNovoJogo(&partida, 0);
                }
                else if(leitura ==0)
                    comandoValido = -2;
                else if(leitura == -1)
                    comandoValido = -4;
                break;

            //Voltar para o jogo em andamento
            case '3':
                if(partida.partidaIniciada == 0){
                    comandoValido =-1;
                }
                else{
                    resultadoPartida = menuNovoJogo(&partida, 0);
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

        if(resultadoPartida!=0){
            organizarRanking(&ranking, &qtdJogadoresRanking, partida, resultadoPartida);
            exibirJogadoresPartida(ranking, qtdJogadoresRanking, partida);
        }
        resultadoPartida = 0;

    }while(!finalizarPrograma);

    salvarArquivoConfiguracao(ranking, qtdJogadoresRanking);

    //Liberando alocações dinâmicas
    for(int i=0; i<3;i++)
        free(partida.tabuleiro[i]);
    free(partida.tabuleiro);
    free(ranking);

    return 0;

}