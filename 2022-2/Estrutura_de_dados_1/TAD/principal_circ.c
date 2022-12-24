#include <stdio.h>
#include "circulo.h" /* basta incluir circulo .h ( cont ém ponto .h ) */

int main()
{
    /* instanciando e manipulando vari á veis do tipo Ponto */
    Ponto *p1 = PontoCria(8.0, 15.0);
    Ponto *p2 = PontoCria(8.0, 16.0);
    /* instanciando e manipulando vari á veis do tipo Circulo */
    Circulo *circ = CirculoCria(p2, 4.9);
    printf(" Area (cir): %f\n", CirculoArea(circ));
    if (CirculaInterior(circ, p1))
        printf("P1 está em Circ \n");
    CirculoLibera(&circ); /* liberando mem ó ria alocada */
    PontoLibera(&p1);
    /* p2 já foi liberado ao liberar o circ */
    return 0;
}