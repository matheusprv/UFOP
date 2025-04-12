-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022

module Frontend.Semantics.StatementTypeChecker (tcProg) where

import Frontend.Semantics.Basics
import Frontend.Semantics.ExpTypeCheck
import Syntax.Syntax

tcProg :: Prog -> Check ()
tcProg (Prog defs) = tcDefs (Ctx {vars=[], funcs=[], registros=[]}) defs

tcDefs :: Ctx -> [Def] -> Check ()
tcDefs ctx [] =
  let functions = [(func, (params, returns)) | (func, params, returns) <- funcs ctx]
  in
  case lookup "main" functions of
    Just _ -> Right ()
    Nothing -> undefinedFunction "main"
tcDefs ctx (d : ds) =
  case tcDef ctx d of
    Left err -> Left err
    Right ctx' -> tcDefs ctx' ds

tcDef :: Ctx -> Def -> Check Ctx
tcDef ctx (DataDef newData) = tcData ctx newData -- verifica se nao existe nenhum outro tipo com mesmo nome e se nao tem declaracoes repetidas
tcDef ctx (Func ident mParams mRetType cmds) =
  case tcFunc ctx ident of -- verifica se nao existe nenhuma outra funcao com mesmo nome
    Left err -> Left err
    Right _ ->
      let paramCtx = case mParams of
            Nothing -> []
            Just params -> params
          retTypeCtx = case mRetType of
            Nothing -> []
            Just (Types ty tys) -> ty : tys
          funcCtx = (ident, paramCtx, retTypeCtx)
          -- contexto criado apenas para a checagem da funcao
          newCtx = ctx {
            funcs = funcCtx : funcs ctx,
            vars = [(var, ty) | Param var ty <- paramCtx] ++ vars ctx
          }
      -- nao retorna o newCtx para nao ter as variaveis de argumento no contexto em outras funcoes
      in case tcCmds newCtx cmds of
          Left err -> Left err
          Right _ -> Right (ctx {funcs = funcCtx : funcs ctx})

tcFunc :: Ctx -> ID -> Check ()
tcFunc ctx ident =
  let functions = [(func, (params, returns)) | (func, params, returns) <- funcs ctx]
  in
  case lookup ident functions of
    Just _ -> Left [RepeatedDeclaration ident]
    Nothing -> Right ()

tcData :: Ctx -> Data -> Check Ctx
tcData ctx (Data ident decls) =
  case tcDeclsData decls of
    Left err -> Left err
    Right() ->
      case lookup ident (registros ctx) of
        Just _ -> Left [RepeatedDeclaration ident]
        Nothing -> Right ctx {registros = (ident, decls) : registros ctx}

tcDeclsData :: [Decl] -> Check ()
tcDeclsData [] = Right ()
tcDeclsData (decl@(Decl ident _) : decls) =
  if decl `elem` decls 
    then Left [RepeatedDeclaration ident] 
    else tcDeclsData decls

-- a função que eu estou é a primeira em funcs do ctx
-- com isso consigo verificar o retorno da mesma no comando return
tcCmds :: Ctx -> [Cmd] -> Check Ctx
tcCmds ctx [] = Right ctx
tcCmds ctx (c:cs) = 
  case tcCmd ctx c of
    Left err -> Left err
    Right ctx' -> tcCmds ctx' cs

tcCmd :: Ctx -> Cmd -> Check Ctx
tcCmd ctx (CmdBlock cmds) = tcCmds ctx cmds
tcCmd ctx (CmdAssign lv e) =
  case (r1, r2) of
    (Right ty1, Right ty2) ->
      if ty1 == ty2 || ty2 == BType (TID "null")
        then Right ctx
        else incompatibleTypes ty1 ty2
    (Left err1, Left err2) -> Left (err1 ++ err2)
    (Left err1, _) -> Left err1
    (_, Left err2) -> Left err2
  where
    r1 = tcLValue ctx lv
    r2 = tcExp ctx e
tcCmd ctx (CmdDecl (Decl ident ty) Nothing) = Right (ctx {vars= (ident, ty) : vars ctx})
tcCmd ctx (CmdDecl (Decl ident ty1) (Just e)) =
  case tcExp ctx e of
    Right ty2 -> 
      if ty1 == ty2 || ty2 == BType (TID "null")
        then Right (ctx {vars= (ident, ty1) : vars ctx})
        else incompatibleTypes ty1 ty2
    Left err -> Left err
tcCmd ctx (CmdIf e c) =
  case tcExp ctx e of
    Right (BType TBool) ->
      case tcCmd ctx c of
        Left err -> Left err
        Right _ -> Right ctx
    Right ty -> incompatibleTypes (BType TBool) ty
    Left err -> Left err
tcCmd ctx (CmdIfElse e mc1 mc2) = 
  case tcExp ctx e of
    Right (BType TBool) ->
      case (mc1, mc2) of
        (Just c1, Just c2) ->
          case tcCmd ctx c1 of
            Left err -> Left err
            Right _ -> 
              case tcCmd ctx c2 of
                Left err2 -> Left err2
                Right _ -> Right ctx
        (Just c1, _) ->
          case tcCmd ctx c1 of
            Left err -> Left err
            Right _ -> Right ctx
        (_, Just c2) ->
          case tcCmd ctx c2 of
            Left err -> Left err
            Right _ -> Right ctx
        (_, _) -> Right ctx
    Right ty -> incompatibleTypes (BType TBool) ty
    Left err -> Left err
tcCmd ctx (CmdIterate e c) =
  case tcExp ctx e of
    Right (BType TInt) ->
      case tcCmd ctx c of
        Left err -> Left err
        Right _ -> Right ctx
    Right ty -> incompatibleTypes (BType TInt) ty
    Left err -> Left err
tcCmd ctx (CmdPrint e) = 
  case tcExp ctx e of
    Right ty ->
      case tcPrintAndRead ty of
        Right _ -> Right ctx
        Left err -> Left err
    Left err -> Left err
tcCmd ctx (CmdRead lv) = 
  case tcLValue ctx lv of
    Right ty ->
      case tcPrintAndRead ty of
        Right _ -> Right ctx
        Left err -> Left err
    Left err -> Left err
tcCmd ctx (CmdReturn e exs) = 
  case funcs ctx of
    [] -> error "Funcao nao adicionada no contexto"
    ((_, _, rTypes) : _) -> tcReturn ctx rTypes (e : exs)
tcCmd ctx (CmdFuncCall ident mExs mLvals) =
  let functions = [(func, (params, returns)) | (func, params, returns) <- funcs ctx]
  in
    case lookup ident functions of
      Just (ps, rs) -> 
        case tcFuncCallCmd ctx ps rs mExs mLvals of
          Right _ -> Right ctx
          Left err -> Left err
      Nothing -> undefinedFunction ident

tcPrintAndRead :: Type -> Check ()
tcPrintAndRead ty@(BType (TID _)) = Left [IncompatibleTypes (BType TInt) ty, 
  IncompatibleTypes (BType TChar) ty, IncompatibleTypes (BType TFloat) ty]
--tcPrintAndRead ty@(BType TBool) = Left [IncompatibleTypes (BType TInt) ty, 
 -- IncompatibleTypes (BType TChar) ty, IncompatibleTypes (BType TFloat) ty]
tcPrintAndRead ty@(TypeArray _) = Left [IncompatibleTypes (BType TInt) ty, 
  IncompatibleTypes (BType TChar) ty, IncompatibleTypes (BType TFloat) ty]
tcPrintAndRead _ = Right ()

-- checa o comando return
tcReturn :: Ctx -> [Type] -> [Exp] -> Check Ctx
tcReturn ctx [] [] = Right ctx
tcReturn _ (_ : _) [] = Left [DifferentNumberOfReturns]
tcReturn _ [] (_ : _) = Left [DifferentNumberOfReturns]
tcReturn ctx (ty : tys) (r : rs) =
  case tcExp ctx r of
    Right tyR ->
      if ty == tyR || tyR == BType (TID "null") 
        then tcReturn ctx tys rs
        else incompatibleTypes ty tyR
    Left err -> Left err

tcFuncCallCmd :: Ctx -> [Param] -> [Type] -> Maybe Exps -> Maybe LValues -> Check ()
tcFuncCallCmd _ (Param ident _ : _) _ Nothing _ = Left [ArgumentWithoutValue ident]
tcFuncCallCmd _ [] _ (Just _) _ = Left [ThereIsNoArgument]
tcFuncCallCmd _ _ (_ : _) _ Nothing = Left [DifferentNumberOfReturns]
tcFuncCallCmd _ _ [] _ (Just _) = Left [DifferentNumberOfReturns]
tcFuncCallCmd ctx [] rTypes Nothing (Just (LValues lv lvs)) = tcFuncReturn ctx rTypes (lv:lvs) -- caso que tenho retorno mas nao tenho parametros
tcFuncCallCmd ctx params [] (Just (Exps e exs)) Nothing = tcFuncArgs ctx params (e:exs) -- caso que tenho parametro mas nao tenho retorno
tcFuncCallCmd ctx params rTypes (Just (Exps e exs)) (Just (LValues lv lvs)) = -- caso que tenho parametros e retornos na definicao e na chamada
  case tcFuncArgs ctx params (e:exs) of
    Right _ -> tcFuncReturn ctx rTypes (lv:lvs)
    Left err -> Left err
tcFuncCallCmd _ [] [] Nothing Nothing = Right () -- Caso em que a definicao da funcao nao tenha parametros nem retornos, e na chamada da funcao tambem nao

-- checa os parametros que foram passados para serem atualizados com o retorno
tcFuncReturn :: Ctx -> [Type] -> [LValue] -> Check ()
tcFuncReturn _ _ [] = Right ()
tcFuncReturn _ [] _ = Left [DifferentNumberOfReturns]
tcFuncReturn ctx (ty : tys) (r : rs) =
  case tcLValue ctx r of
    Right tyR ->
      if ty == tyR || tyR == BType (TID "null")
        then tcFuncReturn ctx tys rs
        else incompatibleTypes ty tyR
    Left err -> Left err