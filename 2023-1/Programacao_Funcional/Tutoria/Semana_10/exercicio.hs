newtype Parser s a = Parser { 
    runParser :: [s] -> [(a,[s])] 
} 

succeed :: a -> Parser s a
succeed v = Parser (\ inp -> [(v,inp)])

failure :: Parser s a
failure = Parser (\ _ -> [])

instance Functor (Parser s) where
    fmap f (Parser p) = Parser(\inp -> [(f x, xs) | (x,xs) <- p inp])

(<|>) :: Parser s a -> Parser s a -> Parser s a
(Parser p) <|> (Parser q) = Parser (\ inp -> p inp ++ q inp)

instance Applicative (Parser s) where
   pure = succeed
   (Parser p) <*> (Parser q) = Parser (\ inp -> [(f x, xs) | (f, ys) <- p inp, (x, xs) <- q ys])


many :: Parser s a -> Parser s [a]
many p = ((:) <$> p <*> many p) <|> succeed []



-- Prova
data Bit = O | I deriving (Eq, Ord, Show)

data Field = Field {
    size :: Int, 
    content :: [Bit]
} deriving (Eq, Ord, Show)

data UDP = UDP {
    source :: Field,
    destination :: Field,
    plength :: Field,
    checksum :: Field,
    pdata :: [Field]
} deriving (Eq, Ord)


--Implemente um parser para o tipo |Bit|, de forma que o dígito 1 seja representado pelo construtor |I| e o dígito 0 por |O|.
bitParser :: Parser Char Bit
bitParser = Parser (\ inp -> case inp of
                                [] -> []
                                (x : xs) -> [(b x,xs)])
    where
        b x = if x == '1' then I else O
{-
    Exemplo de execução
    runParser bitParser "110011"
    [(I,"10011")]
-}



-- Usando o parser para bits, podemos construir um parser que processa uma sequência de n bits.
-- Um parser |bitList n| processa uma sequência de n bits retornando-os como resultado.
bitList :: Int -> Parser Char [Bit]
bitList 1 = (: []) <$> bitParser
bitList n = (:) <$> bitParser <*> bitList (n-1)
{-
    runParser (bitList 3) "110011"
    [([I,I,O],"011")]
-}



-- Usando parser |bitList| implemente um parser para o tipo |Field|
-- Note que |fieldParser n| retorna um valor de tipo |Field| contendo uma 
-- lista de |n| bits e o inteiro n como campos deste registro.
fieldParser :: Int -> Parser Char Field
fieldParser n = Parser (\ inp -> case inp of
        [] -> []
        xs -> [(
                    Field n  $ extract $ runParser (bitList n) xs, 
                    xs
                )]
    )

extract :: [(k, a)] -> k
extract [(value, _)] = value
{-
    runParser (fieldParser 6) "110011"
    [(Field {size = 6, content = [I,I,O,O,I,I]},"110011")]
-}



-- Finalmente, usando os tamanhos de sequências de bits de cada campo de um datagrama UDP, 
-- construa um parser para o tipo |UDP|.
udpParser :: Parser Char UDP
udpParser = undefined