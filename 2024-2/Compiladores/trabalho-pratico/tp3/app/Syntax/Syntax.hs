-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022

{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Use newtype instead of data" #-}

module Syntax.Syntax  where
type ID = String

data Prog
  = Prog [Def]
  deriving (Eq, Ord, Show)

data Data 
  = Data ID [Decl]
  deriving (Eq, Ord, Show)

data Def
  = DataDef Data
  | Func ID (Maybe [Param]) (Maybe Types) [Cmd]
  deriving (Eq, Ord, Show)

data Types
  = Types Type [Type]
  deriving (Eq, Ord, Show)

data Decl
  = Decl ID Type
  deriving (Eq, Ord, Show)

data Param
  = Param ID Type
  deriving (Eq, Ord, Show)

data Type
  = TypeArray Type
  | BType BType
  deriving (Eq, Ord, Show)

data BType
  = TInt
  | TChar
  | TBool
  | TFloat
  | TID ID
  deriving (Eq, Ord, Show)

data Cmd
  = CmdBlock [Cmd]
  | CmdIf Exp Cmd
  | CmdIfElse Exp (Maybe Cmd) (Maybe Cmd)
  | CmdIterate Exp Cmd
  | CmdRead LValue
  | CmdPrint Exp
  | CmdReturn Exp [Exp]
  | CmdAssign LValue Exp
  | CmdDecl Decl (Maybe Exp)
  | CmdFuncCall ID (Maybe Exps) (Maybe LValues)
  deriving (Eq, Ord, Show)

data LValues
  = LValues LValue [LValue]
  deriving (Eq, Ord, Show)

-- data LValue
-- --      w1
--   = LID ID
-- --                 y1  
--   | LArray LValue Exp
-- --               y2
--   | LComp LValue ID
--   deriving (Eq, Ord, Show)

-- without left recursion
data LValue
  = LID ID
  | LID' ID LValue'
  deriving (Eq, Ord, Show)

data LValue'
  = LArray Exp
  | LComp ID
  | LArray' Exp LValue'
  | LComp' ID LValue'
  deriving (Eq, Ord, Show)

data Exps
  = Exps Exp [Exp]
  deriving (Eq, Ord, Show)

data Exp
  = Exp :&&: Exp
  | Exp :<: Exp
  | Exp :>: Exp
  | Exp :==: Exp
  | Exp :!=: Exp
  | Exp :+: Exp
  | Exp :-: Exp
  | Exp :*: Exp
  | Exp :/: Exp
  | Exp :%: Exp
  | ENot Exp
  | ENeg Exp
  | EBool Bool
  | ENull
  | EInt Int
  | EFloat Float
  | EChar Char
  | ELValue LValue
  | EParen Exp
  | ENew Type [Exp]
  | EFuncCall ID (Maybe Exps) Exp
  deriving (Eq, Ord, Show)