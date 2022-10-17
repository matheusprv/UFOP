#include <stdio.h>

int main(){

    float temperaturas[30];
    float somatorio = 0;

    printf("Entre com as temperaturas: ");

    for(int i=0; i<30;i++){
        scanf("%f", &temperaturas[i]);
        somatorio += temperaturas[i];
    }

    float media = somatorio/30;
    int acimaMedia =0, abaixoMedia =0;

    for(int i=0; i<30;i++){
        if(temperaturas[i]>media){
            acimaMedia++;
        }
        else if(temperaturas[i]<media){
            abaixoMedia++;
        }
    }

    printf("Acima: %d\n", acimaMedia);
    printf("Abaixo: %d\n", abaixoMedia);

    return 0;
}