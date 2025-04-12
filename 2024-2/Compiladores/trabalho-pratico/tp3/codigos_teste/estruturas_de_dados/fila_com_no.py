class No:
    def __init__(self, chave=0, prox=None):
        self.chave = chave
        self.prox = prox


class Fila:
    def __init__(self, primeiro=None):
        self.primeiro = primeiro


def novaFila():
    fila = Fila()
    fila.primeiro = None
    return fila, 

def contagemDeItensRecursiva(no):
    if no == None:
        return 0, 


    return contagemDeItensRecursiva(no.prox)[0] + 1, 

def contagemDeItens(fila):
    return contagemDeItensRecursiva(fila.primeiro)[0], 

def inserirNodo(atual, chave):
    if atual == None:
        novo = No()
        novo.prox = None
        novo.chave = chave
        return novo, 


    novo = No()
    novo = inserirNodo(atual.prox, chave)[0]
    atual.prox = novo
    return atual, 

def inserirNaFila(fila, chave):
    no = inserirNodo(fila.primeiro, chave)[0]
    fila.primeiro = no
    return fila, 

def removerNaFila(fila):
    if contagemDeItens(fila)[0] == 0:
        print("n")
        return fila, -1


    chave = fila.primeiro.chave
    fila.primeiro = fila.primeiro.prox
    return fila, chave

def pesquisa(fila, chave):
    temp = fila.primeiro
    for _ in range(contagemDeItens(fila)[0]) :
        if temp.chave == chave:
            return True, 


        temp = temp.prox


    return False, 

def exibirFila(fila):
    temp = fila.primeiro
    for _ in range(contagemDeItens(fila)[0]) :
        print(temp.chave)
        temp = temp.prox



if __name__ == '__main__':
    fila = Fila()
    fila = novaFila()[0]
    i = 1
    for _ in range(10) :
        fila = inserirNaFila(fila, i)[0]
        i = i + 1


    exibirFila(fila)
    print(pesquisa(fila, 3)[0])
    print(pesquisa(fila, 1024)[0])
    removido = 0
    fila, removido = removerNaFila(fila)
    fila, removido = removerNaFila(fila)
    exibirFila(fila)
    print(contagemDeItens(fila)[0])

