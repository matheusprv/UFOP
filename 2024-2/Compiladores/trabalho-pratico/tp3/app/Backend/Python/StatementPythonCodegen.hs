-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022

module Backend.Python.StatementPythonCodegen (programCodegen) where

import Backend.Python.ExpPythonCodegen
import Syntax.Syntax

-- Salvar mapa de variaveis
newtype Env = Env [(ID, Type)] deriving (Show)

insertVal :: Env -> ID -> Type -> Env
insertVal (Env xs) ident ty = Env ((ident, ty) : xs)


-- identation level
type Level = Int

-- top code level code generation function
programCodegen :: Prog -> String
programCodegen (Prog defs) = unlines $ map defsCodeGen defs

defsCodeGen :: Def -> String
defsCodeGen (DataDef d) = dataCodeGen d
defsCodeGen func@(Func {}) = snd $ functionCodeGen (Env []) func


---

dataCodeGen :: Data -> String
dataCodeGen (Data ident decls) = unlines [
        "class " ++ ident ++ ":",
        nest tab "def __init__(self" ++ declTypes decls ++ "):",
        mkDefaultConstructor (tab*2) decls
    ]


declTypes :: [Decl] -> String
declTypes [] = ""
declTypes xs = ", " ++ foldr step "" xs
    where
        step (Decl ident ty) acc =
            if null acc then concat [ident, "=", defaultValueObject ty]
            else concat [ident, "=", defaultValueObject ty] ++ ", " ++ acc

mkDefaultConstructor :: Level -> [Decl] -> String
mkDefaultConstructor d [] = nest d "pass"
mkDefaultConstructor d decls = foldr step "" decls
    where
        step (Decl ident _) acc = (nest d "self." ++ ident ++ " = " ++ ident ++ "\n") ++ acc

defaultValueObject :: Type -> String            
defaultValueObject (BType TInt) = "0"
defaultValueObject (BType TFloat) = "0.0"
defaultValueObject (BType TChar) = "\"\""
defaultValueObject (BType TBool) = "False"
defaultValueObject (BType (TID _)) = "None"
defaultValueObject (TypeArray ty) = defaultValue ty

---

functionCodeGen :: Env -> Def -> (Env, String)
functionCodeGen env (Func ident mParams _ cmds)
    | ident == "main" = 
        let (newEnv, cmdsStr) = foldl step (env, "") cmds
            step (e, acc) cmd = let (e', str) = cmdCodeGen tab e cmd in (e', acc ++ str ++ "\n")
        in (newEnv, "if __name__ == '__main__':\n" ++ cmdsStr)
    | otherwise =
        let (newEnv, cmdsStr) = foldl step (env, "") cmds
            step (e, acc) cmd = let (e', str) = cmdCodeGen tab e cmd in (e', acc ++ str ++ "\n")
        in (newEnv, "def " ++ ident ++ "(" ++ functionParams mParams ++ "):\n" ++ cmdsStr)
functionCodeGen _ _ = error "functionCodeGen: data definition encontrada, esperado função"



functionParams :: Maybe [Param] -> String
functionParams Nothing = ""
functionParams (Just params) = foldr step "" params
    where
        step (Param ident _) acc =
            if null acc then ident 
            else ident ++ ", " ++ acc

---

cmdCodeGen :: Level -> Env -> Cmd -> (Env, String)
cmdCodeGen d env (CmdBlock cmds) = 
    let (newEnv, cmdsStrs) = foldl step (env, []) cmds
        step (e, acc) cmd = let (e', str) = cmdCodeGen d e cmd in (e', acc ++ [str])
    in (newEnv, unlines cmdsStrs)
cmdCodeGen d env (CmdIf expr cmd) = (
        env, 
        nest d $ unlines [
            "if " ++ expCodeGen expr ++ ":",
            snd $ cmdCodeGen (d + tab) env cmd
        ]
    )

cmdCodeGen d env (CmdIfElse expr mCmd1 mCmd2) = (
        env, 
        nest d $ unlines [
            "if " ++ expCodeGen expr ++ ":",
            handleMaybeCmd d env mCmd1,
            nest d "else:",
            handleMaybeCmd d env mCmd2
        ]
    )
cmdCodeGen d env (CmdIterate expr cmd) = (
        env, 
        nest d $ unlines [
            "for _ in range(" ++ expCodeGen expr ++ ") :",
            snd $ cmdCodeGen (d+tab) env cmd
        ]
    )
cmdCodeGen d env (CmdRead lvalue) = (
        env, 
        nest d $ lvalueCodeGen lvalue ++ " = " ++ handleLValueTypeRead lvalue env  ++ "(input())"
    )
cmdCodeGen d env (CmdPrint expr) = (
        env, 
        nest d $ "print("++ expCodeGen expr ++")"
    )

cmdCodeGen d env (CmdReturn expr []) = (
        env, 
        nest d $ "return " ++ expCodeGen expr ++ ", "
    )
cmdCodeGen d env (CmdReturn expr exprs) = (
        env, 
        nest d $ "return " ++ expCodeGen expr ++ unwords ( map (\x -> ", " ++ expCodeGen x) exprs)
    )

cmdCodeGen d env (CmdAssign lvalue expr) = (
        env, 
        nest d $ lvalueCodeGen lvalue ++ " = " ++ expCodeGen expr
    )

cmdCodeGen d env (CmdDecl (Decl ident ty) Nothing) = (
        insertVal env ident ty, 
        nest d $ ident ++ " = " ++ defaultValue ty
    )
cmdCodeGen d env (CmdDecl (Decl ident ty) (Just expr)) = (
        insertVal env ident ty, 
        nest d $ ident ++ " = " ++ expCodeGen expr
    )

cmdCodeGen d env (CmdFuncCall ident mExps mLvalues) =(
        env, 
        nest d $ assignReturns mLvalues ++ ident ++ "(" ++ funcCallParams mExps ++ ")"
    )


handleMaybeCmd :: Level -> Env -> Maybe Cmd -> String
handleMaybeCmd d _ Nothing = nest (d+tab) "pass"
handleMaybeCmd d env (Just cmd) = snd $ cmdCodeGen (d+tab) env cmd


assignReturns :: Maybe LValues -> String
assignReturns Nothing = ""
assignReturns (Just (LValues x xs)) = foldr step "" (x : xs) ++ " = "
    where
        step lv acc =
            if null acc then lvalueCodeGen lv
            else lvalueCodeGen lv ++ ", " ++ acc


handleLValueTypeRead :: LValue -> Env -> String
handleLValueTypeRead (LID ident) (Env env) =
    case lookup ident env of
        Just (BType ty) -> stringType (BType ty)
        Just ty@(TypeArray {}) -> stringType ty
        Nothing -> "eval"
handleLValueTypeRead (LID' ident _) (Env env) =
    case lookup ident env of
        Just (BType ty) -> stringType (BType ty)
        Just ty@(TypeArray {}) -> stringType ty
        Nothing -> "eval"


stringType :: Type -> String
stringType (TypeArray ty) = stringType ty 
stringType (BType TInt) = "int"
stringType (BType TFloat) = "float"
stringType (BType TChar) = "str"
stringType (BType TBool) = "eval"
stringType (BType (TID _)) = "eval"
    

-- nesting function 
tab :: Int
tab = 4

nest :: Int -> String -> String
nest d s = replicate d ' ' ++ s