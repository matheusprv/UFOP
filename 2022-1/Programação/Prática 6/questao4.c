#include <stdio.h>
#include <math.h>

double calculaPI(int);

int main(){

    int nTermos;

    printf("Digite o número de termos: ");
    scanf("%d", &nTermos);

    printf("pi = %.4lf", calculaPI(nTermos));


    return 0;
}

double calculaPI(int n){

    double somatorio = 0;

    for(int i=0; i<n; i++){

        somatorio += pow(-1, i)*(1/(pow(1+(2*i),3))); 

        //printf("i: %d  -  %lf\n", i, pow(-1, i)*(1/(pow(1+(2*i),3))));

    }

    double pi = somatorio * 32;

    return cbrt(pi);
}