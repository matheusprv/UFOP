import Data.Char

--Converte todas as letras de uma função de entrada em maiusculas
uppers :: String -> String
uppers = map (\x -> toUpper x)

--Converte todos os valores de centavos para reais
centsToReals :: [Int] -> [Float]
centsToReals = map (\x -> (fromIntegral x) / 100)

--Remove todos os caracteres que nao sao letras da string
alphas :: String -> String
alphas = filter isLetter 

--Remove todos os valores que são menores do que o que foi especificado
above :: Int -> [Int] -> [Int]
above n = filter ( > n) 