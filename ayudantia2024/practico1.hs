-- Laboratorio 1
--
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

{-# HLINT ignore "Use foldr" #-}

esCero :: Int -> Bool
esCero x = x == 0

esPositivo :: Int -> Bool
esPositivo x = x > 0

esVocal :: Char -> Bool
esVocal = (`elem` "aeiou")

valorAbsoluto :: Int -> Int
valorAbsoluto x
  | x >= 0 = x
  | otherwise = -x

-- Laboratorio 2

paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x : xs) = x && paratodo xs

sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x : xs) = x + sumatoria xs

productoria :: [Int] -> Int
productoria [] = 1
productoria (x : xs) = x * productoria xs

factorial :: Int -> Int
factorial x = productoria [1 .. x]

promedio :: [Int] -> Int
promedio xs = div (sumatoria xs) (length xs)

-- Laboratorio 3

f3a :: [Int] -> Bool
f3a [] = True
f3a (x : xs) = x > 0 && f3a xs

f3b :: Int -> [Int] -> Bool
f3b _ [] = False
f3b z (x : xs) = (z == x) && f3b z xs

f3c xs ys = all (`elem` ys) xs

f3d [] = True
f3d [x] = True
f3d (x : z : xs) = x == z && f3d (z : xs)

-- Laboratorio 4

f4a = productoria

f4b = promedio

f4c [] _ = True -- Ver "Rango vacio" en el digesto
f4c _ [] = True -- Ver "Rango vacio" en el digesto
-- Ahora se asume que ninguna de las dos listas es vacia
f4c xs ys = foldr max (xs !! 1) xs < foldr min (ys !! 1) ys

f4d :: Int -> Bool
f4d n = any (\(i, j) -> i * j == n) aux
  where
    aux = [(i, j) | i <- [2 .. n - 1], j <- [2 .. n - 1]]

-- Laboratorio 5
-- lo omito

-- Laboratorio 6

f6b n xs = n `elem` xs && all (n >) xs

f6c xs = product $ filter even xs

f6d xs = product [xs !! i | i <- indexes]
  where
    indexes = filter even [0 .. (length xs - 1)]

-- Laboratorio 7
-- lo omito

-- Laboratorio 9
-- Hago los que me parecen mas interesantes
--
fib :: Int -> Int
fib 0 = 1
fib 1 = 1
fib n = fib (n - 1) + fib (n - 2)

esPrimo :: Int -> Bool
esPrimo n = all (\x -> rem n x /= 0) [2 .. (round . sqrt . fromIntegral $ n)]

-- Observacion: si n es fib(i), entonces i <= n
-- Entonces [1..n] me da el espacio de busqueda
esFib n = any ((== n) . fib) [1 .. n]

todosFib :: [Int] -> Bool
todosFib = all esFib

-- Laboratorio 10
-- definicion recursiva:
-- todosPorDos [] = []
-- todosPorDos (x:xs) = 2*x : todosPorDos xs
todosPorDos = map (* 2)

-- Laboratorio 11

filterPrimos = filter esPrimo

-- Laboratorio 12

primIgualesA :: (Eq a) => a -> [a] -> [a]
-- De derecha a izquierda, ver cual es el segmento mas grande de elementos iguales a n
-- Si un elemento no es igual a n, 'resetteamos' el acumulador a []
-- primIgualesA n = foldr (\x acc -> if x == n then x : acc else []) []
primIgualesA n = takeWhile (== n)
