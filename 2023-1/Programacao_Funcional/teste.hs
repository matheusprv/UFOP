count :: Num a => [a] -> a 
count [] = 0
count (x : xs) = x + count xs

--Erro
{-
concatenar ++ [a] -> [a] -> [a]
concatenar [] ys = ys
concatenar (x:xs) ys = x ++ concatenar xs ys
-}

--Correta
concatenar2 :: [a] -> [a] -> [a]
concatenar2 [] ys = ys
concatenar2 (x:xs) ys = x : concatenar2 xs ys





