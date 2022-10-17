#include <stdio.h>
#include <stdlib.h>

int main(){

    int bancos, dividas;
    scanf("%d%d", &bancos, &dividas);

    while (bancos !=0 && dividas !=0){
        
        int *dinheiro = (int *) malloc(bancos * sizeof(int));

        for(int i=0; i<bancos; i++){
            scanf("%d", &dinheiro[i]);
        }

        char conseguePagar = 'S';
        int banco, paraQuemDeve, divida;
        for(int i=0; i<bancos; i++){
            scanf("%d%d%d", &banco, &paraQuemDeve, &divida);
            banco--;
            paraQuemDeve--;
            
            dinheiro[banco] -= divida;
            dinheiro[paraQuemDeve] += divida;
        }

        for(int i=0; i<bancos; i++){
            if(dinheiro[i] < 0)
                conseguePagar = 'N';
        }
        free(dinheiro);
        printf("%c\n", conseguePagar);
        scanf("%d%d", &bancos, &dividas);
    }
    

    return 0;
}