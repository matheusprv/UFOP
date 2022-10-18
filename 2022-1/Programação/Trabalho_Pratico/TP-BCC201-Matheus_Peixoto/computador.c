//Matheus Peixoto Ribeiro Vieira - 22.1.4104

#include "structs.h"
#include "funcoes.h"
#include "computador.h"

int procurarVitoria(int *linha, int *coluna, char **tabuleiro, char identificador){
    /*
        Sempre que a função é chamada, ela recebe como identificador o X ou O, para identificar se está procurando onde ocorrerá a vitória do jogador ou a do computador, respectivamente.
        A verificação da possibilidade de vitória é feita a partir de dois FOR que varrem toda a matriz.
        Dentro do segundo for é feita a verificação das linhas e colunas e, fora dele, é feita a verificação das diagonais, posi elas precisam somente do parametro da linha atual.

        Para verificar uma possível vitória, é atribuida uma pontuação para a quantidade de X ou O presente naquele espaço, cada identificador presente acrescenta +1 e cada identificador oposto remove -1
        caso a pontuação nesse espaço seja igual a 2, então uma vitória pode ocorrer naquele local. Dessa forma, é salva a coluna e linha em branco dessa área e ela é marcada na main para o computador.
        Em caso de não ser encontrado nenhuma possível vitória, é retornado 0 para que possa ser passado para o próximo tipo de veridicação.
    */

   //Marcam quantas presenças do identificador há no determinado espaço
    int somadorLinha = 0, somadorColuna = 0, somDiagonalPrinc = 0, somDiagonalSec = 0;
    char identificadorOposto = identificador == 'X' ? 'O' : 'X';
    
    for(int i=0; i<3; i++){
        somadorLinha = 0; 
        somadorColuna = 0;
        //Verificando linhas e colunas
        for(int j=0;j<3; j++){
            //Gerando a pontuação para a linha atual
            if(tabuleiro[i][j] == identificador)
                somadorLinha++;
            else if(tabuleiro[i][j] == identificadorOposto)
                somadorLinha--;

            //Gerando pontuação para a coluna atual
            if(tabuleiro[j][i] == identificador)
                somadorColuna++;
            else if(tabuleiro[j][i] == identificadorOposto)
                somadorColuna--;
        }
        //Verificando possibilidade de vitória em uma linha
        if(somadorLinha == 2){
            for(int j=0; j<3; j++){
                if(tabuleiro[i][j] == ' '){
                    *linha = i;
                    *coluna = j;
                    return 1;
                }
            }
        }

        //Verificando possibilidade de vitória em uma coluna
        if(somadorColuna == 2){
            for(int j=0; j<3; j++){
                if(tabuleiro[j][i] == ' '){
                    *linha = j;
                    *coluna = i;
                    return 1;
                }
            }
        }
    
        //Gerando a pontuação para a diagonal principal
        if(tabuleiro[i][i] == identificador)
            somDiagonalPrinc++;
        else if(tabuleiro[i][i] == identificadorOposto)
            somDiagonalPrinc--;

        //Gerando a pontuação para a diagonal secundária
        if(tabuleiro[i][2-i] == identificador)
            somDiagonalSec++;
        if(tabuleiro[i][2-i] == identificadorOposto)
            somDiagonalSec--;
    }

    //Verificando possibilidade de vitória na diagonal principal
    if(somDiagonalPrinc == 2){
        for(int i = 0; i<3; i++){
            if(tabuleiro[i][i] == ' '){
                *linha = i;
                *coluna =i;
                return 1;
            }
        }
    }

    //Verificando possibilidade de vitória na diagonal secundária
    if(somDiagonalSec == 2){
        for(int i = 0; i<3; i++){
            if(tabuleiro[i][2-i] == ' '){
                *linha = i;
                *coluna = 2-i;
                return 1;
            }
        }
    }
    //Não encontrou nenhuma possibilidade de vencer
    return 0;
}


int melhorPosicao(int *linha, int *coluna, char **tabuleiro){
    //Procura a melhor posição para marcar no tabuleiro quando não há nenhuma outra possibilidade de vitória
    if(tabuleiro[1][1] == ' '){
        *linha = 1;
        *coluna = 1;
        return 1;
    }

    if(tabuleiro[0][0] == 'X'){
        //          [3][2]   
        if(tabuleiro[2][1] == 'X'){
            if(tabuleiro[1][0] == ' '){
                *linha = 1;
                *coluna = 0;
                return 1; //[2][1]
            }
        }
        //          [2][3]
        if(tabuleiro[1][2] == 'X'){
            if(tabuleiro[0][2] == ' '){
                *linha = 0; 
                *coluna = 2;
                return 1; //[1][3]                
            }
        }
        //          [3][3]                    
        if(tabuleiro[2][2] == 'X'){
            if(tabuleiro[0][1] == ' '){
                *linha = 0;
                *coluna = 1;
                return 1; //[1][2]
            }
            if(tabuleiro[2][1] == ' '){
                *linha = 2;
                *coluna = 1;
                return 1;
            }
        }
    }
    if(tabuleiro[0][2] == 'X'){
        //          [3][2]   
        if(tabuleiro[2][1] == 'X'){
            if(tabuleiro[1][0] == ' '){
                *linha = 1;
                *coluna = 0;
                return 1; //[2][1]
            }
        }
        //          [2][1] 
        if(tabuleiro[1][0] == 'X'){
            if(tabuleiro[0][0] == ' '){
                *linha = 0;
                *coluna = 0;
                return 1;
            }
        }
        //          [1][3]
        if(tabuleiro[0][2] == 'X'){
            if(tabuleiro[1][2] == ' '){
                *linha = 1;
                *coluna = 2;
                return 1;
            }
        }
    }

    //          [3][1]
    if(tabuleiro[2][0] == 'X'){
        //          [1][2] 
        if(tabuleiro[0][1] == 'X' || tabuleiro[0][2]){
            if(tabuleiro[1][0] == ' '){
                *linha = 1;
                *coluna = 0;
                return 1;
            }
        }
        //               [2][3]
        else if(tabuleiro[1][2] == 'X'){
            //          [3][2]
            if(tabuleiro[2][1] == ' '){
                *linha = 2;
                *coluna = 1;
                return 1;
            }
        }
    }
    //          [3][3]
    if(tabuleiro[2][2] == 'X'){
        //          [1][2]
        if(tabuleiro[0][1] == 'X' || tabuleiro[0][0] == 'X'){
            if(tabuleiro[1][2] == ' '){
                *linha = 1;
                *coluna = 2;
                return 1;
            }
        }
        if(tabuleiro[1][0] == 'X'){
            if(tabuleiro[2][0] == ' '){
                *linha = 2;
                *coluna = 0;
                return 1;
            }
        }
        
    }

/*
    //Jogando em uma quina
    if(tabuleiro[0][0] == 'X'){
        if(tabuleiro[0][1] == ' '){
            *linha = 0;
            *coluna = 1;
            return 1;
        }
        else if(tabuleiro[1][0] == ' '){
            *linha = 1;
            *coluna = 0;
            return 1;
        }
    }
    else if(tabuleiro[0][2] == 'X'){
        if(tabuleiro[0][1] == ' '){
            *linha = 0;
            *coluna = 1;
            return 1;
        }
        else if(tabuleiro[1][2] == ' '){
            *linha = 1;
            *coluna = 2;
            return 1;
        }
    }
    else if(tabuleiro[0][2] == 'X'){
        if(tabuleiro[1][2] == ' '){
            *linha = 1;
            *coluna = 2;
            return 1;
        }
        else if(tabuleiro[2][1] == ' '){
            *linha = 2;
            *coluna = 1;
            return 1;
        }
    }
    else if(tabuleiro[2][2] == 'X'){
        if(tabuleiro[2][1] == ' '){
            *linha = 2;
            *coluna = 1;
            return 1;
        }
        else if(tabuleiro[1][2] == ' '){
            *linha = 1;
            *coluna = 2;
            return 1;
        }
    }
*/

    return 0;
}

void jogadaComputador(Partida *partida){
    int linha=-1, coluna=-1;

    //Procurar onde o computador pode ganhar
    if(procurarVitoria(&linha, &coluna, partida->tabuleiro, 'O')){
        printf("If 1\n");
        partida->tabuleiro[linha][coluna] = 'O';
    }
    //Procurar onde o jogador pode ganhar para impedí-lo
    else if(procurarVitoria(&linha, &coluna, partida->tabuleiro, 'X')){
        printf("If 2\n");
        partida->tabuleiro[linha][coluna] = 'O';
    }
    //Procurando a melhor posição para marcar já que não há possibilidade de vencer
    else{
        printf("If 3\n");
        melhorPosicao(&linha, &coluna, partida->tabuleiro);
        partida->tabuleiro[linha][coluna] = 'O';
    }
    printf("Linha: %d - Coluna: %d\n", linha, coluna);
    
}