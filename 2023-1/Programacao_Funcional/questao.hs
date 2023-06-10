pairs :: [a] -> [(a,a)]
pairs [] = []
pairs (x1 : []) = []
pairs (x1 : x2 : xs) = (x1, x2) : pairs xs


indexOf :: Int -> [Int] -> Int
indexOf n xs = index n xs 0
    where
        index _ [] _ = -1
        index n (y : ys) ac
            | n == y = ac
            | otherwise = index n ys (ac + 1)




isPrime :: Int -> Bool
isPrime x
    | divisores > 2 = False
    | otherwise = True
    where 
        divisores = length [y | y <- [1 .. x], x `mod` y == 0]

withoutPrimes :: [Int] -> [Int]
withoutPrimes = filter (not.isPrime)