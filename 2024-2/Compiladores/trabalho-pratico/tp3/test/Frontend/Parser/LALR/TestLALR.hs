-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022
module Frontend.Parser.LALR.TestLALR (parserTestsLALR) where

import Frontend.Parser.LALR.Parser (langParser)
import Syntax.Syntax

import Test.Tasty
import Test.Tasty.HUnit ( testCase, (@?=) )


parserTestsLALR :: [TestTree]
parserTestsLALR = [
        testDataParser
        ,testLangParser
    ]


testDataParser :: TestTree
testDataParser = testGroup "Data" [
        testCase "tipo racional" $  langParser "data Racional { numerador :: Int; denominador :: Int; }" @?=
        Right (Prog [DataDef (Data "Racional" [Decl "numerador" (BType TInt), Decl "denominador" (BType TInt)])])

        , testCase "foo" $ readFile "test/TestFiles/testeData.lang" >>= \fileContent -> langParser fileContent  @?=
            Right (Prog [DataDef (Data "Foo" [Decl "f" (BType TFloat),Decl "i" (BType TInt),Decl "c" (BType TChar),Decl "b" (BType TBool)])])
    ]

testLangParser :: TestTree
testLangParser = testGroup "functions" [
        testCase "exemplo de lang 1" $ langParser "fat(num :: Int) : Int {if (num < 1){ return 1; } else { return num * fat(num-1)[0];}}" @?=
            Right (Prog [Func "fat" (Just [Param "num" (BType TInt)]) (Just (Types (BType TInt) [])) [CmdIfElse (ELValue (LID "num") :<: EInt 1) (Just (CmdBlock [CmdReturn (EInt 1) []]))
            (Just (CmdBlock [CmdReturn (ELValue (LID "num") :*: EFuncCall "fat" (Just (Exps (ELValue (LID "num") :-: EInt 1) [])) (EInt 0)) []]))]])

        , testCase "exemplo de lang 2" $ langParser "divmod(num :: Int, div :: Int) : Int, Int {q = num / div; r = num % div; return q, r; }" @?=
            Right (Prog [Func "divmod" (Just [Param "num" (BType TInt),Param "div" (BType TInt)]) (Just (Types (BType TInt) [BType TInt])) [CmdAssign (LID "q")
            (ELValue (LID "num") :/: ELValue (LID "div")),CmdAssign (LID "r") (ELValue (LID "num") :%: ELValue (LID "div")),CmdReturn (ELValue (LID "q")) [ELValue (LID "r")]]])

        , testCase "exemplo de lang 3" $ langParser "main(args :: Char []) {print fat(10)[0];}" @?=
            Right (Prog [Func "main" (Just [Param "args" (TypeArray (BType TChar))]) Nothing [CmdPrint (EFuncCall "fat" (Just (Exps (EInt 10) [])) (EInt 0))]])

        , testCase "Programa errado" $ langParser "int main(){return 0;}" @?=
            Left "Parse error while processing lexeme: Int\n at line 1, column 1"

        , testCase "Lidando com comentarios" $ langParser "-- Este codigo faz o fatorial \n fat(num :: Int) : Int { if (num < 1){ return 1; } else { return num * fat(num-1)[0];}}" @?=
            Right (Prog [Func "fat" (Just [Param "num" (BType TInt)]) (Just (Types (BType TInt) [])) [CmdIfElse (ELValue (LID "num") :<: EInt 1) (Just (CmdBlock [CmdReturn (EInt 1) []]))
            (Just (CmdBlock [CmdReturn (ELValue (LID "num") :*: EFuncCall "fat" (Just (Exps (ELValue (LID "num") :-: EInt 1) [])) (EInt 0)) []]))]])

        , testCase "Programa extenso" $  readFile "test/TestFiles/teste.lang" >>= \fileContent -> langParser fileContent @?=
            Right (Prog [Func "divmod" (Just [Param "num" (BType TInt),Param "div" (BType TInt)]) (Just (Types (BType TInt) [BType TInt])) [CmdAssign (LID "q") (ELValue (LID "num") :/: ELValue 
            (LID "div")),CmdAssign (LID "r") (ELValue (LID "num") :%: ELValue (LID "div")),CmdReturn (ELValue (LID "q")) [ELValue (LID "r")]],Func "main" (Just [Param "args" (TypeArray (BType TChar))]) 
            Nothing [CmdAssign (LID "a") (EInt 10),CmdAssign (LID "b") (EFloat 0.1),CmdAssign (LID "c") (EChar 'a'),CmdAssign (LID "d") (EBool True),CmdAssign (LID "e") (EBool False),CmdIterate 
            ((ELValue (LID "a") :<: EInt 10) :&&: ELValue (LID "d")) (CmdBlock [CmdIfElse (ELValue (LID "a") :==: EInt 10) (Just (CmdBlock [CmdAssign (LID "b") (EFloat 0.11)])) (Just (CmdBlock [CmdAssign 
            (LID "a") (EParen ((ELValue (LID "a") :+: EInt 5) :-: EInt 1) :*: EParen (EInt 6 :/: EParen (EInt 20 :%: EInt 10))),CmdAssign (LID "a") (EInt 5 :+: EInt 5)])),CmdIf (ELValue (LID "b") :!=: EInt 1) 
            (CmdBlock [CmdPrint (EParen (EInt 2 :+: EInt 1)),CmdRead (LID "e")])])]])

    ]
