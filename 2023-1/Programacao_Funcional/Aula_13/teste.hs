import Parser

teste :: Parser Char [Char]
teste = many (sat(\x -> x /= ','))