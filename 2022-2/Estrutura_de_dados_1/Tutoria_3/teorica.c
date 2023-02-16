#include <stdio.h>

int main()
{

    int v[] = {15, 2, 4, 11, 10, 1, 3, 5, 6, 9, 7, 8, 14, 13};

    int n = 14;

    for (int i = 0; i < n; i++)
    {
        int troca = 0;
        for (int j = 1; j < n - i; j++)
        {
            if (v[j] < v[j - 1])
            {
                int aux = v[j];
                v[j] = v[j - 1];
                v[j - 1] = aux;
                troca++;
            }

        for (int cont = 0; cont < n; cont++)
        {
            printf("%4d", v[cont]);
        }
        printf("\n");  

        }
        if (troca == 0)
        {
            return 0;
        }
      
    }

    return 0;
}