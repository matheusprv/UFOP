import Data.Char

capitalize :: String -> String
capitalize xs = map toUpper xs


is_prime :: Int -> Bool
is_prime x = isPrime x
    where 
      sizeTwo (_ : _ : []) = True
      sizeTwo _            = False
      isPrime x = sizeTwo (factors x)
      factors x = [ y | y <- [1 .. x], x `mod` y == 0 ]


withoutPrimes :: [Int] -> [Int]
withoutPrimes xs = filter is_prime xs
