data Toy a b = Output a b | Bell b | Done deriving Show

instance Functor (Toy a) where
    fmap _ Done = Done
    fmap f (Bell b) = Bell (f b)
    fmap f (Output a b) = Output a (f b)

geraToy :: Int -> Int -> Toy Int Int
geraToy x y = Output x y

geraBell :: Int -> Toy Int Int
geraBell x = Bell x

data Teste = Teste Int Int Int


readTeste :: Maybe Teste 
readTeste = ((Teste <$> readInt "12") <*> readInt "23") <*> readInt "43"

readInt :: String -> Maybe Int 
readInt = undefined