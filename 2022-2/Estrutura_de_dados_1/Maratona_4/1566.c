#include <stdio.h>
#include <stdlib.h>

void ordernacao(int *, int, int);

int main(){

    int casosDeTeste;
    scanf("%d", &casosDeTeste);

    for(int cont=0; cont<casosDeTeste; cont++){
        int qtdAlturas;
        scanf("%d", &qtdAlturas);

        int *alturas = malloc(qtdAlturas * sizeof(int));

        for(int i = 0; i < qtdAlturas; i++){
            scanf("%d", &alturas[i]);
        }

        ordernacao(alturas, 0, qtdAlturas-1);

        printf("%d", alturas[0]);
        for(int i = 1; i<qtdAlturas; i++)
            printf(" %d", alturas[i]);

        printf("\n");

        free(alturas);

    }

    return 0;
}


void ordernacao(int * a, int left, int right){
int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while (i <= j)
    {
        while (a[i] < x && i < right)
        {
            i++;
        }
        while (a[j] > x && j > left)
        {
            j--;
        }
        if (i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if (j > left)
    {
        ordernacao(a, left, j);
    }
    if (i < right)
    {
        ordernacao(a, i, right);
    }
}