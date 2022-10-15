#include <stdio.h>
#include <stdlib.h>

int main(){

    int b, n;
    scanf("%d%d", &b,&n);

    while(b!=0 && n!=0){
        int *reservas = malloc(b*sizeof(int));
        
        for(int i=0; i<b; i++){
            scanf("%d", &reservas[i]);
        }

        int devedor;
        scanf("%d", &devedor);

        int credor;
        scanf("%d", &credor);

        int valor;
        scanf("%d", &valor);

        char conseguePagar = 'S';



        printf("%c", conseguePagar);

        free(reservas);
        scanf("%d%d", &b,&n);
    }

    return 0;
}