#include <stdio.h>


int main(){

    int novoGrenal, qtdGrenais = 0, inter = 0, gremio = 0, 
    empate = 0,golsInter, golsGremio;

    while (1){
        scanf("%d%d", &golsInter, &golsGremio);
        qtdGrenais++;
        if(golsInter>golsGremio)
            inter ++;
        else if(golsGremio>golsInter)
            gremio++;
        else
            empate ++;

        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d", &novoGrenal);
        if(novoGrenal!=1)
            break;
    }
    
    printf("%d grenais\n", qtdGrenais);
    printf("Inter:%d\n", inter);
    printf("Gremio:%d\n", gremio);
    printf("Empates:%d\n", empate);

    if(inter>gremio){
        printf("Inter venceu mais\n");
    }
    else if(gremio>inter){
        printf("Gremio venceu mais\n");
    }
    else{
        printf("Nao houve vencedor\n");
    }


    return 0;
}