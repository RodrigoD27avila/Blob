fermatLastTheorem n = [(a,b,c) | c <- [1..], b <- [1..c], a <- [1..b], a^n + b^n == c^n]

main = print $ fermatLastTheorem 2
