#include <stdio.h>
#include <stdlib.h>



int calcula_remendos(int n, int t1, int t2, int *furos, int i, int j, int * valorMinPos)
{
    int k, possibilidade1, possibilidade2;

    if (valorMinPos[i] > 0)
        return valorMinPos[i];

    if (furos[i] - furos[j] <= t1)
        possibilidade1 = t1;
    else{
        k = n;
        while (k-- > 0)
            if (furos[i] - furos[k] > t1)
                break;
        possibilidade1 = calcula_remendos(n, t1, t2, furos, k, j, valorMinPos) + t1;
    }

    if (furos[i] - furos[j] <= t2)
        possibilidade2 = t2;
    
    else{
        k = n;
        while (k-- > 0)
            if (furos[i] - furos[k] > t2)
                break;
        possibilidade2 = calcula_remendos(n, t1, t2, furos, k, j, valorMinPos) + t2;
    }

    valorMinPos[i] = possibilidade1 < possibilidade2 ? possibilidade1 : possibilidade2; 
    return valorMinPos[i];
}

int main()
{

    int n_furos, c_comprimento, t1, t2;

    while (scanf("%d%d%d%d", &n_furos, &c_comprimento, &t1, &t2) != EOF)
    {
        int * valorMinPos = calloc(1000, sizeof(int));
        int *furos = (int *)malloc(n_furos * sizeof(int));

        for (int i = 0; i < n_furos; i++)
            scanf("%d", &furos[i]);

        for(int i = 0; i < n_furos; i++)
            for(int j = 0; j < n_furos; j++){
                if(i != j )
                    calcula_remendos(n_furos, t1, t2, furos, i, j, valorMinPos);
            }

        printf("%d\n", valorMinPos[n_furos - 1]);

        free(valorMinPos);
        free(furos);
    }

    return 0;
}