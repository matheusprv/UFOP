-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022

module Frontend.Semantics.Basics where

import Syntax.Syntax


-- typing context
type Var = ID

-- data TypeVarNOps = TypeVarNOps {
--   tyVar :: Type,
--   tyOps :: [(Type, Type, Type)]
-- }

data Ctx = Ctx {
  vars :: [(Var, Type)],            -- gama
  funcs :: [(ID, [Param], [Type])], -- theta
  registros :: [(ID, [Decl])]       -- delta
}

-- type of errors
type Expected = Type
type Found = Type

data Error
  = IncompatibleTypes Expected Found
  | UndefinedVariable Var
  | UndefinedFunction ID
  | UndefinedRegister ID
  | ArgumentWithoutValue ID
  | ThereIsNoArgument
  | RepeatedDeclaration ID
  | DifferentNumberOfReturns

pType :: Type -> String 
pType (BType TInt) = "Int"
pType (BType TBool) = "Bool"
pType (BType TChar) = "Char"
pType (BType TFloat) = "Float"
pType (BType (TID ident)) = "data " ++ ident
pType (TypeArray ty) = pType ty ++ " Array"

instance Show Error where 
  show (IncompatibleTypes ex fd)
    = unlines [ "Type error:"
              , "Expected:" ++ pType ex 
              , "Found:" ++ pType fd]
  show (UndefinedVariable v) = "Undefined variable: " ++ v
  show (UndefinedFunction f) = "Undefined function: " ++ f
  show (UndefinedRegister r) = "Undefined register: " ++ r
  show (ArgumentWithoutValue ident) = "Argument " ++ ident ++ " didn't received any value."
  show ThereIsNoArgument = "There is no argument in the function to receive any value."
  show (RepeatedDeclaration ident) = "Already exists a declaration " ++ ident
  show DifferentNumberOfReturns = "The numbers of returns in the function is different of its declaration."

undefinedVar :: Var -> Check a
undefinedVar = Left . wrap . UndefinedVariable
  where
    wrap x = [x]

undefinedFunction :: Var -> Check a
undefinedFunction = Left . wrap . UndefinedFunction
  where
    wrap x = [x]
    
undefinedRegister :: Var -> Check a
undefinedRegister = Left . wrap . UndefinedRegister
  where
    wrap x = [x]

incompatibleTypes :: Expected -> Found -> Check a
incompatibleTypes e f
  = Left [IncompatibleTypes e f]

-- type of type checking functions
type Check a = Either [Error] a