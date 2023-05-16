module Aula02 where

--Defina uma função para calcular a função ou-exclusivo (xor).
xor :: Bool -> Bool -> Bool
xor x y 
    | x == y    = False
    | otherwise = True

{-
    Defina a função existsPositive que retorna verdadeiro se a lista de 
    números inteiros fornecida como argumento possui pelo menos um 
    elemento maior que 0.
-}
existsPositive :: [Int] -> Bool
existsPositive [] = False
existsPositive (item : list)
    | item > 0 = True
    | otherwise = existsPositive list