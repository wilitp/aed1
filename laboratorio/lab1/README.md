# Laboratorio 1 - Algorítmos y estructuras de datos 1

### 7. Indagá en Hoogle sobre las funciones map y filter. También podés consultar su tipo en ghci con el comando :t

Map y filter son funciones que reciben una función y una lista, y devuelven otra lista.

- Map devuelve una lista de igual longitud, en la que cada elemento es la imagen de aplicar la función recibida al elemento de igual posición en la lista recibida como input.

- Filter devuelve una lista con los elementos de la lista original que cumplen con el predicado(función) recibida.

#### ¿A qué equivale la expresión map succ [1, -4, 6, 2, -8], donde succ n = n+1?

```haskell
map succ [1, -4, 6, 2, -8] = [2, -3, 7, 3, -7]
```

#### ¿Y la expresión filter esPositivo [1, -4, 6, 2, -8]?

```haskell
filter esPositivo [1, -4, 6, 2, -8] = [1, 6, 2]
```

### 12. Decidí si los patrones están bien tipados y si cubren todos los casos de definición.


a)
```haskell
f :: (a,b) -> ...
f x = ...
```
Está bien tipada y cubre todos los casos.

b)
```haskell
f :: (a,b) -> ...
f (x, y) = ...
```

Está bien tipada y cubre todos los casos.

c)
```haskell
f :: [(a,b)] -> ...
f (a, b) = ...
```
Está definición no tipa, ya que el patrón es de tipo tupla de a y b y no una lista de tuplas de a y b.

d)
```haskell
f :: [(a,b)] -> ...
f (x:xs) = ...
```

Está bien tipada pero no cubre el caso en el que la lista es vacía.

e)
```haskell
f :: [(a,b)] -> ...
f ((x, y) : ((a, b) : xs)) = ...
```

Está bien tipada pero no cubre el caso en el que la lista es vacía.

f)
```haskell
f :: [(Int, a)] -> ...
f [(0, a)] = ...
```

Está bien tipada pero no cubre el caso en el que la lista es vacía, tiene más de un elemento o tiene un elemento pero el primer componente de este no es un 0.

g)
```haskell
f :: [(Int, a)] -> ...
f ((x, 1) : xs) = ...
```

Está bien tipada pero no cubre el caso en el que la lista es vacía ni el caso en el que la tupla en la primera posición no tenga un 1 como segundo componente.

h)
```haskell
f :: [(Int, a)] -> ...
f ((1, x) : xs) = ...
```

Está bien tipada pero no cubre el caso en el que la lista es vacía ni el caso en el que la tupla en la primera posición no tenga un 1 como primer componente.

i)
```haskell
f :: (Int -> Int) -> Int -> ...
f a b = ...
```

Está bien tipada y cubre todos los casos posibles.

j) 
```noop
f :: (Int -> Int) -> Int -> ...
f a 3 = ...
```

Está bien tipada pero le falta cubrir los casos en los que el segundo argumento no es un 3

k)
```noop
f :: (Int -> Int) -> Int -> ...
f 0 1 2 = ...
```

Está mal tipada, ya que f no recibe 3 argumentos, y su primer argumento es una función.

l) 
```noop
f :: a -> (a -> a) -> ...
f a g = ...
```

Está bien tipada y cubre todos los casos posibles.

### 13. Dar al menos una definición cuando sea posible(no undefined). ¿Podés dar alguna otra definición alternativa a la que diste en cada caso?

```haskell
-- a) 
f :: (a, b) -> b
f x = snd x

--b)
f :: (a, b) -> c
-- No es posible dar una definición, ya que no tenemos información sobre el tipo c

-- c)
f :: a -> b
-- No es posible dar una definición, ya que no tenemos información sobre el tipo b

--d)
f :: (a -> b) -> a -> b
f g = g

--e)
f :: (a -> b) -> [a] -> [b]
f = map

-- f)
f :: (a -> b) -> a -> c
-- No es posible dar una definición, ya que no tenemos información sobre el tipo c, y la función que recibimos como primer parámetro devuelve el tipo b.

--g)
f :: (a -> b) -> (b -> c) -> a -> c
f g h = h . g
```

En los casos en los que es posible dar una definición, no es posible dar una segunda alternativa debido a que las funciones declaradas son paramétricas y para definir comportamientos distintos necesitaríamos más información sobre los tipos.
