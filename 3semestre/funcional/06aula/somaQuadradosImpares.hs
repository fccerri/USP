import Data.List
import qualified Data.List as DL    
import Data.Maybe (fromMaybe ) --importa apenas fromMaybe

main = do --Main.map evita conflito de nome com funcoes declaradas e as padroes (Prelude)
    putStrLn $ show $ sum $ map (^2) $ filter ((==1).(`mod`2)) a 
    -- . = "bolinha da composicao de funcao"
    --map = percorre
    --

a = [3,4,2,5,1,2,3,4,7,8]

-- aplica uma funcao a todos os elementos
mapa _ [] = [] -- _ = alguma coisa que nao sera usada
mapa f (x:xs) = (f x:(mapa f xs))