-- variaveis tem valor fixo
main = do --Monad   
    putStrLn "Hello Wolrd!"
    putStrLn (show y) 
    putStrLn $ show y
    putStrLn $ show $ f True
    putStrLn (show (f True))
    putStrLn $ show $ g x --x não é usado, portanto compila  
    putStrLn $ show $ f c

x = x + 1
y = 6
a = True --boleano
c = 5 > y --falso

f True = 5 --funcao f na entrada true
f False = 42 --funcao f na entrada false

g t = 57

h1 x b = if b 
            then x -1 
            else x + 1

j 0  = 1
j x = x * j (x-1) --fatorial 

o1 = [] --lista sem resticao de tipo
o2 = [5, 30, y] --lista numerica
o3 = [True, False, a, x > 3]
o4 = 7:o2 -- 7 cabeca, o2 cauda

tamanhoLista [] = 0 --k de lista vazia é 0
tamanhoLista(x:xs) = 1 + tamanhoLista xs --tamanho da cauda

--pra definir uma funcao primeiro escrever casos especificos