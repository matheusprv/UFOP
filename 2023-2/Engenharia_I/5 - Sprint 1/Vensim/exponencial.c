#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float arredondar(float num, int casas_decimais){

    int casas = pow(10, casas_decimais);
    num = roundf(num * casas) / casas; 
    return num;
}

int main(){

    float inicial = 100;
    int tempo = 100;

    float q = inicial;
    float expoente = 0.01;
    for(int i = 0; i < tempo; i++){
        q *= expoente;
        q = arredondar(q, 4);
        expoente -= q;
        printf("%.4f\n", q);
    }

    return 0;
}