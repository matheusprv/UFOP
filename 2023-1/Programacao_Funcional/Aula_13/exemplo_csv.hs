import Parser

type Cell = String
type Line = [Cell]
type CSV = [Line]

--Célula: qualquer string sem \n e ,.
cellParser :: Parser Char Cell
cellParser = greedy (sat restricao)
    where 
        restricao x = x /= '\n' && x /= ','

-- Linhas: células separadas por colunas
lineParser :: Parser Char Line
lineParser = listOf cellParser (symbol ',')

-- Parser para o conteúdo do CSV
csvParser :: Parser Char CSV
csvParser = endBy lineParser (symbol '\n')


parseCSV :: FilePath -> IO ()
parseCSV file
   = do
       content <- readFile file
       print (runParser csvParser content)