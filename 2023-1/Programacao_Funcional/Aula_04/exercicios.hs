minList :: Ord a => [a] -> a
minList (x : []) = x
minList (x : xs) = menorValor
    where
        menorRecursivo = minList xs
        menorValor
            | x < menorRecursivo = x
            | otherwise = menorRecursivo


andList :: [Bool] -> Bool
andList (x : []) = x
andList (False : _) = False
andList (True : xs) = andList xs

orList :: [Bool] -> Bool
orList (x : []) = x
orList (True : _) = True
orList (False : xs) = orList xs


indexOf :: Int -> [Int] -> Int
indexOf x xs = index x xs 0
    where
        index _ [] _ = -1
        index x (y : ys) ac
            | x == y = ac
            | otherwise = index x ys (ac+1)


removeAll :: Int -> [Int] -> [Int]
removeAll _ [] = []
removeAll x (y : ys) 
    | x == y = [] ++ removeAll x ys
    | otherwise = y : removeAll x ys

