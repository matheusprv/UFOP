#include <stdio.h>
#include "ponto.h"

int main()
{
    Ponto *p1 = PontoCria(2.0, 4.0); /* alocando dinamicamente */
    Ponto *p2 = PontoCria(8.0, 16.0);
    float x, y;              /* vari á veis auxiliares */
    PontoAcessa(p1, &x, &y); /* manipulando o ponto p1 instanciado */
    printf("P1 (%f, %f)\n", x, y);
    printf(" Dist (P1 e P2): %f\n", PontoDistancia(p1, p2));
    PontoLibera(&p1);
    PontoLibera(&p2);
    return 0;
}