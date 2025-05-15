        main = do
            --leitura

                    




        -- transforma a string em uma lista de numeros


        somaPontos [] _ _  = 0
                    --lista-   -int- -int-      -int-           
        somaPontos (x:y:xs) strike spare  = pontosTotais
            | x == 10 = x*bonus1 + somaPontos (y:xs) (strikeAtt+2) 0
            | x + y == 10 = x*bonus1 + y*bonus2 somaPontos (xs) (strikeAtt-1) 1
            otherwise = x*bonus1 + y*bonus2 + somaPontos(xs) (strikeAtt-1) 0
            where bonus1
                    | strike > 0 = 2
                    | spare > 0 = 2
                    otherwise = 1
                bonus2
                    |strike > 1 = 2
                    otherwise = 1
                strikeAtt
                    | strike > 0 =  strike-1
                    otherwise = 0


        somaPontos (x:y:xs) bonus = pontosTotais
            | x == 10 = x*somaBonus + somaPontos (y:xs) (bonusAtt+2) 
            | x + y == 10 = x*somaBonus1 + y*somaBonus2 somaPontos (xs) (bonusAtt) 
            otherwise = x*bonus1 + y*somaBonus2 + somaPontos(xs) (bonusAtt-1) 
            where somaBonus1
                    | bonus > 0 = 2
                    otherwise = 1
                somaBonus2
                    | bonus > 1 = 2
                    otherwise = 1
                bonusAtt
                    | bonusAtt > 0 =  bonus-1
                    otherwise = 0

