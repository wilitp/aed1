# 1. dado el programa:

```haskell
sum : [Num] → Num
sum [] = 0
sum (x:xs) = x + sum xs
```

a) ¿Que hace esta función?
- Suma todos los elementos de una lista.
b) Escriba una especificación de la función con una expresión cuantificada.

```noop
<Sum i : 0<= i < #xs : xs!!i>
```

c) Verifique que esta especificación de la función con una expresión cuantificada.

Inducción

Caso base:

```noop
<Sum i : 0<= i < #[] : []!!i>
<Sum i : false <: []!!i> = 0 = sum []
```

Hipótesis:

```noop
<Sum i : 0<= i < #ks : ks!!i> = sum ks
```

Caso inductivo:

```noop
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
```noop
a) sum_cuad xs = <Sum i : 0 ≤ i < #xs : xs!!i * xs!!i>
```

### Derivación

**Caso base**

```noop
sum_cuad [] = <Sum i : 0 ≤ i < #[] : []!!i * []!!i>

sum_cuad [] = <Sum i : false : []!!i * []!!i>
sum_cuad [] = 0
```

**Hipotesis**

```noop
sum_cuad ks = <Sum i : 0 ≤ i < #ks : ks!!i * ks!!i>
```

**Caso inductivo**

```noop
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

```noop
iga e xs = <Ai : 0 <= i < #xs : xs!i = e>
```


### Derivación por inducción sobre xs

**Caso Base**
```noop
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
```noop
iga e ks = <Ai : 0 <= i < #ks : ks!i = e>
```

**Caso inductivo**

```noop
iga e (k:ks)
<Ai : 0 <= i < #(k:ks) : (k:ks)!i = e>

={}
```


**d)**

```noop
cuantos p xs = <Ni : 0<= i < #xs : p xs!!i>
```

### Derivación por inducción sobre xs

**Caso Base**

```noop
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

```noop
cuantos p ks = <Ni : 0 <= i < #ks : p ks!!i>
```

**Caso inductivo**

```noop
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
```noop
busca e xs = <Min i : 0 <= i < #xs && xs!i = e : i>
```

### Derivación por inducción sobre xs

```noop
busca e [] = <Min i : 0 <= i < #[] && []!i = e : i>

busca e [] = <Min i : False : i>

busca e [] = 0
```

**Paso inductivo**

```noop
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
