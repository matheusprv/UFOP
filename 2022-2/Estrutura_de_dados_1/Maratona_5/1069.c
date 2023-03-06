#include <stdio.h> 
#include <string.h>

int main (){
    int n;
    int countOpen, countClose;
    int tam, diamantes;

    char frase[1002];
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        countOpen = 0, countClose = 0;
        getchar();
        scanf("%s", frase);
        tam = strlen(frase);

        for(int i=0; i<tam; i++){
            if(frase[i] == '<'){
                countOpen++;
            }
            if(frase[i] == '>' && countOpen > countClose){
                countClose++;
            }
        }

        diamantes = countOpen < countClose ? countOpen : countClose;

        printf("%d\n", diamantes);
        frase[0] = '\0';
    }

    return 0;
}