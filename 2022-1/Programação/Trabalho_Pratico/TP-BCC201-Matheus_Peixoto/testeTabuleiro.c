#include <stdio.h>

void imprimeTabuleiro(char disposicaoJogadas [][3]){
    char linhaHorizontal[] = "---------------";
    printf("  | ");
    // Imprimindo o cabeçalho
    for(int i=1;i<=3; i++){
        printf("%-2d| ", i);
    }
    printf("\n%s", linhaHorizontal);

    // Imprimindo a disposição das jogadas
    for (int i = 0; i < 3; i++){
        printf("\n%-2d| ",i+1);
        for(int j=0; j <3; j++){
            printf("%-2c| ", disposicaoJogadas[i][j]);
        }
        printf("\n%s", linhaHorizontal);
    }
    printf("\n");
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