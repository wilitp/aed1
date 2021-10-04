# 1. dado el programa:

```haskell
sum : [Num] → Num
sum [] = 0
sum (x:xs) = x + sum xs
```

a) ¿Que hace esta función?
- Suma todos los elementos de una lista.
b) Escriba una especificación de la función con una expresión cuantificada.

```haskell
<Sum i : 0<= i < #xs : xs!!i>
```

c) Verifique que esta especificación de la función con una expresión cuantificada.

Inducción

Caso base:

```haskell
<Sum i : 0<= i < #[] : []!!i>
<Sum i : false <: []!!i> = 0 = sum []
```

Hipótesis:

```haskell
<Sum i : 0<= i < #ks : ks!!i> = sum ks
```

Caso inductivo:

```haskell
<Sum i : 0 <= i < #(k:ks) : (k:ks)!!i> = sum k:ks
={Caso recursivo de sum}
<Sum i : 0 <= i < #(k:ks) : (k:ks)!!i> = k + sum ks
={hipotesis}
<Sum i : 0 <= i < #(k:ks) : (k:ks)!!i> = k + <Sum i : 0 <= i < #ks : ks!!i>
={}
<Sum i : 0 <= i < #(k:ks) : (k:ks)!!i> = k + <Sum i : 0 <= i < #ks : ks!!i>
```

# 2. A partir de las siguientes especificaciones, dar el tipo de cada función y derivar las soluciones algorítmicas correspondientes.

**a)**
```haskell
a) sum_cuad xs = <Sum i : 0 ≤ i < #xs : xs!!i * xs!!i>
```

### Derivación

**Caso base**

```haskell
sum_cuad [] = <Sum i : 0 ≤ i < #[] : []!!i * []!!i>

sum_cuad [] = <Sum i : false : []!!i * []!!i>
sum_cuad [] = 0
```

**Hipotesis**

```haskell
sum_cuad ks = <Sum i : 0 ≤ i < #ks : ks!!i * ks!!i>
```

**Caso inductivo**

```haskell
sum_cuad (k:ks) = <Sum i : 0 ≤ i < #(k:ks) : (k:ks)!!i * (k:ks)!!i>

={Lógica}
<Sum i : i = 0 V 1 ≤ i < #(k:ks) : (k:ks)!!i * (k:ks)!!i>

={Partición de rango}
<Sum i : i = 0 : (k:ks)!!i * (k:ks)!!i> + <Sum i : 1 ≤ i < #(k:ks) : (k:ks)!!i * (k:ks)!!i>

={Rango unitario}
(k:ks)!!0 * (k:ks)!!0 + <Sum i : 1 ≤ i < #(k:ks) : (k:ks)!!i * (k:ks)!!i>

={Definición de !!}
k*k + <Sum i : 1 ≤ i < #(k:ks) : (k:ks)!!i * (k:ks)!!i>

={Def de cardinal}
k*k + <Sum i : 1 ≤ i < 1 + #(ks) : (k:ks)!!i * (k:ks)!!i>

={Cambio de variable}
k*k + <Sum j : 1 ≤ (j+1) < 1 + #(ks) : (k:ks)!!(j+1) * (k:ks)!!(j+1)>

={Compatibilidad de la suma y el orden}
k*k + <Sum j : 0 ≤ j < #(ks) : (k:ks)!!(j+1) * (k:ks)!!(j+1)>

={Definición de !!}
k*k + <Sum j : 0 ≤ j < #(ks) : ks!!j * :ks!!j>

={Hipótesis}
k*k + sum_cuad ks

```

**b)**

```haskell
iga e xs = <Ai : 0 <= i < #xs : xs!i = e>
```


### Derivación por inducción sobre xs

**Caso Base**
```haskell
iga e [] 

={Esp}

<Ai : 0 <= i < #[] : []!i = e>

={Lógica}

<Ai : False : []!i = e>

={Rango vacio}

True
```

**Caso recursivo**


**HI**
```haskell
iga e ks = <Ai : 0 <= i < #ks : ks!i = e>
```

**Caso inductivo**

```haskell
iga e (k:ks)
<Ai : 0 <= i < #(k:ks) : (k:ks)!i = e>

={}
```


**d)**

```haskell
cuantos p xs = <Ni : 0<= i < #xs : p xs!!i>
```

### Derivación por inducción sobre xs

**Caso Base**

```haskell
cuantos p [] = <Ni : 0 <= i < #[] : p []!!i>

={Def de #}

cuantos p [] = <Ni : 0 <= i < 0 : p []!!i>

={Lógica y definición de conteo}

cuantos p [] = <Sum i : False && p []!!i : 1>

={Lógica}

cuantos p [] = <Sum i : False : 1>

={Rango vacío}

cuantos p [] = 0
```

**Paso inductivo**

Hipótesis:

```haskell
cuantos p ks = <Ni : 0 <= i < #ks : p ks!!i>
```

**Caso inductivo**

```haskell
cuantos p (k:ks) = <Ni : 0 <= i < #(k:ks) : p (k:ks)!!i>

={Def de cardinal}

<Ni : 0 <= i < 1 + #(ks) : p (k:ks)!!i>

={Partición de rango}

<Ni : 0 = i : p (k:ks)!!i> + <Ni : 1 <= i < 1 + #(ks) : p (k:ks)!!i>

={Rango unitario del conteo + definición de indice}

(p k -> 1
 !p k -> 0
)  + <Ni : 1 <= i < 1 + #(ks) : p (k:ks)!!i>

={Comp. de la suma y el órden}

(p k -> 1
 !p k -> 0
)  + <Ni : 0 <= i-1 < #(ks) : p (k:ks)!!i>

={Cambio de variable i por j+1}

(p k -> 1
 !p k -> 0
)  + <Ni : 0 <= j < #(ks) : p (k:ks)!!(j+1)>

={Def de índice}

(p k -> 1
 !p k -> 0
)  + <Ni : 0 <= j < #(ks) : p ks!!j>

={Hipótesis}

(p k -> 1
 !p k -> 0
)  + cuantos p ks

= {Meto sumando al análisis por casos + neutro de la suma}

(p k -> 1 + cuantos p ks
 !p k -> cuantos p ks
)
```

**f)**
```haskell
busca e xs = <Min i : 0 <= i < #xs && xs!i = e : i>
```

### Derivación por inducción sobre xs

```haskell
busca e [] = <Min i : 0 <= i < #[] && []!i = e : i>

busca e [] = <Min i : False : i>

busca e [] = 0
```

**Paso inductivo**

```haskell
busca e (k:ks) = <Min i : 0 <= i < #(k:ks) && (k:ks)!i = e : i>

={Def de #}

<Min i : 0 <= i < 1 + #ks && (k:ks)!i = e : i>

={Partición de rango}

<Min i : i = 0 && (k:ks)!i = e : i> min <Min i : 1 <= i < 1 + #ks && (k:ks)!i = e : i>

={Leibniz}

<Min i : i = 0 && (k:ks)!0 = e : i> min <Min i : 1 <= i < 1 + #ks && (k:ks)!i = e : i>

={Def de indice}

<Min i : i = 0 && k = e : i> min <Min i : 1 <= i < 1 + #ks && (k:ks)!i = e : i>

CASO k = e

  <Min i : i = 0 && True : i> min <Min i : 1 <= i < 1 + #ks && (k:ks)!i = e : i>

  ={Neutro de &&}

  <Min i : i = 0 : i> min <Min i : 1 <= i < 1 + #ks && (k:ks)!i = e : i>
  
  ={Rango unitario}

  0 min <Min i : 1 <= i < 1 + #ks && (k:ks)!i = e : i>
  
  ={Absorvente del min}

  0

CASO k != e

  <Min i : i = 0 && False : i> min <Min i : 1 <= i < 1 + #ks && (k:ks)!i = e : i>

  ={Absorvente de &&}

  <Min i : False : i> min <Min i : 1 <= i < 1 + #ks && (k:ks)!i = e : i>

  ={Rango vacio}

  Infinito min <Min i : 1 <= i < 1 + #ks && (k:ks)!i = e : i>

  ={Neutro del min}

  <Min i : 1 <= i < 1 + #ks && (k:ks)!i = e : i>

  ={Suma y orden}

  <Min i : 0 <= i-1 < #ks && (k:ks)!i = e : i>

  ={Cambio de variable i por i + 1}

  <Min i : 0 <= i < #ks && (k:ks)!(i+1) = e : i+1>

  ={Def de indice}
  
  <Min i : 0 <= i < #ks && ks!i = e : i+1>

  ={Distributividad de suma en min} 

  <Min i : 0 <= i < #ks && ks!i = e : i> + 1

  ={Hipótesis}

  busca e ks + 1

RESULTADO CON ANÁLISIS POR CASOS

busca e (k:ks) = ( e = k -> 0
                   e != k -> (busca e ks) + 1
)
```

# 4. Derivar las siguientes funciones

### a)
```haskell
sum_pot :: Nat -> Nat -> Num
sum_pot x n = <Sum i : 0 <= i <= n : x^i>


-- Caso base

sum_pot x 0 = <Sum i : 0 : x^i>

={rango unitario}

sum_pot x 0 = x^0 = 1


-- Caso inductivo

sum_pot x (k+1)

={Spec}

<Sum i : 0 <= i <= (k+1) : x^i>

={Lógica}

<Sum i : 0 = i V 1 <= i <= (k+1) : x^i>

={Partición de rango}

<Sum i : 0 = i : x^i> + <Sum i : 1 <= i <= (k+1) : x^i>

={Rango unitario}

1 + <Sum i : 1 <= i <= (k+1) : x^i>

={Suma y el orden}

1 + <Sum i : 0 <= i-1 <= k : x^i>

={Cambio de variable i-1 -> j}

1 + <Sum j : 0 <= j <= k : x^(j+1)>

={Potenciacion}

1 + <Sum j : 0 <= j <= k : x^j * x>

={Distributividad del producto en la suma}

1 + <Sum j : 0 <= j <= k : x^j > * x

={Hipótesis inductiva}

sum_pot x (k+1) = 1 + (sum_pot x k) * x


-- Lectura operacional con x = 2 y n = 2

sum_pot 2 2 = 1 + (sum_pot 2 1) * 2

= 1 + (1 + (sum_pot 2 0) * 2) * 2

= 1 + (1 + 2) * 2

= 7
```

### b)


```haskell
-- Computa la aproximacion del coseno del segundo argumento.

cos' :: Nat -> Num -> Num

cos' n x = <Sum i : 0 <= i <= n : (-1)^i * x^(2*i) / (2*i)!>

-- Inducción sobre n

-- Caso base

cos' 0 x

<Sum i : i = 0 : (-1)^i * x^(2*i) / (2*i)!>

={Rango unitario}

(-1)^0 * x^(2*0) / (2*0)!

={Aritmetica}

1 * x^(0) / (0)!

={Aritmetica}

1 * 1 / 1

={Aritmetica}

1


-- Hipótesis

cos' k x = <Sum i : 0 <= i <= k : (-1)^i * x^(2*i) / (2*i)!>

-- Paso Inductivo

cos' (k+1) x

={Esp}

<Sum i : 0 <= i <= (k+1) : (-1)^i * x^(2*i) / (2*i)!>

={Logica}

<Sum i : 0 <= i <= k V i = k+1 : (-1)^i * x^(2*i) / (2*i)!>

={ Partición de rango }

<Sum i : 0 <= i <= k : (-1)^i * x^(2*i) / (2*i)!> + <Sum i : i = k+1 : (-1)^i * x^(2*i) / (2*i)!>

={H.I}

cos'.k.x + <Sum i : i = k+1 : (-1)^i * x^(2*i) / (2*i)!>

={Rango unitario}

cos'.k.x + (-1)^(k+1) * x^(2*(k+1)) / (2*(k+1))!

={Modularizacion, exp viene del ejercicio 2}

cos'.k.x + exp.(-1).(k+1) * exp.x.(2*(k+1)) / factorial (2*(k+1))


-- Derivación de factorial

factorial.x = x!

-- Inducción sobre x

-- Caso base 

factorial.0 = 1

-- Paso inductivo

factorial.(x+1)

={Esp}

(x+1)!

={Matematica}

x! * (x+1)

={H.I}

factorial x * (x+1)


-- Resultado de factorial 

factorial.0 = 1
factorial (x+1) = factorial x * (x+1)

-- Resultado cos'

cos' 0 x = 1
cos'.(k+1).x = cos'.k.x + exp.(-1).(k+1) * exp.x.(2*(k+1)) / factorial (2*(k+1))
```

### c)

```haskell
cubo x = x^3 

-- Inducción sobre x

-- Caso base
x = 0
cubo 0 = 0^3 = 0 

-- Paso inductivo

-- Hipótesis
cubo k = k^3

-- Caso inductivo
cubo (k+1)

={esp}

(k+1)^3

={Matematica}

(k+1) * ((k+1) * (k+1))

={Definición de mult}

mult (k+1) (mult (k+1) (k+1))


-- Derivación de multiplicacion

mult a b = a * b

-- Inducción sobre a
-- Caso base

mult 0 b = 0 * b = 0

-- Paso inductivo

mult (k+1) b 

={esp}

(k+1) * b

={Aritmetica}

k * b + b

={H.I}

mult k b + b


mult 0 _ = 0
mult a b = mult (a-1) b + b


-- Resultado final
cubo 0 = 0
cubo x = mult (x-1) (cubo (x-1))
```

-- Versión sin inducción
### c)

```haskell
cubo x = x^3 

cubo x = x * (x * x)

cubo x = mult x (mult x x)

```

### d)
```haskell
prod_suf :: [Num] → Bool

prod_suf.xs = <Ei : 0 < i <= #xs : <Prod j : 0 < j <= #(drop i xs) : (drop i xs)!j > === xs!(j-1) >

-- Asumimos una función prod
prod_suf.xs = <Ei : 0 < i <= #xs : prod (drop i xs) === xs!(j-1) >

-- Derivamos prod_suf por inducción sobre xs

-- Caso base
prod_suf.[]

={Esp}

prod_suf.[] = <Ei : 0 < i <= #[] : prod (drop i []) === []!(j-1) >

={ Cardinal + logica}

<Ei : False : prod (drop i []) === []!(j-1) >

={ Rango vacio }

False

-- Caso inductivo

prod_suf.(k:ks)

={Esp} 

<Ei : 0 < i <= #(k:ks) : prod (drop i (k:ks)) === (k:ks)!(i-1) >

={Cardinal + Logica}

<Ei : i = 1 V  1 < i <= 1 + #ks : prod (drop i (k:ks)) === (k:ks)!(i-1) >

={Particion de rango}

<Ei : i = 1 : prod (drop i (k:ks)) === (k:ks)!(i-1) > V <Ei : 1 < i <= 1 + #ks : prod (drop i (k:ks)) === (k:ks)!(i-1) >

={ Rango unitario + drop + indice}

(prod ks === k) V <Ei : 1 < i <= 1 + #ks : prod (drop i (k:ks)) === (k:ks)!(i-1) >

={ Suma y orden }

(prod ks === k) V <Ei : 0 < i-1 <= #ks : prod (drop i (k:ks)) === (k:ks)!(i-1) >

={ Cambio de variable i -> j+1}

(prod ks === k) V <Ei : 0 < j <= #ks : prod (drop (j+1) (k:ks)) === (k:ks)!j) >

={ drop }

(prod ks === k) V <Ei : 0 < j <= #ks : prod (drop j ks) === (k:ks)!j) >

={ Indexacion de lista no vacia e indice mayor a 0 }

(prod ks === k) V <Ei : 0 < j <= #ks : prod (drop j ks) === ks!(j-1)) >

={Hipotesis}

(prod ks === k) V prod_suf.(ks)

```

# 5 

### a) Iguales: ve que todos los elementos de una lista sean iguales a los de otra 

**ESTA MAL, ABAJO LO HAGO BIEN**
Yo entendí que había que comparar dos listas, no todos los elementos de una sola lista

```haskell
iguales :: Eq a => [a] -> [a] -> Bool

iguales xs ys = <Ai : 0 <= i < #xs : xs!!i = ys!!i >

-- Lo resolvemos por induccion sobre xs

-- Caso base
iguales [] ys 

={Esp}

<Ai : 0 <= i < #([]) : []!!i = ys!!i >

={Cardina, logica y rango vacio}

iguales [] ys = True


-- Caso inductivo
iguales (k:ks) ys

={Esp}

<Ai : 0 <= i < #(k:ks) : (k:ks)!!i = ys!!i >

={Logica y particion de rango}

<Ai : i = 0 : (k:ks)!!i = ys!!i > /\ <Ai : 1 <= i < #(k:ks) : (k:ks)!!i = ys!!i >

={Rango unitario y leibniz , definicion de cardinal y suma y orden}

k = ys!!0 /\ <Ai : 0 <= i-1 < #ks : (k:ks)!!i = ys!!i >

={Cambio de variable i -> j+1}

k = ys!!0 /\ <Ai : 0 <= j < #ks : (k:ks)!!(j+1) = ys!!(j+1) >

={ys = y:tys, propiedad de indice}

k = ys!!0 /\ <Ai : 0 <= j < #ks : ks!!j = tys!!j >

={H.I}

k = ys!!0 /\ iguales xs tys



```

### a) Iguales: ve que todos los elementos de una lista sean iguales a los de otra

```haskell
iguales :: Eq a => [a] -> [a] -> Bool

iguales xs = <Ai : 0 < i < #xs : xs!!(i-1) == xs!!i>

-- Derivamos por induccion
-- Caso base
iguales [] = <Ai : 0 < i < #[] : []!!(i-1) == []!!i>

True

-- Caso inductivo

iguales (k:ks)

={Esp}

<Ai : 0 < i < #(k:ks) : (k:ks)!!(i-1) == (k:ks)!!i>

={Logica, particion de rango, leibniz}

<Ai : i = 1 : (k:ks)!!(0) == (k:ks)!!1> /\ <Ai : 1 < i < #(k:ks) : (k:ks)!!(i-1) == (k:ks)!!i>

={Rango unitario, indice}

k == ks!!0 /\ <Ai : 1 < i < #(k:ks) : (k:ks)!!(i-1) == (k:ks)!!i>

={Cardinal, suma y orden}

k == ks!!0 /\ <Ai : 0 < i-1 < #ks : (k:ks)!!(i-1) == (k:ks)!!i>

={Cambio de variable i -> j+1}

k == ks!!0 /\ <Ai : 0 < j < #ks : (k:ks)!!(j) == (k:ks)!!(j+1)>

={Indexacion}

k == ks!!0 /\ <Ai : 0 < j < #ks : ks!!(j-1) == ks!!j>

={H.I}

k == ks!!0 /\ iguales ks

-- Resultado

iguales (x:xs) = x == xs!!0 /\ iguales xs

iguales [] = True
```

### b) minimo calcula el minimo valor en una lista no vacia de enteros

```haskell

minimo :: [Int] -> Int
minimo xs = <Min i : 0<= x < #xs : xs!!i>

-- Induccion
-- Caso base
minimo [x] = <Min i : 0 <= x < #[x] : ([x])!!i>

={Cardinal, logica, rango unitario}

minimo [x] = x

-- Caso inductivo

minimo (k:ks)

={Esp}

<Min i : 0<= x < #(k:ks) : (k:ks)!!i>

={Logica y particion de rango, rango unitario, leibniz}

k min <Min i : 1 <= x < #(k:ks) : (k:ks)!!i>

={}

```

### d) prod :: [Num] -> [Num] -> Num calcula el producto escalar entre dos vectores. Si son de longitud distinta, opera con la longitud de la lista mas chica.

```haskell
prod.xs.ys = <Sum i: 0 <= i < #xs && 0 <= i < #ys : xs!i * ys!i >

-- Resolvemos por induccion sobre ambas listas

-- Caso base: Alguna de las listas es vacia
-- Esta prueba vale para ambas listas, ya que queda rango vacio en ambos casos

prod.xs.[] = <Sum i: 0 <= i < #xs && 0 <= i < #[] : xs!i * ys!i >

={Logica}

prod.xs.[] = <Sum i: False : xs!i * ys!i >

={Rango vacio}

prod.xs.[] = 0

-- Caso inductivo: las listas son ambas no vacias

prod.(x|>xs).(y|>ys) = <Sum i: 0 <= i < #(x|>xs) && 0 <= i < #(y|>ys) : (x|>xs)!i * (y|>ys)!i >

={Logica}

<Sum i: i = 0 V (1 <= i < #(x|>xs) && 1 <= i < #(y|>ys)) : (x|>xs)!i * (y|>ys)!i >

={Particion de rango}

<Sum i : i = 0 : (x|>xs)!i * (y|>ys)!i > + <Sum i: i = 0 V (1 <= i < #(x|>xs) && 1 <= i < #(y|>ys)) : (x|>xs)!i * (y|>ys)!i>

={Rango unitario}

x * y + <Sum i: 1 <= i < #(x|>xs) && 1 <= i < #(y|>ys) : (x|>xs)!i * (y|>ys)!i>

={Cardinal, suma y orden}

x * y + <Sum i: 0 <= i-1 < #xs && 0 <= i-1 < #ys : (x|>xs)!i * (y|>ys)!i>

={Cambio de variable i -> i+1, indexacion}

x * y + <Sum i: 0 <= i < #xs && 0 <= i < #ys : xs!i * ys!i>

={Hipótesis}

x * y + prod.xs.ys
```


