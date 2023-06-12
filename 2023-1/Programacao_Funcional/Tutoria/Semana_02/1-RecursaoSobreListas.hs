import Data.Char
-- Retorna todos os valores de uma lista que estão dentro de um intervalo
inRange :: Int -> Int -> [Int] -> [Int]
inRange _ _ [] = []
inRange inferior superior (x : xs) 
    | x >= inferior && x <= superior = x : inRange inferior superior xs
    | otherwise = inRange inferior superior xs

inRangeFold :: Int -> Int -> [Int] -> [Int]
inRangeFold inferior superior = foldr step []
    where 
        step x ac 
            | x >= inferior && x <= superior = x : ac
            |otherwise = ac

-- Retorna a quantidade de números positivos de uma lista
countPositives :: [Int] -> Int
countPositives xs = length [y | y <- xs, y > 0]

countPositivesRec :: [Int] -> Int
countPositivesRec [] = 0
countPositivesRec (x : xs) = if x > 0 then 1 + countPositivesRec xs else countPositivesRec xs

countPositivesRecFold :: [Int] -> Int
countPositivesRecFold = foldr step 0
    where
        step x ac 
            | x > 0 = 1 + ac
            | otherwise = ac

-- Deve retornar True se os resutados de countPositives e countPositivesRec são os mesmos da lista de entrada
propCountPositive :: [Int] -> Bool
propCountPositive xs = countPositives xs == length xs 





-- Fazer com que somente a primeira letra de uma string seja maiuscula
toTitleString :: String -> String
toTitleString [] = []
toTitleString (x : xs) = toUpper x : foldr (\x ac -> toLower x : ac) [] xs



--Retornar a metada de todo número par de uma lista
halfEvens :: [Int] -> [Int]
halfEvens xs = [y `div` 2 | y <- xs, y `mod` 2 == 0]

halfEvensRec :: [Int] -> [Int]
halfEvensRec xs = map (\x -> x `div` 2) (filter (\x -> x `mod` 2 == 0) xs)

propHalfEvans :: [Int] -> Bool
propHalfEvans xs = verifica (halfEvens xs) (halfEvensRec xs)
    where 
        verifica [] [] = True
        verifica _ [] = False
        verifica [] _ = False
        verifica (x : xs) (y : ys) = if x == y then verifica xs ys else False
