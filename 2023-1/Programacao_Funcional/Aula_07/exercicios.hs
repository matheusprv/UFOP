{-# LANGUAGE StandaloneDeriving #-}

{--
Desenvolva uma função para calcular a área de formas geométricas descritas pelo tipo Shape.
--}
data Ponto = Ponto Double Double

data Shape =
    Quadrado Ponto Double Double |
    Circulo Ponto Double |
    Triangulo Ponto Ponto Ponto

distDoisPontos :: Ponto -> Ponto -> Double
distDoisPontos (Ponto x1 y1) (Ponto x2 y2) = sqrt((x1-x2)^2 + (y1-y2)^2)

pontoMedio :: Ponto -> Ponto -> Ponto
pontoMedio (Ponto x1 y1) (Ponto x2 y2) = Ponto x y
    where
        x = (x1 + x2) / 2
        y = (y1 + y2) / 2

calculaArea :: Shape -> Double
calculaArea (Quadrado _ h w) = h * w
calculaArea (Circulo _ raio) = pi * raio * raio
calculaArea (Triangulo p1 p2 p3) =  (base * altura) / 2
    where
        base = distDoisPontos p1 p3
        altura = distDoisPontos (pontoMedio p1 p3) p2

{--
Formato do triangulo
    p2

p1      p3  
--}

{--
Desenvolva funções para calcular o número de elementos e o número de folhas de uma árvore de tipo IntTree.
--}
data IntTree = Nulo | Node Int IntTree IntTree
deriving instance Show IntTree

generateTree :: IntTree
generateTree =  Node 32 (Node 15 (Node 14 Nulo Nulo) (Node 20 Nulo Nulo)) (Node 64 (Node 60 Nulo Nulo) (Node 65 Nulo Nulo))

calculaNos :: IntTree -> Int
calculaNos (Node _ Nulo Nulo) = 1
calculaNos (Node _ esquerda direita) = calculaNos esquerda + calculaNos direita



{--
Desenvolva uma função que a partir de uma lista de clientes, retorne uma lista contendo todos os clientes que desejam receber mensagens de ofertas.
--}
type Name = String
type Surname = String
type SendOffer = Bool

data Cliente = Cliente Name Surname SendOffer
deriving instance Show Cliente

listaClientes :: [Cliente]
listaClientes = [Cliente "Matheus" "Peixoto" True,
                Cliente "Fulano" "Fulano" False,
                Cliente "Ciclano" "Ciclano" True,
                Cliente "Beltrano" "Beltrano" False]

listOffers :: [Cliente] -> [Cliente]
listOffers = filter restricao
    where 
        restricao (Cliente _ _ True) = True
        restricao (Cliente _ _ False) = False
