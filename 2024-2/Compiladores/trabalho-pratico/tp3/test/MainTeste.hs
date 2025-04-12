-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022
module Main (main) where

import Test.Tasty

import Frontend.Lexer.TestLexer (lexerTests)
import Frontend.Parser.Recursive.TestParser (parserTests)
import Backend.Python.TestExpPythonCodeGen(expPythonCodeGenTests)
import Frontend.Parser.LALR.TestLALR (parserTestsLALR)
import Frontend.Parser.PEG.TestPEG (parserTestsPEG)

main :: IO ()
main = defaultMain tests

tests :: TestTree
tests = testGroup "Tests" (
    lexerTests ++ 
    parserTests ++
    parserTestsLALR ++
    parserTestsPEG ++
    expPythonCodeGenTests
    )

