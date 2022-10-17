#include <stdio.h>

struct Racional {
    int numerador;
    int denominador;
};


int calculaMDC(int numerador, int denominador){
    int menorNumero;

    if(numerador < denominador){
        menorNumero = numerador;
    }
    else{
        menorNumero = denominador;
    }
    int mdc = numerador;
    for(int i=menorNumero; i>=1;i--){
        //printf("i: %d\n", i);
        if(numerador % i == 0 && denominador %i == 0){
            //printf("Entrou\n");
            mdc = i;
            break;
        }
    }
    //printf("MDC: %d\n", mdc);
    return mdc;
}


int equal(struct Racional r1, struct Racional r2, struct Racional *valorMDC){

    int mdcR1 = calculaMDC(r1.numerador, r1.denominador);
    r1.numerador /= mdcR1;
    r1.denominador /= mdcR1;

    int mdcR2 = calculaMDC(r2.numerador, r2.denominador);
    r2.numerador /= mdcR2;
    r2.denominador /= mdcR2;
    
    if(r1.numerador == r2.numerador && r1.denominador == r2.denominador){
        valorMDC->numerador = r1.numerador;
        valorMDC->denominador = r1.denominador;
        return 1;
    }
    else{
        return 0;
    }

}

int main(){

    struct Racional r1, r2;

    printf("Digite numerador e denominador de r1: ");
    scanf("%d%d", &r1.numerador, &r1.denominador);

    printf("Digite numerador e denominador de r2: ");
    scanf("%d%d", &r2.numerador, &r2.denominador);

    struct Racional valorMDC; 

    if(equal(r1, r2, &valorMDC)){
        printf("r1 e r2 são iguais a (%d / %d)!\n", valorMDC.numerador, valorMDC.denominador);
    }
    else{
        printf("r1 e r2 são diferentes!\n");
    }

    return 0;
}