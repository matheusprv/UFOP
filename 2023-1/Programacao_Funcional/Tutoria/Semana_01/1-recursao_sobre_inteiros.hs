next :: Int -> Int
next x
    | x `mod` 2 == 0 =  x `div` 2
    | otherwise = 3 * x + 1 

steps :: Int -> (Int, Int)
steps x
    | x == 1 = (1, 1)
    | otherwise = (proximoValor, contador + 1)
    where
        (proximoValor, contador) = steps (next x)


stepsList :: Int -> ([Int], Int)
stepsList x
    | x == 1 = ([1], 1)
    | otherwise = (a : resultadoRecursivo, contador + 1)
    where
        a = next x
        (resultadoRecursivo, contador) = stepsList a
        
