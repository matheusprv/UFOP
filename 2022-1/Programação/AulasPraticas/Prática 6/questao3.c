#include <stdio.h>

int main(){
    int x, y;

    do{
        printf("Digite os valores de x e y: ");
        scanf("%d%d", &x, &y);

        if(x%2!=0 || y%2!=0 ){
            printf("Apenas número pares são aceitos.\n");
        }
        else if(x<0 || y<0){
            printf("Apenas números positivos são aceitos.\n");
        }
        else if(x>y){
            printf("x deve ser menor do que y.\n");
        }

    }while((x%2!=0 || x<0) || (y%2!=0 || y<0) || x>y);

    while(x<=y){
        //Exibir espaços em branco
        for(int i=0; i<((y-x)/2); i++){
            printf(" ");
        }
        for(int i=0;i<x;i++){
            printf("*");
        }
        printf("\n");
        x+=2;
    }   

    return 0;
}

              