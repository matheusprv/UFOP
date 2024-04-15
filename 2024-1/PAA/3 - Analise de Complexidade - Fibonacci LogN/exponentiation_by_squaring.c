#include <stdio.h>
#include <stdlib.h>


/*
    Exponentiation by squaring
        x^n = x(x^2)^(n-1)/2 se n for ímpar
        x^n = (x^2)^(n/2)    se n for par
    onde x é a matriz
*/
int exponenciacao(int base, int n){
    if(n == 0) return 1;
    if(n == 1) return base;
    
    int temp = base * base;
    if(n % 2 == 0){
        return exponenciacao(temp, n/2);
    }
    else{
        int exponenciacao_temp = exponenciacao(temp, (n-1)/2);
        return  base * exponenciacao_temp;
    }
}

int main(){
    printf("%d\n", exponenciacao(6, 2));
    return 0;
}