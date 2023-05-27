#ifndef ARVORE_B_H
#define ARVORE_B_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 2

typedef long TipoChave;

typedef struct TipoRegistro{
    TipoChave chave;
    int valorArbitrario;
}TipoRegistro;

typedef struct TipoPagina * TipoApontador;

typedef struct TipoPagina{
    int numElementos;
    TipoRegistro registros[M];
    TipoApontador paginas[M+1];
}TipoPagina;

TipoPagina * iniciaArvore();

void pesquisa(TipoChave, TipoApontador);

void InsereNaPagina(TipoApontador Ap, TipoRegistro Reg, TipoApontador ApDir) {
    short NaoAchouPosicao;
    int k;
    k = Ap->numElementos;
    NaoAchouPosicao = (k > 0);

    while (NaoAchouPosicao) {
        if (Reg.chave >= Ap->registros[k - 1].chave) {
            NaoAchouPosicao = false;
            break;
        }
        Ap->registros[k] = Ap->registros[k - 1];
        Ap->paginas[k + 1] = Ap->paginas[k];
        k--;
        if (k < 1)
            NaoAchouPosicao = false;
    }
    Ap->registros[k] = Reg;
    Ap->paginas[k + 1] = ApDir;
    Ap->numElementos++;
}

void Ins(TipoRegistro Reg, TipoApontador Ap, short* cresceu, TipoRegistro* RegRetorno, TipoApontador* ApRetorno) {
    long i = 1;
    long j;

    TipoApontador ApTemp;

    if (Ap == NULL) {
        *cresceu = 1;
        (*RegRetorno) = Reg;
        (*ApRetorno) = NULL;

        return;
    }

    while (i < Ap->numElementos && Reg.chave > Ap->registros[i - 1].chave)
        i++;

    if (Reg.chave == Ap->registros[i - 1].chave) {
        printf("Erro: Registro já está presente\n");
        *cresceu = 0;

        return;
    }

    if (Reg.chave < Ap->registros[i - 1].chave)
        i--;

    Ins(Reg, Ap->paginas[i], cresceu, RegRetorno, ApRetorno);

    if (!*cresceu)
        return;

    if (Ap->numElementos < M) { // página tem espaço
        InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
        *cresceu = 0;

        return;
    }

    // Overflow: página tem que ser dividida
    ApTemp = (TipoApontador)malloc(sizeof(TipoPagina));
    ApTemp->numElementos = 0;
    ApTemp->paginas[0] = NULL;

    if (i < M + 1) {
        InsereNaPagina(ApTemp, Ap->registros[M - 1], Ap->paginas[M]);
        Ap->numElementos--;
        InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
    } else
        InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno);

    for (j = M + 2; j <= M; j++)
        InsereNaPagina(ApTemp, Ap->registros[j - 1], Ap->paginas[j]);

    Ap->numElementos = M;
    ApTemp->paginas[0] = Ap->paginas[M + 1];
    *RegRetorno = Ap->registros[M];
    *ApRetorno = ApTemp;
}

void Insere(TipoRegistro Reg, TipoApontador* Ap) {
    short Cresceu;
    TipoRegistro RegRetorno;
    TipoApontador ApRetorno, ApTemp;

    Ins(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno);

    if (Cresceu) {
        ApTemp = (TipoApontador)malloc(sizeof(TipoPagina));
        ApTemp->numElementos = 1;
        ApTemp->registros[0] = RegRetorno;
        ApTemp->paginas[1] = ApRetorno;
        ApTemp->paginas[0] = *Ap;
        *Ap = ApTemp;
    }
}

#endif