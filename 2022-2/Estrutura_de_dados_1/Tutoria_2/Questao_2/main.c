#include "r9.h"
#include <stdio.h>

int main(){
    int n, soma = 0;
    scanf("%d", &n);
    
    while(n!=0){
        

        soma = soma_r9(n);

        while(soma > 9)
            soma = soma_r9(soma);
        

        if(soma == 9)
            printf("%d is a multiple of 9\n", n);
        
        else
            printf("%d is not a multiple of 9\n", n);

        scanf("%d", &n);
        soma = 0;
    }
    
    return 0;
}