module Limp.Frontend.Parser.Parser (limpParser) where
import Limp.Frontend.Lexer.Lexer

import Imp.Syntax.Syntax
import Imp.Frontend.Parser.Parser


limpParser :: String -> Program
limpParser = parser . limpLexer