-- Matheus Peixoto Ribeiro Vieira 22.1.4104
-- Pedro Henrique R. L. de Oliveira 22.1.4022


-- module Backend.SVM.StatementCodeGen (compileProgram) where


-- import Syntax.Syntax
-- import Backend.SVM.ExpCodegen
-- import SVM.Instr

-- compileProgram :: Prog -> IO Code
-- compileProgram (Prog defs) = runCompileM $ do
--     code <- compileDefs defs
--     bfree <- freeVars (vars blk)
--     pure (code ++ bfree ++ [HALT])

-- compileDefs :: [Def] -> CompileM Code
-- compileDefs xs = concat <$> mapM compileDef xs

-- defsCodeGen :: Def -> CompileM Code
-- defsCodeGen (DataDef d) = undefined
-- defsCodeGen func@(Func {}) = functionCodeGen func

-- --- Function code generation
-- functionCodeGen :: Def -> CompileM Code
-- functionCodeGen 


