import Parser

data Bit = O | I deriving (Eq, Ord)

data Field
  = Field {
      size :: Int
    , content :: [Bit]
    } deriving (Eq, Ord)


data UDP
  = UDP {
      source :: Field       --- 16 bits
    , destination :: Field  --- 16 bits
    , plength :: Field      --- 16 bits
    , checksum :: Field     --- 16 bits
    , pdata :: [Field]      --- list of 32 bit fields
    } deriving (Eq, Ord)


bitParser :: Parser Char Bit
bitParser = zero <|> um
    where
        zero = const O <$> symbol '0'
        um = const I <$> symbol '1'


bitList :: Int -> Parser Char [Bit]
bitList n 
    | n <= 0 = succeed []
    | otherwise = (:) <$> bitParser <*> bitList (n-1)

fieldParser :: Int -> Parser Char Field
fieldParser n = Field n <$> bitList n

udpParser :: Parser Char UDP
udpParser = UDP <$> fieldParser 16 <*> fieldParser 16 <*> fieldParser 16 <*> fieldParser 16 <*> greedy (fieldParser 32)