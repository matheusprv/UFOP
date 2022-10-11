//Matheus Peixoto Ribeiro Vieira - 22.1.4104
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int idade;
    char nome[52];
}Duende;

typedef struct{
    Duende lider;//Mais velho
    Duende entregadores;//Do meio
    Duende piloto;//Mais novo
}Equipe;

int main(){    

    int qtdDuendes;

    printf("Digite a quantidade de duendes: ");
    scanf("%d", &qtdDuendes);

    Duende *duendes = malloc(qtdDuendes * sizeof(Duende));
    Equipe *equipes = malloc((qtdDuendes/3) * sizeof(Equipe));

    for(int i=0; i<qtdDuendes; i++){
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
    }

    //Ordenando o vetor dos duendes
    Duende aux;
    for(int i=0; i<qtdDuendes; i++){
        for(int j=0; j<qtdDuendes; j++){
            if(duendes[i].idade > duendes[j].idade){
                aux = duendes[j];
                duendes[j] = duendes[i];
                duendes[i] = aux; 
            }
        }
    }


    //Exibindo Dudens de forma ordenada
    /*
    printf("\n\n");
    for(int i=0; i<qtdDuendes; i++){
        printf("%s %d\n", duendes[i].nome, duendes[i]. idade);
    }
    */

    //Gerando as equipes
    int limiteContador = qtdDuendes/3;

    for(int i=0; i<limiteContador; i++){
        equipes[i].lider = duendes[i];
        equipes[i].entregadores = duendes[i+limiteContador];
        equipes[i].piloto = duendes[i+(limiteContador*2)];

    }

    //Exibindo as equipes
    printf("\n\n");
    for(int i=0; i<qtdDuendes/3; i++){
        printf("Time %d\n", i+1);
        printf("%s %d\n", equipes[i].lider.nome, equipes[i].lider.idade);
        printf("%s %d\n", equipes[i].entregadores.nome, equipes[i].entregadores.idade);
        printf("%s %d\n", equipes[i].piloto.nome, equipes[i].piloto.idade);
        printf("\n");
    }

    free(duendes);
    free(equipes);

    return 0; 
}