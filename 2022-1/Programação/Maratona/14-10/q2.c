#include <stdio.h>

int main(){

    int x,z;

    scanf("%d", &x);

    do{
        scanf("%d", &z);
    }while(z<=x);
    
    int somador = z;
    int i = 0;

    while(z<=x){
        z += somador;
        i++;
    }

    printf("%d\n", i);

    return 0;
}