{-eh_par :: Int -> Bool
eh_par n 
    | n `mod` 2 == 0 = True
    | otherwise = False
-}


quadrado1 :: Num a => [a] -> [a]
quadrado1 [] = []
quadrado1 (x : xs) = x*x : quadrado1 xs

quadrado2 :: Num a => [a] -> [a]
quadrado2 xs = [ x*x | x <- xs]

-- O resultado final será o que atender as duas condições
quadrado3 :: [Int] -> [Int]
quadrado3 xs = [ x*x | x <- xs, eh_par x, x^2 >= 10]
    where 
        eh_par n
            | n `mod` 2 == 0 = True
            | otherwise = False


--O resultado final será a combinação de todas as possibilidades da lista 1 com a lista 2
gerador_multiplo :: [Int] -> [Int] -> [Int]
gerador_multiplo xs ys = [x * y | x <- xs, y <-ys]


--heads :: [[[[a]]]] -> [a]
--heads xss = [x | (x : _) <- xss]  


primes :: Int -> [Int]
primes n = [x | x <- [2 .. n], isPrime x]
    where
        sizeTwo (_ : _ : []) = True
        sizeTwo _            = False
        factors x = [ y | y <- [1 .. x] , x `mod` y == 0 ]
        isPrime x = sizeTwo (factors x)
        
        
        
