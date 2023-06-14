allNats :: [Int] -> Bool
allNats = foldr steps True
    where
        steps x ac = if x > 0 then ac else False

pairs :: [a] -> [(a, a)]
pairs [] = []
pairs (x : []) = []
pairs (x : y : xs) = (x, y) : pairs xs


generateList :: (Int, Int) -> [Int]
generateList (0, _) = []
generateList (n, x) = x : generateList ((n-1), x)


uncompress :: [Int] -> [Int]
uncompress xs
    | allNats xs = foldr step base input
    | otherwise = []

    where
        step x ac = generateList x ++ ac
        base = []
        input = pairs xs