class No:
    def __init__(self, chave=0, esq=None, dir=None):
        self.chave = chave
        self.esq = esq
        self.dir = dir


def novaArvore():
    return None, 

def inserir(no, chave):
    if no == None:
        novoNo = No()
        novoNo.esq = None
        novoNo.dir = None
        novoNo.chave = chave
        return novoNo, 


    if chave < no.chave:
        no.esq = inserir(no.esq, chave)[0]
        return no, 

    else:
        no.dir = inserir(no.dir, chave)[0]
        return no, 



def menorValor(no):
    if no.esq == None:
        return no, 

    else:
        return menorValor(no.esq)[0], 



def remover(no, chave):
    if no == None:
        return None, 


    if chave < no.chave:
        no.esq = remover(no.esq, chave)[0]
        return no, 


    if chave > no.chave:
        no.dir = remover(no.dir, chave)[0]
        return no, 

    else:
        if no.esq == None and no.dir == None:
            return None, 


        if no.esq == None:
            return no.dir, 


        if no.dir == None:
            return no.esq, 


        sucessor = menorValor(no.dir)[0]
        no.chave = sucessor.chave
        no.dir = remover(no.dir, sucessor.chave)[0]
        return no, 



def busca(no, chave):
    if no == None:
        return False, 


    if chave == no.chave:
        return True, 


    if chave < no.chave:
        return busca(no.esq, chave)[0], 

    else:
        return busca(no.dir, chave)[0], 



def preOrdem(no):
    if no != None:
        print((no.chave))
        preOrdem(no.esq)
        preOrdem(no.dir)



def emOrdem(no):
    if no != None:
        emOrdem(no.esq)
        print((no.chave))
        emOrdem(no.dir)



def posOrdem(no):
    if no != None:
        posOrdem(no.esq)
        posOrdem(no.dir)
        print((no.chave))



if __name__ == '__main__':
    raiz = novaArvore()[0]
    raiz = inserir(raiz, 10)[0]
    raiz = inserir(raiz, 7)[0]
    raiz = inserir(raiz, 17)[0]
    raiz = inserir(raiz, 5)[0]
    raiz = inserir(raiz, 45)[0]
    emOrdem(raiz)
    print(busca(raiz, 45)[0])
    print(busca(raiz, 1024)[0])
    raiz = remover(raiz, 7)[0]
    emOrdem(raiz)

