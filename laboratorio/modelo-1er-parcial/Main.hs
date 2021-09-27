data Arbol a = Hoja | Rama (Arbol a) a (Arbol a) deriving Show
data ListaAsoc a b = Vacia | Nodo a b ( ListaAsoc a b ) deriving Show
testLa = Nodo 1 2 (Nodo 3 4 (Nodo 5 6 Vacia))
la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b 

laBusca Vacia _ = Nothing

laBusca (Nodo a b l) x = if a==x then Just b else laBusca l x

la_busca = laBusca

t = Rama (Rama Hoja 4 (Rama Hoja 8 Hoja)) 10 (Rama Hoja (-10) Hoja)

aMin (Rama Hoja v Hoja) = v

aMin (Rama a v Hoja) = min v (aMin a)

aMin (Rama Hoja v a) = min v (aMin a)

aMin (Rama a1 v a2) = min v (min (aMin a1) (aMin a2))

a_min :: Ord a => Arbol a -> a
a_min = aMin


separar' :: [a] -> [a] -> [a] -> (a -> Bool) -> ([a], [a])

separar' ac1 ac2 []  _ = (ac1, ac2) 

separar' ac1 ac2 (x:xs) f | f x = separar' (x:ac1) ac2 xs  f
                          | otherwise = separar' ac1 (x:ac2) xs f

separar = separar' [] []

la_existe :: Eq a => ListaAsoc a b -> a -> Bool

laExiste la x = case la_busca la x of
                          Nothing -> False
                          _ -> True
la_existe = laExiste
