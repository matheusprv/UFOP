-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022
{-# OPTIONS_GHC -Wno-incomplete-uni-patterns #-}

module Frontend.Parser.Recursive.Parser (langParser) where

import Frontend.Parser.Recursive.SimpleCombinators
import Syntax.Syntax
import Frontend.Lexer.Lexer


-- executarParser :: String -> IO ()
-- executarParser input =
--     case lexer input of
--         Left err     -> putStrLn ("Lexical analysis error: " ++ err)
--         Right tokens -> print (langParser tokens)

-- top-level parsing function 

langParser :: [Token] -> Either String Prog
langParser s
  = case runParser programParser s of
      [] -> Left "Parser error"
      ((r, _) : _) -> Right r

-- main program parser 

programParser :: Parser Token Prog
programParser = Prog <$> many defParser <* matchToken TEOF

-- Parser for [Def]

defParser :: Parser Token Def
defParser = choice [dataParser, funcParser]

-- Data

dataParser :: Parser Token Def
dataParser = DataDef <$> (matchToken TData *> dataParser')

dataParser' :: Parser Token Data
dataParser' = Data <$> typer <*> braces (many declParser)

declParser :: Parser Token Decl
declParser = Decl <$> (identifier <* matchToken TDoubleColon) <*> typeParser <* matchToken TSemi

-- Func

funcParser :: Parser Token Def
funcParser =
  Func <$> identifier
       <*> parens (optional paramParser)
       <*> optional (matchToken TColon *> typesParser)
       <*> braces (many cmdParser)

-- Params
paramParser :: Parser Token [Param]
paramParser = sepBy (Param <$> (identifier <* matchToken TDoubleColon) <*> typeParser) (matchToken TComma)

-- Type

typesParser :: Parser Token Types
typesParser = Types <$> typeParser <*> many (matchToken TComma *> typeParser)

typeParser :: Parser Token Type
typeParser = choice [arrayTypeParser, btypeParser]

arrayTypeParser :: Parser Token Type
arrayTypeParser =
  f <$> btypeParser
    <*> matchToken TLBracket
    <*> matchToken TRBracket
    where
      f b _ _ = TypeArray b

btypeParser :: Parser Token Type
btypeParser = BType <$> btypeParser'

btypeParser' :: Parser Token BType
btypeParser' =
  choice [ intParser
         , charParser
         , tboolParser
         , floatParser
         , tidParser
         ]

intParser :: Parser Token BType
intParser = TInt <$ matchToken TTInt

tboolParser :: Parser Token BType
tboolParser = TBool <$ matchToken TTBool

charParser :: Parser Token BType
charParser = TChar <$ matchToken TTChar

floatParser :: Parser Token BType
floatParser = TFloat <$ matchToken TTFloat

tidParser :: Parser Token BType
tidParser = TID <$> typer

-- Cmds

cmdParser :: Parser Token Cmd
cmdParser
  = choice [
             blockParser
           , assignParser
           , ifElseParser
           , ifParser
           , printParser
           , readParser
           , iterateParser
           , returnParser
           , funcCallParser
           , cmdDeclParser
           ]

-- blocks

blockParser :: Parser Token Cmd
blockParser = CmdBlock <$> braces (many cmdParser)

-- assignment

assignParser :: Parser Token Cmd
assignParser = CmdAssign <$> lvalueParser <*> (matchToken TAssign *> expParser) <* matchToken TSemi

lvalueParser :: Parser Token LValue
lvalueParser
  = choice [
             LID <$> identifier
           , LID' <$> identifier <*> lvalueParser'
           ]

lvalueParser' :: Parser Token LValue'
lvalueParser'
  = choice [
             LArray <$> brackets expParser
           , LComp <$> (matchToken TDot *> identifier)
           , LArray' <$> brackets expParser <*> lvalueParser'
           , LComp' <$> (matchToken TDot *> identifier) <*> lvalueParser'
           ]

-- if and if - else

ifParser :: Parser Token Cmd
ifParser
  = CmdIf <$> (matchToken TIf *> parens expParser)
          <*> cmdParser

ifElseParser :: Parser Token Cmd
ifElseParser
  = CmdIfElse <$> (matchToken TIf *> parens expParser)
              <*> optional cmdParser
              <*> (matchToken TElse *> optional cmdParser)

-- print

printParser :: Parser Token Cmd
printParser = CmdPrint <$> (matchToken TPrint *> expParser <* matchToken TSemi)

-- read  

readParser :: Parser Token Cmd
readParser = CmdRead <$> (matchToken TRead *> lvalueParser <* matchToken TSemi)

-- iterate 

iterateParser :: Parser Token Cmd
iterateParser = CmdIterate <$> (matchToken TIterate *> parens expParser) <*> cmdParser

-- return
returnParser :: Parser Token Cmd
returnParser
  = CmdReturn <$> (matchToken TReturn *> expParser) <*>
                  many (matchToken TComma *> expParser) <* matchToken TSemi

-- func call / procedure call

funcCallParser :: Parser Token Cmd
funcCallParser
  = CmdFuncCall <$> identifier <*>
                    parens (optional expsParser) <*>
                    optional (ltgt lvaluesParser) <* matchToken TSemi

expsParser :: Parser Token Exps
expsParser = Exps <$> expParser <*> many (matchToken TComma *> expParser)

lvaluesParser :: Parser Token LValues
lvaluesParser = LValues <$> lvalueParser <*> many (matchToken TComma *> lvalueParser)

-- variable declaration
cmdDeclParser :: Parser Token Cmd
cmdDeclParser 
  = CmdDecl <$> (Decl <$> (identifier <* matchToken TDoubleColon) <*> typeParser) <*>
                optional (matchToken TAssign *> expParser) <* matchToken TSemi

-- expressions.

expParser :: Parser Token Exp
expParser = andExpParser

andExpParser :: Parser Token Exp
andExpParser = chainl compExpParser andop
    where
      andop = (:&&:) <$ matchToken TAnd

compExpParser :: Parser Token Exp
compExpParser = chainl relExpParser compop
    where
      compop = eqp <|> neqp
      eqp = (:==:) <$ matchToken TEq
      neqp = (:!=:) <$ matchToken TNeq

relExpParser :: Parser Token Exp
relExpParser = chainr plusExpParser relop
    where
      relop = ltop <|> gtop
      ltop = (:<:) <$ matchToken TLt
      gtop = (:>:) <$ matchToken TGt

plusExpParser :: Parser Token Exp
plusExpParser = chainl mulExpParser plusop
    where
      plusop = plusp <|> minusp
      plusp = (:+:) <$ matchToken TPlus
      minusp = (:-:) <$ matchToken TMinus

mulExpParser :: Parser Token Exp
mulExpParser = chainl notExpParser mulop
    where
      mulop = timesp <|> divp <|> modp
      timesp = (:*:) <$ matchToken TTimes
      divp = (:/:) <$ matchToken TDiv
      modp = (:%:) <$ matchToken TMod

notExpParser :: Parser Token Exp
notExpParser = negationAndUnaryList <*> factorParser

negationAndUnaryList :: Parser Token (Exp -> Exp)
negationAndUnaryList
  = foldr step id <$> greedy (choice [matchToken TNot, matchToken TMinus])
    where
      step (Token _ TNot) ac = ENot . ac
      step (Token _ TMinus) ac = ENeg . ac
      step _ ac = ac

factorParser :: Parser Token Exp
factorParser
  = choice [ vboolParser
           , vnullParser
           , vintParser
           , vfloatParser
           , vcharParser
           , vlvalueParser
           , vnewParser
           , vfuncCallParser
           , vparenParser
           ]

-- values

vboolParser :: Parser Token Exp
vboolParser = EBool <$> boolParser
  where
    boolParser = trueParser <|> falseParser
    trueParser = True <$ matchToken TTrue
    falseParser = False <$ matchToken TFalse

vnullParser :: Parser Token Exp
vnullParser = ENull <$ matchToken TNull

vintParser :: Parser Token Exp
vintParser = EInt <$> tokenToInt

vfloatParser :: Parser Token Exp
vfloatParser = EFloat <$> tokenToFloat

vcharParser :: Parser Token Exp
vcharParser = EChar <$> tokenToChar

vlvalueParser :: Parser Token Exp
vlvalueParser = ELValue <$> lvalueParser

vnewParser :: Parser Token Exp
vnewParser = ENew <$> (matchToken TNew *> typeParser) <*> brackets (sepBy expParser (matchToken TComma))

vfuncCallParser :: Parser Token Exp
vfuncCallParser = EFuncCall <$> identifier <*> parens (optional expsParser) <*> brackets expParser

vparenParser :: Parser Token Exp
vparenParser = EParen <$> parens expParser

tokenToInt :: Parser Token Int
tokenToInt = sat (\t -> case lexeme t of
                          TIntNumber _ -> True
                          _ -> False) >>= \(Token _ (TIntNumber n)) -> pure n

tokenToFloat :: Parser Token Float
tokenToFloat = sat (\t -> case lexeme t of
                            TFloatNumber _ -> True
                            _ -> False) >>= \(Token _ (TFloatNumber f)) -> pure f

tokenToChar :: Parser Token Char
tokenToChar = sat (\t -> case lexeme t of
                           TCharacter _ -> True
                           _ -> False) >>= \(Token _ (TCharacter c)) -> pure c

optional :: Parser s a -> Parser s (Maybe a)
optional p = (Just <$> p) <|> pure Nothing

sepBy :: Parser s a -> Parser s b -> Parser s [a]
sepBy p sep = (:) <$> p <*> many (sep *> p) <|> pure []