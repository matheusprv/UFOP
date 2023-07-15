{-# LANGUAGE InstanceSigs #-}


data Point = Point Float Float 
    deriving Show

-- Criando uma instancia para a classe Eq do tipo Point 
-- Internamente a instancia já é feita da maneira como foi implmentada, comparando elemento a elemento
instance Eq Point where
    (==) :: Point -> Point -> Bool
    (Point x y) == (Point x' y') = x == x' && y == y'

    (/=) :: Point -> Point -> Bool
    a@(Point x y) /= b@(Point x' y') = not (a==b)


elemExist :: Eq a => a -> [a] -> Bool
elemExist verificador xs = foldr steps False xs
    where
        steps x ac
            | x == verificador = True
            | otherwise = ac




data Vector = Vector Float Float deriving (Eq, Ord, Show) --Usou a instancia de Eq padrao

data Shape = 
    Rectangle Vector Float Float | 
    Circle Vector Float
    deriving (Eq, Ord, Show)

-- Criando classes
-- Define o comportamento e os tipos podem se comportar dessa forma são feitas instancias dessa classe
-- Mas define somente a interface desse comportamento
class Scale a where
    scale :: Float -> a -> a

-- Criando a instancia para a classe Scale
instance Scale Vector where
    scale s (Vector x y) = Vector (x*s') (y*s')
        where
            s' = s / norm (Vector x y)
            norm (Vector a b) = sqrt (a^2 + b^2)


instance Scale Point where
    scale _ (Point x y) = Point (2*x) (2*y)

instance Scale Shape where
    scale s (Circle p r) = Circle p (s * r)
    scale s (Rectangle p w h) = Rectangle p (s * w) (s * h)

instance Scale a => Scale [a] where
    scale s = map(scale s)


doubleEscalable :: Scale a => a -> a
doubleEscalable s = scale 2.0 s