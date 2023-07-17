data Toy a b = Output a b | Bell b | Done

instance Functor (Toy a) where
    fmap _ Done = Done
    fmap f (Bell b) = Bell (f b)
    fmap f (Output a b) = Output a (f b)

data Tree = Leaf | Node Int Tree Tree