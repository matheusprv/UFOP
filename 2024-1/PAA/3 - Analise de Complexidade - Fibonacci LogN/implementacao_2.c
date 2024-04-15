#include <stdio.h>
#include <stdlib.h>

#define MATRIZ_INCIAL {{0,1}, {1, 1}}

void multiplicacao_da_matriz(int a[2][2], int b[2][2]){
    int ab_00 = a[0][0] * b[0][0] + a[0][1] * b[1][0];  //Θ(1) - Multiplicação de valores bem definidos, soma e atribuição.
    int ab_01 = a[0][0] * b[0][1] + a[0][1] * b[1][1];  //Θ(1) - Multiplicação de valores bem definidos, soma e atribuição.
    int ab_10 = a[1][0] * b[0][0] + a[1][1] * b[1][0];  //Θ(1) - Multiplicação de valores bem definidos, soma e atribuição.
    int ab_11 = a[1][0] * b[0][1] + a[1][1] * b[1][1];  //Θ(1) - Multiplicação de valores bem definidos, soma e atribuição.
    a[0][0] = ab_00;                                    //Θ(1) - Atribuição 
    a[0][1] = ab_01;                                    //Θ(1) - Atribuição
    a[1][0] = ab_10;                                    //Θ(1) - Atribuição
    a[1][1] = ab_11;                                    //Θ(1) - Atribuição
}

/*
    Exponentiation by squaring
        x^n = x(x^2)^(n-1)/2 se n for ímpar
        x^n = (x^2)^(n/2)    se n for par
    onde x é a matriz
*/
void potenciacao_da_matriz(int matriz[2][2], int n) {
    if(n == 0 || n == 1) return;                        //Θ(1) - Verificação de valores e possível retorno

    int temp[2][2] = MATRIZ_INCIAL;                     //Θ(1) -  Atribuição de valores a uma variável

    potenciacao_da_matriz(matriz, n/2);                 //Θ(log n) - A chamada recursiva sempre divide por 2 o tamanho de 'n'
    multiplicacao_da_matriz(matriz, matriz);            //Θ(1) - Chamada de função de custo Θ(1)

    if(n%2 != 0)multiplicacao_da_matriz(matriz, temp);  //Θ(1) - Caso N seja ímpar, teremos que multiplicar mais uma vez para chegar no expoente desejado
}

int fibonacci(int n) {
    if(n == 0) return 0;                                //Θ(1) - Verificação e retorno de valor
    if(n == 1) return 1;                                //Θ(1) - Verificação e retorno de valor

    int matriz[2][2] = MATRIZ_INCIAL;                   //Θ(1) - Atribuição de valores a uma variável

    potenciacao_da_matriz(matriz, n - 1);               //Θ(log n) - Chamada da função que possui complexidade Θ(log n)
    return matriz[1][1];                                //Θ(1) - Retorno de um único valor
}

int main(){
    for(int i = 0; i <= 20; i++){
        int fib1 = fibonacci(i);
        printf("f(%d)= %d\n", i, fib1);
    }
    return 0;
}

/*
    f(0) =    0
    f(1) =    1
    f(2) =    1
    f(3) =    2
    f(4) =    3
    f(5) =    5
    f(6) =    8
    f(7) =   13
    f(8) =   21
    f(9) =   34
    f(10)=   55
    f(11)=   89
    f(12)=  144
    f(13)=  233
    f(14)=  377
    f(15)=  610
    f(16)=  987
    f(17)= 1597
    f(18)= 2584
    f(19)= 4181
    f(20)= 6765
*/