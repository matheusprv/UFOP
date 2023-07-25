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
