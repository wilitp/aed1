# Final primera fecha

### 2) Derivar

```haskell
Const N : Int, A : array [0, N) of Int
Var r : Bool;
{N >= 0}
  S
{r = <E i : 0 <= i <= N : <Sum j : 0 <= j < i : A.j> = −1 >}
```

#### Programa intuido

```haskell
Const N : Int, A : array [0, N) of Int
Var r : Bool, n : Nat;
{N >= 0}
  r := False;
  n := 0;
  do N>n
  S 
  n := n+1;
  od
{r = <E i : 0 <= i <= N : <Sum j : 0 <= j < i : A.j> = −1 >}
```

El invariante puede ser algo como:

`(r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n<=N`

donde vamos incrementando n y se cumple que r contiene la existencia hasta esa parte del array.

Propongo una cota t = N-n:
- Siempre >=0
- Decrece con el cuerpo del ciclo

Derivemos el cuerpo del ciclo.
Pruebo con una asignación múltiple

```haskell
{(r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n<=N /\ N>n /\ N-n = K}
  n, r := E, F
{(r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n<=N /\ N-n < K}

={Obligacion de prueba}

(r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n<=N /\ N>n /\ N-n = K
=>
(F = <E i : 0 <= i <= E : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=E<=N /\ N-E < K

={Pruebo con E=n+1}

(r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n<=N /\ N>n /\ N-n = K

=>

(F = <E i : 0 <= i <= n+1 : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n+1<=N /\ N-n-1 < K

={0<=n+1<=N, pues n<N}
={K=N-1 => N-n-1 < K}

(F = <E i : 0 <= i <= n+1 : <Sum j : 0 <= j < i : A.j> = −1 >)

={Particion de rango}

F = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 > V <E i : i = n+1 : <Sum j : 0 <= j < i : A.j> = −1 >

={Hip valor de r}

F = r V <E i : i = n+1 : <Sum j : 0 <= j < i : A.j> = −1 >

={Rango unitario}

F = r V <Sum j : 0 <= j < n+1 : A.j> = −1

={Particion de rango y rango unitario}

F = r V <Sum j : 0 <= j < n : A.j> + A.(n+1) = −1

={Me trabo porque la sumatoria no es programable. fortalezco el invariante}
={Tambien encuentro un problema de border con la expresion A.(n+1). Cambio la guarda a N>n+1}
```

El nuevo invariante va a incluir una nueva variable s, con la suma de los elementos de A hasta el indice n:
`{s = <Sum j : 0 <= j < N : A.j>}`

Derivo el cuerpo del bucle

```haskell
{(r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n<=N /\ s = <Sum j : 0 <= j < n : A.j> /\ N>n+1 /\ N-n = K}
  n, r, s := E, F, R
{(r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n<=N /\ N-n < K}

={Obligacion de prueba}

((r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n<=N /\ s = <Sum j : 0 <= j < n : A.j> /\ N>n+1 /\ N-n = K)
=>

={Pasos que ya hice arriba}

((F = r V <Sum j : 0 <= j < n : A.j> + A.(n+1) = −1) /\ R = <Sum j : 0 <= j < n+1 : A.j>)

={Hip valor de s}

F = r V s + A.(n+1) = −1 /\ R = <Sum j : 0 <= j < n+1 : A.j>

={Propongo F = r V s + A.(n+1) = −1 }

R = <Sum j : 0 <= j < n+1 : A.j>

={Particion de rango y rango unitario}

R = <Sum j : 0 <= j < n : A.j> + A.(n+1)

={Hip valor de s}

R = s + A.(n+1)

```

El cuerpo queda entonces:

```haskell
{(r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n<=N /\ s = <Sum j : 0 <= j < n : A.j> /\ N>n+1 /\ N-n = K}
  n, r, s := n+1, r V s + A.(n+1) = -1, s + A.(n+1)
{(r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n<=N /\ N-n < K}
```

Nuestro queda:

```haskell
Const N : Int, A : array [0, N) of Int
Var r : Bool;
{N >= 0}
  r := False;
  n := 0;
  if N=0
    s := 0
  fi
  [] N!=0
    s := A.0
  fi
  do N>n+1 ->
    n, r, s := n+1, r V s + A.(n+1) = -1, s + A.(n+1)
  od
{r = <E i : 0 <= i <= N : <Sum j : 0 <= j < i : A.j> = −1 >}
```
