{-
Aula 20 de março 
Criamos algumas funções que recebem como parâmetros outras funções 
Portanto, criamos funções mais genéricas 
Falamos dos tipos em Haskell 
-}

main = do 
    putStrLn $ show  a 
    putStrLn $ show $ soma a 
    putStrLn $ show $ somaPos a 
    putStrLn $ show $ somaSe "Pos" a 
    putStrLn $ show $ somaTeste ehPositivo a
    putStrLn $ show $ somaTeste ehNegativo a
    putStrLn $ show $ operaTeste (\x -> x > 0) multiplica 1 a -- multiplica os elementos positivos 
    putStrLn $ show $ soma $ filtra (\x -> x > 0) a 

-- criamos esses testes 
ehPositivo :: Integer -> Bool 
ehPositivo x = x > 0  
-- função que recebe um x de parâmetro e devolve isso (após a ->)
ehPos = \x -> x > 0 
ehNegativo x = x < 0 

multiplica :: Integer -> (Integer -> Integer)
multiplica x y = x * y 
multiplica' x = \y -> x * y 
multiplica'' = \x -> (\y -> x * y)

a :: [Integer] 
a = [3, 5, 1, -9, 42, 50, 90, 10]

-- soma os números do vetor 
soma [] = 0 
soma (x:xs) = x + soma xs 

-- soma os números positivos 
somaPos [] = 0 
somaPos (x:xs)
    | x > 0 = x + somaPos xs
    | otherwise = somaPos xs

somaSe cond [] = 0 
somaSe cond (x:xs) 
    | cond == "Pos" && x > 0 = x + somaSe cond xs 
    | cond == "Neg" && x < 0 = x + somaSe cond xs 
    | cond == "Par" && mod x 2 == 0 = x + somaSe cond xs
    | otherwise = somaSe cond xs  

-- soma os que passarem no teste, é genérico 
somaTeste :: (Integer -> Bool) -> 
somaTeste teste [] = 0 
somaTeste teste (x:xs)
    | teste x = x + somaTeste teste xs 
    | otherwise = somaTeste teste xs 

-- ṕrodutos dos elementos que passarem no teste 
prodTeste teste [] = 1
prodTeste teste (x:xs)
    | teste x = x + prodTeste teste xs 
    | otherwise = prodTeste teste xs 

-- vamos dexar ainda mais genérico 
-- passaremos o operador, o teste
operaTeste teste op neutro [] = neutro -- operaTeste _ _ neutro [] = neutro 
operaTeste teste op neutro (x:xs)
    | teste x = op x $ operaTeste teste op neutro xs 
    | otherwise = operaTeste teste op neutro xs 


-- Haskell Curry 
filtra :: (Integer -> Bool) -> [Integer] -> [Integer] 
filtra teste [] = [] -- ou filtra _ [] = [], porque não usamos o parâmetro 
filtra teste (x:xs)
    | teste x = x:r
    | otherwise = r
      where 
        r = filtra teste xs

-- types

k :: Integer 
k = 5 

m :: Int 
m = 5 