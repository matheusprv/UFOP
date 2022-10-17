#include <stdio.h>

long long fat(int n);

int main(){

    int n1;
    printf("Digite o valor de n:");
    scanf("%d", &n1);

    printf("%d! = %lld", n1, fat(n1));

    return 0;
}


long long fat(int n){

    long fatorial = 1;

    for(int i=n; i>1;i--){
        printf("N: %d\n", i);
        fatorial *= i;
    }

    return fatorial;
}