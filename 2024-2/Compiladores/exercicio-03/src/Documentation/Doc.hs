module Documentation.Doc (generateDocumentation) where

import Limp.Syntax.Syntax
import System.Process (callCommand)
import Control.Monad.State

import Documentation.DocStmt


generateDot :: Program -> String
generateDot prog = 
    let (entry, exit, bodyLines) = evalState (flowBlock (unProgram prog)) 0
        header = [ "digraph G {"
                , "  rankdir=TB;"
                , "  start [label=\"Start\", shape=oval];"
                , "  end [label=\"End\", shape=oval];"
                , "  start -> " ++ entry ++ ";"
            ]
        footer =  [exit ++ " -> end;\n}"]

    in unlines (header ++ bodyLines ++ footer)


-- Extraindo os comentarios
filterItemComment :: [Item] -> [String]
filterItemComment [] = []
filterItemComment ((ItemStmt _) : xs) = filterItemComment xs
filterItemComment ((Comment x) : xs) = x : filterItemComment xs

extractCommentaries :: Program -> String
extractCommentaries (Program (Block itens)) = unlines $ map (\x -> x ++ "\n") (filterItemComment itens)


getFileName :: String -> String
getFileName [] = ""
getFileName (x:xs) 
    | x == '.'  = ""
    | otherwise = x : getFileName xs

generateDocumentation :: Program -> FilePath -> IO ()
generateDocumentation prog filePath = do
    let nomeArq = getFileName filePath
    let dotFileConteudo = generateDot prog

    -- Arquivo .dot
    writeFile (nomeArq ++ ".dot") dotFileConteudo
    putStrLn ("Arquivo DOT " ++ nomeArq ++ " gerado")

    -- Arquivo .png
    callCommand $ "dot -Tpng -o" ++ nomeArq ++ ".png " ++ nomeArq ++ ".dot"
    putStrLn ("Arquivo PNG " ++ nomeArq ++ ".png gerado")

    -- Arquivo .md
    writeFile (nomeArq ++ ".md") $ unlines [
            "# Flowchart Documentation", 
            extractCommentaries prog, 
            "![Flowchart]("++ nomeArq ++".png)"
        ]
    putStrLn $ "Arquivo markdown gerado: " ++ nomeArq ++ ".md"


    -- Arquivo PDF 
    callCommand $ "pandoc " ++ nomeArq ++ ".md -o" ++ nomeArq ++ ".pdf"
    putStrLn ("Arquivo PDF " ++ nomeArq ++ ".pdf gerado")
            