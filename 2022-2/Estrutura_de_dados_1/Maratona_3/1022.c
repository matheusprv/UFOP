#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n1, n2, d1, d2;
    char operacao;
} Operacao;

void soma(Operacao *, int *, int *);
void subtracao(Operacao *, int *, int *);
void multiplicacao(Operacao *, int *, int *);
void divisao(Operacao *, int *, int *);
void simplificar(int *, int*);

int main()
{

    int casos;
    Operacao op;

    scanf("%d", &casos);

    for (int i = 0; i < casos; i++)
    {
        scanf("%d", &op.n1);

        getchar();
        getchar();

        scanf("%d", &op.d1);

        getchar();
        scanf("%c", &op.operacao);

        scanf("%d", &op.n2);

        getchar();
        getchar();

        scanf("%d", &op.d2);

        int numerador, denominador;

        switch (op.operacao){
            case '+':
                soma(&op, &numerador, &denominador);
                break;

            case '-':
                subtracao(&op, &numerador, &denominador);
                break;

            case '*':
                multiplicacao(&op, &numerador, &denominador);
                break;

            default:
                divisao(&op, &numerador, &denominador);
                break;
        }

        printf("%d/%d = ", numerador, denominador);
        simplificar(&numerador, &denominador);
        printf("%d/%d\n", numerador, denominador);
    }

    return 0;
}

void soma(Operacao *op, int *numerador, int *denominador){
    *numerador = op->n1 * op->d2 + op->d1 * op->n2;
    *denominador = op->d1 * op->d2;
}

void subtracao(Operacao *op, int *numerador, int *denominador){
    *numerador = op->n1 * op->d2 - op->d1 * op->n2;
    *denominador = op->d1 * op->d2;
}

void multiplicacao(Operacao *op, int *numerador, int *denominador){
    *numerador = op->n1 * op->n2;
    *denominador = op->d1 * op->d2;
}

void divisao(Operacao *op, int *numerador, int *denominador){
    *numerador = op->n1 * op->d2;
    *denominador = op->d1 * op->n2;
}

void simplificar(int * numerador, int * denominador){
    int maior = *numerador;
    if(*denominador > maior) maior = *denominador;

    for(int i = maior; i>=1; i--){
        if(*numerador % i == 0 && *denominador % i == 0){
            *numerador = *numerador/i;
            *denominador = *denominador/i;
            break;
        }
    }
}