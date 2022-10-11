#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){
    
    char d;
    char n[102], imprimir[102];
    int qtdImpressoes;
    scanf("%c %s", &d, n);
    getchar();
    
    while(d !=0 && strcmp(n, "0") !=0){
        qtdImpressoes = 0;
        int tamanhoString = strlen(n);

        for(int i=0; i < tamanhoString; i++){
            if(n[i] != d){
                imprimir[qtdImpressoes] = n[i];
                qtdImpressoes++;
            }
        }
        imprimir[qtdImpressoes] = '\0';

        tamanhoString = strlen(imprimir);

        // printf("Imprimir: %s\n", imprimir);

        while(imprimir[0] == '0' && imprimir[1] != '\n'){
            for(int i=0; i<tamanhoString;i++){
                imprimir[i] = imprimir[i+1];
            }
        }

        // printf("Imprimir: %s\n", imprimir);

        printf("%s\n", strlen(imprimir)>0? imprimir : "0");

        // if(qtdImpressoes>0)
        //     printf("%lld\n", atoll(imprimir));
        // else    
        //     printf("0\n");

        scanf("%c %s", &d, n);
        getchar();
    }


    return 0;
}