-- Implemente uma instância de Eq para o tipo Vec3.
data Vec3 = Vec3 Int Int Int
    deriving(Show)

instance Eq Vec3 where
    (Vec3 x y z) == (Vec3 x' y' z') = x == x' && y' == y' && z == z'


--Implemente uma instância de Eq para o tipo Person que considere duas pessoas iguais se essas possuírem o mesmo nome.
data Person
  = Person {
      name :: String
    , age  :: Int
    }

instance Eq Person where
    (Person name _) == (Person name' _) = name == name'

-- Implemente uma instância de Show para Person de forma que o resultado da conversão para string de um valor de tipo Person exiba apenas o campo name deste registro.
instance Show Person where
    show (Person name _) = name