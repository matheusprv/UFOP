class Fila:
    def __init__(self, arr=0, qtdItens=0, maximo=0):
        self.arr = arr
        self.qtdItens = qtdItens
        self.maximo = maximo


def novaFila(n):
    fila = Fila()
    fila.arr = [0 for _ in range (n)]
    fila.maximo = n
    return fila, 

def inserirNaFila(fila, valor):
    if fila.qtdItens == fila.maximo:
        print("n")
        return fila, 


    i = fila.qtdItens
    for _ in range(fila.qtdItens) :
        fila.arr[i] = fila.arr[i - 1]
        i = i - 1


    fila.arr[0] = valor
    fila.qtdItens = fila.qtdItens + 1
    return fila, 

def removerNaFila(fila):
    if fila.qtdItens == 0:
        return fila, 


    fila.qtdItens = fila.qtdItens - 1
    fila.arr[fila.qtdItens] = 0
    return fila, 

def exibirFila(fila):
    i = 0
    for _ in range(fila.qtdItens) :
        print(fila.arr[i])
        i = i + 1



if __name__ == '__main__':
    fila = Fila()
    fila = novaFila(5)[0]
    fila = inserirNaFila(fila, 1)[0]
    fila = inserirNaFila(fila, 2)[0]
    fila = inserirNaFila(fila, 3)[0]
    exibirFila(fila)
    fila = removerNaFila(fila)[0]
    exibirFila(fila)

