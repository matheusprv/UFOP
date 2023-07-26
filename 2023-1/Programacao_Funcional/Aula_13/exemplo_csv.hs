import Parser

type CSV = [Line]
type Line = [Cell]
type Cell = String

cellParser :: Parser Char Cell
cellParser = greedy $ sat (\x -> x /= ',' && x /= '\n')

lineParser :: Parser Char Line
lineParser = listOf cellParser (symbol ',')

csvParser :: Parser Char CSV
csvParser = endBy lineParser (symbol '\n')