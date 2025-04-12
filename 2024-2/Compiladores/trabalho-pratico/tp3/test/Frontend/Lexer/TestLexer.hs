-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022
module Frontend.Lexer.TestLexer (lexerTests) where

import Frontend.Lexer.Lexer

import Test.Tasty
import Test.Tasty.HUnit ( testCase, (@?=) )

lexerTests :: [TestTree]
lexerTests = [
                reserverdWords,
                number,
                symbols,
                identifiers,
                newTypes,
                characters,
                comment
            ]

number :: TestTree
number = testGroup "numbers" [
    testCase "int 1" $ lexer "int 1" @?= Right [Token {pos = (1,1), lexeme = TTInt}, Token {pos = (1,5), lexeme = TIntNumber 1},Token {pos = (1,6), lexeme = TEOF}],
    testCase "1" $ lexer "1" @?= Right [Token {pos = (1,1), lexeme = TIntNumber 1},Token {pos = (1,2), lexeme = TEOF}],
    testCase "101.0" $ lexer "101.0" @?= Right [Token {pos = (1,1), lexeme = TFloatNumber 101.0},Token {pos = (1,6), lexeme = TEOF}],
    testCase "pi" $ lexer "3.141526535" @?= Right [Token {pos = (1,1), lexeme = TFloatNumber 3.141526535},Token {pos = (1,12), lexeme = TEOF}],
    testCase "1.25" $ lexer "1.25" @?= Right [Token {pos = (1,1), lexeme = TFloatNumber 1.25},Token {pos = (1,5), lexeme = TEOF}],
    testCase ".25;" $ lexer ".25;" @?= Right [ Token {pos = (1,1), lexeme = TFloatNumber 0.25}, Token {pos = (1,4), lexeme = TSemi} , Token {pos = (1,5), lexeme = TEOF}],
    testCase "float .25" $ lexer "float .25" @?= Right [Token {pos = (1,1), lexeme = TTFloat},Token {pos = (1,7), lexeme = TFloatNumber 0.25},Token {pos = (1,10), lexeme = TEOF}],
    testCase "int .25" $ lexer "int .25" @?= Right [Token {pos = (1,1), lexeme = TTInt},Token {pos = (1,5), lexeme = TFloatNumber 0.25},Token {pos = (1,8), lexeme = TEOF}]
    ]

reserverdWords :: TestTree
reserverdWords = testGroup "Reserverd words" [
        testCase "read" $ lexer "read" @?= Right [Token {pos=(1,1), lexeme = TRead},Token {pos = (1,5), lexeme = TEOF}],
        testCase "print" $ lexer "print" @?= Right [Token {pos=(1,1), lexeme = TPrint},Token {pos = (1,6), lexeme = TEOF}],
        testCase "if" $ lexer "if" @?= Right [Token {pos=(1,1), lexeme = TIf},Token {pos = (1,3), lexeme = TEOF}],
        testCase "then" $ lexer "then" @?= Right [Token {pos=(1,1), lexeme = TThen},Token {pos = (1,5), lexeme = TEOF}],
        testCase "else" $ lexer "else" @?= Right [Token {pos=(1,1), lexeme = TElse},Token {pos = (1,5), lexeme = TEOF}],
        testCase "iterate" $ lexer "iterate" @?= Right [Token {pos=(1,1), lexeme = TIterate},Token {pos = (1,8), lexeme = TEOF}],
        testCase "int" $ lexer "int" @?= Right [Token {pos=(1,1), lexeme = TTInt},Token {pos = (1,4), lexeme = TEOF}],
        testCase "float" $ lexer "float" @?= Right [Token {pos=(1,1), lexeme = TTFloat},Token {pos = (1,6), lexeme = TEOF}],
        testCase "char" $ lexer "char" @?= Right [Token {pos=(1,1), lexeme = TTChar},Token {pos = (1,5), lexeme = TEOF}],
        testCase "bool" $ lexer "bool" @?= Right [Token {pos=(1,1), lexeme = TTBool},Token {pos = (1,5), lexeme = TEOF}],
        testCase "true" $ lexer "true" @?= Right [Token {pos=(1,1), lexeme = TTrue},Token {pos = (1,5), lexeme = TEOF}],
        testCase "false" $ lexer "false" @?= Right [Token {pos=(1,1), lexeme = TFalse},Token {pos = (1,6), lexeme = TEOF}],
        testCase "null" $ lexer "null" @?= Right [Token {pos=(1,1), lexeme = TNull},Token {pos = (1,5), lexeme = TEOF}],
        testCase "data" $ lexer "data" @?= Right [Token {pos=(1,1), lexeme = TData},Token {pos = (1,5), lexeme = TEOF}],
        testCase "return" $ lexer "return" @?= Right [Token {pos=(1,1), lexeme = TReturn},Token {pos = (1,7), lexeme = TEOF}]
    ]

symbols :: TestTree
symbols = testGroup "Symbols" [
        testCase ";" $ lexer ";" @?= Right [Token {pos= (1,1), lexeme = TSemi},Token {pos = (1,2), lexeme = TEOF}],
        testCase ":" $ lexer ":" @?= Right [Token {pos= (1,1), lexeme = TColon},Token {pos = (1,2), lexeme = TEOF}],
        testCase "::" $ lexer "::" @?= Right [Token {pos= (1,1), lexeme = TDoubleColon},Token {pos = (1,3), lexeme = TEOF}],
        testCase "." $ lexer "." @?= Right [Token {pos= (1,1), lexeme = TDot},Token {pos = (1,2), lexeme = TEOF}],
        testCase "," $ lexer "," @?= Right [Token {pos= (1,1), lexeme = TComma},Token {pos = (1,2), lexeme = TEOF}],
        testCase "(" $ lexer "(" @?= Right [Token {pos= (1,1), lexeme = TLParen},Token {pos = (1,2), lexeme = TEOF}],
        testCase ")" $ lexer ")" @?= Right [Token {pos= (1,1), lexeme = TRParen},Token {pos = (1,2), lexeme = TEOF}],
        testCase "{" $ lexer "{" @?= Right [Token {pos= (1,1), lexeme = TLBrace},Token {pos = (1,2), lexeme = TEOF}],
        testCase "}" $ lexer "}" @?= Right [Token {pos= (1,1), lexeme = TRBrace},Token {pos = (1,2), lexeme = TEOF}],
        testCase "[" $ lexer "[" @?= Right [Token {pos= (1,1), lexeme = TLBracket},Token {pos = (1,2), lexeme = TEOF}],
        testCase "]" $ lexer "]" @?= Right [Token {pos= (1,1), lexeme = TRBracket},Token {pos = (1,2), lexeme = TEOF}],
        testCase "+" $ lexer "+" @?= Right [Token {pos= (1,1), lexeme = TPlus},Token {pos = (1,2), lexeme = TEOF}],
        testCase "*" $ lexer "*" @?= Right [Token {pos= (1,1), lexeme = TTimes},Token {pos = (1,2), lexeme = TEOF}],
        testCase "-" $ lexer "-" @?= Right [Token {pos= (1,1), lexeme = TMinus},Token {pos = (1,2), lexeme = TEOF}],
        testCase "/" $ lexer "/" @?= Right [Token {pos= (1,1), lexeme = TDiv},Token {pos = (1,2), lexeme = TEOF}],
        testCase "%" $ lexer "%" @?= Right [Token {pos= (1,1), lexeme = TMod},Token {pos = (1,2), lexeme = TEOF}],
        testCase "==" $ lexer "==" @?= Right [Token {pos= (1,1), lexeme = TEq},Token {pos = (1,3), lexeme = TEOF}],
        testCase "!=" $ lexer "!=" @?= Right [Token {pos= (1,1), lexeme = TNeq},Token {pos = (1,3), lexeme = TEOF}],
        testCase "<" $ lexer "<" @?= Right [Token {pos= (1,1), lexeme = TLt},Token {pos = (1,2), lexeme = TEOF}],
        testCase "!" $ lexer "!" @?= Right [Token {pos= (1,1), lexeme = TNot},Token {pos = (1,2), lexeme = TEOF}],
        testCase "&&" $ lexer "&&" @?= Right [Token {pos= (1,1), lexeme = TAnd},Token {pos = (1,3), lexeme = TEOF}]
    ]

identifiers :: TestTree
identifiers = testGroup "identifiers" [
        testCase "main" $ lexer "main" @?= Right [Token {pos= (1,1), lexeme = TIdent "main"},Token {pos = (1,5), lexeme = TEOF}],
        testCase "int var" $ lexer "int var" @?= Right [Token {pos = (1,1), lexeme = TTInt},Token {pos = (1,5), lexeme = TIdent "var"},Token {pos = (1,8), lexeme = TEOF}],
        testCase "com underline" $ lexer "i_den_ti_fi_ca_dor" @?= Right [Token {pos = (1,1), lexeme = TIdent "i_den_ti_fi_ca_dor"},Token {pos = (1,19), lexeme = TEOF}]
    ]

newTypes :: TestTree
newTypes = testGroup "newTypes" [
        testCase "Teste" $ lexer "Teste" @?= Right [Token {pos= (1,1), lexeme = TTypeName "Teste"},Token {pos = (1,6), lexeme = TEOF}],
        testCase "com underline" $ lexer "I_den_ti_fi_ca_dor" @?= Right [Token {pos = (1,1), lexeme = TTypeName "I_den_ti_fi_ca_dor"},Token {pos = (1,19), lexeme = TEOF}]
    ]

characters :: TestTree
characters = testGroup "characters" [
        testCase "caractere simples 'a'" $ lexer "'a'" @?= Right [Token {pos = (1,1), lexeme = TCharacter 'a'},Token {pos = (1,4), lexeme = TEOF}],
        testCase "'\\n'" $ lexer "\n'\n'" @?= Right [Token {pos = (2,1), lexeme = TCharacter '\n'},Token {pos = (3,2), lexeme = TEOF}],
        testCase "\\t'\t'" $ lexer "\t'\t'" @?= Right [Token {pos = (1,9), lexeme = TCharacter '\t'},Token {pos = (1,18), lexeme = TEOF}],
        testCase "'\b'" $ lexer "'\b'" @?= Right [Token {pos = (1,1), lexeme = TCharacter '\b'},Token {pos = (1,4), lexeme = TEOF}],
        testCase "'\r'" $ lexer "'\r'" @?= Right [Token {pos = (1,1), lexeme = TCharacter '\r'},Token {pos = (1,4), lexeme = TEOF}],
        testCase "\'\\'" $ lexer "\'\\'" @?= Right [Token {pos = (1,1), lexeme = TCharacter '\\'},Token {pos = (1,4), lexeme = TEOF}],
        testCase "'\''" $ lexer "'\''" @?= Right [Token {pos = (1,1), lexeme = TCharacter '\''},Token {pos = (1,4), lexeme = TEOF}]
    ]

comment :: TestTree
comment = testGroup "comment" [
        testCase "--int" $ lexer "-- int " @?= Right [Token {pos = (1,8), lexeme = TEOF}],
        testCase "larger" $ lexer "main(){--int a=15}" @?= Right [Token {pos = (1,1), lexeme = TIdent "main"},Token {pos = (1,5), lexeme = TLParen},Token {pos = (1,6), lexeme = TRParen},Token {pos = (1,7), lexeme = TLBrace},Token {pos = (1,19), lexeme = TEOF}],
        testCase "comment in one line only" $ lexer "main(){--int a=15\n int b=65;}" 
            @?= Right [Token {pos = (1,1), lexeme = TIdent "main"},Token {pos = (1,5), lexeme = TLParen},Token {pos = (1,6), lexeme = TRParen},Token {pos = (1,7), lexeme = TLBrace},Token {pos = (2,2), lexeme = TTInt},Token {pos = (2,6), lexeme = TIdent "b"},Token {pos = (2,7), lexeme = TAssign},Token {pos = (2,8), lexeme = TIntNumber 65},Token {pos = (2,10), lexeme = TSemi},Token {pos = (2,11), lexeme = TRBrace},Token {pos = (2,12), lexeme = TEOF}]
    
    ]