import Parser

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
bitParser = zero <|> um
    where 
        zero = (\ _ -> O) <$> symbol '0'
        um = (\ _ -> I) <$> symbol '1'

-- Usando o parser para bits, podemos construir um parser que processa uma sequência de n bits.
-- Um parser |bitList n| processa uma sequência de n bits retornando-os como resultado.
bitList :: Int -> Parser Char [Bit]
bitList n 
    | n <= 0 = succeed []
    | otherwise = (:) <$> bitParser <*> bitList (n-1)

-- Usando parser |bitList| implemente um parser para o tipo |Field|
-- Note que |fieldParser n| retorna um valor de tipo |Field| contendo uma 
-- lista de |n| bits e o inteiro n como campos deste registro.
fieldParser :: Int -> Parser Char Field
fieldParser n = Field n <$> bitList n

-- Finalmente, usando os tamanhos de sequências de bits de cada campo de um datagrama UDP, 
-- construa um parser para o tipo |UDP|.
udpParser :: Parser Char UDP
udpParser = UDP <$> fieldParser 16 <*>
                    fieldParser 16 <*>
                    fieldParser 16 <*>
                    fieldParser 16 <*>
                    many (fieldParser 32)
