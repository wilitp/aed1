# 1 considerar las siguientes funciones

## a) escribí sus tipos

f : Int -> Int

p : [Num] -> Num

g : [Num] -> Num

h : Int -> [Int] -> Int

## b) decir cuales son recursivas y sobre qué argumento hacen recursión

recursivas = {f, g, h}

f hace recusión sobre su único argumento
g hace recusión sobre su único argumento
g hace recusión sobre sus dos argumentos

## c) Evaluá f.4, g[-1, 4, 2] h.0.[3, -2, -2]

f.4 = f.3 + 6 + 1 
    = f.2 + 4 + 1 + 6 + 1 
    = f.1 + 2 + 1 + 4 + 1 + 6 + 1 
    = f.0 + 0 + 1 + 2 + 1 + 4 + 1 + 6 + 1 
    = 1 + 0 + 1 + 2 + 1 + 4 + 1 + 6 + 1 
    = 17

g[-1, 4, 2] = -1 * (1 + g[4, 2])
            = -1 * (1 + g[4, 2])
            = -1 * (1 + 4 * (1 + g[2]))
            = -1 * (1 + 4 * (1 + 2 * (1 + g[])))
            = -1 * (1 + 4 * (1 + 2 * (1 + 0)))
            = -1 * (1 + 4 * 3)
            = -1 * (13)
            = -13

## d) Escribir f usando análisis por casos en vez de pattern matching

f.(n + 1) | f != 0 = f.n + 2 * n + 1
          | f == 0 = 1

## e) Escribir g' tal que g'.xs = g.xs y que g'[0, 4, 2] se encuentre en menos de 4 pasos

g'.(x:xs) | x != 0 = x * (1 + g.xs)
          | x == 0 = 0

