-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022

import System.Environment (getArgs)

import Frontend.Lexer.Lexer (showLexer, lexer)
import qualified Frontend.Parser.Recursive.Parser as R
import qualified Frontend.Parser.LALR.Parser as L
import qualified Frontend.Parser.PEG.Parser as P

import Backend.Python.StatementPythonCodegen (programCodegen)

import Interpreter.LangInterpreter
import ConvertingToTree (showTree)

import Frontend.Semantics.StatementTypeChecker (tcProg)
import Prelude 

import System.FilePath (replaceExtension)

runLexer :: String -> IO ()
runLexer = showLexer

runRecursive :: String -> IO ()
runRecursive input =
    case lexer input of
        Left err     -> putStrLn ("Lexical analysis error: " ++ err)
        Right tokens -> showTree (R.langParser tokens)

runLALR :: String -> IO()
runLALR input = 
    case L.langParser input of
        Left err    -> putStrLn ("LALR parsing error: " ++ err)
        Right prog  -> do
            _ <- interpProgram prog
            return ()

runPEG :: String -> IO ()
runPEG input =
    case lexer input of
        Left err -> putStrLn ("Lexical analysis error: " ++ err)
        Right tokens ->
            case P.langParserPEG tokens of
                Left err    -> putStrLn ("PEG parsing error: " ++ err)
                Right prog  -> do
                    _ <- interpProgram prog  
                    return ()


typedInterp :: String -> IO ()
typedInterp input =
    case L.langParser input of
        Left err    -> putStrLn ("LALR parsing error: " ++ err)
        Right prog  -> do
            case tcProg prog of
                Left err -> putStrLn ("Semantic analysis error:\n" ++ unlines (map show err))
                Right _ -> do
                    _ <- interpProgram prog  
                    return ()


typedPython :: String -> String -> IO ()
typedPython input filePath =
    case L.langParser input of
        Left err    -> putStrLn ("LALR parsing error: " ++ err)
        Right prog  -> do
            case tcProg prog of
                Left err -> putStrLn ("Semantic analysis error:\n" ++ unlines (map show err))
                Right _ -> do
                    let codigoPython = programCodegen prog 
                    putStrLn codigoPython
                    writeFile (replaceExtension filePath ".py") codigoPython

typedVm :: String -> IO ()
typedVm _ = print "Geração de código para máquina virtual não implmentado"

-- Help message
helpMessage :: String
helpMessage = unlines
  [ "Uso: program [--lexer | --recursive-tree | --lalr | --peg | --typed-interp | --typed-python | --typed-vm | --help] <file-path>",
    "Opções:",
    "\t--lexer            Executa apenas o analisador léxico de lang",
    "\t--recursive-tree   Executa o analisador léxico e o analisador sintático descendente recursivo sob a lista de tokens produzido pelo analisador léxico",
    "\t--lalr             Executa o analisador lexico e o analisador sintático LALR e, com sua saída, executa o código a partir do interpretador",
    "\t--peg              Executa o analisador lexico e o analisador sintático baseado em PEG e, com sua saída, executa o código a partir do interpretador",
    "\t--typed-interp     Executa o analisador léxico, o anlisador sintático LALR, faz a análise semantica e, em seguida, realiza a interpretação do código",
    "\t--typed-python     Executa o analisador léxico, o anlisador sintático LALR, faz a análise semantica e, em seguida, traduz o código para python",
    "\t--typed-vm         Executa o analisador léxico, o anlisador sintático LALR, faz a análise semantica e, em seguida, traduz o código para máquina virtual",
    "\t--help             Exibe esta mensagem de ajuda."
  ]

main :: IO ()
main = do
    args <- getArgs
    case args of
        [flag, filePath] | flag == "--lexer"          -> readFile filePath >>= runLexer
                         | flag == "--recursive-tree" -> readFile filePath >>= runRecursive
                         | flag == "--lalr"           -> readFile filePath >>= runLALR
                         | flag == "--peg"            -> readFile filePath >>= runPEG
                         | flag == "--typed-interp"   -> readFile filePath >>= typedInterp
                         | flag == "--typed-python"   -> readFile filePath >>= \content -> typedPython content filePath
                         | flag == "--typed-vm"       -> readFile filePath >>= typedVm
                         | flag == "--help"           -> putStrLn helpMessage
        ["--help"]                                    -> putStrLn helpMessage
        _                                             -> putStrLn helpMessage
