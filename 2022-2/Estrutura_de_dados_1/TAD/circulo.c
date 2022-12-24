#include <stdlib.h>
#include <stdio.h>
#include "circulo.h"
/* defini ção dados e seus tipos */
struct circulo
{
    Ponto *centro;
    float raio;
};

/* alternativa : receber (x,y) e raio : instanciar o ponto */
Circulo *CirculoCria(Ponto *centro, float raio)
{
    Circulo *circ = (Circulo *)malloc(sizeof(Circulo));
    if (circ == NULL)
    {
        printf("Memória insuficiente !\n");
        exit(1);
    }
    circ->centro = centro;
    circ->raio = raio;
    return circ;
}

void CirculoLibera(Circulo **circ)
{
    PontoLibera(&(*circ)->centro); /* primeiro libera a(s) parte (s) */
    free(*circ);                   /* depois libera o todo */
}

float CirculoArea(Circulo *circ)
{
    return PI * circ -> raio * circ->raio;
}

int CirculoInterior(Circulo *circ, Ponto *pt)
{
    float d = PontoDistancia(circ->centro, pt);
    return (d < (circ->raio)); /*1 se menor , 0 caso contr á rio */
}