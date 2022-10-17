#include <stdio.h>
#include <stdlib.h>
#include "cores.c"
/*
typedef struct{
    int a;
}Teste;

void testar(Teste **tes){
    *tes = malloc(5*sizeof(Teste));

    for(int i=0; i<5;i++){
        (*tes)[i].a = i*3;
    }
}
void alterarValores(Teste *teste){
    for(int i=0; i<5; i++){
        teste[i].a *= 5;
    }
}

void exibirTeste(Teste *tes, int tamanaho){
    for(int i=0; i<tamanaho; i++){
        printf("%d\n", tes[i].a);
    }
}

void aumentarTamanho(Teste **teste){
    *teste = realloc(*teste, 10*sizeof(Teste));

    for(int i=5; i<10;i++){
        (*teste)[i].a = i*400;
    }
}

int main(){

    Teste *teste = NULL;
    testar(&teste);

    exibirTeste(teste,5);
    alterarValores(teste);
    printf("#############\n");
    exibirTeste(teste,5);

    printf("#############\n");
    aumentarTamanho(&teste);
    exibirTeste(teste,10);

    return 0;
}*/
#define QTD_LINHAS_HORIZONTAIS 15
void linhasDoMeio(){
    printf("%s", TAB_ML);
    for(int i=0; i<QTD_LINHAS_HORIZONTAIS;i++)
        printf("%s", TAB_HOR);
    printf("%s", TAB_MR);
}

void imprimeTabuleiro(char disposicaoJogadas [][3]){
    //Linha de cima do cabeçalho
    printf("%s", TAB_TL);
    for(int i=0; i<QTD_LINHAS_HORIZONTAIS;i++)
        printf("%s", TAB_HOR);
    printf("%s\n", TAB_TR);

    //Linhas coordenadas verticais
    printf("%s   %s",TAB_VER,TAB_VER);
    for(int i = 1; i<=3; i++){
        printf(" %d %s", i, TAB_VER);
    }
    
    printf("\n");
    linhasDoMeio();
    printf("\n");

    for(int i=0; i<3; i++){
        printf("%s %d %s", TAB_VER, i+1, TAB_VER);
        
        for(int j=0; j<3; j++){
            printf(" %c %s", disposicaoJogadas[i][j],TAB_VER);
        }
        printf("\n");
        linhasDoMeio();
        printf("\n");
    }

    
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