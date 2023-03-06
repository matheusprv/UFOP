#include <stdio.h>
#include <string.h>

float somaDuracao(char c){    
    switch (c){
        case 'W':
            return 1;
            break;

        case 'H':
            return 0.5;
            break;

        case 'Q':
            return 0.25;
            break;

        case 'E':
            return (float)1/8;
            break;

        case 'S':
            return (float)1/16;
            break;

        case 'T':
            return (float)1/32;
            break;
        
        default:
            return (float)1/64;
            break;
    }
}

int main() {
    char compassos[201];

    scanf("%s", compassos);

    float duracaoCompasso=0;
    int tamStr, compassosCorretos;

    while (compassos[0] != '*'){
        compassosCorretos = 0;

        tamStr = strlen(compassos);
        for (int i = 1; i < tamStr; i++){
            if(compassos[i] == '/'){
                if(duracaoCompasso == 1)
                    compassosCorretos++;

                duracaoCompasso = 0;
            }

            else
                duracaoCompasso += somaDuracao(compassos[i]);
        }
        
        printf("%d\n", compassosCorretos);

        compassos[0] = '\0';
        scanf("%s", compassos);
    }
    
}