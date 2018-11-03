par :: Int -> Bool
par x = if mod x 2 == 0 then True else False

main = print $ par 57
