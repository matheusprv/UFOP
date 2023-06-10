import Prelude hiding (gcd)

gcd :: Int -> Int -> (Int, Int)
gcd a b
    | b == 0 = (a, 1)
    | otherwise = (proximoValor, contador + 1)
        where
            (proximoValor, contador) = gcd b (a `mod` b)



{--
    gcd b (a `mod` b)
--}        