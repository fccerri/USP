main = do -- como main é impuro é sequencial 
    putStrLn $ show "HW"
    la <- getLine --função imputa que recebe uma impura
    let a = read la --função impura recebendo função pura
    lb <- getLine
    let b = read lb
    lc <- getLine
    let c = read lc
    putStrLn $ explica $ baskara a b c
    -- let res = explica $ baskara a b c
    -- putStrLn $ show $ res
        where   
            explica [] = "não ha raizes"
            explica [x] = "raiz dupla" ++ show x
            explica [x',x''] = "duas raizes: " ++ show x'++ "e" ++ show x''

baskara a b c 
    | delta < 0 = []
    | delta == 0 = [x]
    | otherwise = [x', x'']
    where
        delta = b ^ 2 - 4*a*c 
        sqrtD = sqrt delta
        x = (-b) / (2 * a)
        x' = (-b + sqrtD) / (2 * a)
        x'' = (-b - sqrtD) / (2 * a)

sinal2 x = if x < 0
    then -1
    else if x == 0 
        then 0
        else 1

sinal x -- barras são chaves (casos)
    | x < 0 = -1
    | x == 0 = 0
    | otherwise = 1

absoluto x
    | x >= 0 = x
    | otherwise = -x

somaPos [] = 0
somaPs (x:xs)
    | x > 0 = x + somaPos xs
    | otherwise = somaPos xs



