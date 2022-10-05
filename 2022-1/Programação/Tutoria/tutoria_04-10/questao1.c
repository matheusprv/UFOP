#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){

    int n1, n2;

    scanf("%d%d", &n1, &n2);

    FILE *arquivo = fopen("nacao.txt", "r");

    //Variaveis para pegar o nome do pais e o seu numero
    char pais[30];
    int numeroPais;
    char espaco;

    for(int i=1; i<=n2; i++){
        fscanf(arquivo, "%d", &numeroPais);
        fscanf(arquivo, "%c", &espaco);
        fgets(pais, 30, arquivo);

        if(numeroPais>=n1){
            printf("%s", pais);
        }
    }
    fclose(arquivo);
    return 0;
}