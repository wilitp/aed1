-- 4.b)

-- minimoElemento' :: [Int] -> Int
minimoElemento' :: (Ord a, Bounded a) => [a] -> a
minimoElemento' [] = minBound
minimoElemento' [x] = x
minimoElemento' (x : xs) = x `min` minimoElemento' xs
