import Limp.Interpreter.LimpInterpreter (limpInterpProgram)
import qualified Limp.Frontend.Parser.Parser as L
import qualified Limp.Frontend.Semantics.StatementTypeChecker as LS
import qualified Limp.Backend.SVM.StatementCodegen as LSVM
import qualified Limp.Backend.C.StatementCCodegen as LC

import Imp.Interpreter.ImpInterpreter (interpProgram)
import qualified Imp.Frontend.Parser.Parser as IP
import qualified Imp.Frontend.Semantics.StatementTypeChecker as IS
import qualified Imp.Backend.SVM.StatementCodegen as ISVM
import qualified Imp.Backend.C.StatementCCodegen as IC

import qualified Limp.Syntax.Syntax as L
import qualified Imp.Syntax.Syntax as I
import Control.Monad 
import System.Environment
import System.FilePath
import SVM.Instr (pprintCode)


import Documentation.Doc (generateDocumentation) 

-- main function for Imp 

main :: IO ()
main = do 
  opts <- parseOptions 
  either putStrLn runWithOptions opts 

-- running according to options 
runWithOptions :: Option -> IO ()
runWithOptions opts =
  case takeExtension (file opts) of
    ".limp" -> limpRunWithOptions opts
    ".imp"  -> impRunWithOptions opts
    ext     -> putStrLn $ "Error: Unsupported file extension " ++ ext ++ ". Use .limp or .imp"


limpRunWithOptions :: Option -> IO ()
limpRunWithOptions opts 
  = do 
      content <- readFile (file opts)
      let tree = L.impParser content 
      case flag opts of 
        Typed -> 
          case LS.tcProgram tree of 
            Left err -> print err 
            Right _  -> void $ limpInterpProgram tree 
        Untyped -> void $ limpInterpProgram tree 
        SVMCompiler -> limpCompileToSVM tree (file opts)
        CCompiler -> limpCompileToC tree (file opts)
        LimpDocumentation -> generateDocumentation tree (file opts)

impRunWithOptions :: Option -> IO ()
impRunWithOptions opts 
  = do 
      content <- readFile (file opts)
      let tree = IP.impParser content 
      case flag opts of 
        Typed -> 
          case IS.tcProgram tree of 
            Left err -> print err 
            Right _  -> void $ interpProgram tree 
        Untyped -> void $ interpProgram tree 
        SVMCompiler -> impCompileToSVM tree (file opts)
        CCompiler -> impCompileToC tree (file opts)
        _ -> error "Não é possível gerar markdown para imp"

-- compiling to SVM code 

limpCompileToSVM :: L.Program -> FilePath -> IO () 
limpCompileToSVM prog path 
  =  case LS.tcProgram prog of 
        Left err -> print err 
        Right _ -> do 
          code <- LSVM.compileProgram prog 
          let noExt = dropExtension path  
              outPath = noExt <.> ".svm"
          writeFile outPath (pprintCode code)   

impCompileToSVM :: I.Program -> FilePath -> IO () 
impCompileToSVM prog path 
  =  case IS.tcProgram prog of 
        Left err -> print err 
        Right _ -> do 
          code <- ISVM.compileProgram prog 
          let noExt = dropExtension path  
              outPath = noExt <.> ".svm"
          writeFile outPath (pprintCode code) 

-- compiling to C code

limpCompileToC :: L.Program -> FilePath -> IO ()
limpCompileToC prog path
  =  case LS.tcProgram prog of 
        Left err -> print err 
        Right _ -> do 
          let code = LC.programCodegen prog 
              noExt = dropExtension path  
              outPath = noExt <.> ".c"
          writeFile outPath code   

impCompileToC :: I.Program -> FilePath -> IO ()
impCompileToC prog path
  =  case IS.tcProgram prog of 
        Left err -> print err 
        Right _ -> do 
          let code = IC.programCodegen prog 
              noExt = dropExtension path  
              outPath = noExt <.> ".c"
          writeFile outPath code  

-- data type for command line options

data Option 
  = Option {
      flag :: Flag 
    , file :: FilePath
    } deriving Show 

-- flag which determine, what should be executed.

data Flag 
  = Typed 
  | Untyped
  | SVMCompiler
  | CCompiler
  | LimpDocumentation
  deriving Show 

-- error message, when parameters are passed wrong

errorMessage :: IO (Either String Option)
errorMessage 
  = return $ Left str 
    where 
      str = unlines [ "Invalid parameter usage!"
                    , "Imp - compiler"
                    , "Usage:"
                    , "imp <flag> <file>"
                    , "<flag> : type of execution"
                    , " --typed: typed interpreter"
                    , " --untyped: untyped interpreter"
                    , " --svm: compile to SVM bytecode"
                    , " --C: compile to C code"
                    , " --doc: generate de markdown"
                    ]

buildOption :: String -> String -> IO (Either String Option)
buildOption fg fl 
  = case fg of 
      "--type" -> return $ Right (Option Typed fl)
      "--untyped" -> return $ Right (Option Untyped fl)
      "--svm" -> return $ Right (Option SVMCompiler fl)
      "--C" -> return $ Right (Option CCompiler fl)
      "--doc" -> return $ Right (Option LimpDocumentation fl)
      _ -> errorMessage  

parseOptions :: IO (Either String Option)
parseOptions 
  = do 
      args <- getArgs 
      case args of 
        [fg, fl] -> buildOption fg fl 
        _ -> errorMessage



