import numpy as np

class SistemaLinear():

    qtd_espacos = 20

    def __init__(self, matriz = None, tamanho = None):
        self.matriz = matriz
        self.tamanho = tamanho
        
        self.matriz_triangular_superior = None
        self.determinante = None


    def copia_matriz(self, matriz = None) -> [[float]]:
        if(matriz == None):
            matriz = self.matriz
        
        #Copiando a matriz original para uma temporaria 
        temp = []
        for i in matriz:
            temp.append([])
            for j in i:
                temp[-1].append(j)
        
        return temp


    def ler_matriz(self) -> None:
        self.tamanho = int(input("Digite o tamanho da matriz: "))

        matriz = []
        for i in range (0, self.tamanho):
            matriz.append([])
            for j in range(0, self.tamanho):
                novoValor = float(input(f"Digite o valor da linha {i+1} e coluna {j+1}: "))
                matriz[-1].append(novoValor)

            novoValor = float(input(f"Digite o valor da resposta da linha {i+1}: "))
            matriz[-1].append(novoValor)
    

    def print_matriz(self, matriz = None) -> None:

        if(matriz == None):
            matriz = self.matriz

        #Formatando a exibição para o cabeçalho X1, X2, ... Xn e b
        Xs = ""
        for i in range (0, self.tamanho):
            Xs += ("X" + str(i+1)).center(self.qtd_espacos) + " "
        Xs += ("b").center(self.qtd_espacos)

        print(Xs)

        #Exibindo os valores de cada linha
        for i in range(0, self.tamanho):
            texto = ' '.join((str(num)).center(self.qtd_espacos) for num in matriz[i])
            print(texto)

        print("="*120)


    def calcula_determinante(self) -> float:
        temp = self.copia_matriz()
        
        #Removendo o valor de b
        for i in temp:
            i.pop(-1)
        
        self.determinante = np.linalg.det(temp)

        return self.determinante
    

    def eliminacao_de_guass(self) -> None:

        if(self.determinante == 0):
            raise Exception("O determinante não pode ser zero")

        tamanho = self.tamanho
        matriz = self.copia_matriz()

        #Definindo o pivo
        for i in range(0, tamanho):
            pivo = matriz[i][i]
            
            #Definindo o valor de m e aplicando a operacao elementar para uma linha
            for linha in range(i+1, tamanho):
                m = matriz[linha][i] / pivo

                #Alterando o valor de todos os itens da linha, incluindo o b
                for coluna in range (i, tamanho + 1):
                    matriz[linha][coluna] = matriz[linha][coluna] - (m * matriz[i][coluna])

                #Exibindo a execução linha por linha
                self.print_matriz()

        self.matriz_triangular_superior = matriz

    
    def metodo_direto(self) -> None:
        
        if(self.matriz_triangular_superior == None):
            raise Exception("A matriz não é triangular superior. Execute a eliminação de Gauss antes.")
        
        Xs = []
        matriz = self.copia_matriz()
        tamanho = self.tamanho
        
        xn = matriz[-1][-1] / matriz[-1][-2]
        Xs.append(xn)

        for i in reversed(range(tamanho - 1)):
            somatorio = 0
            somatorio_string = ""     

            for j in range(i+1, tamanho):
                somatorio += matriz[i][j] * Xs[-(tamanho-j)]
                somatorio_string += str(matriz[i][j]) + " * " + str(Xs[-(tamanho-j)]) + " + "


            xi = (matriz[i][-1] - somatorio) / matriz[i][i]

            Xs.insert(0, xi)


        print("Conjunto solução:", Xs)


if __name__ == "__main__":

    matriz =[
        [3,2,-3,3],
        [9,8,-8,6],
        [-6,4,3,0]
    ]

    tamanho = len(matriz[0]) -1
    s1 = SistemaLinear(matriz, tamanho)

    s1.eliminacao_de_guass()
    s1.metodo_direto()




            

        