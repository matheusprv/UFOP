-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022

module Frontend.Semantics.ExpTypeCheck where

import Syntax.Syntax
import Frontend.Semantics.Basics

-- type checking expressions

tcBinOp :: Ctx -> (Exp, Expected) -> (Exp, Expected) -> Expected -> Check Type
tcBinOp ctx (e1, t1) (e2, t2) ty
  = case (r1, r2) of
      (Right t1', Right t2') ->
         if t1' == t1 then
            if t2' == t2 then
               Right ty
            else incompatibleTypes t2 t2'
         else incompatibleTypes t1 t1'
      (Left err1, Left err2) -> Left (err1 ++ err2)
      (Left err1, _) -> Left err1
      (_, Left err2) -> Left err2
  where
    r1 = tcExp ctx e1
    r2 = tcExp ctx e2

tcBinOpNumerico :: Ctx -> Exp -> Exp -> Check Type
tcBinOpNumerico ctx e1 e2 = 
  case tcBinOp ctx (e1, BType TInt) (e2, BType TInt) (BType TInt) of
    Right ty -> Right ty
    Left err1 ->
      case tcBinOp ctx (e1, BType TFloat) (e2, BType TFloat) (BType TFloat) of
        Right ty -> Right ty
        Left err2 -> 
          case tcBinOp ctx (e1, BType TInt) (e2, BType TFloat) (BType TFloat) of
            Right ty -> Right ty
            Left err3 -> 
              case tcBinOp ctx (e1, BType TFloat) (e2, BType TInt) (BType TFloat) of
                Right ty -> Right ty
                Left err4 -> Left (err1 ++ err2 ++ err3 ++ err4)

tcBinOpComp :: Ctx -> Exp -> Exp -> Check Type
tcBinOpComp ctx e1 e2 = 
  case tcBinOp ctx (e1, BType TInt) (e2, BType TInt) (BType TBool) of
    Right ty -> Right ty
    Left err1 ->
      case tcBinOp ctx (e1, BType TFloat) (e2, BType TFloat) (BType TBool) of
        Right ty -> Right ty
        Left err2 -> 
          case tcBinOp ctx (e1, BType TChar) (e2, BType TChar) (BType TBool) of
            Right ty -> Right ty
            Left err3 -> 
              case tcBinOp ctx (e1, BType TFloat) (e2, BType TInt) (BType TBool) of
                Right ty -> Right ty
                Left err4 ->
                  case tcBinOp ctx (e1, BType TInt) (e2, BType TFloat) (BType TBool) of
                    Right ty -> Right ty
                    Left err5 -> 
                      case (s1, s2) of
                        (Right ty1, Right ty2) -> if ty1 == BType (TID "null") || ty2 == BType (TID "null")
                                                  then Right (BType TBool)
                                                  else Left (err1 ++ err2 ++ err3 ++ err4 ++ err5) 
                        (Left err1, Left err2) -> Left (err1 ++ err2)
                        (Left err1, _) -> Left err1
                        (_, Left err2) -> Left err2
                        where
                          s1 = tcExp ctx e1
                          s2 = tcExp ctx e2

tcBinOpCompGtLt :: Ctx -> Exp -> Exp -> Check Type
tcBinOpCompGtLt ctx e1 e2 = 
  case tcBinOp ctx (e1, BType TInt) (e2, BType TInt) (BType TBool) of
    Right ty -> Right ty
    Left err1 ->
      case tcBinOp ctx (e1, BType TFloat) (e2, BType TFloat) (BType TBool) of
        Right ty -> Right ty
        Left err2 -> 
          case tcBinOp ctx (e1, BType TChar) (e2, BType TChar) (BType TBool) of
            Right ty -> Right ty
            Left err3 -> 
              case tcBinOp ctx (e1, BType TFloat) (e2, BType TInt) (BType TBool) of
                Right ty -> Right ty
                Left err4 ->
                  case tcBinOp ctx (e1, BType TInt) (e2, BType TFloat) (BType TBool) of
                    Right ty -> Right ty
                    Left err5 -> Left (err1 ++ err2 ++ err3 ++ err4 ++ err5)

tcLValue :: Ctx -> LValue -> Check Type
tcLValue ctx (LID ident)
  = case lookup ident (vars ctx) of
      Just ty -> Right ty
      Nothing -> undefinedVar ident
tcLValue ctx (LID' ident lvalue)
  = case lookup ident (vars ctx) of
      Just ty ->
        case lvalue of
          (LArray ex) -> 
            case ty of
              TypeArray ty' ->
                case tcExp ctx ex of
                  Right (BType TInt) -> Right ty'
                  Right ty'' -> incompatibleTypes (BType TInt) ty''
                  Left err -> Left err
              _ -> incompatibleTypes (TypeArray ty) ty

          (LArray' ex lvalue') -> 
            case ty of
              TypeArray _ ->
                case tcExp ctx ex of
                  Right (BType TInt) -> tcLValue ctx (LID' ident lvalue')
                  Right ty'' -> incompatibleTypes (BType TInt) ty''
                  Left err -> Left err
              _ -> incompatibleTypes (TypeArray ty) ty

          _ -> 
            case ty of
              BType (TID register) -> lookForVarInRegisterInRegister ctx register lvalue
              _ -> incompatibleTypes (BType (TID "(nome do registro)")) ty
          
      Nothing -> undefinedVar ident

-- procurando por um atributo de um registro dentro de outro registro
lookForVarInRegisterInRegister :: Ctx -> ID -> LValue' -> Check Type
lookForVarInRegisterInRegister ctx reg (LComp ident') = 
  case lookup reg (registros ctx) of
    Just decls ->
      case lookup ident' [(idd, tyy) | Decl idd tyy <- decls] of
        Just ty -> Right ty
        Nothing -> undefinedVar ident'
    Nothing -> undefinedRegister reg
lookForVarInRegisterInRegister ctx reg (LComp' ident' lval') =
  case lookup reg (registros ctx) of
    Just decls ->
      case lookup ident' [(idd, tyy) | Decl idd tyy <- decls] of
        Just (BType (TID register')) -> lookForVarInRegisterInRegister ctx register' lval'
        Just (TypeArray ty') -> Right ty'
        Just ty' -> incompatibleTypes (BType (TID "(nome do registro)")) ty'
        Nothing -> undefinedVar ident'
    Nothing -> undefinedRegister reg
lookForVarInRegisterInRegister _ _ _ = incompatibleTypes (BType (TID "(nome do registro)")) (TypeArray (BType TInt)) 

tcFuncArgs :: Ctx -> [Param] -> [Exp] -> Check ()
tcFuncArgs _ [] [] = Right ()
tcFuncArgs _ (Param ident _ : _) [] = Left [ArgumentWithoutValue ident]
tcFuncArgs _ [] (_ : _) = Left [ThereIsNoArgument]
tcFuncArgs ctx (Param _ ty : ps) (e : exs) =
  case tcExp ctx e of
    Right ty' -> 
      if ty == ty' || ty' == BType (TID "null")
        then tcFuncArgs ctx ps exs
        else incompatibleTypes ty ty'
    Left err -> Left err

tcFuncCallExp :: Ctx -> [Param] -> [Type] -> Maybe Exps -> Exp -> Check Type
tcFuncCallExp _ (Param ident _ : _ ) _ Nothing _ = Left [ArgumentWithoutValue ident]
tcFuncCallExp _ []  _ (Just _) _ = Left [ThereIsNoArgument]
tcFuncCallExp ctx [] rTypes Nothing ex1 = 
  case tcExp ctx ex1 of
    Right (BType TInt) -> -- retorna Right e o tipo do retorno na pocisao ex1
      case ex1 of
        EInt n -> Right (rTypes !! n)
        _ -> undefined -- ! retornar Right e o tipo do retorno na pocisao ex1
    Right ty -> incompatibleTypes (BType TInt) ty
    Left err -> Left err
tcFuncCallExp ctx params rTypes (Just (Exps e exs)) ex1 =
  case tcFuncArgs ctx params (e:exs) of
    Right _ -> tcFuncCallExp ctx [] rTypes Nothing ex1
    Left err -> Left err

tcExp :: Ctx -> Exp -> Check Type
tcExp _ (EInt _) = Right (BType TInt)
tcExp _ (EBool _) = Right (BType TBool)
tcExp _ (EFloat _) = Right (BType TFloat)
tcExp _ (EChar _) = Right (BType TChar)
tcExp _ ENull = Right (BType (TID "null"))
tcExp ctx (ELValue lvalue) = tcLValue ctx lvalue
tcExp ctx (EFuncCall ident mexs ex1) = 
  let functions = [(func, (params, returns)) | (func, params, returns) <- funcs ctx]
  in
  case lookup ident functions of
    Just (p, r) -> tcFuncCallExp ctx p r mexs ex1
    Nothing -> undefinedFunction ident
tcExp ctx (ENew ty (ex1 : exs)) = 
  case tcExp ctx ex1 of
    Right (BType TInt) -> tcExp ctx (ENew ty exs)
    Right ty' -> incompatibleTypes (BType TInt) ty'
    Left err -> Left err
tcExp _ (ENew ty []) = Right (TypeArray ty)
tcExp ctx (EParen e1) = tcExp ctx e1
tcExp ctx (e1 :+: e2) = tcBinOpNumerico ctx e1 e2
tcExp ctx (e1 :-: e2) = tcBinOpNumerico ctx e1 e2
tcExp ctx (e1 :*: e2) = tcBinOpNumerico ctx e1 e2
tcExp ctx (e1 :/: e2) = tcBinOpNumerico ctx e1 e2
tcExp ctx (e1 :%: e2) = tcBinOp ctx (e1, BType TInt) (e2, BType TInt) (BType TInt)
tcExp ctx (e1 :==: e2) = tcBinOpComp ctx e1 e2
tcExp ctx (e1 :!=: e2) = tcBinOpComp ctx e1 e2
tcExp ctx (e1 :>: e2) = tcBinOpCompGtLt ctx e1 e2
tcExp ctx (e1 :<: e2) = tcBinOpCompGtLt ctx e1 e2
tcExp ctx (e1 :&&: e2) = tcBinOp ctx (e1, BType TBool) (e2, BType TBool) (BType TBool)
tcExp ctx (ENot e1)
  = case tcExp ctx e1 of
      Right (BType TBool) -> Right (BType TBool)
      Right ty -> incompatibleTypes (BType TBool) ty
      Left err -> Left err
tcExp ctx (ENeg e1)
  = case tcExp ctx e1 of
      Right (BType TInt) -> Right (BType TInt)
      Right (BType TFloat) -> Right (BType TFloat)
      Right ty -> 
        let (Left err1) = incompatibleTypes (BType TInt) ty
            (Left err2) = incompatibleTypes (BType TFloat) ty
        in
          Left (err1 ++ err2)
      Left err -> Left err