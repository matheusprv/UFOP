class No:
    def __init__(self, chave=0, prox=None):
        self.chave = chave
        self.prox = prox


class Pilha:
    def __init__(self, primeiro=None):
        self.primeiro = primeiro


def novaPilha():
    pilha = Pilha()
    pilha.primeiro = None
    return pilha, 

def contagemDeItensRecursiva(no):
    if no == None:
        return 0, 


    return contagemDeItensRecursiva(no.prox)[0] + 1, 

def contagemDeItens(pilha):
    return contagemDeItensRecursiva(pilha.primeiro)[0], 

def inserirNaPilha(pilha, chave):
    novoNo = No()
    novoNo.chave = chave
    novoNo.prox = pilha.primeiro
    pilha.primeiro = novoNo
    return pilha, 

def removerNaPilha(pilha):
    if contagemDeItens(pilha)[0] == 0:
        print("n")
        return pilha, -1


    chave = pilha.primeiro.chave
    pilha.primeiro = pilha.primeiro.prox
    return pilha, chave

def pesquisa(pilha, chave):
    temp = pilha.primeiro
    for _ in range(contagemDeItens(pilha)[0]) :
        if temp.chave == chave:
            return True, 


        temp = temp.prox


    return False, 

def exibirPilha(pilha):
    temp = pilha.primeiro
    for _ in range(contagemDeItens(pilha)[0]) :
        print(temp.chave)
        temp = temp.prox



if __name__ == '__main__':
    pilha = Pilha()
    pilha = novaPilha()[0]
    i = 1
    for _ in range(10) :
        pilha = inserirNaPilha(pilha, i)[0]
        i = i + 1


    exibirPilha(pilha)
    print(pesquisa(pilha, 3)[0])
    print(pesquisa(pilha, 1024)[0])
    removido = 0
    pilha, removido = removerNaPilha(pilha)
    pilha, removido = removerNaPilha(pilha)
    exibirPilha(pilha)
    print(contagemDeItens(pilha)[0])

