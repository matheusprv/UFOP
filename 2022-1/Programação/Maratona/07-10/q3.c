#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){
    
    char d;
    char n = malloc(((int) pow(10, 100)) * sizeof(int));
    int tamanhoString;
    scanf("%c %s", &d, n);
    getchar();
    
    while (d != '0' && strcmp(n, "0") != 0){
        tamanhoString = strlen(n);
        
        for(int i=0; i<tamanhoString || n[i] != '\0'; i++){
            if(n[i] == d){
                for(int j = i; n[j] != '\0'; j++){
                    n[j] = n[j+1];
                }
                i--;
            }
        }
        if(strlen(n)>0)
            printf("%d\n", atoi(n));
        else
            printf("0\n");

        scanf("%c %s", &d, n);
        getchar();
    }
    

    return 0;
}