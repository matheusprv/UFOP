#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cores.c"

/*
#define QTD_LINHAS_HORIZONTAIS 15
void imprimeTabuleiro(char tabuleiro[][3]){

    //Linha de cima do cabeçalho
    printf(TAB_TL""TAB_HOR""TAB_HOR""TAB_HOR);
    for(int i=0; i<3; i++){
        printf(TAB_TJ""TAB_HOR""TAB_HOR""TAB_HOR);
    }
    printf(TAB_TR);


    // Imprimindo o cabeçalho
    printf("\n");
    printf(TAB_VER"   "TAB_VER" ");
    for(int i=1;i<=3; i++){
        printf("%-2d"TAB_VER" ", i);
    }

    //Imprimindo as jogadas
    int i = 0;
    for(; i<3;i ++){
        printf("\n"TAB_ML""TAB_HOR""TAB_HOR""TAB_HOR);
        for(int i=0; i<3; i++){
            printf(TAB_MJ""TAB_HOR""TAB_HOR""TAB_HOR);
        }
        printf(TAB_MR);

        printf("\n"TAB_VER" %d "TAB_VER"", i+1);
        for(int j=0;j<3; j++){

            if(tabuleiro[i][j] == 'X')
                printf(ANSI_COLOR_BLUE" %-2c"ANSI_RESET""TAB_VER, 'X');
            
            else if(tabuleiro[i][j] == 'O')
                printf(ANSI_COLOR_YELLOW" %-2c"ANSI_RESET""TAB_VER, 'O');
            
            else
                printf(" %-2c"TAB_VER, ' ');
        }
    }

    //Linha de baixo
    printf("\n"TAB_BL""TAB_HOR""TAB_HOR""TAB_HOR);
    for(int i=0; i<3; i++){
        printf(TAB_BJ""TAB_HOR""TAB_HOR""TAB_HOR);
    }
    printf(TAB_BR"\n");

    printf("\n");
    //printf("\n"TAB_ML""TAB_HOR""TAB_HOR""TAB_MJ""TAB_HOR""TAB_HOR""TAB_MJ""TAB_HOR""TAB_HOR""TAB_MJ"");

}


int main(){
    char matriz[3][3];
    for(int i=0;i<3;i++){
        for(int j=0; j<3;j++)
            matriz[i][j] = (i*j)%2==0?'O':'X';
    }

    imprimeTabuleiro(matriz);
    return 0;
}
*/
/*
int main(){
    srand(time(NULL));

    for(int i=0; i<30; i++){
        printf("%d\n", (rand() % 4)+1);
    }
    return 0;
}*/