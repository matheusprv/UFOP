-- biblioteca desenvolvida na disciplina

module Frontend.Parser.PEG.Grammar ( module Frontend.Parser.PEG.Grammar
                          , Alternative (..)
                          ) where 

import Control.Applicative
import Data.Char 
import Frontend.Parser.PEG.ParsingExp
import Frontend.Lexer.Lexer

-- running a PEG 

runPEG :: PExp s a -> s -> Either String a 
runPEG p inp =
  case runPExp p inp of
    Pure r -> Right r 
    Commit _ r -> Right r  
    Fail s _ -> Left s

choice :: [PExp s a] -> PExp s a 
choice = foldr (</>) empty

-- packing stuff 

pack :: PExp s a -> PExp s b -> PExp s a -> PExp s b 
pack o r c 
  = f <$> o <*> r <*> c 
    where 
      f _ x _ = x

parens :: PExp [Token] a -> PExp [Token] a
parens p = matchToken TLParen *> p <* matchToken TRParen

braces :: PExp [Token] a -> PExp [Token] a
braces p = matchToken TLBrace *> p <* matchToken TRBrace

brackets :: PExp [Token] a -> PExp [Token] a
brackets p = matchToken TLBracket *> p <* matchToken TRBracket

ltgt :: PExp [Token] a -> PExp [Token] a
ltgt p = matchToken TLt *> p <* matchToken TGt

matchToken :: Lexeme -> PExp [Token] Token
matchToken l = sat (\t -> lexeme t == l)

identifier :: PExp [Token] String
identifier = sat (\t -> case lexeme t of
                        TIdent _ -> True
                        _        -> False) >>= \tok -> case tok of
                                                Token _ (TIdent s) -> pure s
                                                _ -> empty

typer :: PExp [Token] String
typer = sat (\t -> case lexeme t of
                        TTypeName _ -> True
                        _        -> False) >>= \tok -> case tok of
                                                Token _ (TTypeName s) -> pure s
                                                _ -> empty

chainr  ::  PExp [s] a -> PExp [s] (a -> a -> a) -> PExp [s] a
chainr pe po  =  h <$> many (j <$> pe <*> po) <*> pe
  where j x op  =  (x `op`)
        h fs x  =  foldr ($) x fs

chainl  ::  PExp [s] a -> PExp [s] (a -> a -> a) -> PExp [s] a
chainl pe po  =  h <$> pe <*> many (j <$> po <*> pe)
  where j op x  =  (`op` x)
        h x fs  =  foldl (flip ($)) x fs   

greedy :: PExp [s] b -> PExp [s] [b]
greedy =  determ . many

determ :: PExp s a -> PExp s a
determ (PExp p) = PExp (\ts ->
  case p ts of
    Fail msg consumed -> Fail msg consumed
    Pure a            -> Pure a
    Commit rest a     -> Commit rest a )


-- basic stuff 

-- semi :: PExp String ()
-- semi = () <$ token ";"

letter :: PExp String Char 
letter = satisfy isLetter

digit :: PExp String Char 
digit = satisfy isDigit
