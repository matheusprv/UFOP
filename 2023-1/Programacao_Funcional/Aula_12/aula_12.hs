import Prelude hiding (Maybe, Just , Nothing)

data Maybe a = Just a | Nothing deriving Show
data Tree a = Leaf | Node a (Tree a) (Tree a) deriving Show


instance Functor Maybe where
    fmap _ Nothing = Nothing
    fmap f (Just x) = Just (f x)

instance Functor Tree where
    fmap _ Leaf = Leaf
    fmap f (Node x l r) = Node (f x) (f <$> l) (f <$> r)

data Rose a = Rose a [Rose a]
    deriving (Eq, Ord, Show)

instance Functor Rose where
    --fmap f (Rose x xs) = Rose (f x) ((fmap f) <$> xs)
    fmap f (Rose x xs) = Rose (f x) ( fmap (fmap f) xs)

generateTree :: Tree Int
generateTree =  Node 32 (Node 15 (Node 14 Leaf Leaf) (Node 20 Leaf Leaf)) (Node 64 (Node 60 Leaf Leaf) (Node 65 Leaf Leaf))

generateTree2 :: Tree Int
generateTree2 =  Node 32 (Node 14 (Node 13 Leaf Leaf) Leaf) (Node 20 Leaf Leaf)

-- Applicative
instance Applicative Maybe where
    pure x = Just x
    Nothing  <*> _ = Nothing
    _ <*> Nothing  = Nothing
    (Just f) <*> (Just x) = Just (f x)


foo :: Maybe Int -> Maybe Int -> Maybe Int
foo x y = (+) <$> x <*> y


instance Applicative Tree where
    pure x = Node x Leaf Leaf
    Leaf <*> _ = Leaf
    _ <*> Leaf = Leaf
    (Node fx fl fr) <*> (Node x l r) = Node (fx x) (fl <*> l) (fr <*> r)


sumTrees :: Num a => Tree a -> Tree a -> Tree a
sumTrees tree1 tree2 = (+) <$> tree1 <*> tree2