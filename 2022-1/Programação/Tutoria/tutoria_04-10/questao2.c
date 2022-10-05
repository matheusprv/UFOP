#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[30];
}Nacao;

int main(){

    Nacao *nacoes = malloc(217*sizeof(Nacao)); 

    FILE *arquivo = fopen("nacao.txt", "r");

    char espaco;
    int index =0;

    while(index<=216){
        fscanf(arquivo, "%d", &nacoes[index].id);
        fscanf(arquivo, "%c", &espaco);
        fgets(nacoes[index].nome, 30, arquivo);
        nacoes[index].nome[strlen(nacoes[index].nome)-1] = '\0';

        //printf("%d %s\n", nacoes[index].id, nacoes[index].nome);
        index++;
    }

    FILE *arquivoBin = fopen("nacao.bin", "wb");

    for(int i=0; i<216; i++){
        //printf("ID: %d\n", nacoes[i].id);
        fwrite(&nacoes[i].id, sizeof(int), 1, arquivoBin);
        fwrite(nacoes[i].nome, sizeof(char), 1, arquivoBin);
    }

    fclose(arquivo);
    fclose(arquivoBin);

    arquivoBin = fopen("nacao.bin", "rb");

    
    int n1, n2;
    printf("Digite o intervalo entre os números: ");
    scanf("%d%d", &n1, &n2);

    for(int i=0; i<n2; i++){
        fread(&nacoes[i].id, sizeof(int), 1, arquivoBin);
        fread(nacoes[i].nome, sizeof(char), 1, arquivoBin);

        if(nacoes[i].id>=n1){
            printf("%s\n", nacoes[i].nome);
        }
    }

    fclose(arquivoBin);
    free(nacoes);

    return 0;
}