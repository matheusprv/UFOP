#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100000

void imprimeInteiros(int a[], int n){
    for(int i=0; i<n; i++){
        printf("A[%d] = %d\n", i+1, a[i]);
    }
}

int main(){

    srand(5);

    int n;
    int numerosAleatorios[TAM_MAX];
    int a[500];

    printf("Entre com um número inteiro <= 500: ");
    scanf("%d", &n);

    while(n<1 || n>500){
        printf("Entre com um número inteiro <= 500: ");
        scanf("%d", &n);
    }

    for(int i=0; i<TAM_MAX; i++){
        numerosAleatorios[i] = rand()%n+1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<TAM_MAX; j++){
            if(i+1 == numerosAleatorios[j]){
                a[i]++;
            }
        }
    }

    imprimeInteiros(a, n);

    return 0;
}