#include <stdio.h>
#include <stdlib.h>

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
}