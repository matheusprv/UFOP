class Atividade:
    counter = 1
    def __init__(self, s, f) -> None:
        self.i = self.counter
        Atividade.counter = Atividade.counter + 1
        self.s = s
        self.f = f

    def __str__(self):
        return f"{self.i} - Si: {self.s} - Fi: {self.f}"


atividades = [
    Atividade(1, 4),
    Atividade(3, 5),
    Atividade(0, 6),
    Atividade(5, 7),
    Atividade(3, 8),
    Atividade(5, 9),
    Atividade(6, 10),
    Atividade(8, 11),
    Atividade(8, 12),
    Atividade(2, 13),
    Atividade(12, 14)
]

def algoritmo_guloso(atividades: Atividade):
    # Ordenando de forma decrescente do tempo de inicialização
    # Ordenação de forma estável
    atividades.sort(key=lambda x: x.s, reverse=True)
    # Obter a quantidade de atividades
    n = len(atividades)
    # Colocar a atividade com maior tempo inicial no conjunto solução
    A = [atividades[0]]
    i = 0
    # Loop do algoritmo guloso
    for m in range(1, n):
        # Verificar se a próxima atividade acaba antes da atual
        # Caso verdadeiro, adicioná-la no conjunto solução
        if atividades[m].f <= atividades[i].s:
            A.append(atividades[m])
            i = m
    return A

solucao_otima = algoritmo_guloso(atividades)
for a in solucao_otima:
    print(a)
"""
    11 - Si: 12 - Fi: 14
     8 - Si:  8 - Fi: 11
     4 - Si:  5 - Fi: 7
     2 - Si:  3 - Fi: 5
"""