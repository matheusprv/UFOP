{-# LANGUAGE TypeSynonymInstances, FlexibleInstances #-}

type Name = String
--newtype Name = Name String deriving (Eq, Ord, Show)

data VMState = VMState {
    pc :: Int,
    stack :: [Int],
    memory :: [(Name, Int)]
} deriving (Eq, Ord, Show)

data Instr
  = IPush Int
  | IVar Name
  | ISet Name
  | IAdd
  | ISub
  | IJump Int
  | IJumpNeq Int
  | IJumpEq Int
  | IHalt
  deriving (Eq, Ord, Show)

-- instr :: VMState -> Instr -> VMState
-- instr (VMState pc stack memory) instrucao = execInstr (VMState (pc+1) stack memory) instrucao

execInstr :: VMState -> Instr -> VMState
execInstr vm@(VMState pc stack memory) instr = executar vm instr
    where 
        executar vm instr = case instr of 
            vm (IPush x) -> push x vm
            vm (IVar x) -> lookMemory x vm
            vm (ISet x) -> setMemory x vm
            vm (IAdd) -> stackOp (\x y -> x + y) vm
            vm (ISub) -> stackOp (\x y -> x - y) vm
            -- execInstr vm (IJump Int) = 
            -- execInstr vm (IJumpNeq Int) = 
            -- execInstr vm (IJumpEq Int) = 
            -- execInstr vm (IHalt) = 


vm :: VMState
--vm = VMState 5 [1..10] [(Name "a", 1), (Name "b", 2), (Name "c", 3), (Name"d", 4)]
vm = VMState 0 [1..10] [("a", 1), ("b", 2), ("c", 3), ("d", 4)]

push :: Int -> VMState -> VMState
push instr (VMState pc stack memory) = VMState pc (instr : stack) memory  

procuraVariavel :: Name -> [(Name, Int)] -> Maybe (Name , Int)
procuraVariavel _ [] = Nothing
procuraVariavel nomeVar ((nome, valor) : xs) 
    | nomeVar == nome = Just (nome, valor)
    | otherwise = procuraVariavel nomeVar xs


lookMemory :: Name -> VMState -> VMState
lookMemory var vm@(VMState pc stack memory) = pilha 
    where 
        pilha = case procuraVariavel var memory of
                    Nothing -> vm
                    Just (_, x) -> push x vm

-- lookMemory (Name "d")  vm
--setMemory (Name "d") vm
setMemory:: Name -> VMState -> VMState
setMemory var vm@(VMState pc (top : xs) memory) = VMState pc (top : xs) (foldr steps [] memory)
    where
        steps variavel@(nomeVar, _) ac 
            | nomeVar == var = (nomeVar, top) : ac 
            | otherwise = variavel : ac

stackOp :: (Int -> Int -> Int) -> VMState -> VMState
stackOp op st = push (resultadoOperacao st) st 
    where 
        resultadoOperacao (VMState _ (x : x' : _) _) = op x x'

