# 1. Considerá la siguiente lista casosCba = [133, 147, 137, 144, 162, 150, 205] de nuevos casos de Covid en la provincia de Córdoba para la semana del 3/8/2020 al 9/8/2020.

### a. ¿Todos los días hubo más de 140 casos?

```noop
<Ax : x E casosCba : x > 140 >
```

### b. ¿Hubo algún día que hubo menos de 144 casos?

```noop
<Ex : x E casosCba : x < 144 >
```


### c. ¿Cada día tuvo más casos que el día anterior?

```noop
<Ai : 1 <= i < casosCba# : casosCba!(i-1) casosCba!i >
```

### d. ¿Hay dos días que hubo menos de 135 casos?


> Revisar notación
```noop
<Sum x : x E casosCba && x < 135 : 1 > == 2
```

### e. Considerando que Santa Fe tuvo el siguiente registro casosSfe = [63, 101, 101, 141, 134, 137, 87]. ¿Es el máximo para Santa Fe menor a todos los registros de Córdoba?

```noop
(<Max x : x E casosSfe : x >) < (<Max y : y E casosCba : y>)
```

# Para cada una de las siguientes fórmulas, describí su significado utilizando el lenguaje natural. Marcá todas las ocurrencias de variables, indicando si son libres o ligadas.

### a. `<Ai : 0 <= i < #xs : xs!i > 140 >`
Para todo índice válido de xs, tenemos que el elemento de xs para ese índice es mayor a 140

Variables ligadas: i
Variables libres: xs

### b. `<Ei : 0 <=i < #xs : xs!i = x>`

Entre los índices válidos de xs, existe uno tal que el elemento de xs para ese índice es igual a x

Variables ligadas: i
Variables libres: xs, x

### c. `<Ai : 0 <=i < #xs : <Ej : 0 <= j < #ys : xs!i = ys!j>>`

Para todo índice válido de xs, se cumple que existe un índice válido de ys tal que el elemento en xs para el primer índice sea igual al elemento ys para el segundo.

Variables ligadas: i, j
Variables libres: xs, ys

### d `<Ai : 0 <= i < #xs-1 : xs!i <= xs!(i+1)>`

Para todo índice válido de xs, exceptuando el último, se cumple que el elemento de xs para ese índice es menor o igual al siguiente.

Variables ligadas: i
Variables libres: xs

# 3. Evaluá las fórmulas anteriores con xs = [141, 134, 137, 87] y xs = [133, 147, 137, 144]. Para los incisos b. y c., considerá x = 134 e ys = [137, 141, 87], respectivamente.

# 4. Para cada una de las siguientes fórmulas, describí su significado utilizando el lenguaje natural. Marcá todas las ocurrencias de variables, indicando si son libres o ligadas.

### a. `<Prod i : 1 <= i <= n : i>`

El producto de todas las i's entre 1 y n cerrado.

Variables libres: n

Variables ligadas: i

### b. `<Sum i : 0 <= i < #xs: xs!i>/#xs`

El promedio de los elementos de xs 

Variables libres: xs
Variables ligadas: i

### c. `<Max i : 0 <= i #xs : xs!i> < <Min i : 0 <= i < #ys : ys!i>`

El mínimo elemento de ys es mayor al máximo elemento de xs.

Variables ligadas: i
Variables libres: xs, ys

### d. `<Ei,j : (2 <= i,j < n) : i * j = n>`

Existen dos números entre 2 y n tal que su producto es igual a n

# 5. Para cada uno de los ítems del ejercicio anterior, evaluá respectivamente con los siguientes valores.

#6. Decidí el tipo de cada variable y de cada una de las expresiones en elenguaje natural. Luego escribí una expresión para cada una de ellas.

### a. m es la cantidad de más contagios diarios en el registro casos.

m : Nat
casos : [Nat]

m = `<Max i : 0 <= i < #xs : xs!i>` 

### b. La posición de la lista xs donde está su mayor elemento. 

La posición = i : Nat

i = `<Min j : 0 <= j <#xs & xs!j = max.xs : j>`
<Max i : i sea indice : i>

### c. La suma de los elementos de xs entre i e i+7

La suma = s : Int
xs = [Int]

s = `<Sum j : 0 <= j < #xs & i <= j <= i+7 : xs!j >`

### d. Los casos del día d son mayores al promedio móvil(promedio de los siete días anteriores a d).

d : Nat

pm : Num (pm es el promedio truncado)
pm = `<Sum i : d-7 <= i < d : casos!i> / 7`

casos!d < pm

### e. La suma de los elementos en la posición par de xs.
### f. n es potencia de 2.

# 7. Calculá los rangos de las siguientes cuantificaciones como fonjuntos de posibles valores. Tomar n = 10, xs = [-3,9,8,9], m=3. Usá tuplas cuando haya más de una variable cuantificada. 

# 8. Simplificá y acplicá, según corresponda, rango vacío, rango unitario o término constante.

### a. `<Ei : i = 3 && par.i : 2 * i = 6>`
= `<Ei : False : 2 * i = 6>`
