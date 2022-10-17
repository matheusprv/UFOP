#include <stdio.h>
#include <string.h>
#define TAM_MAX 71

int main(){
    char nome[TAM_MAX];

    printf("Digite o nome completo: ");
    fgets(nome, TAM_MAX, stdin);
    
    
    nome[strlen(nome)-1]='\0';
    int tamanhoNome = strlen(nome);
    int totalLetras = 0;
    for(int i=0; i<tamanhoNome; i++){
        if(nome[i] != ' '){
            totalLetras++;
        }
    }

    //salvando a posição do espaço do último sobrenome
    int posicaoEspaco = 0;
    for(int i=tamanhoNome-1; i>=0;i--){
        if(nome[i]==' '){
            posicaoEspaco = i;
            break;
        }
    }

    //Recebendo o valor do último nome e removendo-o da string original
    char ultimo_sobrenome [TAM_MAX];
    int contador =0, i = posicaoEspaco+1;

    for(; i < tamanhoNome; i++){
        ultimo_sobrenome[contador] = nome[i]; 
        nome[i] = '\0';
        contador++;
    }
    ultimo_sobrenome[contador] = '\0';

    printf("%s, %s\n", ultimo_sobrenome, nome);
    printf("Total de letras: %d\n", totalLetras);
    printf("Total de letras do último sobrenome: %d\n", (int)strlen(ultimo_sobrenome));


    return 0;
}