main = do
    la <- getLine
    let a = read la
    lb <- getLine
    let b = read lb
    let [d, p, ab] = contabiliza_range a b
    print d
    print p
    print ab

contabiliza_range a b = [defeituosos, perfeitos, abundantes]
    where
        range_classificado = map classifica_numero [a..b] --classifica todo o range fornecido
        defeituosos = length $ filter (==0) $ range_classificado --determina qtd de defeituosos
        perfeitos = length $ filter (==1) $ range_classificado --determina qtd de perfeitos
        abundantes = length $ filter (==2) $ range_classificado--determina qtd de abundantes

classifica_numero x 
    | sum_divisores x < x = 0 --defeituoso
    | sum_divisores x == x = 1 --perfeito
    | otherwise = 2 --abundante
    
sum_divisores x = sum $ filter ((==0) . (x `mod`)) [1..x-1] --soma da lista dos divisores de x