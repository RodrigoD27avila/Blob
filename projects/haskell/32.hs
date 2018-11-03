count32 :: Integer -> Integer
count32 4294967296 = 0
count32 n = count32 n+1

main = print $ count32 0
