
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


suman :: [Int] -> Int -> Int
suman [] _ = 0
suman (k:ks) m | k == m = 1 + suman ks (m-k)
               | otherwise = suman ks (m-k)
               
prefijo [] ys = True
prefijo xs [] = False

-- prefijo (x:xs) (y:ys) = if x == y then prefijo xs ys else False

-- unoAlMedioG [] ks = ks == []
unoAlMedioG ([x]) ks = x==1 && ks == []
unoAlMedioG (x:xs) ks = (x == 1 && xs==[] && ks == []) || unoAlMedioG xs (ks++[x])
