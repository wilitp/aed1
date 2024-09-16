import GHC.Float (powerFloat)

-- 4.b)

-- minimoElemento' :: [Int] -> Int
minimoElemento' :: (Ord a, Bounded a) => [a] -> a
minimoElemento' [] = minBound
minimoElemento' [x] = x
minimoElemento' (x : xs) = x `min` minimoElemento' xs

type Punto = (Float, Float)

data Figura = Circulo Punto Float
  deriving (Eq)

aproxPiTerm i = 4 * (powerFloat (-1) i / (2 * i + 1))

aproxPi n = sum (map aproxPiTerm [0 .. n])
