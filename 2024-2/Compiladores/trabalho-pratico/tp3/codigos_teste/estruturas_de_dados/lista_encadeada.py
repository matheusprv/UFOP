class No:
    def __init__(self, chave=0, prox=None):
        self.chave = chave
        self.prox = prox


class Lista:
    def __init__(self, primeiro=None, ultimo=None, qtdElementos=0):
        self.primeiro = primeiro
        self.ultimo = ultimo
        self.qtdElementos = qtdElementos


def novaLista():
    lista = Lista()
    lista.primeiro = None
    lista.ultimo = None
    return lista, 

def inserirNodo(atual, chave):
    if atual == None:
        novo = No()
        novo.prox = None
        novo.chave = chave
        return novo, 1


    novo = No()
    totalItens = 0
    novo, totalItens = inserirNodo(atual.prox, chave)
    atual.prox = novo
    totalItens = totalItens + 1
    return atual, totalItens

def inserirNaLista(lista, chave):
    no = No()
    totalItens = 0
    no, totalItens = inserirNodo(lista.primeiro, chave)
    lista.primeiro = no
    lista.qtdElementos = totalItens
    return lista, 

def removerNodo(atual, chave, remover):
    if atual == None:
        return atual, 0


    if atual.chave == chave and remover:
        prox = No()
        totalItens = 0
        prox, totalItens = removerNodo(atual.prox, chave, False)
        return prox, totalItens

    else:
        prox = No()
        totalItens = 0
        prox, totalItens = removerNodo(atual.prox, chave, True)
        atual.prox = prox
        return atual, totalItens + 1



def removerNaLista(lista, chave):
    no = No()
    totalItens = 0
    no, totalItens = removerNodo(lista.primeiro, chave, True)
    lista.primeiro = no
    lista.qtdElementos = totalItens
    return lista, 

def pesquisa(lista, chave):
    temp = lista.primeiro
    for _ in range(lista.qtdElementos) :
        if temp.chave == chave:
            return True, 


        temp = temp.prox


    return False, 

def exibirLista(lista):
    temp = lista.primeiro
    for _ in range(lista.qtdElementos) :
        print(temp.chave)
        temp = temp.prox



if __name__ == '__main__':
    lista = Lista()
    lista = novaLista()[0]
    i = 1
    for _ in range(10) :
        lista = inserirNaLista(lista, i)[0]
        i = i + 1


    exibirLista(lista)
    print(pesquisa(lista, 3)[0])
    print(pesquisa(lista, 1024)[0])
    lista = removerNaLista(lista, 5)[0]
    exibirLista(lista)
    print(lista.qtdElementos)

