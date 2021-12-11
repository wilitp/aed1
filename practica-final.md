# Final primera fecha

### 2) Derivar

```haskell
Const N : Int, A : array [0, N) of Int
Var r : Bool;
{N >= 0}
  S
{r = <E i : 0 <= i <= N : <Sum j : 0 <= j < i : A.j> = −1 >}
```


El invariante puede ser algo como:

`(r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n<=N`

donde vamos incrementando n y se cumple que r contiene la existencia hasta esa parte del array.

Propongo este ciclo con una inicializacion anterior

```haskell
Const N : Int, A : array [0, N) of Int
Var r : Bool, n : Nat;
{N >= 0}
  S0
{I}
  do b
  S 
  n := n+1;
  od
{I}
{r = <E i : 0 <= i <= N : <Sum j : 0 <= j < i : A.j> = −1 >}
```

Busquemos una cota tq I /\ !b => Q

```haskell
(r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n<=N /\ !b 

=> 

r = <E i : 0 <= i <= N : <Sum j : 0 <= j < i : A.j> = −1 >

={Propongo b = N>n; !b = N<=n}

(r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n<=N /\ n>=N 

=> 

r = <E i : 0 <= i <= N : <Sum j : 0 <= j < i : A.j> = −1 >

={Logica}

(r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ n=N 

=> 

={De ahora en mas asumo las premisas y trato de llegar a true}
={N=n}

r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >

={True por hip}
```

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

F = r V <Sum j : 0 <= j < n+1 : A.j> = −1 >

={Particion de rango}

F = r V <Sum j : 0 <= j < n : A.j> + A.n = −1

={Fortalezco el invariante para poder programar la sumatoria, agrego s = <Sum j : 0 <= j < n : A.j>}
={Sumo la asignacion de s := R al cuerpo del bucle para mantener el invariante}

F = r V <Sum j : 0 <= j < n : A.j> + A.n = −1 /\ R = <Sum j : 0 <= j < n+1 : A.j>

={Hip valor de s}

F = r V s + A.n = −1 /\ R = <Sum j : 0 <= j < n+1 : A.j>

={Parto el rango y rango unitario}

F = r V s + A.n = −1 /\ R = s + A.n
```


#### Derivo la inicializacion de las variables

```haskell
{N>=0}
r,n,s := R, E, S
{(r = <E i : 0 <= i <= n : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=n<=N /\ s = <Sum j : 0 <= j < n : A.j>}

={Obligacion de prueba}

N>=0

=> 

(R = <E i : 0 <= i <= E : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=E<=N /\ S = <Sum j : 0 <= j < E : A.j>

={Propongo E=0 y R=False}

(False = <E i : 0 <= i <= 0 : <Sum j : 0 <= j < i : A.j> = −1 >) /\ 0<=0<=N /\ S = <Sum j : 0 <= j < 0 : A.j>

={Hip N>=0; Rango vacio de sum; rango unitario del existe}

(False = <Sum j : 0 <= j < 0 : A.j> = −1) /\ S = 0

={Rango unitario; igualdad x2; Neutro del /\}

S = 0

={S = 0}

True

```

Listo, el programa queda:

```haskell
Const N : Int, A : array [0, N) of Int
Var r : Bool, n : Nat;
{N >= 0}
  r,n,s := False, 0, 0;
  do N>n
    r, s, n := r V s + A.n = -1, s + A.n, n+1
  od
{r = <E i : 0 <= i <= N : <Sum j : 0 <= j < i : A.j> = −1 >}
```
