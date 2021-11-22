todosEntre b a [] = True

todosEntre b a (x:xs) = x < a && x > b && todosEntre b a xs

maxPrefEntreG b a [x] ps | todosEntre b a ps = length ps
                        | otherwise = 0


maxPrefEntreG b a (x:xs) ps | todosEntre b a ps = length ps `max` maxPrefEntreG b a xs (ps++[x])
                            | otherwise = maxPrefEntreG b a xs (ps++[x])


maxPrefEntre b a xs = maxPrefEntreG b a xs []

queHace b a [] = 0
queHace b a (k:ks) = maxPrefEntre b a (k:ks) `max` queHace b a ks
