#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ponto.h"

/* defini ção dos dados e seus tipos */
struct ponto
{
    float x;
    float y;
};
Ponto *PontoCria(float x, float y)
{
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));
    if (p == NULL)
    {
        printf("Memó ria insuficiente !\n");
        exit(1);
        // return NULL ;
    }
    p->x = x;
    p->y = y;
    return p;
}

void PontoLibera(Ponto **p)
{
    free(*p);
}
void PontoAcessa(Ponto *p, float *x, float *y)
{
    *x = p->x;
    *y = p->y;
}

void PontoAtribui(Ponto *p, float x, float y)
{
    p->x = x;
    p->y = y;
}

float PontoDistancia(Ponto *p1, Ponto *p2)
{
    float dx = p2->x - p1 -> x;
    float dy = p2->y - p1 -> y;
    return sqrt(dx * dx + dy * dy);
}