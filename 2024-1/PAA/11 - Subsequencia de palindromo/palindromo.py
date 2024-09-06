"""
Matheus Peixoto Ribeiro Vieira - 22.1.4104
"""

import numpy as np

def maior_palindromo(palavra: str):
    n = len(palavra)
    if n == 1: return 1
    if n == 2 :
        if palavra[0] == palavra[1]: return 2
        else: return 0

    # A linha representa o comeco e a coluna o fim da substring
    tabela = np.zeros((n,n))
    tamanho_max = 1

    # Substring de tamanho 1 sempre sera um palindromo
    for i in range(n):
        tabela[i][i] = 1

    # Verificando se os dois primeiros elementos formam um palindromo
    for i in range(n-1):
        if palavra[i] == palavra[i+1]:
            tabela[i][i+1] = 1
            tamanho_max = 2

    # vai variar para cada tamanho possivel de palavra >= 3
    for tamanho in range(3, n + 1): 
        # Vai passando na diagonal superior que ainda nao foi verificada
        for inicio in range(n - tamanho + 1): 
            fim = inicio + tamanho - 1 

            # Verifica se palavra e um palindromo
            if palavra[inicio] == palavra[fim] and tabela[inicio + 1][fim - 1] == 1:
                tabela[inicio][fim] = 1

                if tamanho > tamanho_max:
                    tamanho_max = tamanho

    print(tabela)
    print(tamanho_max)


palavra = "aaaabbaa"
maior_palindromo(palavra)

"""
Execucao:
[[1. 1. 1. 1. 0. 0. 0. 0.]
 [0. 1. 1. 1. 0. 0. 0. 0.]
 [0. 0. 1. 1. 0. 0. 0. 1.]
 [0. 0. 0. 1. 0. 0. 1. 0.]
 [0. 0. 0. 0. 1. 1. 0. 0.]
 [0. 0. 0. 0. 0. 1. 0. 0.]
 [0. 0. 0. 0. 0. 0. 1. 1.]
 [0. 0. 0. 0. 0. 0. 0. 1.]]

6
"""