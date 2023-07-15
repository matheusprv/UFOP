list :: [Integer]
list = 1 : prop [1 ..]
    where
        prop (x : xs) =  [y | y <- xs, y `mod` 2 == 0 || y `mod` 3 == 0 || y `mod` 5 == 0 ]



list_filter :: [Integer]
list_filter = 1 : filter (\y -> y `mod` 2 == 0 || y `mod` 3 == 0 || y `mod` 5 == 0 ) [1 ..]