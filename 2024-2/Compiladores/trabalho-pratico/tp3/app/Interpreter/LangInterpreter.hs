-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022
{-# LANGUAGE LambdaCase #-}

module Interpreter.LangInterpreter where

import Data.Char (isDigit)
import Data.List (union)
import Syntax.Syntax

data Value
  = VBool Bool
  | VNull
  | VInt Int
  | VFloat Float
  | VChar Char
  | VData [Decl]
  | VFunc (Maybe [Param]) (Maybe Types) [Cmd]
  | VArray [Value]
  | VObj [(ID, Value)]
  deriving (Eq, Ord, Show)

type Var = ID

data Env =
  Env { memory :: [(Var, Value)],
        retorno :: Maybe [Value] }

-- type Env = [(Var, Value)]

interpProgram :: Prog -> IO Env
interpProgram (Prog defs) =
  fst <$> interpDefs (Env {memory=[], retorno=Nothing}) defs

interpDefs :: Env -> [Def] -> IO (Env, [Var])
interpDefs env defs =
  do
    (env1, vs) <- interpListDefs env defs
    return (removeVars vs env1, [])

interpListDefs :: Env -> [Def] -> IO (Env, [Var])
interpListDefs env [] = return (env, [])
interpListDefs env (def : defs) =
  do
    (env1, vs) <- case def of
      DataDef d -> interpData env d
      Func ident mParams mRet cmds -> interpFunc env ident mParams mRet cmds
    (env2, vss) <- interpListDefs env1 defs
    return (env2, vs `union` vss)

interpData :: Env -> Data -> IO (Env, [Var])
interpData env (Data ident decls) = return (insertVal ident dataVal env, [ident])
  where
    dataVal = VData decls

-- Se a funcao for a main, executa o bloco de comandos, caso contrario coloca ela no ambiente
-- A main deve ser a ultima funcao declarada no codigo
interpFunc :: Env -> ID -> Maybe [Param] -> Maybe Types -> [Cmd] -> IO (Env, [Var])
interpFunc env ident mParams mRet cmds =
  if ident == "main"
    then do
      (env1, vs) <- interpBlockCmd env cmds
      return (insertVal ident funcVal env1, ident : vs)
    else
      return (insertVal ident funcVal env, [ident])
  where
    funcVal = VFunc mParams mRet cmds

interpBlockCmd :: Env -> [Cmd] -> IO (Env, [Var])
interpBlockCmd env [] = return (env, [])
interpBlockCmd env (c : cs) = do
  (env1, vs) <- interpCmd env c
  case retorno env1 of
    Nothing -> do
      (env2, vss) <- interpBlockCmd env1 cs
      return (removeVars (vs `union` vss) env2, [])
    Just _ -> return (removeVars vs env1, [])

-- Expression
showType :: Value -> String
showType (VInt _)   = "Int"
showType (VFloat _) = "Float"
showType (VChar _)  = "Char"
showType (VBool _)  = "Bool"
showType VNull = "null"
showType _ = "OTHER_TYPE"

(.&&.) :: Value -> Value -> Value
(VBool b1) .&&. (VBool b2) = VBool (b1 && b2)
x .&&. y = error ("Type error in &&: " ++ showType x ++ " && " ++ showType y)

(.<.) :: Value -> Value -> Value
(VInt b1) .<. (VInt b2) = VBool (b1 < b2)
(VFloat b1) .<. (VFloat b2) = VBool (b1 < b2)
(VFloat b1) .<. (VInt b2) = VBool (b1 < fromIntegral b2)
(VInt b1) .<. (VFloat b2) = VBool (fromIntegral b1 < b2)
(VChar b1) .<. (VChar b2) = VBool (b1 < b2)
x .<. y = error ("Type error in <: " ++ showType x ++ " < " ++ showType y)

(.>.) :: Value -> Value -> Value
(VInt b1) .>. (VInt b2) = VBool (b1 > b2)
(VFloat b1) .>. (VFloat b2) = VBool (b1 > b2)
(VFloat b1) .>. (VInt b2) = VBool (b1 > fromIntegral b2)
(VInt b1) .>. (VFloat b2) = VBool (fromIntegral b1 > b2)
(VChar b1) .>. (VChar b2) = VBool (b1 > b2)
x .>. y = error ("Type error in >: " ++ showType x ++ " > " ++ showType y)


(.==.) :: Value -> Value -> Value
(VInt b1) .==. (VInt b2) = VBool (b1 == b2)
(VFloat b1) .==. (VFloat b2) = VBool (b1 == b2)
(VFloat b1) .==. (VInt b2) = VBool (b1 == fromIntegral b2)
(VInt b1) .==. (VFloat b2) = VBool (fromIntegral b1 == b2)
(VChar b1) .==. (VChar b2) = VBool (b1 == b2)
(VBool b1) .==. (VBool b2) = VBool (b1 == b2)
VNull .==. VNull = VBool True
_ .==. VNull = VBool False
VNull .==. _ = VBool False
x .==. y = error ("Type error in ==: " ++ showType x ++ " == " ++ showType y)


(.!=.) :: Value -> Value -> Value
(VInt b1) .!=. (VInt b2) = VBool (b1 /= b2)
(VFloat b1) .!=. (VFloat b2) = VBool (b1 /= b2)
(VFloat b1) .!=. (VInt b2) = VBool (b1 /= fromIntegral b2)
(VInt b1) .!=. (VFloat b2) = VBool (fromIntegral b1 /= b2)
(VChar b1) .!=. (VChar b2) = VBool (b1 /= b2)
(VBool b1) .!=. (VBool b2) = VBool (b1 /= b2)
VNull .!=. VNull = VBool False
_ .!=. VNull = VBool True
VNull .!=. _ = VBool True
x .!=. y = error ("Type error in !=: " ++ showType x ++ " != " ++ showType y)

(.+.) :: Value -> Value -> Value
(VInt n) .+. (VInt m) = VInt (n + m)
(VFloat n) .+. (VFloat m) = VFloat (n + m)
(VInt n) .+. (VFloat m) = VFloat (fromIntegral n + m)
(VFloat n) .+. (VInt m) = VFloat (n + fromIntegral m)
x .+. y = error ("Type error in +: " ++ showType x ++ " + " ++ showType y)

(.-.) :: Value -> Value -> Value
(VInt n) .-. (VInt m) = VInt (n - m)
(VFloat n) .-. (VFloat m) = VFloat (n - m)
(VInt n) .-. (VFloat m) = VFloat (fromIntegral n - m)
(VFloat n) .-. (VInt m) = VFloat (n - fromIntegral m)
x .-. y = error ("Type error in -: " ++ showType x ++ " - " ++ showType y)

(.*.) :: Value -> Value -> Value
(VInt n) .*. (VInt m) = VInt (n * m)
(VFloat n) .*. (VFloat m) = VFloat (n * m)
(VInt n) .*. (VFloat m) = VFloat (fromIntegral n * m)
(VFloat n) .*. (VInt m) = VFloat (n * fromIntegral m)
x .*. y = error ("Type error in *: " ++ showType x ++ " * " ++ showType y)


(./.) :: Value -> Value -> Value
(VInt n) ./. (VInt m) = VInt (round $ fromIntegral n / fromIntegral m)
(VFloat n) ./. (VFloat m) = VFloat (n / m)
(VInt n) ./. (VFloat m) = VFloat (fromIntegral n / m)
(VFloat n) ./. (VInt m) = VFloat (n / fromIntegral m)
x ./. y = error ("Type error in /: " ++ showType x ++ " / " ++ showType y)


(.%.) :: Value -> Value -> Value
(VInt n) .%. (VInt m) = VInt (n `mod` m)
x .%. y = error ("Type error in %: " ++ showType x ++ " % " ++ showType y)


interpBinOp :: Env -> (Value -> Value -> Value) -> Exp -> Exp -> IO Value
interpBinOp env f e1 e2 =
  do
    v1 <- interpExp env e1
    v2 <- interpExp env e2
    return (f v1 v2)

interpNot :: Env -> Exp -> IO Value
interpNot env (ENot e) = do
  v1 <- interpExp env e
  case v1 of
    (VBool b) -> return (VBool (not b))
    _ -> error "type error!"
interpNot _ _ = error "type error!"

interpNeg :: Env -> Exp -> IO Value
interpNeg env (ENeg e) = do
  v1 <- interpExp env e
  case v1 of
    (VInt v) -> return (VInt (-v))
    (VFloat v) -> return (VFloat (-v))
    _ -> error "type error on interpNeg!"
interpNeg _ _ = error "type error on interpNeg!"

accessArray :: [Value] -> [Int] -> Value
accessArray [] _ = error "Array vazio."
accessArray _ [] = error "Posições não especificadas para acessar o array."
accessArray arr (i : iss)
  | i < 0 || i >= length arr = error "Invalid index."
  | otherwise = 
    case arr !! i of
      VArray subList -> accessArray subList iss
      val ->
        if null iss
          then val
          else error "Há menos dimensões no array que o que foi tentado acessar."

createArray :: Type -> [Int] -> Value
createArray _ []        = error "Dimensão do vetor vazia"
createArray ty [x]      = VArray (replicate x (defaultValue (Decl " " ty) Env {memory=[], retorno=Nothing}))
createArray ty (x : xs) = VArray (replicate x (createArray ty xs))

-- !Fazer pro caso de ser array
accessAttributes :: LValue' -> [(ID, Value)] -> Value
accessAttributes (LComp attr) attributes = 
  case lookup attr attributes of
    Just value -> value
    Nothing -> error "Esse atributo não existe."
accessAttributes (LComp' attr lval') attributes = 
  case lookup attr attributes of
    Just (VObj nAttributes) -> accessAttributes lval' nAttributes -- caso esse atributo seja um outro objeto
    Just _ -> -- caso esse atributo nao seja um outro objeto, logo lval' so pode ser uma posicao de array ou esta errado
      case lval' of
        (LArray _) -> undefined -- accessAttributes lval' faltaAq
        (LArray' _ _) -> undefined -- accessAttributes lval' faltaAq
        _ -> error "Esse campo não é um objeto, portanto não é possível acessar um atributo do mesmo."
    Nothing -> error "Esse atributo não existe."
accessAttributes (LArray _) _ = undefined
accessAttributes (LArray' _ _) _ = undefined

interpExp :: Env -> Exp -> IO Value
interpExp env (ELValue (LID ident)) =
  case lookup ident (memory env) of
    Just val -> return val
    Nothing -> error "Undefined variable"

-- ! Fazer caso seja um array ou uma composicao
interpExp env (ELValue (LID' ident (LArray e))) = 
  case lookup ident (memory env) of
    Just (VArray arr) -> do
      pos <- interpExp env e
      case pos of
        (VInt n) -> return $ arr !! n
        _ -> error "A posição de um vetor deve ser um valor inteiro."
    Just _ -> error "Não é um Array"
    Nothing -> error "Undefined variable"

interpExp env (ELValue (LID' ident larray@(LArray' _ _))) = do
  indexes <- listOfIndexes env larray
  case lookup ident (memory env) of
    Just (VArray arr) -> return (accessArray arr indexes)
    Just _ -> error "Não é um Array"
    Nothing -> error "Undefined variable"

interpExp env (ELValue (LID' ident lcomp)) =
  case lookup ident (memory env) of
    Just (VObj attributes) -> return $ accessAttributes lcomp attributes
    Just _ -> error "Não é um objeto"
    Nothing -> error "Undefined variable"

interpExp env (e1 :&&: e2) = interpBinOp env (.&&.) e1 e2
interpExp env (e1 :>: e2)  = interpBinOp env (.>.) e1 e2
interpExp env (e1 :<: e2)  = interpBinOp env (.<.) e1 e2
interpExp env (e1 :==: e2) = interpBinOp env (.==.) e1 e2
interpExp env (e1 :!=: e2) = interpBinOp env (.!=.) e1 e2
interpExp env (e1 :+: e2)  = interpBinOp env (.+.) e1 e2
interpExp env (e1 :-: e2)  = interpBinOp env (.-.) e1 e2
interpExp env (e1 :*: e2)  = interpBinOp env (.*.) e1 e2
interpExp env (e1 :/: e2)  = interpBinOp env (./.) e1 e2
interpExp env (e1 :%: e2)  = interpBinOp env (.%.) e1 e2
interpExp env (ENot e) = interpNot env (ENot e)
interpExp env (ENeg e) = interpNeg env (ENeg e)
interpExp _ (EBool b) = return (VBool b)
interpExp _ ENull = return VNull
interpExp _ (EInt b) = return (VInt b)
interpExp _ (EFloat b) = return (VFloat b)
interpExp _ (EChar b) = return (VChar b)
interpExp env (EParen e) = interpExp env e
interpExp env (ENew ty dims) = do
  sizes <- mapM (\e -> do
                    v <- interpExp env e
                    case v of
                      VInt n -> return n
                      _ -> error "Dimension size must be an integer"
                ) dims
  return $ createArray ty sizes
interpExp env (EFuncCall ident mExps expr) = do
  let env2 = justFuncAndData env
  case lookup ident (memory env2) of
    Just (VFunc mParams mTypes cmds) -> do
      env' <- case mExps of
        Just (Exps fstExp exps) -> insertParams (fstExp : exps) mParams env2 env
        Nothing                 -> return env2
      (envFinal, _) <- interpBlockCmd env' cmds
      case getRetorno (retorno envFinal) of
        [] -> case mTypes of
          Just _ -> error ("A função "++ ident ++" deveria ter retorno, mas não está retornando nada.")
          Nothing -> return VNull
        values -> case mTypes of
          Nothing -> error ("A função "++ ident ++" não deveria retornar nada, pois não foram definidos tipos de retorno.")
          Just (Types t ts) -> if length (t:ts) == length values
            then do
              pos <- interpExp env expr
              return (values !! getPosRetorno pos)
            else error ("Não foi definido o mesmo número de retornos que a função"++ ident ++" está retornando.")
    Just _ -> error "Não é uma função"
    Nothing -> error ("Undefined function " ++ ident) 

justFuncAndData :: Env -> Env
justFuncAndData env = env {memory = [(x, v) | (x, v) <- memory env, isVFuncOrVData v]}
  where
    isVFuncOrVData VFunc {} = True
    isVFuncOrVData VData {} = True
    isVFuncOrVData _        = False

getPosRetorno :: Value -> Int
getPosRetorno (VInt pos) = pos
getPosRetorno _ = 0

getRetorno :: Maybe [Value] -> [Value]
getRetorno (Just values) = values
getRetorno Nothing = []

insertParams :: [Exp] -> Maybe [Param] -> Env -> Env -> IO Env
insertParams [] _ env _ = return env
insertParams _ (Just []) env _ = return env
insertParams (e : ess) (Just ((Param ident _) : pss)) newEnv originalEnv = 
  do
    v <- interpExp originalEnv e
    let env1 = insertVal ident v newEnv
    env2 <- insertParams ess (Just pss) env1 originalEnv
    return env1 {memory = memory env1 `union` memory env2}
insertParams _ Nothing _ _ = error "Error in params"

printValue :: Value -> IO ()
printValue (VInt n) = print n
printValue (VBool b) = print b
printValue (VChar c) = print c
printValue (VFloat f) = print f
printValue _ = print ""

readValue :: IO Value
readValue = do
    s <- getLine
    if all isDigit s then return (VInt (read s))
    else if isFloat s then return (VFloat (read s))
    else if s `elem` ["True", "False"] then return (VBool (read s))
    else if length s == 3 && head s == '\'' && last s == '\'' then return (VChar (s !! 1))
    else if s == "Null" then return VNull
    else error "type error"

isFloat :: String -> Bool
isFloat s =
  let parts = splitDot s
   in case parts of
        [intPart] -> all isDigit intPart
        [intPart, decPart] -> all isDigit intPart && all isDigit decPart
        _ -> False

splitDot :: String -> [String]
splitDot = splitOn '.'

splitOn :: Char -> String -> [String]
splitOn _ "" = [""]
splitOn delim (c : cs)
  | c == delim = "" : rest
  | otherwise = (c : head rest) : tail rest
  where
    rest = splitOn delim cs

insertVal :: Var -> Value -> Env -> Env
insertVal v val env = env {memory = (v, val) : memory env}

defaultValue :: Decl -> Env -> Value
defaultValue (Decl _ (BType TInt)) _ = VInt 0
defaultValue (Decl _ (BType TChar)) _ = VChar ' '
defaultValue (Decl _ (BType TBool)) _ = VBool False
defaultValue (Decl _ (BType TFloat)) _ = VFloat 0.0
defaultValue (Decl _ (BType (TID ident))) env =
  case lookup ident (memory env) of
    Just (VData decls) -> VObj (createObjectAttributs decls env)
    Just _ -> error "Não é um Data"
    Nothing -> error ("Tipo de "++ ident ++" não definido.")
defaultValue _ _ = VNull

createObjectAttributs :: [Decl] -> Env -> [(ID, Value)]
createObjectAttributs [] _ = []
createObjectAttributs (decl@(Decl ident _) : decls) env = 
  (ident, defaultValue decl env) : createObjectAttributs decls env

removeVars :: [Var] -> Env -> Env
removeVars vs env = env {memory = [(x, v) | (x, v) <- memory env, x `notElem` vs]}

interpCmd :: Env -> Cmd -> IO (Env, [Var])
interpCmd env (CmdBlock cmds) = interpBlockCmd env cmds
interpCmd env (CmdIf expr cmd) =
  do
    val <- interpExp env expr
    case val of
      VBool True -> interpCmd env cmd
      VBool False -> return (env, [])
      _ -> error "type error"
interpCmd env (CmdIfElse expr mCmd1 mCmd2) =
  do
    val <- interpExp env expr
    case val of
      VBool True -> maybe (return (env, [])) (interpCmd env) mCmd1
      VBool False -> maybe (return (env, [])) (interpCmd env) mCmd2
      _ -> error "type error"
interpCmd env (CmdIterate expr cmd) =
  do
    val <- interpExp env expr
    case val of
      VInt 0 -> return (env, [])
      VInt n -> 
        if n < 0 then error "a condição do iterate deve ser >= 0" else
          do
            (env1, _) <- interpCmd env cmd
            (env', _) <- interpCmd env1 (CmdIterate (EInt (n-1)) cmd)
            return (env', [])
      _ -> error "type error"
interpCmd env (CmdRead lval) =
  do
    n <- readValue
    setValue lval n env
-- !Fazer os casos do lvalue ser um array ou uma composição

interpCmd env (CmdPrint expr) =
  do
    val <- interpExp env expr
    printValue val
    return (env, [])
interpCmd env (CmdReturn expr exps) =
  do
    val <- interpExp env expr
    vals <- mapM (interpExp env) exps
    return (env{retorno= Just (val:vals)}, [])
interpCmd env (CmdAssign lval expr) =
  do
    val <- interpExp env expr
    setValue lval val env
-- !Fazer os casos do lvalue ser um array ou uma composição 

interpCmd env (CmdDecl decl@(Decl ident _) mExp) =
  case mExp of
    Just expr -> do
      val <- interpExp env expr
      return (insertVal ident val env, [ident])
    Nothing -> return (insertVal ident (defaultValue decl env) env, [ident])

interpCmd env (CmdFuncCall ident mExps mVars) = do
  let env2 = justFuncAndData env
  case lookup ident (memory env) of
    Just (VFunc mParams mTypes cmds) -> do
      envForCmd <- case mExps of
        Just (Exps fstExp exps) -> insertParams (fstExp : exps) mParams env2 env
        Nothing                 -> return env2
      (envFinal, _) <- interpBlockCmd envForCmd cmds
      case getRetorno (retorno envFinal) of
        [] -> case mVars of
          Nothing -> case mTypes of
            Just _ -> error ("A função "++ ident ++" deveria ter retorno, mas não está retornando nada.")
            Nothing -> return (env, [])
          Just _  -> error "Não há retorno para atribuir às variáveis"
        values -> case mTypes of
          Nothing -> error ("A função "++ ident ++" não deveria retornar nada, pois não foram definidos tipos de retorno.")
          Just (Types t ts) -> if length (t:ts) == length values
            then case mVars of
              Nothing -> return (env, [])
              Just (LValues v vs) -> do
                env' <- setReturnToVars values (v:vs) env
                return (env', [])
            else error ("Não foi definido o mesmo número de retornos que a função"++ ident ++" está retornando.")
    Just _ -> error "Não é uma função"
    Nothing -> error "Undefined function"


setValue :: LValue -> Value -> Env -> IO (Env, [Var])
setValue (LID ident) n env = return (insertVal ident n env, [])
-- criar funcao para retorna uma lista com as posicoes que quero acessar do array
-- criar funcao para dar um lookup no array, alterar a posicao certa da lista e retornar ela
-- fazer um insertVal com essa nova lista do array
setValue (LID' ident lcomp@(LComp _)) n env = return (insertVal ident (VObj (updateObj ident env lcomp n)) env, [])
setValue (LID' ident lcomp'@(LComp' _ _)) n env = return (insertVal ident (VObj (updateObj ident env lcomp' n)) env, [])
setValue (LID' ident larray) n env = do
  ps <- listOfIndexes env larray
  return (insertVal ident (VArray (updateArray ident env ps n)) env, [])

-- !Fazer caso que lvalue' seja array
updateObj :: Var -> Env -> LValue' -> Value -> [(ID, Value)]
updateObj ident env lval n =
  case lookup ident (memory env) of
    Just (VObj attributes) -> case lval of
      LComp attr -> case lookup attr attributes of
        Just _ -> changeAttribute attr n attributes
        Nothing -> error ("Atributo "++ ident ++ "não existe.")
      LComp' attr lval' -> case lookup attr attributes of
        Just (VObj nAttributes) -> changeAttribute attr (VObj (updateObjAttribute lval' n nAttributes)) attributes
        Just _ -> error ("Esse atributo "++ ident ++" não é um objeto.")
        Nothing -> error ("Atributo"++ ident ++" não existe.")
      _ -> error ("Função "++ ident ++" feita para atualizar apenas objetos.")
    Just _ -> error "Não é um objeto"
    Nothing -> error ("Undefined variable " ++ ident)

changeAttribute :: ID -> Value -> [(ID, Value)] -> [(ID, Value)]
changeAttribute _ _ [] = []
changeAttribute attr new (x@(ident, _) : xs)
    | ident == attr = (attr, new) : xs
    | otherwise   = x : changeAttribute attr new xs

-- atualiza um atributo de um objeto que também é um objeto
updateObjAttribute :: LValue' -> Value -> [(ID, Value)] -> [(ID, Value)]
updateObjAttribute (LComp attr) n attributes = changeAttribute attr n attributes
updateObjAttribute (LComp' attr lval') n attributes =
  case lookup attr attributes of 
    Just (VObj nAttributes) -> changeAttribute attr (VObj (updateObjAttribute lval' n nAttributes)) attributes
    Just _ -> error "Esse atributo não é um objeto."
    Nothing -> error "Atributo não existe."
updateObjAttribute _ _ _ = error "Função feita para atualizar apenas objetos."

-- !Fazer os casos do lvalue ser um array ou uma composição
setReturnToVars :: [Value] -> [LValue] -> Env -> IO Env
setReturnToVars [] (_ : _) _ = error "Há mais variáveis do que retornos."
setReturnToVars _ [] env = return env
setReturnToVars (val:vals) ((LID ident):vars) env = setReturnToVars vals vars (insertVal ident val env)
setReturnToVars (val:vals) ((LID' ident lcomp@(LComp _)):vars) env = setReturnToVars vals vars (insertVal ident (VObj (updateObj ident env lcomp val)) env)
setReturnToVars (val:vals) ((LID' ident lcomp'@(LComp' _ _)):vars) env = setReturnToVars vals vars (insertVal ident (VObj (updateObj ident env lcomp' val)) env)
setReturnToVars (val:vals) ((LID' ident larray):vars) env = do
  ps <- listOfIndexes env larray
  setReturnToVars vals vars (insertVal ident (VArray (updateArray ident env ps val)) env)

updateArray :: Var -> Env -> [Int] -> Value -> [Value]
updateArray ident env posicoes newValue =
  case lookup ident (memory env) of
    Just (VArray arr) -> loopThroughArray arr posicoes newValue

    Just _ -> error "Essa variável não é um Array."

    _ -> error "Array indefinido."

loopThroughArray :: [Value] -> [Int] -> Value -> [Value]
loopThroughArray values [] _ = values
loopThroughArray values (p : ps) newVal
  | p < 0 || p >= length values = error "Invalid index."  -- Indice invalido
  | otherwise =
      case values !! p of
        VArray subList ->
          let updatedSubList = loopThroughArray subList ps newVal
              (before, _:after) = splitAt p values
          in before ++ [VArray updatedSubList] ++ after
        _ -> 
          if null ps
            then let (before, _:after) = splitAt p values
                 in before ++ [newVal] ++ after
            else error "Há menos dimensões no array que o que foi tentado acessar."

-- ! Fazer para caso seja composicao
listOfIndexes :: Env -> LValue' -> IO [Int]
listOfIndexes env (LArray e) = do
  pos <- interpExp env e
  case pos of
    VInt p -> return [p]
    _ -> error "Posição inválida. Deve ser sempre um valor inteiro."
listOfIndexes env (LArray' e lvalue') = do
  pos <- interpExp env e
  case pos of
    VInt p -> do
      ps <- listOfIndexes env lvalue'
      return (p : ps)
    _ -> error "Posição inválida. Deve ser sempre um valor inteiro."
listOfIndexes _ (LComp _) = undefined
  -- case lookup ident (memory env) of
  --   Just (VInt i) -> [i]
  --   Just _ -> error "Posicao do vetor inválida"
  --   Nothing -> error "Posicao do vetor inválida"
listOfIndexes _ (LComp' _ _) = undefined
  -- case lookup ident (memory env) of
  --   Just (VInt i) -> [i] ++ listOfIndexes env lvalue'
  --   Just _ -> error "Posicao do vetor inválida"
  --   Nothing -> error "Posicao do vetor inválida"