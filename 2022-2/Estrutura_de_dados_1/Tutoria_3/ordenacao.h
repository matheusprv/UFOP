#ifndef ORDENACAO_H
#define ORDENACAO_H

typedef struct upa TADupa;

int alocarUpa (TADupa **aux, int n); //funcao que aloca memoria para a quantidade de upas que preciso ler

void preencheVetor(TADupa *upas, int n); //lendo as informacoes sobre as upas

void ordenaUpas(TADupa *upas, int n); //ordenando as upas de acordo com a necessidade, o metodo utilizado
                                      //foi o selection sort

void imprimeUpas(TADupa *upas, int n); //funcao que imprime as upas apos a ordenacao  

void desalocaUpas(TADupa **aux);

#endif