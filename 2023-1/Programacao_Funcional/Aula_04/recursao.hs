import Prelude hiding ( length
                      , replicate
                      , sum
                      , reverse
                      , elem
                      , take
                      , (++)
                      , zip
                      )

-- Verifica se um elemento está dentro de uma lista
elemento :: Int -> [Int] -> Bool
elemento _ [] = False
elemento x (y : ys) 
    | x == y = True
    |otherwise = elemento x ys


(++) :: [a] -> [a] -> [a]
[] ++ ys = ys
(x : xs) ++ ys = x : (xs ++ ys)


zip :: [a] -> [b] ->[(a,b)]
zip [] _  = []
zip _ []  = []
zip (x : xs) (y : ys) = (x, y) : zip xs ys





reverse :: [a] -> [a]
reverse [] = []
reverse (x : xs) = reverse xs ++ [x]