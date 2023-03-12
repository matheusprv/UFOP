#include <stdio.h>
#include <stdlib.h>

int calculaFuro(int n, int c, int t1, int t2, int *f, int pos, int posicaoCom){

            int j, respsota1, resposta2;
            int *Aux = calloc(n, sizeof(int));
            Aux[pos] = 0;

            for (int i = pos - 1; i >= 0; i--){
                if (f[pos] - f[i] > t1){
                    j = i;
                    break;
                }
            }

            if (f[pos] - f[j] <= t1)
                respsota1 = t1;
            else
                respsota1 = Aux[j] + t1;

            for (int i = pos - 1; i >= 0; i--){
                if (f[pos] - f[i] > t2){
                    j = i;
                    break;
                }
            }


            if (f[pos] - f[j] <= t2)
                resposta2 = t2;
            else
                resposta2 = Aux[j] + t2;

            if (respsota1 < resposta2)
                Aux[pos] = respsota1;
            else
                Aux[pos] = resposta2;


            int k = pos + 1;
            while (k < n && f[k] - f[pos] <= c){

                if (Aux[k] == 0){

                    for (int i = k - 1; i >= 0; i--){
                        if (f[k] - f[i] > c){
                            j = i;
                            break;
                        }
                    }

                    if (f[k] - f[j] <= c)
                        Aux[k] = Aux[j] + c;
                    else
                        Aux[k] = calculaFuro(n, c, t1, t2, f, j, k) + c;
                }
                k++;

            }

            int resultado = Aux[pos];
            free(Aux);
            return resultado;


}

int main(){

    int n, c, tamRemendos[2];

    while(scanf("%d%d%d%d", &n, &c, &tamRemendos[0], &tamRemendos[1]) != EOF){

        if(tamRemendos[0] > tamRemendos[1]){
            int aux = tamRemendos[0];
            tamRemendos[0] = tamRemendos[1];
            tamRemendos[1] = aux;
        }

        int * furos = malloc(n * sizeof(int));
        for(int i = 0; i < n; i++){
            scanf("%d", &furos[i]);
        }

            for(int cont1 = 0; cont1 < n; cont1++){
        for(int cont2 = 0; cont2 < n; cont2++){

        printf("%d",calculaFuro(n, c, tamRemendos[0], tamRemendos[1], furos, 0, n));

    }

    return 0;
}