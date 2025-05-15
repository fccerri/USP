main = do
    la <- getLine
    let a = read la
    lb <- getLine
    let b = read lb
    lc <- getLine
    let c = read lc
    putStrLn $ area a b c

triangulo a b c
    | a > b + c = False
    | b > c + a = False
    | c > a + b = False
    | otherwise = True

heron a b c = sqrt(p*(p-a)*(p-b)*(p-c))
    where p = (a + b + c)/2

area a b c
    | triangulo a b c = show (heron a b c)
    | otherwise = "-"
        where ar = heron a b c 