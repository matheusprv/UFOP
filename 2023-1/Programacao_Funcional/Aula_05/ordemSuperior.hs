import Prelude hiding ( map, filter, foldr, foldl, flip, (.))
import Data.Char

-- MAP
map :: (a -> b) -> [a] -> [b]
map _ [] = []
map f (x : xs) = f x : map f xs


doubleList :: Num a => [a] -> [a]
doubleList xs = map double xs
    where
        double x = 2 * x

notList :: [Bool] -> [Bool]
notList xs = map not xs



-- FILTER
filter :: (a -> Bool) -> [a] -> [a]
filter _ [] = []
filter f (x : xs) 
    | f x = x : filter f xs
    | otherwise = filter f xs


lowers :: String -> String
lowers [] = []
lowers (x : xs) 
    | isLower x = x : lowers xs
    | otherwise = lowers xs

lowers2 :: String -> String
lowers2 xs = filter isLower xs

evens :: [Int] -> [Int]
evens xs = filter even xs

dois_x :: (Num a, Ord a) => [a] -> [a]
dois_x xs = filter restricao xs
    where 
        restricao x = 2 * x >= 10


-- FILTER AND MAP
--Recebe Uma lista com valores numéricos e retorna uma lista com todos os que, multiplicados por 2, são maiores que 10
dois_x_maior_10 :: (Num a, Ord a) => [a] -> [a]
dois_x_maior_10 xs = map multiplicacao listaFiltrada
    where 
        multiplicacao x = 2 * x 
        
     -- listaFiltrada xs = filter restricao xs
        listaFiltrada = filter restricao xs
        restricao x = 2 * x >= 10 


-- Função Curried
multThree :: (Num a) => a -> (a -> (a -> a))
multThree x y z = x * y * z  