module Documentation.DocStmt where

import Limp.Syntax.Syntax
import Control.Monad.State


type DotGen = State Int

nodeName :: DotGen String
nodeName = do
    n <- get
    modify (+1)
    return $ "n" ++ show n


flowBlock :: Block -> DotGen (String, String, [String])
flowBlock (Block stmts) = flowStmts $ filterItemStmt stmts


flowStmts :: [Stmt] -> DotGen (String, String, [String])
flowStmts [] = do
    n <- nodeName
    return (n, n, [n ++ " [label=\"\", width=0.2, shape=circle];"])
flowStmts (x : xs) = do
    (entry1, exit1, lines1) <- flowStmt x
    (entry2, exit2, lines2) <- flowStmts xs
    return (entry1, exit2, lines1 ++ lines2 ++ [exit1 ++ "->" ++ entry2 ++ ";"])


flowStmt :: Stmt -> DotGen (String, String, [String])
flowStmt Skip = do
    n <- nodeName
    return (n, n, [n ++ " [label=\"skip\", shape=box];"])
flowStmt (v := e) = do
    n <- nodeName
    return (n, n, [n ++ " [label=\"" ++ unVar v ++ " := " ++ expString e ++ "\", shape=box];"])
flowStmt (Def ty v maybeExp) = do
    n <- nodeName
    let label = case maybeExp of
            Nothing -> "def " ++ typeString ty ++ " " ++ unVar v
            Just e  -> "def " ++ typeString ty ++ " " ++ unVar v ++ " = " ++ expString e
    return (n, n, [n ++ " [label=\"" ++ label ++ "\", shape=box];"])
flowStmt (Print e) = do
    n <- nodeName
    return (n, n, [n ++ " [label=\"print " ++ expString e ++ "\", shape=box];"])
flowStmt (SRead v) = do
    n <- nodeName
    return (n, n, [n ++ " [label=\"read " ++ unVar v ++ "\", shape=box];"])
flowStmt (If cond thenBlock elseBlock) = do
    condNode <- nodeName
    let condition = condNode ++ " [label=\"" ++ "if " ++ expString cond ++ "?" ++ "\", shape=diamond];"
    (thenEntry, thenExit, thenLines) <- flowBlock thenBlock
    (elseEntry, elseExit, elseLines) <- flowBlock elseBlock
    joinNode <- nodeName
    let joinLine = joinNode ++ " [label=\"\", shape=circle, width=0.2, fixedsize=true];"
    let edges = [ condNode ++ " -> " ++ thenEntry ++ " [label=\"true\"];"
                    , condNode ++ " -> " ++ elseEntry ++ " [label=\"false\"];"
                    , thenExit ++ " -> " ++ joinNode ++ ";"
                    , elseExit ++ " -> " ++ joinNode ++ ";"
                ]
    return (condNode, joinNode, [condition] ++ thenLines ++ elseLines ++ [joinLine] ++ edges)

flowStmt (While cond body) = do
    condNode <- nodeName
    let condition = condNode ++ " [label=\"" ++ "while " ++ expString cond ++ "?" ++ "\", shape=diamond];"
    (bodyEntry, bodyExit, bodyLines) <- flowBlock body
    exitNode <- nodeName
    let exitLine = exitNode ++ " [label=\"\", shape=circle, width=0.2, fixedsize=true];"
    let edges = [ condNode ++ " -> " ++ bodyEntry ++ " [label=\"true\"];"
              , condNode ++ " -> " ++ exitNode ++ " [label=\"false\"];"
              , bodyExit ++ " -> " ++ condNode ++ ";"
              ]
    return (condNode, exitNode, [condition] ++ bodyLines ++ [exitLine] ++ edges)


expString :: Exp -> String
expString (EValue v) = valueString v
expString (EVar v)   = unVar v
expString (a :+: b)  = "(" ++ expString a ++ " + " ++ expString b ++ ")"
expString (a :*: b)  = "(" ++ expString a ++ " * " ++ expString b ++ ")"
expString (a :-: b)  = "(" ++ expString a ++ " - " ++ expString b ++ ")"
expString (a :/: b)  = "(" ++ expString a ++ " / " ++ expString b ++ ")"
expString (a :==: b) = "(" ++ expString a ++ " == " ++ expString b ++ ")"
expString (a :<: b)  = "(" ++ expString a ++ " < " ++ expString b ++ ")"
expString (ENot a)   = "(!" ++ expString a ++ ")"
expString (a :&: b)  = "(" ++ expString a ++ " && " ++ expString b ++ ")"

valueString :: Value -> String
valueString (EInt n) = show n
valueString (EBool b) = if b then "true" else "false"

typeString :: Ty -> String
typeString TInt  = "int"
typeString TBool = "bool"
