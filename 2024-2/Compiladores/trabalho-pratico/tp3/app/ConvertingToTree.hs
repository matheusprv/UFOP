-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022
module ConvertingToTree (showTree) where

import Data.Tree
import Syntax.Syntax

-- convertendo para Tree String a saida do parser recursivo

showTree :: Either String Prog -> IO ()
showTree (Right prog) = putStrLn $ drawTree (progToTree prog)
showTree (Left s) = print s

progToTree :: Prog -> Tree String
progToTree (Prog defs) = Node "Prog" (map defToTree defs)

defToTree :: Def -> Tree String
defToTree (DataDef dataDef) = Node "DataDef" [dataToTree dataDef]
defToTree (Func name params typesFunc cmds)
  = Node ("Func: " ++ name)
      [ maybe (Node "No Params" []) (Node "Params" . map paramToTree) params
      , maybe (Node "No Return Type" []) typesToTree typesFunc
      , Node "Commands" (map cmdToTree cmds)
      ]

-- convertendo um Data para Tree String

dataToTree :: Data -> Tree String
dataToTree (Data name decls) = Node ("Data: " ++ name) (map declToTree decls)

declToTree :: Decl -> Tree String
declToTree (Decl name typ) = Node ("Decl: " ++ name) [typeToTree typ]

typeToTree :: Type -> Tree String
typeToTree (TypeArray t) = Node "Array" [typeToTree t]
typeToTree (BType bt) = Node "BType" [btypeToTree bt]

typesToTree :: Types -> Tree String
typesToTree (Types firstType otherTypes) = Node "Types" (map typeToTree (firstType : otherTypes))

-- convertendo uma funcao para Tree String

paramToTree :: Param -> Tree String
paramToTree (Param name typ) = Node ("Param: " ++ name) [typeToTree typ]

btypeToTree :: BType -> Tree String
btypeToTree TInt = Node "TInt" []
btypeToTree TChar = Node "TChar" []
btypeToTree TBool = Node "TBool" []
btypeToTree TFloat = Node "TFloat" []
btypeToTree (TID ident) = Node ("TID: " ++ ident) []

cmdToTree :: Cmd -> Tree String
cmdToTree (CmdBlock cmds) = Node "CmdBlock" (map cmdToTree cmds)
cmdToTree (CmdIf expr cmd) = Node "If" [expToTree expr, cmdToTree cmd]
cmdToTree (CmdIfElse expr maybeCmd1 maybeCmd2) =
  Node "IfElse"
    [ expToTree expr
    , maybe (Node "No If Cmd" []) cmdToTree maybeCmd1
    , maybe (Node "No Else Cmd" []) cmdToTree maybeCmd2
    ]
cmdToTree (CmdIterate expr cmd) = Node "Iterate" [expToTree expr, cmdToTree cmd]
cmdToTree (CmdRead lvalue) = Node "Read" [lvalueToTree lvalue]
cmdToTree (CmdPrint expr) = Node "Print" [expToTree expr]
cmdToTree (CmdReturn expr exps) = Node "Return" (expToTree expr : map expToTree exps)
cmdToTree (CmdAssign lvalue expr) = Node "Assign" [lvalueToTree lvalue, expToTree expr]
cmdToTree (CmdDecl decl maybeExps) = Node "Decl" [declToTree decl, maybe (Node "No Exps" []) expToTree maybeExps]
cmdToTree (CmdFuncCall ident maybeExps maybelvs) =
  Node ("FuncCall: " ++ ident)
    [
      maybe (Node "No Exps" []) expsToTree maybeExps
    , maybe (Node "No LValues" []) lvaluesToTree maybelvs
    ]

lvaluesToTree :: LValues -> Tree String
lvaluesToTree (LValues firstlv otherslvs) = Node "LValues" (map lvalueToTree (firstlv : otherslvs))

lvalueToTree :: LValue -> Tree String
lvalueToTree (LID ident) = Node ("LID: " ++ ident) []
lvalueToTree (LID' ident lv') = Node ("LID: " ++ ident) [lvalue'ToTree lv']

lvalue'ToTree :: LValue' -> Tree String
lvalue'ToTree (LArray expr) = Node "Array" [expToTree expr]
lvalue'ToTree (LComp ident) = Node ("Comp: " ++ ident) []
lvalue'ToTree (LArray' expr lv') = Node "Array" [expToTree expr, lvalue'ToTree lv']
lvalue'ToTree (LComp' ident lv') = Node ("Comp: " ++ ident) [lvalue'ToTree lv']

expsToTree :: Exps -> Tree String
expsToTree (Exps firstExp otherExps) = Node "Exps" (map expToTree (firstExp : otherExps))

expToTree :: Exp -> Tree String
expToTree (exp1 :&&: exp2) = Node "And" [expToTree exp1, expToTree exp2]
expToTree (exp1 :<: exp2) = Node "Less Than" [expToTree exp1, expToTree exp2]
expToTree (exp1 :>: exp2) = Node "Greater Than" [expToTree exp1, expToTree exp2]
expToTree (exp1 :==: exp2) = Node "Equal" [expToTree exp1, expToTree exp2]
expToTree (exp1 :!=: exp2) = Node "Not Equal" [expToTree exp1, expToTree exp2]
expToTree (exp1 :+: exp2) = Node "Add" [expToTree exp1, expToTree exp2]
expToTree (exp1 :-: exp2) = Node "Subtract" [expToTree exp1, expToTree exp2]
expToTree (exp1 :*: exp2) = Node "Multiply" [expToTree exp1, expToTree exp2]
expToTree (exp1 :/: exp2) = Node "Divide" [expToTree exp1, expToTree exp2]
expToTree (exp1 :%: exp2) = Node "Mod" [expToTree exp1, expToTree exp2]
expToTree (EInt n) = Node ("Int: " ++ show n) []
expToTree (EFloat n) = Node ("Float: " ++ show n) []
expToTree (EBool b) = Node ("Bool: " ++ show b) []
expToTree (EChar c) = Node ("Char: " ++ show c) []
expToTree ENull = Node "Null" []
expToTree (ENeg expr) = Node "Neg" [expToTree expr]
expToTree (ENot expr) = Node "Not" [expToTree expr]
expToTree (ELValue lval) = Node "LValue" [lvalueToTree lval]
expToTree (EParen expr) = Node "Parentheses" [expToTree expr]
expToTree (ENew typ exps) = Node "New" (typeToTree typ : map expToTree exps)
expToTree (EFuncCall ident exps expr) 
  = Node ("FuncCall: " ++ ident) 
    [
      maybe (Node "No Exps" []) expsToTree exps
    , expToTree expr
    ]