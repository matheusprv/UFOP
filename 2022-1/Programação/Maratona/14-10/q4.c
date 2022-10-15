#include <stdio.h>

int main(){

    float matriz [12][12];
    float somatorio=0;
    int linha;
    char operacao;

    scanf("%d", &linha);
    getchar();
    scanf("%c", &operacao);

    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            scanf("%f", &matriz[i][j]);
            if(linha == i)
                somatorio += matriz[i][j];
        }
    }
    printf("%.1f\n", operacao == 'S' ? somatorio : somatorio/12.0);

    return 0;
}