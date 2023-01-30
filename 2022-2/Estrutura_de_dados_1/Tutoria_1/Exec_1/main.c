#include <stdio.h>
#include "lista.h"

int main(){
    
    TLista lista;
    TLista_Inicia(&lista);

    char string[100000];
    int tamString;

    char caracter;
    //HOME = -1  --  END = 1
    int homeEnd = 1;

    while(scanf("%s", string) != EOF){

        tamString = strlen(string);

        for(int i = 0; i< tamString; i++){

            caracter = string[i];

            if(caracter == '[' || caracter == ']'){
                homeEnd *= -1;
                continue;
            }

            if(homeEnd == 1){
                TLista_Insere_Fim(&lista, caracter);
            }
            else{
                TLista_Insere_Inicio(&lista, caracter);
            }
        }

        TLista_Imprime(&lista);
        TLista_Esvazia(&lista);
        TLista_Inicia(&lista);


    }

    TLista_Esvazia(&lista);


    return 0;
}