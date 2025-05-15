main = do
    la <- getLine
    let a = read la
    lb <- getLine
    let b = read lb
    let (d, p, ab) = conta_numeros a b
    print d
    print p
    print ab


conta_numeros a b = (defeituosos, perfeitos, abundantes)
    where
        tipos = map classifica_numero [a..b]
        defeituosos = length (filter (== 0) tipos) 
        perfeitos   = length (filter (== 1) tipos)
        abundantes  = length (filter (== 2) tipos)

classifica_numero a
    | soma_div a < a = 0 --defeituoso
    | soma_div a == a = 1 --perfeito
    | soma_div a > a = 2 --abundante

soma_div a = sum [x | x <- [1..a-1], checa a x] --soma os divisores de um numero

checa n = (==0).(n`mod`)

