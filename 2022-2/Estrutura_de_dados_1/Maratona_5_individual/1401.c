    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    void quicksort(char * palavra, int start, int end){
        int l = start;
        int r = end;

        char pivo = palavra[(l+r)/2];

        while(l<r){
            while(palavra[l] < pivo ) l++;
            while(palavra[r] > pivo ) r--;

            if(l<=r){
                char aux = palavra[l];
                palavra[l] = palavra[r];
                palavra[r] = aux;
                l++;
                r--;
            }
        }

        if(r>start) quicksort(palavra, start, r);
        if(l<end) quicksort(palavra, l, end);
    }

    void trocaStrings(char * c1, char * c2){
        char aux = *c1;
        *c1 = *c2;
        *c2 = aux;
    }

    void permutacao(char * vetor, int inicio, int fim) {
        if (inicio == fim) {
            for (int i = 0; i <= fim; i++) {
                printf("%c", vetor[i]);
            }
            printf("\n");
        } else {
            for (int i = inicio; i <= fim; i++) {
                trocaStrings(&vetor[inicio], &vetor[i]);
                permutacao(vetor, inicio+1, fim);
                trocaStrings(&vetor[inicio], &vetor[i]);
            }
        }
    }


    int main(){

        int casos_de_teste;
        scanf("%d",&casos_de_teste);

        for(int cont = 0; cont < casos_de_teste; cont++){
            char palavra[12];
            scanf("%s", palavra);

            int tamanhoPalavra = strlen(palavra);

            quicksort(palavra, 0, tamanhoPalavra-1);

            permutacao(palavra, 0, tamanhoPalavra-1);

            if(cont != casos_de_teste-1)
                printf("\n");

        }

        return 0;
    }