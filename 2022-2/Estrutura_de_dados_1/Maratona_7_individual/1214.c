#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int n;
    scanf("%d", &n);

    for(int cont = 0; cont< n; cont++){
        int nAlunos, acimaMedia = 0;
        double somatorio = 0;

        scanf("%d", &nAlunos);
        double * notas = malloc(sizeof(double) * nAlunos);

        for(int i = 0; i < nAlunos; i++){
            scanf("%lf", &notas[i]);
            somatorio += notas[i];
        }

        double media = (somatorio) / nAlunos;

        for(int i = 0; i<nAlunos; i++){
            if(notas[i] > media)
                acimaMedia++;
        }

        printf("%.3lf%%\n", ((double)acimaMedia/nAlunos) * 100);

        free(notas);
        
    }

}