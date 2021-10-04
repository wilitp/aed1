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

sumanOcho xs = <Ni : 0 <= i < #xs :sum(take i xs) = 8>

-- Derivacion por induccion

-- Caso base

sumanOcho [] =

<Ni : 0 <= i < #[] : 8 = sum(take i [])>

={Sum, Take}

<Ni : 0 <= i < #[] : 8 = 0>

={Rango Vacio del conteo}

sumanOcho [] = 0

-- Caso inductivo

sumanOcho (k:ks) = <Ni : 0 <= i < #(k:ks) : 8 = sum(take i (k:ks))>

={Division de siempre}

<Ni : i = 0 : 8 = sum(take i (k:ks))> + <Ni : 1 <= i < #(k:ks) : 8 = sum(take i (k:ks))>

={Cardinal + suma y orden}

<Ni : i = 0 : (k:ks)!i = sum(take i (k:ks))> + <Ni : 0 <= i-1 < #ks : 8 = sum(take i (k:ks))>

={Rango unitario y analisis por casos}

( k = 8 -> 1
  k != 8 -> 0 ) + <Ni : 0 <= i-1 < #ks : 8 = sum(take i (k:ks))>

={Cambio de variable}

( k = 8 -> 1
  k != 8 -> 0 ) + <Ni : 0 <= i < #ks : 8 = sum(take i+1 (k:ks))>

={Take, sum}

( k = 8 -> 1
  k != 8 -> 0 ) + <Ni : 0 <= i < #ks : 8-k = sum(take i ks)>

={Generalizo}

sumanOchoGen xs m = <Ni : 0 <= i < #xs :sum(take i xs) = 8 + m>

-- Caso base

sumanOcho [] =

<Ni : 0 <= i < #[] : 8+m = sum(take i [])>

={Sum, Take}

<Ni : 0 <= i < #[] : 8+m = 0>

={Rango Vacio del conteo}

sumanOcho [] = 0

-- Caso inductivo

sumanOcho (k:ks) = <Ni : 0 <= i < #(k:ks) : 8+m = sum(take i (k:ks))>

={Division de siempre}

<Ni : i = 0 : 8+m = sum(take i (k:ks))> + <Ni : 1 <= i < #(k:ks) : 8+m = sum(take i (k:ks))>

={Cardinal + suma y orden}

<Ni : i = 0 : 8+m = sum(take i (k:ks))> + <Ni : 0 <= i-1 < #ks : 8+m = sum(take i (k:ks))>

={Rango unitario}

(8+m = k -> 1
 8+m /= k -> 0) + <Ni : 0 <= i-1 < #ks : 8+m = sum(take i (k:ks))>

={Cambio de variable}

(8+m = k -> 1
 8+m /= k -> 0) + <Ni : 0 <= i < #ks : 8+m = sum(take i+1 (k:ks))>

={Take, Sum}

(8+m = k -> 1
 8+m /= k -> 0) + <Ni : 0 <= i < #ks : 8+m-k = sum(take i ks)>

={H.I}

(8+m = k -> 1
 8+m /= k -> 0) + sumanOchoGen ks (m-k)

```

#3. Expresar en lenguaje natural cada una de las siguientes expresiones; para ello primero calcular los rangos, ya sea como conjunto de tuplas o una tabla, y evaluar las expresiones para xs = [9, −5, 1, −3] e ys = [9, −5, 3].

```haskell
a) <A as, bs : xs = as ++ bs : sum.as >= 0 >
-- Todo prefijo de xs suma 0 o mas

b) <Min as, bs, cs : xs = as ++ bs ++ cs : sum.bs>
-- La menor suma de un segmento de xs

c) <N as, b, bs : xs = as ++ (b|>bs) : b > sum.bs>
-- Cantidad de elementos que son mayores a la suma de sus siguientes

d) <Max as, bs, cs : xs = as ++ bs ∧ ys = as ++ cs : #as>
-- Maximo prefijo comun entre xs e ys 

```

#4 Expresar utilizando cuantificadores las siguientes sentencias del lenguaje natural; entre paréntesis esté el nombre de la función.

```haskell
a) La lista xs es un segmento inicial de la lista ys (prefijo.xs.ys).

prefijo.xs.ys = <E bs : ys = xs ++ bs : xs = as>

b) La lista xs es un segmento de la lista ys (seg.xs.ys).

seg.xs.ys = <E as, bs, cs : ys = as ++ bs ++ cs : xs = bs>

c) La lista xs es un segmento final de la lista ys (sufijo.xs.ys).

sufijo.xs.ys = <E as, bs : ys = as ++ bs : xs = bs>

={Intercambio r y t}

-- Abajo se simplifica(no se usa bs)
sufijo.xs.ys = <E as, bs : ys = as ++ bs /\ xs = bs : True>

={Leibniz bs = xs => Podemos precindir de as como referencia}

sufijo.xs.ys = <E as : ys = as ++ xs /\ xs = xs : True>

={Neutro de /\}

sufijo.xs.ys = <E as : ys = as ++ xs : True>

d) Las listas xs e ys tienen en común un segmento no vacío (segComun.xs.ys).

segComun.xs.ys = <E (b|>bs) : seg.(b|>bs).xs : seg.(b|>bs).xs >

e) La lista xs posee un segmento que no es ni prefijo ni sufijo y cuyo mínimo es mayor a los valores del prefijo y del sufijo (hayMeseta.xs).

-- xs es segmento interno de ys
segInt.xs.ys = <E a,as,bs,c,cs : ys = (a|>as)++bs++(c|>cs) : xs = bs > 

hayMeseta.xs = <E as, bs, cs : xs = as++bs++cs  : segInt.bs.xs /\ min.bs > max.as /\ min.bs > max.cs >

f) La lista xs de numeros enteros tiene la misma cantidad de elementos pares e impares (balanceada.xs).

balanceada.xs = <N i : 0 <= i < #xs : par.(xs!i)> = <N i : 0 <= i < #xs : !(par.(xs!i))>
```

#5 Derivar las funciones para a y b del punto anterior 
```haskell
a) La lista xs es un segmento inicial de la lista ys (prefijo.xs.ys).

prefijo.xs.ys = <E bs : ys = xs ++ bs : True>

-- Resolvemos por induccion sobre ambas listas
-- Caso base: una de las listas es vacia
-- Caso primera lista
prefijo.[].ys = <E bs : ys = [] ++ bs : True>

={Neutro de ++ y rango unitario}

prefijo.[].ys = True

-- Caso segunda lista
prefijo.xs.[] = <E bs : [] = xs ++ bs : True>

={Concatenacion lista vacia}

prefijo.xs.[] = <E bs : [] = xs = bs : True>

={Logica}

prefijo.xs.[] = <E bs : [] = xs /\ [] = bs : True>

={Intercambio de R y T}

prefijo.xs.[] = <E bs : [] = bs : [] = xs>

={Rango constante}

prefijo.xs.[] = (xs == [])


-- Caso inductivo

prefijo (x|>xs) (y|>ys) = <E bs : (y|>ys) = (x|>xs) ++ bs : True>

={Concatenacion y pegar}

prefijo (x|>xs) (y|>ys) = <E bs : [y] ++ ys = [x] ++ xs ++ bs : True>

={Concatenacion y pegar}

prefijo (x|>xs) (y|>ys) = <E bs : y|>ys = x|>(xs ++ bs) : True>

={Nose}

prefijo (x|>xs) (y|>ys) = <E bs : y = x /\ ys = (xs ++ bs) : True>

={Analisis por casos: y = x; neutro de la /\ }

  prefijo (x|>xs) (y|>ys) = <E bs : ys = (xs ++ bs) : True>

  ={H.I}

  prefijo (x|>xs) (y|>ys) = prefijo xs ys

={Analisis por casos: y != x}

  prefijo (x|>xs) (y|>ys) = <E bs : False /\ ys = (xs ++ bs) : True >
  
  ={Absorvente del /\ }

  prefijo (x|>xs) (y|>ys) = <E bs : False : True >

  ={Rango vacio}

  prefijo (x|>xs) (y|>ys) = False


prefijo (x|>xs) (y|>ys) = (
  x = y -> prefijo xs ys
  x != y -> False
)

b) La lista xs es un segmento de la lista ys (seg.xs.ys).

seg.xs.ys = <E as, cs : ys = as ++ xs ++ cs : True>

-- Induccion sobre ys
-- Caso base
seg.xs.[] = <E as, cs : [] = as ++ xs ++ cs : True>

={Propiedad de concat}

seg.xs.[] = <E as, cs : [] = as /\ [] = xs /\ [] = cs : True>

={Intercambio de rango y termino}

seg.xs.[] = <E as, cs : [] = as /\ [] = cs : [] = xs>

={Rango unitario}

seg.xs.[] = (xs =[]) 

-- Caso inductivo
seg.xs.(y:ys) = <E as, cs : (y|>ys) = as ++ xs ++ cs : True>

={Pegar y concatenar}

<E as, cs : [y] ++ ys = as ++ xs ++ cs : True>

={Tercero excluido}

<E as, cs : [y] ++ ys = as ++ xs ++ cs : as = [] V as != []>

={Particion de rango}

<E as, cs : [y] ++ ys = as ++ xs ++ cs : as = []> V <E as, cs : [y] ++ ys = as ++ xs ++ cs : as != []>

={Leibniz, Neutro de ++, Eliminacion de variable}

<E cs : [y] ++ ys = xs ++ cs : True> V <E as, cs : [y] ++ ys = as ++ xs ++ cs : as != []>

={Especificacion de prefijo}

prefijo xs (y:ys) V <E as, cs : [y] ++ ys = as ++ xs ++ cs : as != []>

={ as = (n:ns) dado que as != []}

prefijo xs (y:ys) V <E (n|>ns), cs : [y] ++ ys = [n] ++ ns ++ xs ++ cs : (n|>ns) != []>

={Prodiedad de listas}

prefijo xs (y:ys) V <E (n|>ns), cs : y = n /\ ys = ns ++ xs ++ cs : (n|>ns) != []>

={Logica}

prefijo xs (y:ys) V <E (n|>ns), cs : y = n /\ ys = ns ++ xs ++ cs : True>

={Particion de casos disjuntos(La disjuncion se da en y = n, que hace que ambos rangos sean disjuntos)}

prefijo xs (y:ys) V <E (n|>ns), cs : False /\ ys = ns ++ xs ++ cs : True> V <E (n|>ns), cs : True /\ ys = ns ++ xs ++ cs : True>

={Logica}

prefijo xs (y:ys) V <E (n|>ns), cs : False : True> V <E (n|>ns), cs : ys = ns ++ xs ++ cs : True>

={Rango vacio}

prefijo xs (y:ys) V Falso V <E (n|>ns), cs : ys = ns ++ xs ++ cs : True>

={Neutro}

prefijo xs (y:ys) V <E (n|>ns), cs : ys = ns ++ xs ++ cs : True>

={Eliminacion de variable}

prefijo xs (y:ys) V <E ns, cs : ys = ns ++ xs ++ cs : True>

={H.I}

prefijo xs (y:ys) V seg xs ys
```

# 6. El predicado eco.xs dice si la palabra xs es la duplicación de un segmento (pensemos en sílabas).

```haskell
eco: String → Bool
eco.xs = <E as, bs : xs = as ++ bs /\ as 6= [] : as = bs >
```

**Calcular el rango para xs =“frufru”; luego decidir si eco.“frufru”.**

| "frufru" | ""       |
| "frufr"  | "u"      |
| "fruf"   | "ru"     |
| "fru"    | "fru"    |
| "fr"     | "ufru"   |
| "f"      | "rufru"  |
| ""       | "frufru" |

# 7. Especificar semiEco : String → Bool que decide si una palabra comienza con eco. Ejemplos que satisfacen semiEco son: “paparulo”, “mamado”, “tetera”, “anana”.

```haskell
semiEco: String → Bool
semiEco.xs = <E as, bs, cs : xs = as++bs++cs : eco.as.bs >

-- Derivacion por induccion
-- Caso base
semiEco.[] = <E as, bs, cs : [] = as++bs++cs : eco.as.bs >

={Rango constante}

semiEco.[] = <E as, bs, cs : False : eco.as.bs >

-- Caso inductivo
semiEco.(x:xs) 

={Esp}

<E as, bs, cs : (x:xs) = as++bs++cs : eco.as.bs >

={Casos disjuntos as =? []}

<E as, bs, cs : (x:xs) = as++bs++cs : eco.as.bs > V <E as, bs, cs : (x:xs) = as++bs++cs : eco.as.bs >

```
