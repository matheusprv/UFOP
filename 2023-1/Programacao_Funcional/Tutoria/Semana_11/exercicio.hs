import Parser

type Fuel = Int
type Distance = Int
type Position = (Int, Int)

data Robot
   = Robot {
      energy :: Fuel,         -- actual energy
      distance :: Distance,   -- distance travelled
      current :: Position     -- current position
   } deriving (Eq, Ord)

roboExemplo :: Robot
roboExemplo = Robot 10 5 (0,0)

data Instr
    = North      -- walk north
    | South      -- walk south
    | East       -- walk east
    | West       -- walk west
    | Collect    -- collect material
    | Recharge   -- stay and recharge
    deriving (Eq, Ord)

data Program
    = Program {
        limit :: Position, -- extreme right map position
        init  :: Position, -- initial position of the robot
        instrs :: [Instr]  -- the program
    } deriving (Eq, Ord, Show)


instance Show Robot where
    show (Robot energy distance (x, y)) = "Energy: " ++ show energy ++ "\nDistance: " ++ show distance ++ "\nPosition:\n\tx: " ++ show x ++ "\n\ty: "++ show y

    show robo = "Energy: " ++ show (energy robo) ++ "\nDistance: " ++ show (distance robo) ++ "\nPosition:\n\tx: " ++ show ( (fst . current) robo ) ++ "\n\ty: "++ show ( (\(_, y) -> y) <$> current robo )
    
    --show robo = "Energy: " ++ show (energy robo) ++ "\nDistance: " ++ show (distance robo) ++ "\nPosition:\n\tx: " ++ show (fst $ current robo ) ++ "\n\ty: "++ show ( snd $ current robo )
    
    -- show robo = "Energy: " ++ show (energy robo) ++ "\nDistance: " ++ show (distance robo) ++ "\nPosition:\n\tx: " ++ show x ++ "\n\ty: "++ show y
    --     where
    --         (x, y) = current robo


instance Show Instr where
    show (North) = "North"
    show (South) = "South"
    show (East) = "East"
    show (West) = "West"    
    show (Collect) = "Collect"
    show (Recharge) = "Recharge"


parserPosition :: Parser Char Position
parserPosition = f <$> symbol '[' <*> natural <*> symbol ',' <*> natural <*> symbol ']'
    where 
        f _ x _ y _ = (x, y)

parserInstr :: Parser Char Instr
parserInstr = north <|> south <|> east <|> west <|> collect <|> recharge
    where 
        north = const North <$> symbol 'N'
        south = const South <$> symbol 'S'
        east = const East <$> symbol 'E'
        west = const West <$> symbol 'W'
        collect = const Collect <$> symbol 'C'
        recharge = const Recharge <$> symbol 'R'

parseProgram :: Parser Char Program
parseProgram = Program <$> parserPosition <*> parserPosition <*> greedy parserInstr


runRobot :: [Instr] -> Robot -> Robot
runRobot [] robo = robo
runRobot (x : xs) r@(Robot 0 d c) = runRobot xs r
runRobot (x : xs) r@(Robot e d c@(posX, posY)) = case x of
    North -> mkMove xs ((+0) , (+1))  r
    South -> mkMove xs ((+0) , (+(-1))) r
    East -> mkMove xs ((+1) , (+0)) r
    West -> mkMove xs ((+(-1)) , (+0)) r
    Collect -> if e >= 10 then runRobot xs (Robot (e - 10) d c) else runRobot xs r 
    Recharge -> runRobot xs (Robot (e + 20) d c)

    where 
        mkMove xs (f, g) (Robot e' d' (x', y')) 
            | e' >= 5 = runRobot xs (Robot (e-5) (d+1) (f x', g y'))
            | otherwise = runRobot xs r