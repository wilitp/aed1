
psumGen :: Int -> [Int] -> Bool
psumGen n [] = 0 >= n
psumGen n (x:xs) = 0 >= n && psumGen (n-x) xs

psum = psumGen 0

sumAnt :: Integer -> [Integer] -> Bool
sumAnt _ [] = False
-- sumAnt acc (x:xs) = x == acc || sumAnt (acc+x) xs
sumAnt n (k:ks) = k == n || sumAnt (k+n) ks

esCuadGen 0 m = 0 == m
esCuadGen 1 0 = True
esCuadGen n m = (n*n*(1/4) == n+m) || esCuadGen (n-1) (m+1)

esCuad n = esCuadGen n 0

