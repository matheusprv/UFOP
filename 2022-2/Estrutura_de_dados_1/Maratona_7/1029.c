#include <stdio.h>
#include <stdlib.h>

int fibonacci(int * chamadas, int fib){
    if(fib == 1)  return 1;
    else if(fib == 0) return 0;
    else{
        *chamadas += 2;
        return fibonacci(chamadas, fib-1) + fibonacci(chamadas, fib-2);
    }
}


int main(){

    int casosDeTeste;
    scanf("%d", &casosDeTeste);
    int fib;
    
    for(int cont=0; cont<casosDeTeste; cont++){
        
        scanf("%d", &fib);
        
        int chamadas = 0;
        int resultado = fibonacci(&chamadas, fib);

        printf("fib(%d) = %d calls = %d\n", fib, chamadas, resultado);
    }

    return 0;
}