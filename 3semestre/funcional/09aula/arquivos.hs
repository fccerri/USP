import System.IO 



main = do 
        fp <- openFile "MonteCastelo.txt" ReadMode
        contents <- hGetContents fp 
        let ls = lines contents
        let l = length ls 
        putStrLn $ show l --so aqui ee percebe que precisa abrir o arquivo
        hClose fp --haskell é lazy, se viesse antes ia dar erro (close não é lazy)
