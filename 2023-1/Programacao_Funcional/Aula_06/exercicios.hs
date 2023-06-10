import Prelude hiding ( takeWhile, all, concatMap)

{-- 
    A função all determina se todos os elementos de uma lista satisfazem um predicado. Seu tipo é:
    all :: (a -> Bool) -> [a] -> Bool
    Implemente a função all: 1) usando recursão e 2) usando foldr.
--}
all :: (a -> Bool) -> [a] -> Bool
all _ [] = True
all f (x : xs) 
    | f x = True && all f xs
    | otherwise = False

all_fold :: (a -> Bool) -> [a] -> Bool
all_fold predicado xs = foldr step True xs
    where 
        step x acc = predicado x && acc

testaAll :: Bool -> Int -> Bool
testaAll recursao minimo
    | recursao = all_fold (\x -> x > minimo) [1,2,3,4,5,6]
    | otherwise = all_fold (\x -> x > minimo) [1,2,3,4,5,6]
    

{--
    Implemente a função concatMap de tipo:
    concatMap :: (a -> [b]) -> [a] -> [b]
    Usando recursão e foldr.
--}
concatMap :: (a -> [b]) -> [a] -> [b]
concatMap _ [] = []
concatMap f (x : xs) = f x ++ concatMap f xs

concatMap_fold :: (a -> [b]) -> [a] -> [b]
concatMap_fold f xs = foldr funcao [] xs
    where
        funcao x ac = f x ++ ac 


testaConcat = concatMap_fold funcao [1,2,3,4,5]
    where 
        funcao x = [x^2, x^3, x*0]


{--
    Implemente a função
    allNats :: [Int] -> Bool
    que retorna True se todos os valores da lista fornecida como entrada são maiores que zero. 
--}

allNats :: [Int] -> Bool
allNats [] = True
allNats (x : xs)
    | x >= 0 = True && allNats xs
    |otherwise = False

allNats_ordem_superior :: [Int] -> Bool
allNats_ordem_superior xs = foldr predicado True xs
    where
        predicado x acc
            | x >= 0 = True && acc
            | otherwise = False 


