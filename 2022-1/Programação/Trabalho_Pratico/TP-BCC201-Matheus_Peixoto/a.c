int main(){

    char tabuleiro[3][3];

    if (tabuleiro[1][1] != ' ')
        tabuleiro[1][1] = 'O';

    //Linhas 0
    for(int j=0; j<3; j++){
        if(tabuleiro[0][j] == ' '){
            *linha = 0;
            *coluna = j;
            return 1;
        }
    }

    //Linha 1 - Evitando que o jogador use técnicas para ganhar em dois lugares
    // if (tabuleiro[1][2] != ' ')
    //     tabuleiro[1][2] = 'O';
    
    // if (tabuleiro[1][0] != ' ')
    //     tabuleiro[1][0] = 'O';
    if (tabuleiro[1][0] != ' '){
        *linha = 1;
        *coluna = 0;
        return 1;
    }
    if (tabuleiro[1][2] != ' '){
        *linha = 1;
        *coluna = 2;
        return 1;
    }
    


    //Linha 2
    for(int j=0; j<3; j++){
        if(tabuleiro[2][j] == ' '){
            *linha = 2;
            *coluna = j;
            return 1;
        }
    }
    // if (tabuleiro[2][0] != ' ')
    //     tabuleiro[2][0] = 'O';

    // if (tabuleiro[2][2] != ' ')
    //     tabuleiro[2][2] = 'O';

    // if (tabuleiro[2][1] != ' ')
    //     tabuleiro[2][1] = 'O';



    return 0;
}

