#include <stdio.h>
#include <string.h>
#define A 65
#define Z 90
int main(){
    char texto[52];
    int repeticoes, cifra, tamanhoTexto, diferenca;
    
    scanf("%d", &repeticoes);
    getchar();
    for(int i=0; i<repeticoes; i++){
        fgets(texto, 52, stdin);
        texto[strlen(texto)-1] = '\0';
        tamanhoTexto = strlen(texto);
        
        scanf("%d", &cifra);
        getchar();
        for(int j=0; j<tamanhoTexto; j++){
            if(texto[j]-cifra >= A){
                texto[j] -= cifra;
            }
            else{
                diferenca = texto[j] - A;
                texto[j] = Z+diferenca+1-cifra;    
            }
        }
        printf("%s\n", texto);
    }
    return 0;
}