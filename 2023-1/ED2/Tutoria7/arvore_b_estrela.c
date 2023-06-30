#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MB 2
#define MMB 2*MB

#define MB2 2
#define MMB2 2*MB2

typedef enum {Interna, Externa} TipoIntExt;

typedef struct TipoPaginaEstrela* TipoApontadorEstrela;

typedef long TipoChave;

typedef struct TipoRegistroEstrela{
    TipoChave Chave;
    long dado1;
} TipoRegistroEstrela;

typedef struct TipoPaginaEstrela{ 
    TipoIntExt Pt; 
    union {
        struct { 
            int ni; 
            TipoChave ri[MMB]; 
            TipoApontadorEstrela pi[MMB + 1];
        } U0; 
        struct { 
            int ne; 
            TipoRegistroEstrela re[MMB2];
        } U1;
    } UU;
} TipoPaginaEstrela;




void inicializa_b_estrela (TipoApontadorEstrela * Arvore) 
{
    *Arvore = NULL;
}


void InsereNaPaginaExterna(TipoApontadorEstrela Ap, TipoRegistroEstrela Reg){
    bool NaoAchouPosicao;
    int k;  

    k = Ap->UU.U1.ne; 
    NaoAchouPosicao = (k > 0);

    while(NaoAchouPosicao){
        if(Reg.Chave > Ap->UU.U1.re[k-1].Chave){
            NaoAchouPosicao = false;
            break;
        }
        Ap->UU.U1.re[k] = Ap->UU.U1.re[k-1];
        k--;
        if(k < 1)
            NaoAchouPosicao = false;
    }

    Ap->UU.U1.re[k] = Reg;
    Ap->UU.U1.ne++;
}

void InsereNaPaginaInterna(TipoApontadorEstrela Ap, TipoChave Reg, TipoApontadorEstrela ApDir){
    bool NaoAchouPosicao;
    int k;

    k = Ap->UU.U0.ni;
    NaoAchouPosicao = (k > 0);

    while (NaoAchouPosicao)
    {
        if (Reg >= Ap->UU.U0.ri[k - 1])
        {
            NaoAchouPosicao = false;
            break;
        }
        Ap->UU.U0.ri[k] = Ap->UU.U0.ri[k - 1];
        Ap->UU.U0.pi[k+1] = Ap->UU.U0.pi[k];
        k--;
        if (k < 1)
            NaoAchouPosicao = false;
    }
    Ap->UU.U0.ri[k]= Reg;
    Ap->UU.U0.pi[k + 1] = ApDir;
    Ap->UU.U0.ni++;

}

void Ins_b_estrela(TipoRegistroEstrela Reg, TipoApontadorEstrela Ap, short *cresceu, TipoChave *RegRetorno, TipoApontadorEstrela *ApRetorno){
    long i = 1;
    long j;

    TipoApontadorEstrela ApTemp;

    if(Ap->Pt == Externa){
        *cresceu = true;
        *RegRetorno = Reg.Chave;
        *ApRetorno = NULL;

        while(i < Ap->UU.U1.ne && Reg.Chave > Ap->UU.U1.re[i-1].Chave){
            i++;
        }

        //caso ja exista o registro na arvore
        if(Reg.Chave == Ap->UU.U1.re[i-1].Chave){
            *cresceu = false;
            return;
        }

        //Se a pagina atual comporta o item a ser inserido
        if(Ap->UU.U1.ne < MMB2){ 
            InsereNaPaginaExterna(Ap, Reg);
            *cresceu = false;
            return;
        }

        //Overflow: Pagina tem que ser dividida
        //Criando uma nova pagina
        ApTemp = (TipoApontadorEstrela) malloc(sizeof(TipoPaginaEstrela));
        ApTemp->UU.U1.ne = 0;
        ApTemp->Pt = Externa;

        //Verifica para onde a chave ira
        if(i < MB2 + 1){
            //Insere o item na pagina que ja existe
            //Coloca o ultimo registro na nova pagina
            InsereNaPaginaExterna(ApTemp, Ap->UU.U1.re[MMB2 - 1]);
            Ap->UU.U1.ne--;
            //Insere o novo item na pagina atual
            InsereNaPaginaExterna(Ap, Reg);
        }

        // Inserindo o item que deu o overflow na pagina vizinha
        else InsereNaPaginaExterna(ApTemp, Reg);
            
        //Colocando os valores excedentes e colocando na pagina nova
        for(j = MB2 + 1; j <= MMB2; j++)
            InsereNaPaginaExterna(ApTemp, Ap->UU.U1.re[j-1]);
            
        *RegRetorno = Ap->UU.U1.re[MB2].Chave;
        Ap->UU.U1.ne = MB2;
        *ApRetorno = ApTemp;

        return;
    }

    else{ //Ap->Pt == Interna
        
        while(i < Ap->UU.U0.ni && Reg.Chave > Ap->UU.U0.ri[i-1]){ 
            i++;
        }

        //Verifica se iremos para a sub arvore a esquerda (true) ou direita (false)
        if(Reg.Chave < Ap->UU.U0.ri[i-1]) i--;

        Ins_b_estrela(Reg, Ap->UU.U0.pi[i], cresceu, RegRetorno, ApRetorno);

        if(!*cresceu) return;

        //Verifica se a pagina NAO ira crescer, mesmo apos a recursao e adiciona o item no nodo
        if(Ap->UU.U0.ni < MMB){ 
            InsereNaPaginaInterna(Ap, *RegRetorno, *ApRetorno);
            *cresceu = false;

            return;
        }

        //Overflow: Pagina tem que ser dividida
        //Criando uma nova pagina
        ApTemp = (TipoApontadorEstrela) malloc(sizeof(TipoPaginaEstrela));
        ApTemp->Pt = Interna;
        ApTemp->UU.U0.ni = 0;
        ApTemp->UU.U0.pi[0] = NULL;

        //Verifica para onde a chave ira
        if(i < MB + 1){
            //Insere o item na pagina que ja existe
            //Coloca o ultimo registro na nova pagina
            InsereNaPaginaInterna(ApTemp, Ap->UU.U0.ri[MMB - 1], Ap->UU.U0.pi[MMB]);
            Ap->UU.U0.ni--;
            //Insere o novo item na pagina atual
            InsereNaPaginaInterna(Ap, *RegRetorno, *ApRetorno);
        }
        
        // Inserindo o item que deu o overflow na pagina vizinha
        else InsereNaPaginaInterna(ApTemp, *RegRetorno, *ApRetorno);
            
        //Colocando os valores excedentes e colocando na pagina nova
        for(j = MB + 2; j <= MMB; j++)
            InsereNaPaginaInterna(ApTemp, Ap->UU.U0.ri[j-1], Ap->UU.U0.pi[j]);
            
        Ap->UU.U0.ni = MB;
        ApTemp->UU.U0.pi[0] = Ap->UU.U0.pi[MB + 1];
        *RegRetorno = Ap->UU.U0.ri[MB];
        *ApRetorno = ApTemp;
    }
}

void Insere_b_estrela(TipoRegistroEstrela Reg, TipoApontadorEstrela *Ap){
    //caso seja uma nova arvore
    if(*Ap == NULL){
        TipoPaginaEstrela *ApTemp = (TipoPaginaEstrela *)malloc(sizeof(TipoPaginaEstrela));

        ApTemp->Pt = Externa;
        ApTemp->UU.U1.ne = 1;
        ApTemp->UU.U1.re[0] = Reg;
        *Ap = ApTemp;

        return;
    }
    
    short Cresceu;
    TipoChave RegRetorno;
    TipoPaginaEstrela *ApRetorno = NULL, *ApTemp = NULL;

    Ins_b_estrela(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno);

    // arvore cresce na altura pela raiz
    if (Cresceu){ 
        ApTemp = (TipoPaginaEstrela *)malloc(sizeof(TipoPaginaEstrela));
        ApTemp->Pt = Interna;
        ApTemp->UU.U0.ni = 1;
        ApTemp->UU.U0.ri[0] = RegRetorno;
        ApTemp->UU.U0.pi[1] = ApRetorno;
        ApTemp->UU.U0.pi[0] = *Ap;
        *Ap = ApTemp;
    }

}

void liberaArvoreBEstrela(TipoApontadorEstrela Arvore){
    int i = 0;

    if (Arvore->Pt == Externa){
        free(Arvore);
        
        return;
    }

    while (i <= Arvore->UU.U0.ni) {
        liberaArvoreBEstrela(Arvore->UU.U0.pi[i]);

        if (i == Arvore->UU.U0.ni){
            free(Arvore);
            break; //break para sair do while e nao fazer uma comparacao com a Arvore que foi liberada
        }

        i++;
    } 
}

bool Media(TipoRegistroEstrela *x, TipoApontadorEstrela *Ap, long * media){
    
    TipoApontadorEstrela Pag = *Ap;

    if(Pag == NULL) return false;

    if(Pag->Pt == Interna){
        
        int i = 1;

        while(i < Pag->UU.U0.ni && x->Chave > Pag->UU.U0.ri[i-1]) i++;

        if(x->Chave >= Pag->UU.U0.ri[i-1]) return Media(x, &Pag->UU.U0.pi[i], media);
        else return Media(x, &Pag->UU.U0.pi[i-1], media);
    }
    else{
        //Verificando se o item existe na pagina
        int i;
        long somatorio = 0;
        bool existe = false;
        
        for(i = 0; i < Pag->UU.U1.ne; i++){
            somatorio += Pag->UU.U1.re[i].dado1;
            
            if(Pag->UU.U1.re[i].Chave == x->Chave)
                existe = true;
        }

        if(existe){
            *media = somatorio/i;
            return true;
        }
        return false;
    }

}

void exibirItensArvoreBEstrela(TipoApontadorEstrela * arvore){
    if((*arvore)->Pt == Interna){

        exibirItensArvoreBEstrela(&(*arvore)->UU.U0.pi[0]);

        for(int i = 1; i <= (*arvore)->UU.U0.ni; i++){
            printf("Chave interna: %ld\n", (*arvore)->UU.U0.ri[i-1]);
            exibirItensArvoreBEstrela(&(*arvore)->UU.U0.pi[i]);
        }
    }
    else{
        for(int i = 0; i < (*arvore)->UU.U1.ne; i++){
            printf("\t%ld : %ld\n", (*arvore)->UU.U1.re[i].Chave, (*arvore)->UU.U1.re[i].dado1);
        }
    }
}




int main(){
    TipoChave inserir [] = {11, 36, 53, 95, 8, 91, 81, 48, 25, 27, 31, 16, 21, 59, 63, 72};
    int valor [] =          {1, 2,   3,  4, 5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16};

    TipoApontadorEstrela Ap;
    inicializa_b_estrela(&Ap);

    for(int i = 0; i<16; i++){
        TipoRegistroEstrela reg;
        reg.Chave = inserir[i];
        reg.dado1 = valor[i];

        Insere_b_estrela(reg, &Ap);
    }

    exibirItensArvoreBEstrela(&Ap);

    long media;
    TipoRegistroEstrela pesq;
    pesq.Chave = 36;
    if(Media(&pesq, &Ap, &media))
        printf("Média: %ld\n", media);
    else
        printf("Chave não presente na árvore\n");

    return 0;
}