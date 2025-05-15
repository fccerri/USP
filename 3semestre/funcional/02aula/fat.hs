main = do 
    la <- getLine
    let a = read la
    putStrLn $ show $ fat a

fat x 
    | x == 1 = 1
    | otherwise = x * fat (x-1)