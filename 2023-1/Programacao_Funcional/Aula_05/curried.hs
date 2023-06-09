import Prelude

add :: Int -> Int -> Int
add = \x -> (\y -> x+y)


-- A cash machine gets a card as an input
-- It gives back a function that expets the pin number
-- Finally it gives back a function to you decide what action you are gonna do
-- In this case, the machine will give back 100 dolars
cash_machine = \card -> (\pin -> (\action -> 100))



--COMPOSIÇÃO
-- f(g(x)) onde g(x)=2x e f(x)=x^4
operacao :: Num a => a ->  a
operacao = quarta . vezesDois
    where
        vezesDois x = 2 * x
        quarta x = x ^ 4


operacaoLista :: [Int] -> [Int]
operacaoLista xs = map operacao (filter even xs)
