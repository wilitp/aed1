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
{res = <Sum i : 0 <= i < N : a[i] * b[i]>}
```
