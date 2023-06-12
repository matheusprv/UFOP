{-# LANGUAGE StandaloneDeriving #-}

import Prelude hiding ( Maybe, Nothing, Just)

deriving instance Show Ponto
deriving instance Show Shape
deriving instance Show IntList
deriving instance Show IntTree
deriving instance Show a => Show (Maybe a)


data Ponto = Ponto Float Float 

norm :: Ponto -> Float
norm (Ponto x y) = sqrt(x^2 + y^2)

dist :: Ponto -> Ponto -> Float
dist (Ponto x1 y1) (Ponto x2 y2) = 
    sqrt((x1 - x2)^2 + (y1 - y2)^2)

data Shape =
    Rectangle Ponto Float Float | -- Ponto inicial, largura, altura
    Circle Ponto Float | --Centro, raio
    Triangle Ponto Ponto Ponto

perimeter :: Shape -> Float
perimeter (Rectangle _ x y) = 2*x + 2*y
perimeter (Circle _ r) = 2 * 3.1415 * r
perimeter (Triangle a b c) = (dist a b) + (dist b c) + (dist a c)


-- Tipos Recursivos
data IntList = Nula | Corpo Int IntList
data IntTree = Leaf | Node Int IntTree IntTree

buscaSequencial :: Int -> IntList -> Bool
buscaSequencial _ Nula = False
buscaSequencial n (Corpo x xs)
    | n == x = True
    | otherwise = buscaSequencial n xs

buscaArvore :: Int -> IntTree -> Bool
buscaArvore _ Leaf = False
buscaArvore n (Node centro esq dir)
    | centro == n = True
    | n < centro = buscaArvore n esq
    | otherwise = buscaArvore n dir

alturaArvore :: IntTree -> Int
alturaArvore Leaf = 1
alturaArvore (Node _ esq dir) = 1 + verificaLados
    where
        alturaEsquerda = alturaArvore esq
        alturaDireita = alturaArvore dir
        verificaLados 
            | alturaEsquerda > alturaDireita = alturaEsquerda 
            | otherwise = alturaDireita


concatenarListas :: IntList -> IntList -> IntList
concatenarListas Nula ys = ys
concatenarListas (Corpo x xs) ys = Corpo x (concatenarListas xs ys)

arvoreParaLista :: IntTree -> IntList
arvoreParaLista Leaf = Nula
arvoreParaLista (Node centro esq dir) = Corpo centro (concatenarListas esq1 dir1)
    where
        esq1 = arvoreParaLista esq
        dir1 = arvoreParaLista dir
        

-- Tipos polimórficos
data Maybe a = Just a | Nothing 

safeHead :: [a] -> Maybe a
safeHead [] = Nothing
safeHead (x : xs) = Just x

verificador :: Eq a => a -> [a] -> Int -> Maybe Int
verificador _ [] _ = Nothing
verificador n (x :xs) ac 
    | n == x = Just ac
    | otherwise = verificador n xs (ac+1)

position :: Eq a => a -> [a] -> Maybe Int
position n xs = verificador n xs 0

--Representando clientes
type Name = String
type Surname = String
type SendOffer = Bool

sendOfferString :: SendOffer -> String
sendOfferString sendOffer
    | sendOffer = "True"
    | otherwise = "False"

data Cliente = Customer Name Surname SendOffer | Cliente Name Surname

showInfo :: Cliente -> String
showInfo (Customer name surname sendOffer) = "Ola, " ++ name ++ " " ++ surname ++ "\nSend Offer esta como " ++ (sendOfferString sendOffer)
showInfo (Cliente name surname) = "Ola, " ++ name ++ " " ++ surname
