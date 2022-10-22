#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void binarioParaDecimal(char numero[33]){
    long long int decimal = 0;
    int tamanhoNumero = strlen(numero);
    for(int i=0; i < tamanhoNumero; i++){
        decimal += (numero[tamanhoNumero-i-1] - '0') * pow(2, i);
    }
    printf("%lld dec\n", decimal);
}

void decimalParaBinario(char numero[33]){
    long long int decimal = 0;
    int tamanhoNumero = strlen(numero);

    for(int i = 0; i < tamanhoNumero; i++){
        decimal += (numero[tamanhoNumero - i - 1] - '0') * pow(10, i);
    }

    char binario[33];
    
    int i = 0;
    for(; decimal > 0; i++){
        binario[i] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binario[i] = '\0';
    
    int tamanhoBinario = strlen(binario);
    for(int i=0; i<tamanhoBinario/2; i++){
        char aux = binario[i];
        binario[i] = binario[tamanhoBinario - 1- i];
        binario[tamanhoBinario -1 -i] = aux;
    }
    
    printf("%s bin\n", binario);

}

void decimalParaHexa(char numero[33]){
    long long int decimal = 0;
    int tamanhoNumero = strlen(numero);
    
    for(int i = 0; i < tamanhoNumero; i++){
        decimal += (numero[tamanhoNumero - i - 1] - '0') * pow(10, i);
    }

    char hexadecimal[33];
    int i =0;
    while(decimal != 0){
        int temp = decimal % 16;
        if(temp<10){
            hexadecimal[i] = temp + 48;
            i++;
        }
        else{
            hexadecimal[i] = temp + 'a' - 10;
            i++;
        }
        decimal = decimal /16;
    }
    for(int j = i-1; j >=0; j--){
        printf("%c", hexadecimal[j]);
    }
    printf(" hex\n");

}

void hexaParaDecimal(char numero[33]){
    int tamanhoNumero = strlen(numero);
    long long int decimal = 0;

    char hexaAtual;
    for(int i=0; i<tamanhoNumero; i++){
        hexaAtual = numero[tamanhoNumero - 1 - i];
        
        if(hexaAtual >= '0' && hexaAtual <= '9'){
            decimal += (hexaAtual - '0') * pow (16, i);
        }
        else{
            decimal += (hexaAtual - 87) * pow (16, i);
        }
    }

    printf("%lld dec\n", decimal);
}

void hexaParaBinario(char numero[33]){
    //Transformando para decimal
    int tamanhoNumero = strlen(numero);
    long long int decimal = 0;

    char hexaAtual;
    for(int i=0; i<tamanhoNumero; i++){
        hexaAtual = numero[tamanhoNumero - 1 - i];
        
        if(hexaAtual >= '0' && hexaAtual <= '9'){
            decimal += (hexaAtual - '0') * pow (16, i);
        }
        else{
            decimal += (hexaAtual - 87) * pow (16, i);
        }
    }

    //Transformando em binário
    char binario[33];
    
    int i = 0;
    for(; decimal > 0; i++){
        binario[i] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binario[i] = '\0';
    
    int tamanhoBinario = strlen(binario);
    for(int i=0; i<tamanhoBinario/2; i++){
        char aux = binario[i];
        binario[i] = binario[tamanhoBinario - 1- i];
        binario[tamanhoBinario -1 -i] = aux;
    }
    
    printf("%s bin\n", binario);
}

void binarioParaHexa(char numero[33]){
    //Transformando para decimal
    long long int decimal = 0, quociente, resto;
    int tamanhoNumero = strlen(numero);
    for(int i=0; i < tamanhoNumero; i++){
        decimal += (numero[tamanhoNumero-i-1] - '0') * pow(2, i);
    }

    char hexadecimal[33];
    int numeros = 0;
    quociente = decimal;
    while(quociente != 0){
        resto = quociente %16;
        if(resto <10)
            hexadecimal[numeros] = 48 + resto;
        else   
            hexadecimal[numeros] = 'a' -10 +resto;
        
        quociente /= 16;

        numeros++;
    }

    hexadecimal[numeros] = '\0';

    for(int j = numeros-1; j >=0; j--){
        printf("%c", hexadecimal[j]);
    }
    printf(" hex\n");
}

int main(){

    int qtdRepeticoes;
    scanf("%d", &qtdRepeticoes);
    getchar();

    for(int cont = 0; cont< qtdRepeticoes; cont++){
        char numero[33];
        char base[4];

        scanf("%s", numero);
        getchar();
        scanf("%s", base);
        getchar();

        printf("Case %d:\n", cont+1);
        if(strcmp(base, "bin") == 0){
            binarioParaDecimal(numero);
            binarioParaHexa(numero);
        }
        else if(strcmp(base, "dec") == 0){
            decimalParaHexa(numero);
            decimalParaBinario(numero);
        }
        else{
            hexaParaDecimal(numero);
            hexaParaBinario(numero);
        }
        printf("\n");

    }

    return 0;
}
