{-# LANGUAGE TypeSynonymInstances, FlexibleInstances #-}

import Data.Char

newtype Parser s a = Parser { 
    -- Recebe somente um elemento de entrada
    runParser :: [s] -> [(a,[s])] 
} 


symbol :: Eq s => s -> Parser s s
symbol s = Parser (\ inp -> case inp of
                              [] -> []
                              (x : xs) -> if x == s
                                          then [(s,xs)]
                                          else [])

-- runParser (symbol '1') "123456"

token :: Eq s => [s] -> Parser s [s]
token s = Parser (\inp -> if s == (take n inp) 
                        then [(s, drop n inp)]  
                        else [])
    where 
        n = length s
        
-- Processando um símbolo que atende uma condição
sat :: (s -> Bool) -> Parser s s
sat p = Parser (\ inp -> case inp of
                           [] -> []
                           (x : xs) -> if p x
                                       then [(x,xs)]
                                       else [])


digitChar :: Parser Char Char
digitChar = sat isDigit

instance Functor (Parser s) where
    fmap f (Parser p) = Parser(\inp -> [(f x, xs) | (x,xs) <- p inp])

--Transformando digitos em inteiros
digit :: Parser Char Int
digit = f <$> digitChar 
    where
        f c = ord c - ord '0' 


-- Parser que não falaha
succeed :: a -> Parser s a
succeed v = Parser (\ inp -> [(v,inp)])

--Parser que sempre falha
failure :: Parser s a
failure = Parser (\ _ -> [])


-- Escolha entre dois parseres
--infixr 4 <|>

(<|>) :: Parser s a -> Parser s a -> Parser s a
(Parser p) <|> (Parser q)
   = Parser (\ inp -> p inp ++ q inp)


instance Applicative (Parser s) where
   pure = succeed
   (Parser p) <*> (Parser q) = Parser (\ inp -> [(f x, xs) | (f, ys) <- p inp, (x, xs) <- q ys])

