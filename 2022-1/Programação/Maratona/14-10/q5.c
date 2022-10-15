#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

    int nLinhas;
    scanf("%d", &nLinhas);
    getchar();

    while(nLinhas != 0 ){
        //int maiorTexto = -1;
        int *tamanhoStrings = malloc(nLinhas*sizeof(int));
        char **texto = malloc(nLinhas*sizeof(char*));
        
        for(int i=0; i<nLinhas; i++){
            
            texto[i] = malloc(52 * sizeof(char));
            //printf("Digite o texto: ");
            fgets(texto[i], 52, stdin);
            texto[i][strlen(texto[i])-1] = '\0';  
            tamanhoStrings[i] = strlen(texto[i]);

            //printf("Texto: %s\n", texto[i]);

            //Removendo caracteres à esquerda
            while(texto[i][0] == ' '){
                for(int j=0; j<tamanhoStrings[i]; j++){
                    texto[i][j] = texto[i][j+1];
                }
            }
            tamanhoStrings[i] = strlen(texto[i]);

            //Removendo caracteres à direita
            while(texto[i][tamanhoStrings[i]-1] < 65 || texto[i][tamanhoStrings[i]-1] >90){
                texto[i][tamanhoStrings[i]-1] = '\0';
                tamanhoStrings[i]--;
            }

            //Removendo espaços do meio
            for(int j=0; j<tamanhoStrings[i]; j++){
                //printf("texto[%d][%d] = %c - texto[%d][%d] = %c\n", i,j, texto[i][j], i,j+1, texto[i][j+1]);
                while((texto[i][j] < 65 || texto[i][j] > 90) && (texto[i][j+1] < 65 || texto[i][j+1] > 90)){
                    for(int k=j; k<tamanhoStrings[i]; k++){
                        texto[i][k] = texto[i][k+1];
                    }
                    tamanhoStrings[i]--;
                }
            }

            //printf("Texto: %s\n",texto[i]);
        }
        
        //Procurando a maior string
        int maiorString = tamanhoStrings[0];
        for(int i = 1; i<nLinhas; i++){
            if(tamanhoStrings[i]>maiorString){
                maiorString = tamanhoStrings[i];
            }
        }

        //Exibindo os textos
        for(int i=0; i<nLinhas; i++){
            //Verificando se precisa adicionar espaços na esquerda
            if(tamanhoStrings[i]<maiorString){
                int qtdEspacosAdicionar = maiorString - tamanhoStrings[i];
                for(int j=0; j<qtdEspacosAdicionar; j++)
                    printf(" ");
            }
            printf("%s\n", texto[i]);
        }
        printf("\n");
        

        for(int x=0; x<nLinhas;x++)
            free(texto[x]);
        free(texto);
        free(tamanhoStrings);
        
        scanf("%d", &nLinhas);
        getchar();
    }

    return 0;
}