import Data.Char
-- import Test.Tasty
-- import Test.Tasty.HUnit      as TH
-- import Test.Tasty.QuickCheck as TQ
-- import Test.QuickCheck


data Name = MkName String deriving Eq

mkName :: String -> Name
mkName [] = MkName []
mkName (x : xs) = MkName((toUpper x) : map toLower xs)


render :: Name -> String
render (MkName s) = s

mkNameTest :: TestTree
mkNameTest = testCase "MkName Test" (s @?= "Matheus")
  where s = render (mkName "maria")


--Propriedades de um nome 
--Começar com letra maisucula
startsWithUpper :: String -> Bool
startsWithUpper [] = True
startsWithUpper (c : _) = isUpper c

nameCorrect :: String -> Bool
nameCorrect s = startsWithUpper (render (mkName s))

--Corrigindo para a string "1"
implies :: Bool -> Bool -> Bool
implies x y = not x || y

nameCorrectFixed :: String -> Bool
nameCorrectFixed s = (all isLetter s) `implies` b
   where
     b  = startsWithUpper s'
     s' = render (mkName s)








--Algoritmo de ordenação com erro
sort1 :: [Int] -> [Int]
sort1 [] = []
sort1 (x : xs) = insert1 x xs

insert1 Int -> [Int] -> [Int]
insert1 x [] = [x]
insert1 x (y : ys)
--  | x <= y = x : ys
    | x <= y = x : y : ys
    | otherwise = y: insert1 x ys

-- A lista deve preservar o seu tamanho
sortPreserversLength :: [Int] -> Bool
sortPreserversLength xs = length(sort xs) == length xs

--Todos os itens devem ser preservados
preserves :: E1 b -> (a->a) -> (a->b) -> a -> Bool
(f `preserves` p) x = p x == p (f x)


sortPreservesLength = sort `preserves` length

idPreservesLength :: [Int] -> Bool
idPreservesLength = id `preserves` length

-- Verificando se os itens estão ordenados
sorted :: [Int] -> Bool
sorted []  = True
sorted [_] = True
sorted (x : y : ys) = x <= y && sorted (y : ys)

sortEnsuresSorted :: [Int] -> Bool
sortEnsuresSorted = sorted . sort


sort2 :: [Int] -> [Int]
sort2 [] = []
sort2 (x : xs) = insert2 x (sort2 xs)