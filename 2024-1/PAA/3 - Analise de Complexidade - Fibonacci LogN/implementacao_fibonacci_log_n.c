#include <stdio.h>
#include <stdlib.h>

typedef struct Matriz{
    int matriz[2][2];
}Matriz;

Matriz multiplicacao_da_matriz(Matriz a, Matriz b){ //Θ(1) - Operações constantes
    int ab_00 = a.matriz[0][0] * b.matriz[0][0] + a.matriz[0][1] * b.matriz[1][0];  //Θ(1) - Multiplicação de valores bem definidos, soma e atribuição.
    int ab_01 = a.matriz[0][0] * b.matriz[0][1] + a.matriz[0][1] * b.matriz[1][1];  //Θ(1) - Multiplicação de valores bem definidos, soma e atribuição.
    int ab_10 = a.matriz[1][0] * b.matriz[0][0] + a.matriz[1][1] * b.matriz[1][0];  //Θ(1) - Multiplicação de valores bem definidos, soma e atribuição.
    int ab_11 = a.matriz[1][0] * b.matriz[0][1] + a.matriz[1][1] * b.matriz[1][1];  //Θ(1) - Multiplicação de valores bem definidos, soma e atribuição.
    Matriz resultado;                                                               //Θ(1) - Inicialização de variável
    resultado.matriz[0][0] = ab_00;                                                 //Θ(1) - Atribuição 
    resultado.matriz[0][1] = ab_01;                                                 //Θ(1) - Atribuição
    resultado.matriz[1][0] = ab_10;                                                 //Θ(1) - Atribuição
    resultado.matriz[1][1] = ab_11;                                                 //Θ(1) - Atribuição
    return resultado;                                                               //Θ(1) - Retorno
}

/*
    Exponentiation by squaring
        x^n = x(x^2)^(n-1)/2  se n for ímpar
        x^n = (x^2)^(n/2)     se n for par
    onde x é a matriz
*/
Matriz exponenciacao(Matriz base, int n){ //Θ(log n) - Função recursiva onde o valor de N é sempre decrementado por sua metade
    if(n == 0 || n == 1 ) return base;                                              //Θ(1) - Verificação e retorno

    Matriz temp = multiplicacao_da_matriz(base, base); //y = x^2                    //Θ(1) - Chamada de função com complexidade Θ(1)
    if(n%2 == 0){                                                                   //Θ(1) - Comparação
        return exponenciacao(temp, n/2); //y^(n/2)                                  //Θ(log n) - A chamada recursiva sempre divide por 2 o tamanho de 'n'
    }
    else{
        Matriz exponenciacao_temp = exponenciacao(temp, (n-1)/2); //z = y^(n-1)/2   //Θ(log n) - A chamada recursiva sempre divide por 2 o tamanho de 'n'
        return multiplicacao_da_matriz(base, exponenciacao_temp); //x * z           //Θ(1) - Chamada de função com complexidade Θ(1)
    }
}

int fibonacci(int n) {//Θ(log m) - Chamada de função com complexidade Θ(log n)
    if(n == 0) return 0;                                                            //Θ(1) - Verificação e retorno de valor
    if(n == 1) return 1;                                                            //Θ(1) - Verificação e retorno de valor

    Matriz m;                                                                       //Θ(1) - Inicialização de variável
    m.matriz[0][0] = 0;                                                             //Θ(1) - Atribuição 
    m.matriz[0][1] = 1;                                                             //Θ(1) - Atribuição
    m.matriz[1][0] = 1;                                                             //Θ(1) - Atribuição
    m.matriz[1][1] = 1;                                                             //Θ(1) - Atribuição

    Matriz resultado = exponenciacao(m, n - 1);                                     //Θ(log n) - Chamada da função que possui complexidade Θ(log n)
    return resultado.matriz[1][1];                                                  //Θ(1) - Retorno de um único valor
}

int main(){
    int n;
    while(1){
        printf("Digite o valor de N desejado, ou '-1' para sair: ");
        scanf("%d", &n);
        if(n == -1) break;
        printf("f(%d) = %d\n", n, fibonacci(n));
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