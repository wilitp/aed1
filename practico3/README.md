# 1. A partir de las siguientes especificaciones expresar en lenguaje natural qu´e devuelven las funciones, agregarles su tipo y derivarlas:

```haskell
-- La suma de cualquier prefijo de xs es positiva
a) psum.xs = <Ai : 0 ≤ i ≤ #xs : sum.(take i xs) ≥ 0>


-- Resolvemos por induccion
psum.(k:ks)
<Ai : 0 ≤ i ≤ #(k:ks) : sum.(take i (k:ks)) ≥ 0>

={Cardinal}

<Ai : 0 ≤ i ≤ 1 + #ks : sum.(take i (k:ks)) ≥ 0>

={Logica}

<Ai : 0 = i V 0 < i ≤ 1 + #ks : sum.(take i (k:ks)) ≥ 0>

={Particion de rango}

<Ai : 0 = i : sum.(take i (k:ks)) ≥ 0> /\ <Ai :0 < i ≤ 1 + #ks : sum.(take i (k:ks)) ≥ 0>

={Rango unitario}

True /\ <Ai :0 < i ≤ 1 + #ks : sum.(take i (k:ks)) ≥ 0>

={Neutro de /\ y logica}

<Ai : 1 <= i ≤ 1 + #ks : sum.(take i (k:ks)) ≥ 0>

={Suma y orden}

<Ai : 0 <= i-1 ≤ #ks : sum.(take i (k:ks)) ≥ 0>

= {Cambio de variable i -> i+1}

<Ai : 0 <= i ≤ #ks : sum.(take (i+1) (k:ks)) ≥ 0>

={Take}

<Ai : 0 <= i ≤ #ks : sum.(k : take i ks) ≥ 0>

={Sum}

<Ai : 0 <= i ≤ #ks : k + sum.(take i ks) ≥ 0>

-- Generalizo

-- Especificacion mas general

psum_gen.xs.n = <Ai : 0 ≤ i ≤ #xs : sum.(take i xs) ≥ n>
psum.xs = psum_gen.xs.0

-- Caso base

psum.xs = <Ai : 0 ≤ i ≤ #[] : sum.(take i []) ≥ n>

={Cardinal, logica, rango unitario}

psum.xs = sum.(take 0 []) ≥ n

={sum y take}

psum.xs = 0 ≥ n


-- Seguimos los mismos pasos de arriba, pero cambiando el 0 del termino por n 

<Ai : 0 ≤ i ≤ #(k:ks) : sum.(take i (k:ks)) ≥ n>

={Cardinal, Lógica y partición}

<Ai : i = 0 : sum.(take i (k:ks)) >= n > /\ <Ai : 1 <= i <= #ks + 1 : sum.(take i (k:ks)) ≥ n>

={Rango unitario}

0 >= n /\ <Ai : 1 <= i <= #ks + 1 : sum.(take i (k:ks)) ≥ n>

={Cambio de variable i-> i+1}

0 >= n /\ <Ai : 1 <= i + 1 <= #ks + 1 : sum.(take i+1 (k:ks)) ≥ n>

={Orden y suma}

0 >= n /\ <Ai : 0 <= i <= #ks : sum.(take i+1 (k:ks)) ≥ n>

={take y sum}

0 >= n /\ <Ai : 0 <= i <= #ks : k + sum.(take i ks) ≥ n>

={Orden y suma}

0 >= n /\ <Ai : 0 <= i <= #ks : sum.(take i ks) ≥ n-k>

={H.I}

0 >= n /\ psum_gen ks (n-k)

```

```haskell

-- Existe un elemento en xs que sea igual a la suma de los elementos anteriores. 

sum_ant.xs = < Ei : 0 <= i < #xs : xs!i = sum.(take i xs) >

-- Induccion

-- Caso base
sum_ant.[]

< Ei : False : []!i = sum.(take i []) >

False

-- Caso inductivo

sum_ant.(k:ks)

={Esp}

< Ei : 0 <= i < #(k:ks) : (k:ks)!i = sum.(take i (k:ks)) >

={Logica}

< Ei : i = 0 V 1 <= i < #(k:ks) : (k:ks)!i = sum.(take i (k:ks)) >

={Particion}

< Ei : i = 0 : (k:ks)!i = sum.(take i (k:ks))> V <Ei : 1 <= i < #(k:ks) : (k:ks)!i = sum.(take i (k:ks)) >

={Rango unitario}

k = 0 V <Ei : 1 <= i < #(k:ks) : (k:ks)!i = sum.(take i (k:ks)) >

={Cardinal y suma y orden}

k = 0 V <Ei : 0 <= i-1 < #ks : (k:ks)!i = sum.(take i (k:ks)) >

={Cambio de variable}

k = 0 V <Ei : 0 <= i < #ks : (k:ks)!i+1 = sum.(take i+1 (k:ks)) >

={Indice, take, sum}

k = 0 V <Ei : 0 <= i < #ks : (ks)!i = k + sum.(take i ks) >

-- Hay que generalizar

sum_ant_gen.xs.n = < Ei : 0 <= i < #xs : xs!i = n + sum.(take i xs) >

-- Caso base

sum_ant_gen.[].n

<Ei : False : []!i = n + sum.(take i [])>

False

-- Caso inductivo

sum_ant_gen.(k:ks).n

={Esp}

< Ei : 0 <= i < #(k:ks) : (k:ks)!i = n + sum.(take i (k:ks)) >

={Logica}

< Ei : i = 0 V 1 <= i < #(k:ks) : (k:ks)!i = n + sum.(take i (k:ks)) >

={Particion}

< Ei : i = 0 : (k:ks)!i = n + sum.(take i (k:ks))> V <Ei : 1 <= i < #(k:ks) : (k:ks)!i = n + sum.(take i (k:ks)) >

={Rango unitario}

k = n V <Ei : 1 <= i < #(k:ks) : (k:ks)!i = n + sum.(take i (k:ks)) >

={Cardinal y suma y orden}

k = n V <Ei : 0 <= i-1 < #ks : (k:ks)!i = n + sum.(take i (k:ks)) >

={Cambio de variable}

k = n V <Ei : 0 <= i < #ks : (k:ks)!i+1 = n + sum.(take i+1 (k:ks)) >

={Indice, take, sum}

k = n V <Ei : 0 <= i < #ks : (ks)!i = (k+n) + sum.(take i ks) >

={H.I}

k = n V sum_ant.ks.(k+n)

sum_ant_gen.[].n = False

sum_ant_gen.xs.n = k == n V sum_ant.ks.(k+n)
sum_ant.xs = sum_ant.xs.0
```
# 2. Especificar formalmente utilizando cuantificadores cada una de las siguientes funciones descriptas informalmente. Luego, derivar soluciones algoítmicas para cada una.

```haskell
-- a) Dado un numero natural, determina si es el cuadrado de un numero
esCuad :: Nat -> Bool

-- Especificacion
esCuad n = <Ei : 0<= i <= n/2 : i*i = n>

-- Derivacion

-- Caso base
esCuad 0 = <Ei : 0<= i <= 0/2 : i*i = 0>

esCuad 0 = <Ei : i = 0 : i*i = 0>

esCuad 0 = <Ei : i = 0 : True>

esCuad 0 = True

-- Caso inductivo

esCuad n+1

<Ei : 0 <= i <= (n+1)/2 : i*i = n+1>

={Matematica}

<Ei : 0 <= 2i <= (n+1) : i*i = n+1>

={Logica}

<Ei : 0 <= 2i <= n V (2i = n+1) : i*i = n+1>

={Particion de rango disjunto}

<Ei : (2i = n+1) : i*i = n+1> V <Ei : 0 <= 2i <= n : i*i = n+1>

={Rango unitario}

(n+1)*(n+1)*(1/4) = n+1 V <Ei : 0 <= 2i <= n : i*i = n+1>

={Orden y suma}

(n+1)*(n+1)*(1/4) = n+1 V <Ei : 0 <= i <= n/2 : i*i = n+1>

={No se puede aplicar H.I, hay que generalizar para poder sumar cosas a n en el termino}

-- Especificacion mas general
esCuadGen n m = <Ei : 0<= i <= n/2 : i*i = n+m>

-- Caso base
esCuadGen 0 m = <Ei : 0<= i <= 0/2 : i*i = 0+m>

={Logica}

<Ei : i=0 : i*i = 0+m>

={Rango unitario}

0 = m

-- Caso inductivo
-- Despues de repetir los pasos de arriba...

(n+1)*(n+1)*(1/4) = n+1+m V <Ei : 0 <= i <= n/2 : i*i = n+(1+m)>

={H.I}

esCuadGen n+1 m = ((n+1)*(n+1)*(1/4) = n+1+m) V esCuadGen n (m+1)

-- La especificacion no contempla el caso de 1, que es su propia raiz, por lo que necesitamos definirlo

esCuadGen 1 0 = True

esCuad n = esCuadGen n 0



-- b) Cuenta la cantidad de prefijos que suman Ocho
sumanOcho :: -> [Num] -> Nat

sumanOcho xs = <Ni : 0 <= i < #xs : xs!i = sum(take i xs)>

-- Derivacion por induccion

-- Caso base

sumanOcho [] =

<Ni : 0 <= i < #[] : []!i = sum(take i [])>

={Sum, Take}

<Ni : 0 <= i < #[] : []!i = 0>

={Rango Vacio del conteo}

0

```



