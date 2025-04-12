def novaArvore():
    arr = [0 for _ in range (3)]
    i = 0
    for _ in range(3) :
        arr[i] = None
        i = i + 1


    return arr, 

def tamanhoArvore(arvore):
    count = 0
    for _ in range(1000) :
        if arvore[count] == None:
            return count / 3, 


        count = count + 3


    return count / 3, 

def expandirArvore(arvore, novoTamanho):
    novaArvore = [0 for _ in range (novoTamanho * 3)]
    i = 0
    for _ in range(novoTamanho * 3) :
        if i < tamanhoArvore(arvore)[0] * 3:
            novaArvore[i] = arvore[i]

        else:
            novaArvore[i] = None


        i = i + 1


    return novaArvore, 

def inserirNaArvore(arvore, valor, tamanhoAtual):
    arvore = expandirArvore(arvore, tamanhoAtual + 1)[0]
    i = 0
    for _ in range(tamanhoAtual + 1) :
        if arvore[i] == None:
            arvore[i] = valor
            return arvore, 

        else:
            if valor < arvore[i]:
                i = 3 * i + 1

            else:
                i = 3 * i + 2





    return arvore, 

def pesquisarNaArvore(arvore, valor, maximo):
    i = 0
    for _ in range(maximo) :
        if arvore[i] == None:
            return False, 

        else:
            if arvore[i] == valor:
                return True, 

            else:
                if valor < arvore[i]:
                    i = 3 * i + 1

                else:
                    i = 3 * i + 2






    return False, 

def removerDaArvore(arvore, valor, maximo):
    i = 0
    for _ in range(maximo) :
        if arvore[i] == None:
            print("n")
            return arvore, 

        else:
            if arvore[i] == valor:
                arvore[i] = None
                return arvore, 

            else:
                if valor < arvore[i]:
                    i = 3 * i + 1

                else:
                    i = 3 * i + 2






    return arvore, 

if __name__ == '__main__':
    arvore = novaArvore()[0]
    arvore = inserirNaArvore(arvore, 50, 1)[0]
    arvore = inserirNaArvore(arvore, 70, 2)[0]
    arvore = inserirNaArvore(arvore, 30, 3)[0]
    print(pesquisarNaArvore(arvore, 30, 3)[0])
    print(pesquisarNaArvore(arvore, 100, 3)[0])
    arvore = removerDaArvore(arvore, 30, 3)[0]
    print(pesquisarNaArvore(arvore, 30, 3)[0])

