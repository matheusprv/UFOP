module Aula02 where

bools :: [Bool]
bools = [True, False, True, False]

nums  :: [[Int]]
nums = [[1, 2, 3, 4], [5, 6, 7, 8]]

add   :: Int -> Int -> Int -> Int
add a b c = a + b + c

copy  :: a -> (a, a)
copy a = (a, a)

{-
apply :: (a -> b) -> a -> b
apply (a -> b)
-}

swap  :: (a,b) -> (b,a)
swap (x, y) = (y, x)