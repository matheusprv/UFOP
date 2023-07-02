inRange :: Int -> Int -> [Int] -> [Int]
inRange begin end = foldr steps []
    where 
        steps x ac 
            | x >= begin && x <= end = x : ac
            | otherwise = ac

inRangeProperty :: Int -> Int -> [Int] -> Bool
inRangeProperty begin end xs = all (\x -> x >= begin && x <= end) xs