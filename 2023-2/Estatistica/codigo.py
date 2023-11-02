import numpy as np

class Dados:
    
    def __init__(self, lista) -> None:
        self.lista = np.array(lista)

    def tabela_frequencia(self):
        pass

    def media(self):
        return (self.lista).mean(self)

    def mediana(self):
        pass

    def moda(self):
        pass

    def separatrizes(self, d):
        pass

    def variancia_amostral(self):
        string = ""
        media = self.media()
        somatorio = 0.0

        for i in self.lista:
            string += "(" + str(media) + "-" + str(i) + ")^2" + "+"
            somatorio += (media-i)**2
        
        string = string[:len(string)]

        divisao = len(self.lista) - 1
        string += "/" + str(divisao)
        variancia = somatorio / divisao

        print(string)
        print("Solução:", variancia)