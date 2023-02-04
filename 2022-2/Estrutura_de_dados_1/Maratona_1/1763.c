#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_STR 10002

typedef struct{
    char pais[30];
    char mensagem[30];
}Dados;

int main(){

    Dados dados[24];
    strcpy(dados[0].pais, "alemanha"); strcpy(dados[0].mensagem, "Frohliche Weihnachten!");
    strcpy(dados[1].pais, "austria"); strcpy(dados[1].mensagem, "Frohe Weihnacht!");
    strcpy(dados[2].pais, "coreia"); strcpy(dados[2].mensagem, "Chuk Sung Tan!");
    strcpy(dados[3].pais, "espanha"); strcpy(dados[3].mensagem, "Feliz Navidad!");
    strcpy(dados[4].pais, "grecia"); strcpy(dados[4].mensagem, "Kala Christougena!");
    strcpy(dados[5].pais, "estados-unidos"); strcpy(dados[5].mensagem, "Merry Christmas!");
    strcpy(dados[6].pais, "inglaterra"); strcpy(dados[6].mensagem, "Merry Christmas!");
    strcpy(dados[7].pais, "australia"); strcpy(dados[7].mensagem, "Merry Christmas!");
    strcpy(dados[8].pais, "portugal"); strcpy(dados[8].mensagem, "Feliz Natal!");
    strcpy(dados[9].pais, "suecia"); strcpy(dados[9].mensagem, "God Jul!");
    strcpy(dados[10].pais, "turquia"); strcpy(dados[10].mensagem, "Mutlu Noeller");
    strcpy(dados[11].pais, "argentina"); strcpy(dados[11].mensagem, "Feliz Navidad!");
    strcpy(dados[12].pais, "chile"); strcpy(dados[12].mensagem, "Feliz Navidad!");
    strcpy(dados[13].pais, "mexico"); strcpy(dados[13].mensagem, "Feliz Navidad!");
    strcpy(dados[14].pais, "antardida"); strcpy(dados[14].mensagem, "Merry Christmas!");
    strcpy(dados[15].pais, "canada"); strcpy(dados[15].mensagem, "Merry Christmas!");
    strcpy(dados[16].pais, "irlanda"); strcpy(dados[16].mensagem, "Nollaig Shona Dhuit!");
    strcpy(dados[17].pais, "belgica"); strcpy(dados[17].mensagem, "Zalig Kerstfeest!");
    strcpy(dados[18].pais, "italia"); strcpy(dados[18].mensagem, "Buon Natale!");
    strcpy(dados[19].pais, "libia"); strcpy(dados[19].mensagem, "Buon Natale!");
    strcpy(dados[20].pais, "siria"); strcpy(dados[20].mensagem, "Milad Mubarak!");
    strcpy(dados[21].pais, "marrocos"); strcpy(dados[21].mensagem, "Milad Mubarak!");
    strcpy(dados[22].pais, "japao"); strcpy(dados[22].mensagem, "Merii Kurisumasu!");
    strcpy(dados[23].pais, "brasil"); strcpy(dados[23].mensagem, "Feliz Natal!");

    char entrada[TAM_STR];
    while(scanf("%s", entrada) != EOF){
        int saiu = 0;
        for(int i=0; i<24; i++){
            if(!strcmp(dados[i].pais, entrada)){
                printf("%s\n", dados[i].mensagem);
                saiu = 1;
                break;
            }
        }
        if(!saiu){
            printf("--- NOT FOUND ---\n");
        }

    }

    return 0;
}