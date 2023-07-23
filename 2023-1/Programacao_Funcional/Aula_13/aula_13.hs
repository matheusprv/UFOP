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


token :: Eq s => [s] -> Parser s [s]
token s = Parser (\inp -> if s == (take (length s) inp) --PEga os primeiros itens da lista 
                        then [(s, drop (length s) inp)]  
                        else [])
        
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
digit = funcao <$> digitChar 
    where
        funcao c = ord c - ord '0' 


-- Parser que não falaha
succeed :: a -> Parser s a
succeed v = Parser (\ inp -> [(v,inp)])

--Parser que sempre falha
failure :: Parser s a
failure = Parser (\ _ -> [])


-- Escolha entre dois parseres
infixr 4 <|>

(<|>) :: Parser s a -> Parser s a -> Parser s a
(Parser p) <|> (Parser q) = Parser (\ inp -> p inp ++ q inp)


instance Applicative (Parser s) where
   pure = succeed
   (Parser p) <*> (Parser q) = Parser (\ inp -> [(f x, xs) | (f, ys) <- p inp, (x, xs) <- q ys])


ex1 :: Parser Char String
ex1 = token "ab" <|> token "ba"


data Paren = Match Paren Paren | Empty deriving Show

open :: Parser Char Char
open = symbol '('

close :: Parser Char Char
close = symbol ')'

parens :: Parser Char Paren
parens = (f <$> open <*> parens <*> close <*> parens) <|> succeed Empty
         where
           f _ p _ p' = Match p p'

option :: Parser s a -> a -> Parser s a
option p d = p <|> succeed d

many :: Parser s a -> Parser s [a]
many p = ((:) <$> p <*> many p) <|> succeed []

many1 :: Parser s a -> Parser s [a]
many1 p = (:) <$> p <*> many p

-- natural :: Parser Char Int
-- natural = foldl step 0 <$> (many digit)
--      where
--        step ac d = ac * 10 + d

natural :: Parser Char Int
natural = many digit
     where
       step ac d = ac * 10 + d

first :: Parser s a -> Parser s a
first (Parser p)
   = Parser (\ inp -> let r = p inp
                      in if null r then []
                         else [head r])

greedy :: Parser s a -> Parser s [a]
greedy = first . many

greedy1 :: Parser s a -> Parser s [a]
greedy1 = first . many1