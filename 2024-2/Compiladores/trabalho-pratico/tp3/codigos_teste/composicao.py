class Racional:
    def __init__(self, numerador=0, denominador=0):
        self.numerador = numerador
        self.denominador = denominador


class Teste:
    def __init__(self, nome="", r1=None, t1=None):
        self.nome = nome
        self.r1 = r1
        self.t1 = t1


if __name__ == '__main__':
    t = Teste()
    t.r1.numerador = 2
    print(t.t1.r1.numerador)
    a = Racional()
    a.numerador = eval(input())
    a.numerador = 10
    a.denominador = 2
    print(a.numerador / a.denominador)
    teste = Teste()
    teste.nome = "o"
    print(teste.nome)
    teste.r1.numerador = 4
    teste.r1.denominador = 2
    b = 0
    b = teste.r1.numerador
    print(b)
    print((teste.r1.numerador / teste.r1.denominador))
    a.numerador = eval(input())

