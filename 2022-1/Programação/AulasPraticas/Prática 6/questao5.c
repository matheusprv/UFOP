#include <stdio.h>
#include <math.h>

int validaCPF(long long);

int main(){

    long long cpf;
    printf("Digite o CPF: ");
    scanf("%lld", &cpf);

    if(validaCPF(cpf) == 1){
        printf("Válido!");
    }
    else{
        printf("Inválido!");
    }

    return 0;
}

int validaCPF(long long cpf){
    long long somatorio = 0;
    long long verificadorPrimeiroDigito = cpf;
    for(int i=10; i>=2; i--){
        //Pegando a maior casa do número, fazendo a multiplicação e substraindo o seu valor do original Ex: 5222255 -> 5222255 - 5000000 =  222255
        int n = verificadorPrimeiroDigito/pow(10, i);
        somatorio += n*i;
        verificadorPrimeiroDigito -= n*(pow(10, i));
    }
    
    //Resto dessa equação deve ser igual ao primeiro digito após o verificador (-)
    int resto = (somatorio*10)%11;
    resto = resto == 10 ? 0 : resto;

    if(resto != (verificadorPrimeiroDigito/10)){
        return 0;
    }

    long long verificadorSegundoDigito = cpf;
    somatorio = 0;
    for(int i=10; i>=2; i--){
        //Pegando a maior casa do número, fazendo a multiplicação e substraindo o seu valor do original Ex: 5222255 -> 5222255 - 5000000 =  222255
        int n = verificadorSegundoDigito/pow(10, i);
        somatorio += n*(i+1);
        verificadorSegundoDigito -= n*(pow(10, i));
    }
    somatorio += (verificadorPrimeiroDigito/10)*2;

    //Resto dessa equação deve ser igual ao primeiro digito após o verificador (-)
    resto = (somatorio*10)%11;
    resto = resto == 10 ? 0 : resto;

    //Dividindo por 10 e pegando o módulo dessa divisão por 10 para obter o último digito
    if(resto != (verificadorPrimeiroDigito%10)){
        return 0;
    }

    return 1;
}