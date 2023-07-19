-- guess :: Int -> IO ()
-- guess valorCorreto = do
    
--     tentativaStr <- getLine
--     let tentativa = read tentativaStr

--     if tentativa == valorCorreto then do{
--         putStrLn "Você acertou.";
--     }
--     else if tentativa < valorCorreto then do{
--         putStrLn "O valor correto é maior do que o que foi escrito";
--         guess valorCorreto;
--     }
--     else do{
--         putStrLn "O valor correto é menor do que o que foi escrito";
--         guess valorCorreto;
--     }

realizarTentativa :: Int -> IO ()
realizarTentativa valorCorreto = do

    tentativaStr <- getLine
    let tentativa = read tentativaStr

    if tentativa == valorCorreto then do
        putStrLn "Você acertou."
    
    else if tentativa < valorCorreto then do
        putStrLn "O valor correto é maior do que o que foi escrito"
    
    else do
        putStrLn "O valor correto é menor do que o que foi escrito"


guess :: Int -> Int -> IO ()
guess valorCorreto qtdTentativas = do
    if qtdTentativas > 0 then do 
        realizarTentativa valorCorreto 
        guess valorCorreto (qtdTentativas-1)

    else putStrLn "As chances acabaram"
    

inicio :: Int -> IO ()
main valorCorreto = guess valorCorreto 5