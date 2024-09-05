import numpy as np

palavra_1 = "situado"
palavra_2 = "estudo"

# palavra_1 = "logaritmo"
# palavra_2 = "algoritmo"
x = [''] + list(palavra_1)
y = [''] + list(palavra_2)



def distEdicao(x, y):
    n = len(x)
    m = len(y)

    E = np.zeros((n, m))

    for i in range(n):
        E[i][0] = i
    
    for j in range(m):
        E[0][j] = j

    for i in range(1, n):
        for j in range(1, m):
            ins = E[i][j-1]   + 1
            rem = E[i-1][j]   + 1
            cas = E[i-1][j-1] + (0 if x[i] == y[j] else 1)
            E[i][j] = min(ins, rem, cas)

    print(E)

    return E[n-1][m-1], E

ed, E = distEdicao(x, y)


def imprimeOperacoes(x, y, E):
    n = len(x)
    m = len(y)

    operacoes = []
    i = n-1
    j = m-1

    while i != 0 and j != 0:
        cas = E[i-1, j-1]
        ins = E[i, j-1]
        rem = E[i-1, j]
        
        ops = [cas, ins, rem]
        realizado = ops.index(min(ops)) #Obtendo a operação com o menor custo
        
        string =""
        if realizado == 0:
            if E[i-1, j-1] != E[i, j]:
                string = f"substituição do {x[i]} por {y[j]}"
            else:
                string = f"casamento do {x[i]} com {y[j]}"
            i = i-1
            j = j-1
        elif realizado == 1:
            string = f"inserindo {y[j]}"
            j = j-1
        else:
            string = f"removendo {x[i]}"
            i = i-1

        operacoes.append(string)

    for op in reversed(operacoes):
        print(op)

imprimeOperacoes(x, y, E)