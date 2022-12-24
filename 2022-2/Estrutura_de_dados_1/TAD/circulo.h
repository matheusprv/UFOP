/* TAD Circulo */
#ifndef circulo_h
#define circulo_h

#include <stdio.h>
#include "ponto.h"

typedef struct circulo Circulo; /* forward declaration */

#define PI 3.14159 /* constante PI */

/* fun ções exportadas */
Circulo *CirculoCria(Ponto *centro, float raio);
void CirculoLibera(Circulo **circ);
float CirculoArea(Circulo *circ);
int CirculaInterior(Circulo *circ, Ponto *pt);

#endif /* circulo_h */