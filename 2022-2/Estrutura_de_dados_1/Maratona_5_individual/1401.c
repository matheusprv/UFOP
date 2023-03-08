#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void calcula_fatorial(int fatoriais[11]){
    fatoriais[0] = 1;
    for(int i=1; i<11; i++){
        fatoriais[i] = i * fatoriais[i-1];
    }

    /*for(int i = 0; i < 11; i++){
        printf("fatorial[%d]: %d\n", i, fatoriais[i]);
    }*/
}

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

void trocaCaracteres(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(char * palavra, int n, int fatorial[11]){
    int j, k, l;

    for (int i = 0; i < fatorial[n]; i++) {
        printf("%s\n", palavra);

        //Procura o menor caracter à direita
        for (j = n - 2; j >= 0; j--) {
            if (palavra[j] < palavra[j+1]) {
                break;
            }
        }

        // Se não tem, todas as permutações foram feitas
        if (j < 0) {
            break;
        }

        // Encontra o menor caracter à direita do caracter no indece j que é maior que ele
        for (k = n - 1; k > j; k--) {
            if (palavra[k] > palavra[j]) {
                break;
            }
        }

        trocaCaracteres(&palavra[j], &palavra[k]);

        l = j + 1;
        k = n - 1;
        while (l < k) {
            trocaCaracteres(&palavra[l], &palavra[k]);
            l++;
            k--;
        }
    } 


}


int main(){

    int casos_de_teste;
    scanf("%d",&casos_de_teste);

    int fatorial[11];
    calcula_fatorial(fatorial);

    for(int cont = 0; cont < casos_de_teste; cont++){
        char palavra[12];
        scanf("%s", palavra);

        int tamanhoPalavra = strlen(palavra);

        quicksort(palavra, 0, tamanhoPalavra-1);

        permutation(palavra, tamanhoPalavra, fatorial);

        if(cont != casos_de_teste-1)
            printf("\n");
    }

    return 0;
}