-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022

module Backend.Python.TestExpPythonCodeGen (expPythonCodeGenTests) where

import Syntax.Syntax

import Test.Tasty
import Test.Tasty.HUnit ( testCase, (@?=) )
import Backend.Python.ExpPythonCodegen (expCodeGen)



expPythonCodeGenTests :: [TestTree]
expPythonCodeGenTests = [
                            operations,
                            terminals,
                            parentesis,
                            funcCall,
                            enew
                        ]

operations :: TestTree                        
operations = testGroup "operacoes" [
        testCase "&&" $ expCodeGen (EBool True :&&: EBool False) @?= "True and False"
        , testCase "==" $ expCodeGen (EInt 5 :==: EInt 5) @?= "5 == 5"
        , testCase "!=" $ expCodeGen (EInt 5 :!=: EInt 5) @?= "5 != 5"
        , testCase "<" $ expCodeGen (EInt 5 :<: EInt 5) @?= "5 < 5"
        , testCase ">" $ expCodeGen (EInt 5 :>: EInt 5) @?= "5 > 5"
        , testCase "+" $ expCodeGen (EInt 5 :+: EInt 5) @?= "5 + 5"
        , testCase "-" $ expCodeGen (EInt 5 :-: EInt 5) @?= "5 - 5"
        , testCase "*" $ expCodeGen (EInt 5 :*: EInt 5) @?= "5 * 5"
        , testCase "/" $ expCodeGen (EInt 5 :/: EInt 5) @?= "5 / 5"
        , testCase "%" $ expCodeGen (EInt 5 :%: EInt 5) @?= "5 % 5"
        , testCase "!" $ expCodeGen (ENot (EBool True)) @?= "not(True)"
        , testCase "-" $ expCodeGen (ENeg (EInt 5)) @?= "-5"
    ]

terminals :: TestTree
terminals = testGroup "terminais" [
        testCase "True" $ expCodeGen (EBool True) @?= "True",
        testCase "False" $ expCodeGen (EBool False) @?= "False",
        testCase "None" $ expCodeGen ENull @?= "None",
        testCase "int" $ expCodeGen (EInt 5) @?= "5",
        testCase "float" $ expCodeGen (EFloat 0.1) @?= "0.1",
        testCase "char" $ expCodeGen (EChar 'a') @?= "\"a\""
    ]

parentesis :: TestTree
parentesis = testGroup "parentesis" [
        testCase "(5 + 5)" $ expCodeGen (EParen (EInt 5 :+: EInt 5)) @?= "(5 + 5)"
    ]

funcCall :: TestTree
funcCall = testGroup "funcCall" [
        testCase "teste()[0]" $ expCodeGen (EFuncCall "teste" Nothing (EInt 0)) @?= "teste()[0]",
        testCase "teste((5 + 5))[5]" $ expCodeGen (EFuncCall "teste" (Just (Exps (EParen (EInt 5 :+: EInt 5)) [])) (EInt 5)) @?= "teste((5 + 5))[5]",
        testCase "teste(4, 1, 2)[5]" $ expCodeGen (EFuncCall "teste" (Just (Exps (EInt 4) [EInt 1, EInt 2])) (EInt 5)) @?= "teste(4, 1, 2)[5]"

    ]

enew :: TestTree
enew = testGroup "ENew" [
        testCase "new Int [10]" $ expCodeGen (ENew (BType TInt) [EInt 10]) @?= "[0 for _ in range (10)]",
        testCase "new Bool [10, 5]" $ expCodeGen (ENew (BType TBool) [EInt 10, EInt 5]) @?= "[[False for _ in range (5)] for _ in range (10)]"

    ]