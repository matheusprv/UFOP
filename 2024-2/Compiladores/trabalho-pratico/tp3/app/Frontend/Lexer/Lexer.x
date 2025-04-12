-- Pedro Henrique R. L. de Oliveira 22.1.4022
-- Matheus Peixoto Ribeiro Vieira 22.1.4104

{
{-# OPTIONS_GHC -Wno-name-shadowing #-}
module Frontend.Lexer.Lexer where

}


%wrapper "monadUserState"

$digit = 0-9            -- digits
$alpha = [a-zA-Z]       -- alphabetic characters
$lower = [a-z]          -- lower case alphabetic characters 
$upper = [A-Z]          -- upper case alphabetic characters 

-- second RE macros
@identifier  = $lower[$alpha $digit _]* -- identifiers
@typeName    = $upper[$alpha $digit _]*
@intNumber   = [$digit]+
@floatNumber = [$digit]*"."[$digit]+
@character   = [\'][$alpha $digit \n \t \b \r \\ \'][\']

-- tokens declarations

tokens :-
     <0> $white+       ;
     <0> "--".*        ;
     <0> @intNumber    {mkIntNumber}
     <0> @floatNumber  {mkFloatNumber}
     <0> @character    {mkCharacter}
     <0> "="           {simpleToken TAssign}
     <0> "read"        {simpleToken TRead}
     <0> "print"       {simpleToken TPrint}
     <0> "if"          {simpleToken TIf}
     <0> "then"        {simpleToken TThen}
     <0> "else"        {simpleToken TElse}
     <0> "iterate"     {simpleToken TIterate}
     <0> ";"           {simpleToken TSemi}
     <0> ":"           {simpleToken TColon}
     <0> "::"          {simpleToken TDoubleColon}
     <0> "."           {simpleToken TDot}
     <0> ","           {simpleToken TComma}
     <0> "("           {simpleToken TLParen}
     <0> ")"           {simpleToken TRParen}
     <0> "{"           {simpleToken TLBrace}
     <0> "}"           {simpleToken TRBrace}
     <0> "["           {simpleToken TLBracket}
     <0> "]"           {simpleToken TRBracket}
     <0> "+"           {simpleToken TPlus}
     <0> "*"           {simpleToken TTimes}
     <0> "-"           {simpleToken TMinus}
     <0> "/"           {simpleToken TDiv}
     <0> "%"           {simpleToken TMod}
     <0> "=="          {simpleToken TEq}
     <0> "!="          {simpleToken TNeq}
     <0> "<"           {simpleToken TLt}
     <0> ">"           {simpleToken TGt}
     <0> "!"           {simpleToken TNot}
     <0> "&&"          {simpleToken TAnd}
     <0> "Int"         {simpleToken TTInt}
     <0> "Float"       {simpleToken TTFloat}
     <0> "Char"        {simpleToken TTChar}
     <0> "Bool"        {simpleToken TTBool}
     <0> "true"        {simpleToken TTrue}
     <0> "false"       {simpleToken TFalse}
     <0> "null"        {simpleToken TNull}
     <0> "data"        {simpleToken TData}
     <0> "return"      {simpleToken TReturn}
     <0> "new"         {simpleToken TNew}
     <0> @identifier   {mkIdent}
     <0> @typeName     {mkTypeName}
{

-- useer state
data AlexUserState 
  = AlexUserState {
      nestLevel :: Int 
    }

alexInitUserState :: AlexUserState 
alexInitUserState 
  = AlexUserState 0 

get :: Alex AlexUserState
get = Alex $ \s -> Right (s, alex_ust s)

put :: AlexUserState -> Alex ()
put s' = Alex $ \s -> Right (s{alex_ust = s'}, ())

modify :: (AlexUserState -> AlexUserState) -> Alex ()
modify f 
  = Alex $ \s -> Right (s{alex_ust = f (alex_ust s)}, ())

alexEOF :: Alex Token
alexEOF = do
  (pos, _, _, _) <- alexGetInput
--   startCode <- alexGetStartCode
--   when (startCode == state_comment) $
--     alexError "Error: unclosed comment"
  pure $ Token (position pos) TEOF

-- token definition

data Token
  = Token {
      pos :: (Int, Int)
    , lexeme :: Lexeme 
    } deriving (Eq, Ord, Show)

data Lexeme    
  = TIdent String
  | TTypeName String
  | TIntNumber Int
  | TFloatNumber Float
  | TCharacter Char
  | TAssign 
  | TRead 
  | TPrint 
  | TIf 
  | TThen 
  | TElse 
  | TIterate 
  | TSemi 
  | TColon
  | TDoubleColon
  | TDot
  | TComma
  | TLParen 
  | TRParen 
  | TLBrace 
  | TRBrace 
  | TLBracket
  | TRBracket
  | TPlus 
  | TTimes 
  | TMinus 
  | TDiv 
  | TMod
  | TEq 
  | TNeq
  | TLt 
  | TGt
  | TNot 
  | TAnd 
  | TTInt 
  | TTFloat
  | TTChar
  | TTBool 
  | TTrue 
  | TFalse 
  | TNull
  | TData
  | TReturn
  | TNew
  | TEOF
  deriving (Eq, Ord)

position :: AlexPosn -> (Int, Int)
position (AlexPn _ x y) = (x,y)

mkIdent :: AlexAction Token 
mkIdent (st, _, _, str) len = case take len str of
  "if"      -> pure $ Token (position st) TIf
  "then"    -> pure $ Token (position st) TThen
  "else"    -> pure $ Token (position st) TElse
  "true"    -> pure $ Token (position st) TTrue
  "false"   -> pure $ Token (position st) TFalse
  "null"    -> pure $ Token (position st) TNull
  "int"     -> pure $ Token (position st) TTInt
  "float"   -> pure $ Token (position st) TTFloat
  "char"    -> pure $ Token (position st) TTChar
  "bool"    -> pure $ Token (position st) TTBool
  "read"    -> pure $ Token (position st) TRead
  "print"   -> pure $ Token (position st) TPrint
  "iterate" -> pure $ Token (position st) TIterate
  "data"    -> pure $ Token (position st) TData
  "return"  -> pure $ Token (position st) TReturn
  "new"     -> pure $ Token (position st) TNew
  _ ->  pure $ Token (position st) (TIdent (take len str))

-- mkTypeName :: AlexAction Token
-- mkTypeName p s = Token (position p) (TTypeName s)
mkTypeName :: AlexAction Token
mkTypeName (st, _, _, str) len = pure $ Token (position st) (TTypeName $ take len str)


mkIntNumber :: AlexAction Token
mkIntNumber (st, _, _, str) len = pure $ Token (position st) (TIntNumber $ read $ take len str)


mkFloatNumber :: AlexAction Token
mkFloatNumber (st, _, _, ('.' : xs)) len = pure $ Token (position st) (TFloatNumber $ read $ "0." ++ (take (len-1) xs))
mkFloatNumber (st, _, _, str) len = pure $ Token (position st) (TFloatNumber $ read $ take len str)


mkCharacter :: AlexAction Token
mkCharacter (st, _, _, str) _ = 
    case str of
        [] -> pure $ Token (position st) (TCharacter ' ')  
        [c] -> pure $ Token (position st) (TCharacter c)
        (_ : c : _) -> pure $ Token (position st) (TCharacter c)



simpleToken :: Lexeme -> AlexAction Token
simpleToken lx (st, _, _, _) _ = return $ Token (position st) lx


lexer :: String -> Either String [Token]
lexer s = runAlex s go 
  where 
    go = do 
      output <- alexMonadScan 
      if lexeme output == TEOF then 
        pure [output]
      else (output :) <$> go


instance Show Lexeme where
    show (TIdent id) = "ID:" ++ id
    show (TTypeName name) = "TYPE:" ++ name
    show (TIntNumber x) = "INT:" ++ (show x)
    show (TFloatNumber x) = "FLOAT:" ++ (show x)
    show (TCharacter x) = "CHAR:" ++ [x]
    show (TAssign) = "="
    show (TRead) = "READ"
    show (TPrint) = "PRINT"
    show (TIf) = "IF"
    show (TThen) = "THEN"
    show (TElse) = "ELSE"
    show (TIterate) = "ITERATE"
    show (TSemi) = ";" 
    show (TColon) = ":" 
    show (TDoubleColon) = "::" 
    show (TDot) = "." 
    show (TComma) = "," 
    show (TLParen) = "(" 
    show (TRParen) = ")" 
    show (TLBrace) = "{" 
    show (TRBrace) = "}" 
    show (TLBracket) = "[" 
    show (TRBracket) = "]" 
    show (TPlus) = "+" 
    show (TTimes) = "*" 
    show (TMinus) = "-" 
    show (TDiv) = "/" 
    show (TMod) = "%" 
    show (TEq) = "==" 
    show (TNeq) = "!=" 
    show (TLt) = "<" 
    show (TGt) = ">" 
    show (TNot) = "!" 
    show (TAnd) = "&&" 
    show (TTInt) = "Int"
    show (TTFloat) = "Float"
    show (TTChar) = "Char"
    show (TTBool) = "Bool"
    show (TTrue) = "true"
    show (TFalse) = "false"
    show (TNull) = "null"
    show (TData) = "data"
    show (TReturn) = "RETURN"
    show (TNew) = "NEW"
    show (TEOF) = "TEOF"


showLexer :: String -> IO ()
showLexer input = do
    case lexer input of
        Left err -> putStrLn $ "Lexer error: " ++ err
        Right tokens -> mapM_ (putStrLn . showLexeme) tokens
  where
    showLexeme (Token _ lexeme) = show lexeme

}