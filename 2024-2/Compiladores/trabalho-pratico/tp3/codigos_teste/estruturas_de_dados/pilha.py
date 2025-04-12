class Pilha:
    def __init__(self, arr=0, qtdItens=0, maximo=0):
        self.arr = arr
        self.qtdItens = qtdItens
        self.maximo = maximo


def novaPilha(n):
    pilha = Pilha()
    pilha.arr = [0 for _ in range (n)]
    pilha.maximo = n
    return pilha, 

def pilhaCheia(pilha):
    return (pilha.qtdItens == pilha.maximo), 

def inserirNaPilha(pilha, chave):
    if pilhaCheia(pilha)[0]:
        print("n")
        return pilha, 


    print("s")
    i = pilha.qtdItens
    pilha.arr[i] = chave
    pilha.qtdItens = pilha.qtdItens + 1
    print(pilha.qtdItens)
    return pilha, 

def exibirPilha(pilha):
    i = 0
    for _ in range(pilha.qtdItens) :
        print(pilha.arr[i])
        i = i + 1



if __name__ == '__main__':
    pilha = novaPilha(10)[0]
    pilha = inserirNaPilha(pilha, 77)[0]
    pilha = inserirNaPilha(pilha, 44)[0]
    pilha = inserirNaPilha(pilha, 33)[0]
    exibirPilha(pilha)

