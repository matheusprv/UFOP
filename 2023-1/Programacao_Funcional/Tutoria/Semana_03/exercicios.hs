-- import           Control.Monad
-- import           Data.List                     (transpose)
-- import           Test.Tasty
-- import           Test.Tasty.HUnit
-- import qualified Test.Tasty.QuickCheck  as QC

-- main :: IO()
-- main = defaultMain tests

type Matrix = [[Float]]

example :: Matrix
example = [ [1, 4, 9] 
          , [2, 5, 7]] 

invalid :: Matrix
invalid = [ [1, 4, 9] 
          , [2]] 

uniform :: [Float] -> Bool
uniform [] = True
uniform (x : []) = True
uniform (x : x1 : xs) 
    | x == x1 = True && uniform xs
    | otherwise = False


valid :: Matrix -> Bool
valid [] = False
valid xs = uniform (foldr steps [] xs)
    where 
        steps x ac = fromIntegral(length x) : ac

dimension :: Matrix -> (Int, Int)
dimension matrix = (outside, inside matrix)
    where
        valid_matrix = valid matrix
        outside = if valid_matrix then length(matrix) else 0
        inside [] = 0
        inside (x : xs) = if valid_matrix then length x else 0


square :: Matrix -> Bool
square [] = False
square matrix = verifica (dimension matrix)
    where
        dimensao = dimension matrix
        verifica :: (Int, Int) -> Bool
        verifica (x , y) = x == y






























-- question1Tests :: TestTree
-- question1Tests
--    = testGroup "Tests for exercice 1"
--                [
--                  uniformTests
--                , validTests
--                ] 


-- zipWithProperty :: QC.Property
-- zipWithProperty
--    = QC.forAll (QC.arbitrary :: QC.Gen ([Int],[Int]))
--             (\ (xs,ys) -> zipWith' (+) xs ys == zipWith (+) xs ys)


-- question4Tests :: TestTree
-- question4Tests
--   = testGroup "Tests for exercice 4"
--               [
--                 QC.testProperty "zipWith' test" zipWithProperty
--               ]

-- buildFromDimensions :: Int -> Int -> QC.Gen Matrix
-- buildFromDimensions n m
--   = replicateM n (replicateM m genEntry)
--     where
--       genEntry = QC.choose (1,10) :: QC.Gen Float


-- matrixGen :: QC.Gen Matrix
-- matrixGen
--   = do
--        n <- QC.choose (1,5) :: QC.Gen Int
--        m <- QC.choose (1,5) :: QC.Gen Int
--        buildFromDimensions n m 

-- question5Tests :: TestTree
-- question5Tests
--   = testGroup "Tests for exercice 5"
--               [
--                 addRowTest
--               , sumMatrixTest
--                ] 

-- question6Tests :: TestTree
-- question6Tests
--   = testGroup "Tests for exercice 6"
--               [
--                 innerProductTest
--               , prodMatrixTest
--                ] 

-- tests :: TestTree
-- tests
--    = testGroup "Semana 3 tests"
--                 [
--                   question1Tests,
--                   question2Tests,
--                    question3Tests,
--                    question4Tests,
--                    question5Tests,
--                    question6Tests
--                  ]