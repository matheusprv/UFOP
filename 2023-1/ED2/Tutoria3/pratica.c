#define MM 2
#define MM2 2

typedef long TipoChave;

typedef struct TipoRegistro{
    TipoChave chave;
}TipoRegistro;

typedef enum {Interna, Externa} TipoIntExt;

typedef struct TipoPagina * TipoApontador;

typedef struct TipoPagina{
    TipoIntExt Pt;

    union{
        struct{
            int ni;
            TipoChave ri[MM];
            TipoApontador pi[MM+1];
        }U0;

        struct{
            int ne;
            TipoRegistro re[MM2];
        }U1;
        
    }UU;

}TipoPagina;

//Como está a procura do elemento de maior chave, basta ir até a última posição da árvore
void Maximo(TipoRegistro *x, TipoApontador * Ap){
    
    if((*Ap)->Pt == Interna){
        int ultimaPosicao = (*Ap)->UU.U0.ni;
        Maximo(x, (*Ap)->UU.U0.pi[ultimaPosicao]);
    }
    else{
        int ultimaPosicao = (*Ap)->UU.U1.re;
        *x = (*Ap)->UU.U1.re[ultimaPosicao-1];
    }
}