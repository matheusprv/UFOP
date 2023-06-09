import Data.Char

{--
    Implemente a função capitalize que converte todas as letras minúsculas em uma string para maiúsculas. 
    Utilize a função toUpper da biblioteca Data.Char.
--}

capitalize :: String -> String
capitalize xs = map toUpper xs


{--
    Implemente a função withoutPrimes que remove todos os valores primos de uma lista de inteiros fornecida como argumento.
--}

isPrime :: Int -> Bool
isPrime x 
    | length divisors > 2 = False
    | otherwise = True
        where
            divisors = [y | y <- [1.. x], x `mod` y  == 0]


withoutPrimes :: [Int] -> [Int]
withoutPrimes = filter (not.isPrime) 
