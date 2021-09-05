-- Ejercicio 1

-- a
esCero :: Int -> Bool
esCero = (==0)

-- b
esPositivo :: Int -> Bool
esPositivo = (>=0)

-- c
esVocal :: Char -> Bool
esVocal x = x `elem` "aeiouáéíóúüAEIOUÁÉÍÓÚ"

-- Ejercicio 2


-- a
paraTodo :: [Bool] -> Bool
paraTodo [] = True
paraTodo (x:xs) = x && paraTodo xs

-- b
sumatoria :: [Int] -> Int
sumatoria = sum

-- c
productoria :: [Int] -> Int
productoria = product

-- d
factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial n-1

-- e
promedio :: [Int] -> Int
promedio xs = sumatoria xs `div` length xs 

-- Versión pointfree
promedio' :: [Int] -> Int
promedio' = (div . sumatoria) <*> length

-- Ejercicio 3

pertenece :: Int -> [Int] -> Bool

pertenece _ [] = False

pertenece n (x:xs) = n == x || pertenece n xs 

-- Ejercicio 4

-- a
paraTodo' :: [a] -> (a -> Bool) -> Bool
paraTodo' [] _ = True
paraTodo' (x:xs) f = f x && paraTodo' xs f

-- b
existe' :: [a] -> (a -> Bool) -> Bool
existe' [] _ = False
existe' (x:xs) f = f x || existe' xs f

--c 
sumatoria' :: [a] -> (a->Int) -> Int
sumatoria' [] _ = 0
sumatoria' (x:xs) f = f x + sumatoria' xs f

--d 
productoria' :: [a] -> (a -> Int) -> Int
productoria' [] _ = 1
productoria' (x:xs) f = f x * productoria' xs f


-- Ejercicio 5

paratodo :: [Bool] -> Bool
paratodo xs = paraTodo' xs (==True)

-- Ejercicio 6

-- Revertí el orden de los argumentos en algunas funciones
-- para hacer más fácil escribir las del enunciado en forma point-free

reverseParaTodo' :: (a -> Bool) -> [a] -> Bool
reverseParaTodo' f xs = paraTodo' xs f

reverseExiste' :: (a -> Bool) -> [a] -> Bool
reverseExiste' f xs = existe' xs f

reverseSumatoria' :: (Int -> Int) -> [Int] -> Int
reverseSumatoria' f xs = sumatoria' xs f

reverseMod :: Integral a => a -> a -> a
reverseMod a b = mod b a 

-- a

todosPares :: [Int] -> Bool
todosPares = reverseParaTodo' ((==0) . reverseMod 2)

-- b
hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo n = reverseExiste' ((==0) . reverseMod n)

-- c 
cuadrado :: Int -> Int
cuadrado n = n*n 

rango :: Int -> Int -> [Int]
rango n m = [n..m]

sumaCuadrados :: Int -> Int
sumaCuadrados = reverseSumatoria' cuadrado . rango 1

-- d
factorial' :: Int -> Int
factorial' = productoria . rango 1

-- e 
multiplicaPares :: [Int] -> Int
multiplicaPares = productoria . filter even 

-- Ejercicio 8 Programá una función que dada una lista de números xs, devuelve la lista que resulta de duplicar cada valor de xs.

-- a) Definila usando recursión

duplicaLista :: [Int] -> [Int]
-- duplicaLista [] = []
-- duplicaLista (x:xs) = 2*x : duplicaLista xs

-- b) Definila usando recursión
duplicaLista = map (*2)

-- Ejercicio 9 Programá una función que dada una lista de números xs, calcula una lista que tiene como elementos aquellos números de xs que son pares.

-- a) Definila usando recursión
soloPares :: [Int] -> [Int]

-- soloPares [] = True
-- soloPares (x:xs) = even x && soloPares xs

-- b) Definila usando filter

soloPares = filter even

-- c) Revisá tu definicón del ejercicio 6e. ¿Cómo podés mejorarla?

-- Ya había usado filter :) Pero alguna forma mejor debe haber

-- Ejercicio 10 La función primIgualesA toma un valor y una lista, y cualcula el tramo inicial más largo de la lista cuyos elementos son iguales a ese valor. Por ejemplo:

-- primIgualesA 3 [3,3,4,1] = [3,3]
-- primIgualesA 3 [4,3,3,4,1] = []
-- primIgualesA 3 [] = []
-- primIgualesA 'a' "aaadaa" = "aaa"

-- a) Programá primIgualesA por recursión.

primIgualesA :: Eq a => a -> [a] -> [a]

-- Versión recursiva comentada
-- primIgualesA _ [] = []
-- primIgualesA y (x:xs) | y == x = x : primIgualesA y xs
--                       | otherwise = []

-- b) Programá nuevamente la función utilizando takeWhile
-- Versión con takeWhile
primIgualesA y = takeWhile (==y) 

-- Ejercicio 11 primIguales toma una lista y devuelve el mayor tramo inicial de la lista cuyos elementos son iguales.

-- primIguales [3,3,4,1] = [3,3]
-- primIguales [4,3,3,4,1] = [4]
-- primIguales [] = []
-- primIguales "aaadaa" = "aaa"

-- a) Programá primIguales por recursión

primIguales :: Eq a => [a] -> [a]

-- Versión recursiva comentada
-- primIguales [] = []
-- primIguales (x:xs) | x == head xs = x : primIguales xs
--                    | otherwise = x : []

-- primIguales xs = primIgualesA (head xs) xs
primIguales = (primIgualesA . head) <*> id

