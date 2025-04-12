-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022
{-# OPTIONS_GHC -Wno-incomplete-uni-patterns #-}

module Frontend.Parser.PEG.Parser (langParserPEG) where

--import Frontend.Parser.Recursive.SimpleCombinators
import Syntax.Syntax
import Frontend.Lexer.Lexer
import Frontend.Parser.PEG.Grammar
import Frontend.Parser.PEG.ParsingExp

-- executarParserPEG :: String -> IO ()
-- executarParserPEG input =
--     case lexer input of
--         Left err     -> putStrLn ("Lexical analysis error: " ++ err)
--         Right tokens -> print (langParserPEG tokens)

-- Top-level parsing function
langParserPEG :: [Token] -> Either String Prog
langParserPEG s = runPEG programPEG s

-- Main program parser
programPEG :: PExp [Token] Prog
programPEG = Prog <$> many defPEG <* matchToken TEOF

-- Parser for [Def]
defPEG :: PExp [Token] Def
defPEG = choice [dataPEG, funcPEG]

-- Data
dataPEG :: PExp [Token] Def
dataPEG = DataDef <$> (matchToken TData *> dataPEG')

dataPEG' :: PExp [Token] Data
dataPEG' = Data <$> typer <*> braces (many declPEG)

declPEG :: PExp [Token] Decl
declPEG = Decl <$> (identifier <* matchToken TDoubleColon) <*> typePEG <* matchToken TSemi

-- Func
funcPEG :: PExp [Token] Def
funcPEG = Func <$> identifier
               <*> parens (optional paramPEG)
               <*> optional (matchToken TColon *> typesPEG)
               <*> braces (many cmdPEG)

-- Params
paramPEG :: PExp [Token] [Param]
paramPEG = sepBy (Param <$> (identifier <* matchToken TDoubleColon) <*> typePEG) (matchToken TComma)

-- Type
typesPEG :: PExp [Token] Types
typesPEG = Types <$> typePEG <*> many (matchToken TComma *> typePEG)

typePEG :: PExp [Token] Type
typePEG = choice [arrayTypePEG, btypePEG]

arrayTypePEG :: PExp [Token] Type
arrayTypePEG = 
    f <$> btypePEG
    <*> matchToken TLBracket
    <*> matchToken TRBracket
    where
      f b _ _ = TypeArray b

btypePEG :: PExp [Token] Type
btypePEG = BType <$> btypePEG'

btypePEG' :: PExp [Token] BType
btypePEG' = choice [ intPEG
                   , charPEG
                   , tboolPEG
                   , floatPEG
                   , tidPEG
                   ]

intPEG :: PExp [Token] BType
intPEG = TInt <$ matchToken TTInt

tboolPEG :: PExp [Token] BType
tboolPEG = TBool <$ matchToken TTBool

charPEG :: PExp [Token] BType
charPEG = TChar <$ matchToken TTChar

floatPEG :: PExp [Token] BType
floatPEG = TFloat <$ matchToken TTFloat

tidPEG :: PExp [Token] BType
tidPEG = TID <$> typer

-- Cmds

cmdPEG :: PExp [Token] Cmd
cmdPEG 
    = choice [ 
              blockPEG
            , assignPEG
            , ifElsePEG
            , ifPEG
            , printPEG
            , readPEG
            , iteratePEG
            , returnPEG
            , funcCallPEG
            , cmdDeclPEG
            ]

-- blocks

blockPEG :: PExp [Token] Cmd
blockPEG = CmdBlock <$> braces (many cmdPEG)

-- assignment

assignPEG :: PExp [Token] Cmd
assignPEG = CmdAssign <$> lvaluePEG <*> (matchToken TAssign *> expPEG) <* matchToken TSemi

lvaluePEG :: PExp [Token] LValue
lvaluePEG 
    = choice [ 
              LID' <$> identifier <*> lvaluePEG'
            , LID <$> identifier
            ]

lvaluePEG' :: PExp [Token] LValue'
lvaluePEG' 
    = choice [ 
              LArray' <$> brackets expPEG <*> lvaluePEG'
            , LComp' <$> (matchToken TDot *> identifier) <*> lvaluePEG'
            , LArray <$> brackets expPEG
            , LComp <$> (matchToken TDot *> identifier)
            ]

-- if and if-else
ifPEG :: PExp [Token] Cmd
ifPEG 
    = CmdIf <$> (matchToken TIf *> parens expPEG) 
            <*> cmdPEG

ifElsePEG :: PExp [Token] Cmd
ifElsePEG 
    = CmdIfElse <$> (matchToken TIf *> parens expPEG)
                <*> optional cmdPEG
                <*> (matchToken TElse *> optional cmdPEG)

-- print
printPEG :: PExp [Token] Cmd
printPEG = CmdPrint <$> (matchToken TPrint *> expPEG <* matchToken TSemi)

-- read  
readPEG :: PExp [Token] Cmd
readPEG = CmdRead <$> (matchToken TRead *> lvaluePEG <* matchToken TSemi)

-- iterate 
iteratePEG :: PExp [Token] Cmd
iteratePEG = CmdIterate <$> (matchToken TIterate *> parens expPEG) <*> cmdPEG

-- return
returnPEG :: PExp [Token] Cmd
returnPEG = CmdReturn <$> (matchToken TReturn *> expPEG) <*>
                          many (matchToken TComma *> expPEG) <* matchToken TSemi

-- func call / procedure call
funcCallPEG :: PExp [Token] Cmd
funcCallPEG = CmdFuncCall <$> identifier <*>
                           parens (optional expsPEG) <*>
                           optional (ltgt lvaluesPEG) <* matchToken TSemi

-- variable declaration
cmdDeclPEG :: PExp [Token] Cmd
cmdDeclPEG 
  = CmdDecl <$> (Decl <$> (identifier <* matchToken TDoubleColon) <*> typePEG) <*>
                optional (matchToken TAssign *> expPEG) <* matchToken TSemi

-- expressions.

expsPEG :: PExp [Token] Exps
expsPEG = Exps <$> expPEG <*> many (matchToken TComma *> expPEG)

lvaluesPEG :: PExp [Token] LValues
lvaluesPEG = LValues <$> lvaluePEG <*> many (matchToken TComma *> lvaluePEG)

-- expressions.
expPEG :: PExp [Token] Exp
expPEG = andExpPEG

andExpPEG :: PExp [Token] Exp
andExpPEG = chainl compExpPEG andop
    where
      andop = (:&&:) <$ matchToken TAnd

compExpPEG :: PExp [Token] Exp
compExpPEG = chainl relExpPEG compop
    where
      compop = eqp <|> neqp
      eqp = (:==:) <$ matchToken TEq
      neqp = (:!=:) <$ matchToken TNeq

relExpPEG :: PExp [Token] Exp
relExpPEG = chainr plusExpPEG relop
    where
      relop = ltop <|> gtop
      ltop = (:<:) <$ matchToken TLt
      gtop = (:>:) <$ matchToken TGt

plusExpPEG :: PExp [Token] Exp
plusExpPEG = chainl mulExpPEG plusop
    where
      plusop = plusp <|> minusp
      plusp = (:+:) <$ matchToken TPlus
      minusp = (:-:) <$ matchToken TMinus

mulExpPEG :: PExp [Token] Exp
mulExpPEG = chainl notExpPEG mulop
    where
      mulop = timesp <|> divp <|> modp
      timesp = (:*:) <$ matchToken TTimes
      divp = (:/:) <$ matchToken TDiv
      modp = (:%:) <$ matchToken TMod

notExpPEG :: PExp [Token] Exp
notExpPEG = negationAndUnaryList <*> factorPEG

negationAndUnaryList :: PExp [Token] (Exp -> Exp)
negationAndUnaryList = foldr step id <$> greedy (choice [matchToken TNot, matchToken TMinus])
    where
      step (Token _ TNot) ac = ENot . ac
      step (Token _ TMinus) ac = ENeg . ac
      step _ ac = ac

factorPEG :: PExp [Token] Exp
factorPEG 
    = choice [ vboolPEG
             , vnullPEG
             , vintPEG
             , vfloatPEG
             , vcharPEG
             , vfuncCallPEG
             , vlvaluePEG
             , vnewPEG
             , vparenPEG 
             ]

-- values

vboolPEG :: PExp [Token] Exp
vboolPEG = EBool <$> boolPEG
  where
    boolPEG = truePEG <|> falsePEG
    truePEG = True <$ matchToken TTrue
    falsePEG = False <$ matchToken TFalse

vnullPEG :: PExp [Token] Exp
vnullPEG = ENull <$ matchToken TNull

vintPEG :: PExp [Token] Exp
vintPEG = EInt <$> tokenToInt

vfloatPEG :: PExp [Token] Exp
vfloatPEG = EFloat <$> tokenToFloat

vcharPEG :: PExp [Token] Exp
vcharPEG = EChar <$> tokenToChar

vlvaluePEG :: PExp [Token] Exp
vlvaluePEG = ELValue <$> lvaluePEG

vnewPEG :: PExp [Token] Exp
vnewPEG = ENew <$> (matchToken TNew *> typePEG) <*> brackets (sepBy expPEG (matchToken TComma))

vfuncCallPEG :: PExp [Token] Exp
vfuncCallPEG = EFuncCall <$> identifier <*> parens (optional expsPEG) <*> brackets expPEG

vparenPEG :: PExp [Token] Exp
vparenPEG = EParen <$> parens expPEG

tokenToInt :: PExp [Token] Int
tokenToInt = sat (\t -> case lexeme t of
                          TIntNumber _ -> True
                          _ -> False) >>= \(Token _ (TIntNumber n)) -> pure n

tokenToFloat :: PExp [Token] Float
tokenToFloat = sat (\t -> case lexeme t of
                            TFloatNumber _ -> True
                            _ -> False) >>= \(Token _ (TFloatNumber f)) -> pure f

tokenToChar :: PExp [Token] Char
tokenToChar = sat (\t -> case lexeme t of
                           TCharacter _ -> True
                           _ -> False) >>= \(Token _ (TCharacter c)) -> pure c

sepBy :: PExp s a -> PExp s b -> PExp s [a]
sepBy p sep = (:) <$> p <*> many (sep *> p) <|> pure []

optional :: PExp s a -> PExp s (Maybe a)
optional p = (Just <$> p) <|> pure Nothing