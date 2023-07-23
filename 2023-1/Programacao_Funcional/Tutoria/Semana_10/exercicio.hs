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
} deriving (Eq, Ord, Show)


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
        xs -> [extract n $ runParser (bitList n) xs]
    )
    where
        extract n [] = (Field n [], [])
        extract n [(value, rest)] = (Field n value, rest)
{-
    runParser (fieldParser 5) "110011"
    [(Field {size = 5, content = [I,I,O,O,I]},"1")]
-}

-- Finalmente, usando os tamanhos de sequências de bits de cada campo de um datagrama UDP, 
-- construa um parser para o tipo |UDP|.
-- udpParser :: Parser Char UDP
-- udpParser = Parser (\inp -> case inp of
--         [] -> []
--         xs -> [(
--             UDP <$> fieldParser 16 <*> fieldParser 16 <*> fieldParser 16 <*> fieldParser 16 <*> many (fieldParser 32),
--             drop 96 xs)]
--     )

udpParser = UDP <$> fieldParser 16 <*>
                      fieldParser 16 <*>
                      fieldParser 16 <*>
                      fieldParser 16 <*>
                      many (fieldParser 32)
{-
runParser udpParser "111111111100000000001111111111000000000011111111110000000000111111111100000000001111111111000000"
[(
    UDP {
        source = Field {size = 16, content = [I,I,I,I,I,I,I,I,I,I,O,O,O,O,O,O]}, 
        destination = Field {size = 16, content = [O,O,O,O,I,I,I,I,I,I,I,I,I,I,O,O]}, 
        plength = Field {size = 16, content = [O,O,O,O,O,O,O,O,I,I,I,I,I,I,I,I]}, 
        checksum = Field {size = 16, content = [I,I,O,O,O,O,O,O,O,O,O,O,I,I,I,I]}, 
        pdata = [Field {size = 32, content = [I,I,I,I,I,I,O,O,O,O,O,O,O,O,O,O,I,I,I,I,I,I,I,I,I,I,O,O,O,O,O,O]}]},""),
        
        (UDP {
            source = Field {size = 16, content = [I,I,I,I,I,I,I,I,I,I,O,O,O,O,O,O]}, 
            destination = Field {size = 16, content = [O,O,O,O,I,I,I,I,I,I,I,I,I,I,O,O]}, 
            plength = Field {size = 16, content = [O,O,O,O,O,O,O,O,I,I,I,I,I,I,I,I]}, 
            checksum = Field {size = 16, content = [I,I,O,O,O,O,O,O,O,O,O,O,I,I,I,I]}, 
            pdata = []},"11111100000000001111111111000000"
        )]
-}