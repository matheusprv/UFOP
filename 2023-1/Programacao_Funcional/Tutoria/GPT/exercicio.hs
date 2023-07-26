import Parser

parserList :: Parser Char [Int]
parserList = listOf natural (symbol ',')



data Config = Config { 
    param1 :: String, 
    param2 :: Int, 
    param3 :: Bool 
} deriving (Show)

param1Parser :: Parser Char String
param1Parser = greedy (sat (\x -> x /= ','))

param3Parser :: Parser Char Bool
param3Parser = true <|> false
    where
        true = const True <$> token "True"
        false = const False <$> token "False"

mkConfig :: Parser Char Config
mkConfig = f <$> param1Parser <*> symbol ',' <*> natural <*> symbol ',' <*>  param3Parser
    where
        f p1 _ p2 _ p3 = Config p1 p2 p3

--config :: String -> Config
-- config inp = (\[x : xs] -> fst x) <$> (runParser mkConfig inp )


parseCoordinates :: Parser Char (Int, Int)
parseCoordinates = (\ _ n1 _ n2 _ -> (n1, n2)) <$> symbol '(' <*> natural <*> symbol ',' <*> natural <*> symbol ')'  


--Adaptando o parser de natural para poder receber numero inteiro
parseInt :: Parser Char Int
parseInt = (*) <$> (negativo <|> neutro) <*> natural
    where 
        negativo = const (-1) <$> symbol '-'
        neutro = succeed 1