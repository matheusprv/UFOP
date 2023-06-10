module Aula06 where

import Prelude hiding ( foldr
                      , foldl
                      , sum
                      , concat
                      , and
                      , length
                      , map
                      , reverse
                      , filter
                      , (++)
                      )

sum :: Num a => [a] -> a
sum [] = 0
sum (x : xs) = x + sum xs

and :: [Bool] -> Bool
and (x : []) = x
and (x : xs) = x && and xs

foldr :: (a -> b -> b) -> b -> [a] -> b
foldr _ dv [] = dv
foldr f dv (x : xs) = x `f` foldr f dv xs

sum_foldr :: Num a => [a] -> a
sum_foldr = foldr (+) 0 

and_foldr :: [Bool] -> Bool
and_foldr = foldr (&&) true

length :: [a] -> Int
length  = foldr step 0 
    where 
        step _ ac = 1 + ac

map :: (a -> b) -> [a] -> [b]
map f xs = foldr step [] xs
    where 
        step x ac = f x : ac