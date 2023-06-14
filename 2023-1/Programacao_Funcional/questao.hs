{-# LANGUAGE StandaloneDeriving #-}

import Prelude hiding (takeWhile, all)
import Data.Char

takeWhile :: (a -> Bool) -> [a] -> [a]
takeWhile f = foldr steps [] 
    where
        steps x ac
            | f x = x : ac
            | otherwise = []

all :: (a -> Bool) -> [a] -> Bool
all f [] = True
all f (x : xs)
    | f x = all f xs
    | otherwise = False

allFold :: (a -> Bool) -> [a] -> Bool
allFold f xs = foldr steps True xs
    where 
        steps x ac = if f x then ac else False


concatMap :: (a -> [b]) -> [a] -> [b]
concatMap f xs = foldr steps [] xs
    where 
        steps x ac = f x ++ ac 

safeHead :: [a] -> Maybe a
safeHead [] = Nothing
safeHead (x : xs) = Just x

-- position :: Eq a => a -> [a] -> Maybe a
-- position n xs = posicao n xs 0
--     where

capitalize :: String -> String
capitalize = map toUpper


isPrime :: Int -> Bool
isPrime x = length [y | y <- [1 .. x], x `mod` y == 0] == 2

withoutPrimes :: [Int] -> [Int]
withoutPrimes xs = filter (not.isPrime) xs

withoutPrimesFold :: [Int] -> [Int]
withoutPrimesFold = foldr steps []
    where
        steps x ac 
            | not (isPrime x) = ac
            | otherwise = x : ac 


data Point = Point Float Float
deriving instance Show IntTree

data Shape = Square Point Float Float | Circle Point Float | Triangle Point Point Point

distanciaPontos :: Point -> Point -> Float
distanciaPontos (Point x1 y1) (Point x2 y2) = sqrt((x1-x2)^2 + (y1-y2)^2)

area :: Shape -> Float
area (Square _ w h) = w*h
area (Circle _ raio) = pi*raio*raio
--area (Triangle p1 p2 p3) = distanciaPontos p1 p2 + distanciaPontos p2 p3 distanciaPontos p3 p1

{--
    p2
   /  \
 p1 -- p3    

        53
    18              60
14       20       59      
        19
--}

data IntTree = Nulo | Node Int IntTree IntTree

generateTree :: IntTree
generateTree = (Node 53 (Node 18 (Node 14 Nulo Nulo) (Node 20 (Node 19 Nulo Nulo) Nulo)) (Node 60 (Node 59 Nulo Nulo)(Nulo)))

countLeafs :: IntTree -> Int
countLeafs (Nulo) = 0
countLeafs (Node _ Nulo Nulo) = 1
countLeafs (Node _ esq dir) = countLeafs esq + countLeafs dir

countItens :: IntTree -> Int
countItens (Node _ Nulo Nulo) = 1
countItens (Node _ esq Nulo) = 1 + countItens esq
countItens (Node _ Nulo dir) = 1 + countItens dir
countItens (Node _ esq dir) = 1 + countItens esq + countItens dir


treeHeight :: IntTree -> Int
treeHeight (Node _ Nulo Nulo) = 1
treeHeight (Node _ esq Nulo) = 1 + treeHeight esq
treeHeight (Node _ Nulo dir) = 1 + treeHeight dir
treeHeight (Node _ esq dir) 
    | treeHeight esq > treeHeight dir = 1 + treeHeight esq
    | otherwise = 1 + treeHeight dir
    

teste :: (Ord a, Num a) => a -> Bool
teste ab = ab > 5