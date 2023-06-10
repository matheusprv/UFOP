--import Prelude hiding (sum)

squareSum :: Int -> Int
squareSum n = sum [y^2 | y <- [1 .. n]]

grid :: Int -> Int -> [(Int, Int)]
grid m n = [(x, y) | x <- [1 .. n], y <- [1 .. m]]

scalarProduct :: [Int] -> [Int] -> Int
scalarProduct xs ys = sum [x*y | (x,y) <- zip xs ys]