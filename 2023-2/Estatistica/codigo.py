import numpy as np
import math
from tabulate import tabulate
import statistics

class Linha:
    def __init__(self, limite_inferior, limite_superior, Xi, fi, fr, fa, fra) -> None:
        self.limite_inferior = limite_inferior
        self.limite_superior = limite_superior
        self.Xi = Xi
        self.fi = fi
        self.fr = fr
        self.fa = fa
        self.fra = fra

    def amplitude(self):
        return self.limite_superior - self.limite_inferior

    def objeto_para_lista(self):
        limites = str(self.limite_inferior) + " |- " + str(self.limite_superior)
        return [ limites, self.Xi, self.fi, self.fr, self.fa, self.fra]


class Dados:
    
    def __init__(self, lista = None) -> None:
        if lista != None:
            lista.sort()
            self.lista = np.array(lista)
            self.n = len(lista)
        
        else:
            self.lista = []
            self.n = 0
        
        self.linhas_tabela_frequencia = []
        self.variancia = None
    #################################################################################################################
    def arredondar(self, n, decimal_places = 3):
        return round(n, decimal_places)
    
    #################################################################################################################
    def ler_tabela_frequencia(self, casas_decimais_arredondamento = 3):
        k = int(input("Digite a quantidade de classes: "))

        limite_inferior = float(input(f"Digite o limite inferior da linha 1: "))
        limite_superior = float(input(f"Digite o limite superior da linha 1: "))    
        
        c = self.arredondar(limite_superior - limite_inferior, casas_decimais_arredondamento)

        Xi = self.arredondar((limite_inferior+limite_superior)/2, casas_decimais_arredondamento)

        lista_fi = []
        for i in range(0, k):
            fi = int(input(f"Digite o fi da linha {i+1}: "))            
            lista_fi.append(fi)

        total_itens = sum(lista_fi)

        fa = 0
        fra = 0.0
        for fi in lista_fi:
            fr = self.arredondar(fi/total_itens, casas_decimais_arredondamento)
            fa += fi
            fra = self.arredondar(fra+fr, casas_decimais_arredondamento)
            
            linha = Linha(limite_inferior, limite_superior, Xi, fi, fr, fa, fra)
            self.linhas_tabela_frequencia.append(linha)

            Xi = self.arredondar(Xi+c, casas_decimais_arredondamento)
            limite_inferior = limite_superior
            limite_superior = self.arredondar(limite_superior+c, casas_decimais_arredondamento)

        self.tabela_frequencia()

    #################################################################################################################
    def tabela_frquencia_de_uma_lista(self):
        a = self.arredondar(self.lista[-1] - self.lista[0])
        k = int(self.arredondar(math.sqrt(self.n)))
        c = self.arredondar(a / k)

        print(f"a: {a}, k: {k}, c: {c}")

        limite_inferior = self.lista[0]

        fa = 0
        fra = 0
        for i in range(0, k):
            #Limites e Xi
            limite_superior = self.arredondar(limite_inferior + c)
            Xi = self.arredondar((limite_superior + limite_inferior)/2)

            #fi
            fi_list = [item for item in self.lista if limite_inferior <= item and item <= limite_superior]
            fi = len(fi_list)

            # fr, Fa, Fra
            fr  = self.arredondar(fi / self.n)
            fa  = self.arredondar (fi + fa)
            fra = self.arredondar (fra + fr)
            
            self.linhas_tabela_frequencia.append(Linha(limite_inferior, limite_superior, Xi, fi, fr, fa, fra))

            #! Final do loop - NÃO REMOVA
            limite_inferior = limite_superior

    #################################################################################################################
    def tabela_frequencia(self):
        if(len(self.linhas_tabela_frequencia) == 0):
            self.tabela_frquencia_de_uma_lista()

        #Printando a tabela
        headers = ["Limites", "Xi", "fi", "fr", "fa", "fra"]
        data = []
        
        for l in self.linhas_tabela_frequencia:
            data.append(l.objeto_para_lista())

        print(tabulate( data, headers=headers, tablefmt="pretty"))

    #################################################################################################################
    def media(self):
        return (self.lista).mean()

    def media_tabela_frequencia(self, casas_decimais_arredondamento):
        somatorio = 0
        somatorio_string = "("
        qtd_itens = 0
        
        for linha in self.linhas_tabela_frequencia:
            fi = linha.fi
            Xi = linha.Xi
            
            qtd_itens += fi
            somatorio += fi*Xi
            
            somatorio_string += str(Xi) + "*" + str(fi) + " + "

        somatorio_string = somatorio_string[: len(somatorio_string)-3]

        print(somatorio_string +")/" + str(qtd_itens))

        media = somatorio / qtd_itens

        media = self.arredondar(media, casas_decimais_arredondamento)

        print("Media: ", media)

    #################################################################################################################
    def mediana(self):
        lista = self.lista
        n = self.n

        if n % 2 == 0:
            x1 = lista[n/2]
            x2 = lista[(n+2)/2]
            self.mediana = (x1+x2)/2

        else:
            self.mediana = lista[(n+1)/2]

        print("Mediana:", self.mediana)

    #################################################################################################################
    def moda(self):
        moda = statistics.multimode(self.lista)
        
        print("Moda:",moda)
        for m in moda:
            aparicoes = 0
            for i in self.lista:
                if m == i:
                    aparicoes += 1
            print("Aparições do",m,":", aparicoes)

    def moda_tabela_frequencia(self, casas_decimais_arredondamento):
        linha_maior_frequencia = self.linhas_tabela_frequencia[0]
        index = 0
        for i, linha in enumerate(self.linhas_tabela_frequencia):
            if linha.fi > linha_maior_frequencia.fi:
                linha_maior_frequencia = linha
                index = i
        
        limite_inferior = linha_maior_frequencia.limite_inferior
        limite_superior = linha_maior_frequencia.limite_superior

        fi_classe_anterior = 0 if index == 0 else self.linhas_tabela_frequencia[index-1].fi
        fi_classe_posterior = 0 if index == len(self.linhas_tabela_frequencia) else self.linhas_tabela_frequencia[index+1].fi

        delta_1 = linha_maior_frequencia.fi - fi_classe_anterior
        delta_2 = linha_maior_frequencia.fi - fi_classe_posterior

        amplitude = self.arredondar((limite_superior-limite_inferior), casas_decimais_arredondamento)

        print(str(limite_inferior) + " + " + str(delta_1) + f"/({delta_1}+{delta_2}) * " + str(amplitude))

        moda = limite_inferior + delta_1/(delta_1+delta_2) * amplitude

        moda = self.arredondar(moda, casas_decimais_arredondamento)

        print(moda)


    #################################################################################################################
    def separatrizes(self, i, d, casas_decimais_arredondamento):
        # lista_fi = []
        # for linha in self.linhas_tabela_frequencia:
        #     lista_fi.append(linha.fi)
        # n  = sum(lista_fi)

        # e = i * n / d

        pass

    #################################################################################################################
    def variancia_amostral(self):
        string = ""
        media = self.media()
        somatorio = 0.0

        for i in self.lista:
            string += "(" + str(media) + "-" + str(i) + ")^2" + "+"
            somatorio += (media-i)**2
        
        string = string[:len(string)-1]

        divisao = len(self.lista) - 1
        string += "/" + str(divisao)

        somatorio = self.arredondar(somatorio, 3)

        variancia = somatorio / divisao

        print(string)
        print(f"{somatorio}/{divisao}")
        print("Solução:", self.arredondar(variancia, 3))

        self.variancia = self.arredondar(variancia, 3)

    #################################################################################################################
    def variancia_dados_agrupados(self, casas_decimansi_arredondamento = 3):
        lista_fi = []
        for linha in self.linhas_tabela_frequencia:
            lista_fi.append(linha.fi)

        n  = sum(lista_fi)
        
        divisao_externa_string = f"1/{n-1}"
        divisao_externa = self.arredondar(1/(n-1), casas_decimansi_arredondamento)

        somatorio_1_string = ""
        somatorio_1 = 0
        for linha in self.linhas_tabela_frequencia:
            somatorio_1 += linha.fi * (linha.Xi ** 2)
            somatorio_1_string += f"{linha.fi}*{linha.Xi}² + "
        somatorio_1_string = somatorio_1_string[: len(somatorio_1_string)-2]


        somatorio_2_string = "("
        somatorio_2 = 0
        for linha in self.linhas_tabela_frequencia:
            somatorio_2 += (linha.fi * linha.Xi)
            somatorio_2_string += f"{linha.fi}*{linha.Xi} + "
        #Equacao
        somatorio_2 *= somatorio_2
        somatorio_2 /= n
        #String
        somatorio_2_string = somatorio_2_string [:len(somatorio_2_string) - 3]
        somatorio_2_string += ")²/" + str(n)

        print(divisao_externa_string, "*{",somatorio_1_string, "-", somatorio_2_string,"}")

        print(f"{divisao_externa_string} *({somatorio_1} - {somatorio_2})")

        variancia = divisao_externa * (somatorio_1 - somatorio_2)

        variancia = self.arredondar(variancia, casas_decimansi_arredondamento)

        print(variancia)

        self.variancia = variancia

    #################################################################################################################
    def desvio_padrao(self):
        if self.variancia == None:
            self.variancia_amostral()

        dp = math.sqrt(self.variancia)
        dp = self.arredondar(dp, 3)

        print("Desvio padrão = √" + str(self.variancia) + " = " + str(dp))

if __name__ == '__main__':
    dados = Dados()
    dados.ler_tabela_frequencia()

    dados.media_tabela_frequencia(casas_decimais_arredondamento=3)
    dados.variancia_dados_agrupados(3)
    dados.desvio_padrao()

    # lista = [
    #     8.13,8.23,8.60,8.80,8.97,9.05,9.12,9.30,9.35,9.78,
    #     9.80,9.86,9.90,9.95,10.00,10.11,10.13,10.15,10.16,10.23,
    #     10.31,10.33,10.40,10.46,10.50,11.14,11.29,11.46,12.05,12.14
    # ]
    
    # print(len(lista))

    # dados = Dados(lista)

    # dados.tabela_frequencia()

    # dados.moda_tabela_frequencia(3)