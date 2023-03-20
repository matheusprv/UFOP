#include <stdio.h>
#include <math.h>

int main(){

    int casosDeTeste;
    scanf("%d", &casosDeTeste);

    for(int cont=0; cont<casosDeTeste; cont++){
        unsigned int num;
        scanf("%u", &num);

        if(num==1){
            printf("Not Prime\n");
            continue;
        }

        double raiz = sqrt(num);

        int primo = 1;

        for(int i=2; i <= raiz; i++){
            if(num%i == 0){
                primo = 0;
                break;
            }
        }

        if(primo)
            printf("Prime\n");
        else 
            printf("Not Prime\n");
    }

    return 0;
}