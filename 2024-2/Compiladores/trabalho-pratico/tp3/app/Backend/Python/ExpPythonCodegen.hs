-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022

module Backend.Python.ExpPythonCodegen where

import Syntax.Syntax


-- top level code generation for expressions. 
-- code uses the grammar structure for printing 
-- code using the right precedence.

binOp :: String -> Exp -> Exp -> String
binOp op e1 e2 = d1 <> op <> d2
    where
        d1 = expCodeGen e1
        d2 = expCodeGen e2

expCodeGen :: Exp -> String
expCodeGen (e1 :&&: e2) = binOp " and " e1 e2

expCodeGen (e1 :==: e2) = binOp " == " e1 e2
expCodeGen (e1 :!=: e2) = binOp " != " e1 e2
expCodeGen (e1 :<: e2)  = binOp " < " e1 e2
expCodeGen (e1 :>: e2)  = binOp " > " e1 e2

expCodeGen (e1 :+: e2) = binOp " + " e1 e2
expCodeGen (e1 :-: e2) = binOp " - " e1 e2

expCodeGen (e1 :*: e2) = binOp " * " e1 e2
expCodeGen (e1 :/: e2) = binOp " / " e1 e2
expCodeGen (e1 :%: e2) = binOp " % " e1 e2

expCodeGen (ENot e) = "not(" <> expCodeGen e <> ")"
expCodeGen (ENeg e) = "-" <> expCodeGen e


expCodeGen (EBool x) = if x then "True" else "False"
expCodeGen ENull = "None"
expCodeGen (EInt x) = show x
expCodeGen (EFloat x) = show x
expCodeGen (EChar x) = "\"" ++ x : "\""

expCodeGen (ELValue lvalue) = lvalueCodeGen lvalue

expCodeGen (EParen e) = "(" ++ expCodeGen e ++ ")"

expCodeGen (ENew _ []) = "[]"  
expCodeGen (ENew ty [x]) = 
    "[" ++ defaultValue ty ++ " for _ in range ("++ expCodeGen x ++")]"
expCodeGen (ENew ty (x : xs)) = 
    "[" ++ expCodeGen (ENew ty xs) ++ " for _ in range ("++ expCodeGen x ++")]" 


expCodeGen (EFuncCall ident mExps expr) = 
    ident ++ "(" ++ funcCallParams mExps ++ ")" ++ "[" ++ expCodeGen expr ++ "]"


funcCallParams :: Maybe Exps -> String
funcCallParams Nothing = ""
funcCallParams (Just (Exps x xs)) = foldr step "" (x : xs)
    where 
        step e acc = 
            if null acc then expCodeGen e
            else expCodeGen e ++ ", " ++ acc


defaultValue :: Type -> String            
defaultValue (BType TInt) = "0"
defaultValue (BType TFloat) = "0.0"
defaultValue (BType TChar) = "\"\""
defaultValue (BType TBool) = "False"
defaultValue (BType (TID ident)) = ident ++ "()" 
defaultValue (TypeArray ty) = defaultValue ty


lvalueCodeGen :: LValue -> String
lvalueCodeGen (LID ident) = ident
lvalueCodeGen (LID' ident lvalue') = ident ++ lvalueLinhaCodeGen lvalue'

lvalueLinhaCodeGen :: LValue' -> String
lvalueLinhaCodeGen (LArray expr) = "["++ expCodeGen expr ++"]"
lvalueLinhaCodeGen (LComp ident) = "." ++ ident
lvalueLinhaCodeGen (LArray' expr lvalue') = "["++ expCodeGen expr ++"]" ++ lvalueLinhaCodeGen lvalue'
lvalueLinhaCodeGen (LComp' ident lvalue') =  "." ++ ident ++ lvalueLinhaCodeGen lvalue'
