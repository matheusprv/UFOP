import Parser
import Prelude hiding (const)

const :: a -> b -> a
const x _ = x


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
bitParser = zero <|> one
    where
        zero = const O <$> symbol '0'
        one = const I <$> symbol '1'

bitList :: Int -> Parser Char [Bit]
bitList n
    | n <= 0 = succeed []
    | otherwise = (:) <$> bitParser <*> bitList (n-1)

fieldParser :: Int -> Parser Char Field
fieldParser n = Field n <$> bitList n

udpParser :: Parser Char UDP
udpParser = UDP <$> fieldParser 16 <*>
                      fieldParser 16 <*>
                      fieldParser 16 <*>
                      fieldParser 16 <*>
                      many (fieldParser 32)