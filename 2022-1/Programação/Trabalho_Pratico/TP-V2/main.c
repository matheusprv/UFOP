//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "funcoes.h"
#include "funcoes_jogo.h"
#include "structs.h"

int main(){

    //Inicializando o tabuleiro
    Partida partida;
    partida.tabuleiro = malloc(3*sizeof(int*));
    for(int i=0; i<3; i++){
        partida.tabuleiro[i] = malloc(3*sizeof(int));
    }

    int comandoValido=1, finalizarPrograma = 0;
    char opcaoMenu;

    //Menu do Jogo
    do{
        imprimeMenuPrincipal(comandoValido);
        comandoValido = 1;
        lerCaracter(&opcaoMenu);

        switch (opcaoMenu){
            case '0':
                finalizarPrograma = 1;
                break;
            //Novo Jogo
            case '1':
                menuNovoJogo(&partida, 1);
                break;
            
            //Continuar jogo salvo
            case '2':
                break;

            //Voltar para o jogo em andamento
            case '3':
                if(partida.numJogadas == -1){
                    comandoValido =-1;
                }
                else{
                    menuNovoJogo(&partida, 0);
                }
                break;

            //Visualizar o ranking
            case '4':
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

}





