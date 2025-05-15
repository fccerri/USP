main = do
    la <- getLine
    let a = read la 
    lb <- getLine
    let b = read lb 
    putStrLn $ show $ maiorDif $ primos a b

maiorDif [] = 0
maiorDif [x] = 0
maiorDif (x:y:xs)
    | y - x > maxTail = y - x
    | otherwise = maxTail
    where
        maxTail = maiorDif (y:xs)

primos a b = filter (>= a) (crivo [2..b])
    where
        crivo [] = []
        crivo (x:xs) = x:(crivo $ filter ((/=0).(`mod` x)) xs)