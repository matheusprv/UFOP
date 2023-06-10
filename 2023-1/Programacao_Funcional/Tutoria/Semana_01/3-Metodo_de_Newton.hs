avarage :: Double -> Double -> Double
avarage a b = (a + b)/2

goodEnough :: Double -> Double -> Bool
goodEnough x guess
    | verifica = True
    | otherwise = False
    where   
        verifica = abs (guess^2 - x) < 0.001 

improve :: Double -> Double -> Double
improve 