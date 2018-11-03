lucky :: (Num a) => a -> String
lucky 7 = "LUCKY NUMBER SEVEN!"
lucky x = "Sorry, you're out of luck, pal!"

sayMe :: (Num a) => a-> String
sayMe 1 = "One!"
sayMe 2 = "Two!"
sayMe 3 = "Three!"
sayMe 4 = "Four!"
sayMe 5 = "Five!"
sayMe x = "Not between 1 and 5"

factorial :: (Num a) => a -> a
factorial 0 = 1
factorial n = n  * factorial (n - 1)

charName :: Char -> String
charName 'a' = "Albert"
charName 'b' = "Broseph"
charName 'c' = "Cecil"

addVectors :: (Num a) => (a,a) -> (a,a) -> (a,a)
addVectors (x1, y1) (x2, y2) = (x1 + x2, y1 + y2)

first :: (a,b,c) -> a
first (x, _, _) = x

second :: (a,b,c) -> b
second (_, y, _) = y

third :: (a,b,c) -> c
third (_, _, z) = z

head' :: [a] -> a
--head' [] = error "Can't call head on an empty list, dummy!"
--head' (x:_) = x

--head' xs = case xs of [] -> error "No head for empty lists"
head' = foldr1 (\x _ -> x)

last' :: [a] -> a
last' = foldl1 (\_ x -> x)

tell :: (Show a) => [a] -> String
tell [] = "The list ins empty"
tell (x:[]) = "The list has one element: " ++ show x
tell (x:y:[]) = "The list has two elements: " ++ show x ++ " and " ++ show y
tell (x:y:_) = "This list is long. The first two elements are: " ++ show x ++ " and " ++ show y

length' :: (Num b) => [a] -> b
length' [] = 0
length' (_:xs) = 1 + length' xs

sum' :: (Num a) => [a] -> a
--sum' [] = 0
--sum' (x:xs) = x + sum' xs
--sum' xs = foldl (\acc x -> acc + x) 0 xs
sum' = foldl (+) 0

capital :: String -> String
capital "" = "Empty string, whoops!"
capital all@(x:xs) = "The first letter of " ++ all ++ " is " ++ [x]

bmiTell :: (RealFloat a) => a -> a -> String
bmiTell weight height
    | bmi <= skinny = "You're underweight, you emo, you"
    | bmi <= normal = "You're supposedly normal.Pffft, I bet you're ugly"
    | bmi <= fat    = "You're fat! Lose some weight, fatty!"
    | otherwise   = "you are a whale, congratulations!"
    where bmi = weight / height ^2
          (skinny, normal, fat) = (18.5, 25.0, 30.0)

max' :: (Ord a) => a -> a -> a
max' a b
    | a > b      = a
    | otherwise  = b

myCompare :: (Ord a) => a -> a -> Ordering
a `myCompare` b
    | a > b     = GT
    | a == b    = EQ
    | otherwise = LT

initials :: String -> String -> String
initials firstname lastname = [f] ++ ". " ++ [l] ++ "."
    where (f:_) = firstname
          (l:_) = lastname

--calcBmis :: (RealFloat a) => [(a,a)] -> [a]
--calcBmis xs = [bmi w h | (w,h) <- xs]
--    where bmi weight height = weight / height ^2

calcBmis :: (RealFloat a) => [(a,a)] -> [a]
calcBmis xs = [bmi | (w,h) <- xs, let bmi = w / h ^2, bmi >= 25.0]

cylinder :: (RealFloat a) => a -> a -> a
cylinder r h =
    let sideArea = 2 * pi * r * h
        topArea  = pi * r ^2
    in  sideArea + 2 * topArea

describleList :: [a] -> String
--describleList xs = "The list is " ++ case xs of []  -> "empty."
--                                               [x] -> "a singleton list."
--                                                xs  -> "a longer list."

describleList xs = "The list is " ++ what xs
    where what []  = "empty."
          what [x] = "a simgleton list."
          what xs  = "a lobger list."

maximum' :: (Ord a) => [a] -> a

--maximum' [] = error "maximum of empty list"
--maximum' [x] = x
--maximum' (x:xs) = max x (maximum' xs)

--maximum' (x:xs)
--    | x > maxtail = x
--    | otherwise = maxtail
--    where maxtail = maximum' xs

maximum' = foldr1 (\x acc -> if x > acc then x else acc)

replicate' :: (Num i, Ord i) => i -> a -> [a]
replicate' n x
    | n <= 0    = []
    | otherwise = x:replicate' (n-1) x

take' :: (Num i, Ord i) => i -> [a] -> [a]
take' n _
    | n <= 0   = []
take' _ []     = []
take' n (x:xs) = x : take' (n-1) xs

reverse' :: [a] -> [a]
--reverse' [] = []
--reverse' (x:xs) = reverse' xs ++ [x]
reverse' = foldl (\acc x -> x : acc) []


repeat' :: a -> [a]
repeat' x = x:repeat' x

zip' :: [a] -> [b] -> [(a,b)]
zip' _ [] = []
zip' [] _ = []
zip' (x:xs) (y:ys) = (x,y):zip' xs ys

elem' :: (Eq a) => a -> [a] -> Bool
--elem' a [] = False
--elem' a (x:xs)
--    | a == x    = True
--    | otherwise = a `elem'` xs
elem' y ys = foldl (\acc x -> if x == y then True else acc) False ys

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
    let sSorted = quicksort (filter (<=x) xs) --[a | a <- xs, a <= x]
        bSorted = quicksort (filter (>x) xs)  --[a | a <- xs, a >  x]
    in  sSorted ++ [x] ++ bSorted

multTree :: (Num a) => a -> a -> a -> a
multTree x y z = x * y * z

compareWithHundred :: (Num a, Ord a) => a -> Ordering
compareWithHundred = compare 100

divideByTen :: (Floating a) => a -> a
divideByTen = (/10)

isUpperAlphanum :: Char -> Bool
isUpperAlphanum = (`elem` ['A'..'Z'])

applyTwice :: (a -> a) -> a -> a
applyTwice f x = f (f x)

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys

flip' :: (a -> b -> c) -> b -> a -> c
--flip' f y x = f x y
flip' f = \x y -> f y x

largestDivisible :: (Integral a) => a
largestDivisible = head (filter p [10000,9999..])
    where p x = x `mod` 3892 == 0

chain :: (Integral a) => a -> [a]
chain 1 = [1]
chain n
    | even n = n:chain (n `div` 2)
    | odd n  = n:chain (n*3 + 1)

numLongChains :: Int
--numLongChains = length (filter isLong (map chain [1..100]))
--    where isLong xs = length xs > 15
numLongChains = length (filter (\xs -> length xs > 15) (map chain [1..100]))

addTree :: (Num a) => a -> a -> a -> a
addTree = \x -> \y -> \z -> x + y + z

map' :: (a -> b) -> [a] -> [b]
map' f xs = foldr (\x acc -> f x : acc) [] xs

product' :: (Num a) => [a] -> a
product' = foldr1 (*)

filter' :: (a -> Bool) -> [a] -> [a]
filter' p = foldr (\x acc -> if p x then x : acc else acc) []

sqrtSums :: Int
sqrtSums = length (takeWhile (<1000) (scanl1 (+) (map sqrt [1..]))) + 1
