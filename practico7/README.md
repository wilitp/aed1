# 1. Sea N>=0
- a) Derivar un programa que calcule el menor entero x que satisfaga x^3 + x >= N
- b) Derivar un programa que calcule el mayor entero x que satisfaga x^3 + x <= N

#### a)
Especificacion:

- x^3 + x es una funcion monotona creciente
- x^3 + x siempre tiene el mismo signo que x
- N>=0, por lo que nuestra x resultado va a ser siempre positiva (>=0)

Entonces, podemos buscar el resultado desde 0 para arriba.

Programa intuido:
```haskell
Const N : Int
Var x : Int;
{N>=0}
x := 0;
do x^3+x < N ->
  x := x+1
od
{x^3+x >= N /\ <A i : 0<=i<x : i^3+i < N}

```

Especificacion
```haskell
Const N : Int
Var x : Int;
{N>=0}
S
{x^3+x >= N /\ <A i : 0<=i<=x : i^3+i < N>}
```

Propongo `I = {0<=x<=N /\ <A i : 0<=i<x : i^3+i < N}`
Para que P => I, necesitamos inicializar x como 0

```haskell
Const N : Int
Var x : Int;
{N>=0}
x:=0;
S
{x^3+x >= N /\ <A i : 0<=i<=x : i^3+i < N>}
```
Buscamos la cota:
```haskell
(0<=x<=N /\ <A i : 0<=i<x : i^3+i < N>) /\ !b => (x^3+x >= N /\ <A i : 0<=i<=x : i^3+i < N>)

={Usando <A i : 0<=i<x : i^3+i < N> como premisa, podemos asumir lo mismo en la consecuencia
  Nos queda x^3+x >= N
  Propongo entonces la guarda b = x^3+x < N
  Veamos que sirve:
}

(0<=x<=N /\ <A i : 0<=i<x : i^3+i < N>) /\ !(x^3+x < N) => (x^3+x >= N /\ <A i : 0<=i<=x : i^3+i < N>)

(0<=x<=N /\ <A i : 0<=i<x : i^3+i < N>) /\ x^3+x >= N => (x^3+x >= N /\ <A i : 0<=i<=x : i^3+i < N>)

True
```

Tenemos entonces:
```haskell
Const N : Int
Var x : Int;
{N>=0}
x:=0;
do x^3+x < N ->
  S
od
{x^3+x >= N /\ <A i : 0<=i<=x : i^3+i < N>}
```

Propongo una cota tq cota >= 0 y cuando cota = 0 el ciclo termine
t = N - x^3+x // No me sirve, ya que quizas sea negativa
t= N-x        // Sabemos que N cumple la condicion x^3+x >= N

Solo nos queda derivar el cuerpo del ciclo:

```haskell
{I /\ b /\ t = K}
S
{I /\ t < K}
```

===

```haskell
{(0<=x<=N /\ <A i : 0<=i<x : i^3+i < N>) /\ x^3+x<N /\ N-x = K}
S
{0<=x<=N /\ <A i : 0<=i<x : i^3+i < N> /\ N-x < K}
```

Nos preguntamos: P => Q? No, ya que N-x = K no implica N-x < K.
Tenemos que hacer al menos una asignacion a una variable de la cota.
La cota solo tiene una variable(x), asi que planteamos la asignacion:

```haskell
{(0<=x<=N /\ <A i : 0<=i<x : i^3+i < N>) /\ x^3+x<N /\ N-x = K}
x := X
{0<=x<=N /\ <A i : 0<=i<x : i^3+i < N> /\ N-x < K}
```

Descubramos entonces X:
```haskell
0<=x<=N /\ <A i : 0<=i<x : i^3+i < N> /\ x^3+x<N /\ N-x = K

=>

0<=X<=N /\ <A i : 0<=i<X : i^3+i < N> /\ N-X < K

={Propongo X = x+1
  ya que:
   - por hip tenemos que x<N(cota)
   - Necesitamos que N-x disminuya
   - No podemos asignar ningun valor mayor al siguiente de x, ya que podriamos estar dejando de cumplir x<=N
}

0<=x<=N /\ <A i : 0<=i<x : i^3+i < N> /\ x^3+x<N /\ N-x = K

=>

0<=x+1<=N /\ <A i : 0<=i<x+1 : i^3+i < N> /\ N-(x+1) < N-1

={Aritmetica}

0<=x+1<=N /\ <A i : 0<=i<x+1 : i^3+i < N> /\ N-x < N

={Como la cota es != 0, sabemos que como mucho x puede ser N-1, entonces sabemos que 0<=x+1<=N se cumple
  Sabemos que <A i : 0<=i<x+1 : i^3+i < N>, ya que x^3+x<N y <A i : 0<=i<x : i^3+i < N> por hipotesis
  Sabemos N-x < N ya que N y x son positivos
}
```

Listo, tenemos nuestro programa:
```haskell
Const N : Int
Var x : Int;
{N>=0}
x:=0;
do x^3+x < N ->
  x:=x+1
od
{x^3+x >= N /\ <A i : 0<=i<=x : i^3+i < N>}
```

#### b)
Especificacion
```haskell
Const N : Int
Var x : Int;
{N>=0}
S
{x^3+x <= N /\ <A i : 0<=i<=x : i^3+i <= N> /\ <A i : x<i<=N : i^3+i > N>}
```

Programa intuido:
```haskell
Const N : Int
Var x : Int;
{N>=0}
x := N;
do x^3+x>N ->
  x := x-1
od
{x^3+x <= N /\ <A i : 0<=i<=x : i^3+i <= N> /\ <A i : x<i<=N : i^3+i > N>}
```


Propongo el invariante `{I : 0<=x<=N /\ <A i : x<i : i^3+i > N>}`
Veamos que P no implica I, debido a que x puede ser cualquier cosa. Debemos derivar la siguiente terna:

```haskell
{N>=0}
S0
{I : 0<=x<=N /\ <A i : x<i : i^3+i > N>}
```

Es facil ver que hay que asignarle algo a x. Tenemos:

```haskell
{N>=0}
x := X
{I : 0<=x<=N /\ <A i : x<i : i^3+i > N>}
```

Al no conocer la distancia entre 0 y N, y sabiendo que N>=0, solo podemos probar con x:= N
```haskell
{N>=0}
x := N
{I : 0<=x<=N /\ <A i : x<i : i^3+i > N>}
```

Si probamos esta terna nos queda:
```haskell
N>=0 =>  0<=N<=N /\ <A i : N<i : N^3+N > N>}

True
```

Entonces hasta ahora nuestro programa es:

```haskell
Const N : Int
Var x : Int;
{N>=0}
x:=N;
{I : 0<=x<=N /\ <A i : x<i : i^3+i > N>}
do b ->
  S
od
{x^3+x <= N /\ <A i : 0<=i<=x : i^3+i <= N> /\ <A i : x<i<=N : i^3+i > N>}
```

Buscamos una guarda b tq I /\ !b => Q

```haskell
(0<=x<=N /\ <A i : x<i : i^3+i > N>) /\ !b

=> 

(x^3+x <= N /\ <A i : 0<=i<=x : i^3+i <= N> /\ <A i : x<i<=N : i^3+i > N>)

={
  - La parte <A i : x<i<=N : i^3+i > N> sale por premisa
  - x^3+x <= N no es seguro por ahora
  - <A i : 0<=i<=x : i^3+i <= N> tampoco es seguro
  
  Estas ultimas dos partes se pueden probar si supieramos x^3+x<=N:
    - En el caso de la primera es trivial
    - En el caso de la segunda, tenemos que ver que si x^3+x<=N, entonces esto es verdad para cualquier i<x

  Probamos entonces con !b === x^3+x<=N
                         b  === x^3+x>N
}

b  === x^3+x>N
```

Hasta ahora tenemos:
```haskell
Const N : Int
Var x : Int;
{N>=0}
x:=N;
{I : 0<=x<=N /\ <A i : x<i : i^3+i > N>}
do x^3+x>N ->
  S
od
{I : 0<=x<=N /\ <A i : x<i : i^3+i > N>}
{x^3+x <= N /\ <A i : 0<=i<=x : i^3+i <= N> /\ <A i : x<i<=N : i^3+i > N>}
```

Planteamos la cota t = x.

Sabemos que t>=0 ya que 0^3+0<=N es obviamente True
Sabemos que t=0 => !b, 0^3+0<=N

Ahora solo nos queda derivar el cuerpo del bucle:
```haskell
{I : 0<=x<=N /\ <A i : x<i : i^3+i > N> /\ x^3+x>N /\ x = K}
S
{I : 0<=x<=N /\ <A i : x<i : i^3+i > N> /\ x < K}
```

P no implica Q, entonces tenemos que asignarle algo a la unica variable que tenemos: x
```haskell
{I : 0<=x<=N /\ <A i : x<i : i^3+i > N> /\ x^3+x>N /\ x = K}
x:=X
{I : 0<=x<=N /\ <A i : x<i : i^3+i > N> /\ x < K}
```

Usemos la obligacion de prueba:

```haskell
(0<=x<=N /\ <A i : x<i : i^3+i > N> /\ x^3+x>N /\ x = K)

=> 

(0<=X<=N /\ <A i : X<i : i^3+i > N> /\ X < x)

={Reducimos 0<=X<=N /\ X<x}

=>

(0<=X<N /\ <A i : X<i : i^3+i > N>)

={
  En palabras:
  - X tiene que ser menor a x
  - Sabemos que x = K > 0, por lo que x-1 cumple 0<=X<N

  Probamos entonces con X = x-1
}

=>

(0<=x-1<N /\ <A i : x-1<i : i^3+i > N>)

={0<=x-1<N por hip}

=>
(<A i : x-1<i : i^3+i > N>)

={
  Sabemos x^3+x>N por hip. Y tambien sabemos que cualquier numero mayor a x cumple la misma condicion
}

=> True
```

Listo. Nuestro programa es 

```haskell
Const N : Int
Var x : Int;
{N>=0}
x:=N;
{I : 0<=x<=N /\ <A i : x<i : i^3+i > N>}
do x^3+x>N ->
  x:=x-1
od
{I : 0<=x<=N /\ <A i : x<i : i^3+i > N>}
{x^3+x <= N /\ <A i : 0<=i<=x : i^3+i <= N> /\ <A i : x<i<=N : i^3+i > N>}
```

# 4. Especificar y derivar un programa que, dado un arreglo de enteros, determine si los elementos del arreglo están ordenados de manera creciente.

Intuyo el programa
```haskell
Const A : array[0, N) of Num;
Var i : Int, r : Bool;
{True}
i := 0;
r := True;
do i<N-1 ->
  r = r && A.i < A.(i+1);
  i = i+1
od
{r = <Ai : 0<=i<N-1 : A.i < A.(i+1) >}
```

Especificacion
```haskell
Const A : array[0, N) of Num;
r : Bool;
{True}
S
{r = <Aj : 0<=j<N-1 : A.j < A.(j+1) >}
```

Este programa va a tener que recorrer un arreglo, asi que introduzco un ciclo y una variable i que inicializo desde 0 porque es la primera posicion de nuestro arreglo. Voy a usar i para indexar.

```haskell
Const A : array[0, N) of Num;
Var r : Bool, i : I;
{True}
i = 0;
do b ->
  S
od
{r = <Aj : 0<=j<N-1 : A.j < A.(j+1) >}
```
Propongo el invariante `0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1) >`

Para conseguirlo pense en los valores que va a tomar i para recorrer el arreglo y tambien use la postcondicion reemplazando la constante N-1 por i

Probemos para encontrar el valor inicial de r:

```haskell
{True}
i = 0;
r = R;
{0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)>}

-- Obligacion de prueba
True => 0<=0<N-1 /\ r = <Aj : 0<=j<0 : A.j < A.(j+1)>

0<=N-1 /\ r = <Aj : 0<=j<0 : A.j < A.(j+1)>

0<=N-1 /\ r = <Aj : 0<=j<0 : A.j < A.(j+1)>
-- N es un natural mayor a 0

r = <Aj : 0<=j<0 : A.j < A.(j+1)>

-- Rango vacio del para todo

r = True
```

Hasta ahora tenemos:

```haskell
Const A : array[0, N) of Num;
Var r : Bool, i : I;
{True}
i = 0;
r = True;
do b ->
  S
od
{r = <Aj : 0<=j<N-1 : A.j < A.(j+1) >}
```

Busquemos una b tal que `I /\ !b => Q`

```haskell
(0<=i<N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)>) /\ !b
=> 
(r = <Aj : 0<=j<N-1 : A.j < A.(j+1) >)

-- Proponemos !b === i>=N-1 

(0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)>) /\ i>=N-1
=> 
(r = <Aj : 0<=j<N-1 : A.j < A.(j+1)>)

-- i<=N-1 /\ i>=N-1 === i=N-1

r = <Aj : 0<=j<N-1 : A.j < A.(j+1)> 
=> 
(r = <Aj : 0<=j<N-1 : A.j < A.(j+1) >)

-- p => p

True
```

Hasta ahora tenemos

```haskell
Const A : array[0, N) of Num;
Var r : Bool, i : I;
{True}
i = 0;
r = True;
do i<N-1 ->
  S
od
{r = <Aj : 0<=j<N-1 : A.j < A.(j+1) >}
```
Ahora queda encontrar una cota t tq t>=0

Propongo `t = (N-1)-i`

Sabemos que N>=1, y sabemos que i=0 en la inicializacion.
Tenemos entonces que t>=0.

Derivemos ahora el cuerpo del ciclo:

```haskell
{0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ i<N-1 /\ (N-1)-i=K}
S
{0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ (N-1)-i>K}
```

Vemos que el cuerpo del ciclo va a tener que hacer una asignacion a i para que la cota decrezca.

```haskell
{0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ i<N-1 /\ (N-1)-i=K}
i:=E
{0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ (N-1)-i>K}
```

Ya que asignamos un nuevo valor a i, entonces quizas tengamos que asignarle un valor a r para mantener el invariante.

```haskell
{0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ i<N-1 /\ (N-1)-i=K}
r, i:=R, E
{0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ (N-1)-i>K}
```

Usamos la obligacion de prueba
```haskell
(0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ i<N-1 /\ (N-1)-i=K) 
=> 
(0<=R<=N-1 /\ R = <Aj : 0<=j<E : A.j < A.(j+1)> /\ (N-1)-E>K)

-- Def de K

(0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ i<N-1 /\ (N-1)-i=K) 
=> 
(0<=R<=N-1 /\ R = <Aj : 0<=j<E : A.j < A.(j+1)> /\ (N-1)-E<(N-1)-i)

-- Propongo E=i+1 para que la cota decrezca

(0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ i<N-1 /\ (N-1)-i=K) 
=> 
(0<=R<=N-1 /\ R = <Aj : 0<=j<E : A.j < A.(j+1)> /\ (N-1)-i-1<(N-1)-i)

-- Aritmetica

(0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ i<N-1 /\ (N-1)-i=K) 
=> 
(0<=R<=N-1 /\ R = <Aj : 0<=j<E : A.j < A.(j+1)> /\ N-1<N)

-- N es natural

(0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ i<N-1 /\ (N-1)-i=K) 
=> 
(0<=(i+1)<=N-1 /\ R = <Aj : 0<=j<i+1 : A.j < A.(j+1)>)

-- Particion de rango y qcy

(0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ i<N-1 /\ (N-1)-i=K) 
=> 
(0<=(i+1)<=N-1 /\ R = A.(i+1) < A.(i+2) && r)

-- Propongo R = R = A.(i+1) < A.(i+2)

(0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ i<N-1 /\ (N-1)-i=K) 
=> 
(0<=(i+1)<=N-1)

-- Sabemos que i<i+1

(0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ i<N-1 /\ (N-1)-i=K) 
=> 
(i+1<=N-1)

-- Sabemos que i<N-1

(0<=i<=N-1 /\ r = <Aj : 0<=j<i : A.j < A.(j+1)> /\ i<N-1 /\ (N-1)-i=K) 
=> 
True
```

Finalmente tenemos:

```haskell
Const A : array[0, N) of Num;
Var r : Bool, i : I;
{True}
i = 0;
r = True;
do i<N-1 ->
  i = i+1;
  r = A.(i+1) < A.(i+2) && r
od
{r = <Aj : 0<=j<N-1 : A.j < A.(j+1) >}
```

# 5. Especificar y derivar un programa que, dados dos arreglos de enteros A y B del mismo tamaño N, calcule el producto punto entre los elementos de ambos arreglos.

Para dos arreglos(a y b) de enteros del mismo tamaño(N), el producto punto(res) es: 

```haskell
res = <Sum i : 0 <= i < N : a[i] * b[i] >
```

Entonces la especificacion de nuestro programa es:

```
{True}
Var a: Array[0,N)
Var b: Array[0,N)
S
{res = <Sum j : 0 <= j < N : a[j] * b[j]>}
```

Vamos a necesitar un ciclo, ya que hay que recorrer los arreglos. Introducimos una variable i para usar cómo índice.
Esta variable la inicializamos en 0, que es el primer indice.
Tambien tenemos que inicializar res.
```
Var a: Array[0,N)
Var b: Array[0,N)
{True}
i:=0;
r:=R;
do b ->
  S
od
{res = <Sum j : 0 <= j < N : a[j] * b[j]>}
```

Planteo un invariante a partir de la postcondicion:

```haskell
{I : 0<=i<=N /\ res = <Sum j : 0 <= j < i : a[j] * b[j]>}
```

Veamos que se cumpla el invariante luego de la inicializacion

```haskell
{True}
i, res :=0, R;
{I : 0<=i<=N /\ res = <Sum j : 0 <= j < i : a[j] * b[j]>}

-- Obligacion de prueba

True 
=>
(I : 0<=0<=N /\ R = <Sum j : 0 <= j < 0 : a[j] * b[j]>)

-- Sabemos que N >=0

(R = <Sum j : 0 <= j < 0 : a[j] * b[j]>)

-- Rango vacio de Sum

(R = 0)

-- Propongo R=0

True
```

Hasta ahora tenemos:

```
Var a: Array[0,N)
Var b: Array[0,N)
{True}
i:=0;
r:=0;
do b ->
  S
od
{res = <Sum j : 0 <= j < N : a[j] * b[j]>}
```
Ahora busquemos una guarda b tal que I /\ !b => Q

```haskell
0<=i<=N /\ res = <Sum j : 0 <= j < i : a[j] * b[j]> /\ !b 
=> 
res = <Sum j : 0 <= j < N : a[j] * b[j]>

-- si i fuera N, esto quedaria probado
-- Propongo b = i<N

0<=i<=N /\ res = <Sum j : 0 <= j < i : a[j] * b[j]> /\ i>=N 
=> 
res = <Sum j : 0 <= j < N : a[j] * b[j]>

-- 0<=i<=N /\ i>=N === 0<=i=N 

res = <Sum j : 0 <= j < N : a[j] * b[j]>
=> 
res = <Sum j : 0 <= j < N : a[j] * b[j]>

True
```

```haskell
Var a: Array[0,N)
Var b: Array[0,N)
{True}
i:=0;
r:=0;
do i<N ->
  S
od
{res = <Sum j : 0 <= j < N : a[j] * b[j]>}
```

Ahora buscamos una cota t tq t>=0 
Propongo N-i

Queda derivar el cuerpo del bucle

```haskell
{0<=i<=N /\ res = <Sum j : 0 <= j < i : a[j] * b[j]> /\ i<N /\ N-i=T}
S
{0<=i<=N /\ res = <Sum j : 0 <= j < i : a[j] * b[j]> /\ N-i<T}
```
