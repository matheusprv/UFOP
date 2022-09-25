#include <stdio.h>

int primo(int n);

int main(){
    
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    if(primo(numero) == 1)
        printf("%d é um número primo!", numero);
    
    else
        printf("%d não é um número primo!", numero);
    

    return 0;
}

int primo(int n){
    for(int i=2; i<n; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
    
}