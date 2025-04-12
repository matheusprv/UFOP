def novaPilha(n):
    arr = [0 for _ in range (n)]
    i = 0
    for _ in range(n) :
        arr[i] = None
        i = i + 1


    return arr, 

def tamanhoPilha(pilha, maximo):
    count = 0
    for _ in range(1000) :
        if pilha[count] == None:
            return count, 


        count = count + 1


    return count, 

def pilhaCheia(pilha, maximo):
    return (tamanhoPilha(pilha, maximo)[0] == maximo), 

def inserirNaPilha(pilha, chave, maximo):
    if pilhaCheia(pilha, maximo)[0]:
        print("N")
        return pilha, 


    i = tamanhoPilha(pilha, maximo)[0]
    pilha[i] = chave
    return pilha, 

def removerDaPilha(pilha, maximo):
    qtdItens = tamanhoPilha(pilha, maximo)[0]
    if qtdItens == 0:
        print("n")
        return pilha, 


    pilha[qtdItens - 1] = None
    return pilha, 

def exibirPilha(pilha, maximo):
    i = 0
    qtdItens = tamanhoPilha(pilha, maximo)[0]
    for _ in range(qtdItens) :
        print(pilha[i])
        i = i + 1



if __name__ == '__main__':
    maximo = 10
    pilha = novaPilha(maximo)[0]
    pilha = inserirNaPilha(pilha, 77, maximo)[0]
    pilha = inserirNaPilha(pilha, 44, maximo)[0]
    pilha = inserirNaPilha(pilha, 33, maximo)[0]
    exibirPilha(pilha, maximo)
    pilha = removerDaPilha(pilha, maximo)[0]
    exibirPilha(pilha, maximo)

