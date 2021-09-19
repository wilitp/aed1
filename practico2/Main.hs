
-- Suma las potencias de un número x
-- Version derivada que no entiendo
sumPot _ 0 = 1
sumPot x n = 1 + sumPot x (n-1) * x

-- Version pensada
sumPot' _ 0 = 1
sumPot' x n = x^n + sumPot' x (n-1)


-- factorial
factorial :: (Show a, Fractional a, Eq a) => a -> a 
factorial 0 = 1
factorial x = x * factorial (x-1)

-- Aproximacion de coseno, no funciona en runtime, no se porq :(
cos' :: (Integral a, Fractional a, Show a) => a -> a -> a
cos' 0 _ = 1
cos' k x = cos'(k-1) x + (-1)^(k+1) * x^(2*(k+1)) / factorial (2*(k+1))


mult 0 _ = 0
mult a b = mult (a-1) b + b

cubo x = mult x (mult x x)
