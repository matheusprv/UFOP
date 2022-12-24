/* TAD : Ponto (x,y) */
#ifndef ponto_h
#define ponto_h

/* Tipo exportado : somente o nome do NOVO TIPO */
typedef struct ponto Ponto; /* forward declaration */

/* Fun ções exportadas */
Ponto *PontoCria(float x, float y);

void PontoLibera(Ponto **p);

void PontoAcessa(Ponto *p, float *x, float *y);

void PontoAtribui(Ponto *p, float x, float y);

float PontoDistancia(Ponto *p1, Ponto *p2);

#endif /* ponto_h */