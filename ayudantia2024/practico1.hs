f :: Int -> Bool
f n = any (\(i, j) -> i * j == n) aux
  where
    aux = [(i, j) | i <- [1 .. n - 1], j <- [1 .. n - 1]]
