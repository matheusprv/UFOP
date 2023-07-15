ones :: [Int]
ones = 1 : ones

five_ones :: [Int]
five_ones = take 5 ones


-- Lista com todos os naturais
nats :: [Int]
nats = 0 : map (+1) nats

n_naturais :: Int -> [Int]
n_naturais n = take n nats


{-- 
    zipWith recebe uma função e duas listas, depois converte as duas listas a partir da função. No caso está somando fibs com a própria cauda
    Input: zipWith (+) [1,2,3] [3,2,1]
    Output: [4,4,4]
--}
-- Listando a sequência de Fibonacci
fibs :: [Integer]
fibs = 0 : 1 : zipWith (+) fibs (tail fibs) 



-- Algoritmo para listar os numeros primos
primes :: [Integer]
primes = sieve [2 ..] -- 1) Começando por um número p, onde p = 2
    where 
        sieve (p : ns) = p : [x | x <- ns, x `mod` p /=0] --Removendo todos os multiplos de p



-- Algoritmo de Newton para encontrar a raiz quadrada de um numero n
next :: Double -> Double -> Double
next n x0 = (x0 + n / x0) / 2

--Criando uma lista infinita de aproximações sucessivas.
approximations :: Double -> Double -> [Double]
approximations x0 n = iterate (next n) x0

--Obtendo o resultado a partir das aproximações consectutivas.
within :: Double -> [Double] -> Double
within phi (x0 : x1 : xs)
  | abs (x0 - x1) < phi = x1
  | otherwise           = within phi (x1 : xs)

--Função para raiz quadrada usando o algoritmo de Newton.
newton :: Double -> Double
newton n = within 0.000000001 (approximations (n / 2) n)