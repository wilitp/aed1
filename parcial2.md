```haskell Var x,r,y : Int; σ₀ = (x→20,r→21,y→22).  
l1 r,y ≔ 0,1;
l2 do x ≥ y*2 →
l3  r,y≔r+1,y*2
l4 od;
l5 x≔x-y
```



```haskell




{ r = 〈 N i : 0 ≤ i < n : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉 }
  if n mod 2 ≡ 0 →
  r,n ≔ r+1, n+1
      [] n mod 3 ≡ 0 →
          r,n ≔ r+1, n+1
  fi
{ r = 〈 N i : 0 ≤ i < n : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉 }


( r = 〈 N i : 0 ≤ i < n : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉)

=>

( r = 〈 N i : 0 ≤ i < n : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉 )


( r = 〈 N i : 0 ≤ i < n : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉 )












{ r = 〈 N i : 0 ≤ i < n : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉 ∧ (n mod 2 ≡ 0 ∨ n mod 3 ≡ 0) }
if 
  n mod 2 ≡ 0 → 
    r,n ≔ r+1, n+1

  [] n mod 3 ≡ 0 → 
    r,n ≔ r+1, n+1
fi
{ r = 〈 N i : 0 ≤ i < n : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉 }


{ r = 〈 N i : 0 ≤ i < n : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉 ∧ (n mod 2 ≡ 0 ∨ n mod 3 ≡ 0) /\ n mod 2 ≡ 0 }
  r,n ≔ r+1, n+1
{ r = 〈 N i : 0 ≤ i < n : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉 }

( r = 〈 N i : 0 ≤ i < n : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉 ∧ (n mod 2 ≡ 0 ∨ n mod 3 ≡ 0) /\ n mod 2 ≡ 0 )

=>

( r+1 = 〈 N i : 0 ≤ i < n+1 : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉 )

( r+1 = 〈 N i : 0 ≤ i < n V i = n+1 : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉 )

( r+1 = 〈 N i : n+1 : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉+〈 N i : 0 ≤ i < n : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉 )

( r+1 = 〈 N i : n+1 : i mod 2 ≡ 0 ∨ i mod 3 ≡ 0 〉+ r)

Contraejemplo:
n=8 -> n=9 no es divisible por 3 ni por 2

```



```haskell
Const N: Int, A: Array[0,N) of Int;
Var u,n : Int, r:Bool;
{ N>0 }
r,u,n ≔ False, 0,0;
{ INV :0≤n≤N-1 ∧ u = sum.A.0.n ∧ r = 〈Ei : 0 ≤ i < n : sum.A.0.i = 3 ∧ A.i =3 〉 }
do n≠N-1 ∧ ¬r →
    u,n ≔u+A.n,n+1;
    { R }
   r ≔ u=3 ∧ A.n=3
od
{ r = 〈 Ei : 0 ≤ i < N : sum.A.0.i = 3 ∧ A.i =3 〉 }

-- Verifico

{ N>0 }
r,u,n ≔ False, 0,0;
{ INV :0≤n≤N-1 ∧ u = sum.A.0.n ∧ r = 〈Ei : 0 ≤ i < n : sum.A.0.i = 3 ∧ A.i =3 〉 }


{ N>0 }
r,u,n ≔ False, A.0,1;
{ INV :0≤n≤N-1 ∧ u = sum.A.0.n ∧ r = 〈Ei : 0 ≤ i < n : sum.A.0.i = 3 ∧ A.i =3 〉 }

===

( N>0 )
=>
r,u,n ≔ False, A.0,1;
( INV :0≤1≤N-1 ∧ A.0 = sum.A.0.1 ∧ False = 〈Ei : 0 ≤ i < 1 : sum.A.0.i = 3 ∧ A.i =3 〉 )

( INV :1≤2<=N ∧ True ∧ False = 〈Ei : 0 ≤ i < 1 : sum.A.0.i = 3 ∧ A.i =3 〉 )

( INV :2<=N ∧ True ∧ False = 〈Ei : 0 ≤ i < 1 : sum.A.0.i = 3 ∧ A.i =3 〉 )

( INV :1<=N-1 ∧ True ∧ False = 〈Ei : 0 ≤ i < 1 : sum.A.0.i = 3 ∧ A.i =3 〉 )


===

( N>0 )
=>
( INV :0≤0≤N-1 ∧ 0 = sum.A.0.0 ∧ False = 〈Ei : 0 ≤ i < 0 : sum.A.0.i = 3 ∧ A.i =3 〉)

( INV : True ∧ 0 = sum.A.0.0 ∧ False = 〈Ei : 0 ≤ i < 0 : sum.A.0.i = 3 ∧ A.i =3 〉)

( INV : True ∧ True ∧ False = 〈Ei : 0 ≤ i < 0 : sum.A.0.i = 3 ∧ A.i =3 〉)

( INV : True ∧ True ∧ False = False)

True

-- Verificamos el bucle

{ INV : 0≤n≤N-1 ∧ u = sum.A.0.n ∧ r = 〈Ei : 0 ≤ i < n : sum.A.0.i = 3 ∧ A.i =3 〉 }
do n≠N-1 ∧ ¬r →
    u,n ≔u+A.n,n+1;
    { R }
   r ≔ u=3 ∧ A.n=3
od
{ r = 〈 Ei : 0 ≤ i < N : sum.A.0.i = 3 ∧ A.i =3 〉 }

-- ver que INV /\ !b => Q
( 0≤n≤N-1 ∧ u = sum.A.0.n ∧ r = 〈Ei : 0 ≤ i < n : sum.A.0.i = 3 ∧ A.i =3 〉/\ (n=N-1 V r ) )

( 0≤n<N ∧ u = sum.A.0.n ∧ r = 〈Ei : 0 ≤ i < n : sum.A.0.i = 3 ∧ A.i =3 〉/\ (n=N-1 V r ) )

=>

Casos:

-- (n=N-1 /\ r )
( True = True V 〈 Ei : i = n+1 : sum.A.0.i = 3 ∧ A.i =3 〉 )

True

-- n=N-1 /\ !r 
False = (〈 Ei : 0 ≤ i < n : sum.A.0.i = 3 ∧ A.i =3 〉V〈 Ei : i = n+1 : sum.A.0.i = 3 ∧ A.i =3 〉)

False = (False V〈 Ei : i = n+1 : sum.A.0.i = 3 ∧ A.i =3 〉)

False = (sum.A.0.N = 3 ∧ A.N = 3)



I /\ !b => Q
( 0≤n≤N-1 ∧ u = sum.A.0.n ∧ r = 〈Ei : 0 ≤ i < n : sum.A.0.i = 3 ∧ A.i =3 〉/\ n=N-1 )

( 0≤n<N ∧ u = sum.A.0.n ∧ r = 〈Ei : 0 ≤ i < n : sum.A.0.i = 3 ∧ A.i =3 〉/\ n=N-1 )

=>

( r = 〈 Ei : 0 ≤ i < N : sum.A.0.i = 3 ∧ A.i =3 〉 )

-- 

( r = 〈 Ei : 0 ≤ i <= n : sum.A.0.i = 3 ∧ A.i =3 〉 )

( r = 〈 Ei : 0 ≤ i < n : sum.A.0.i = 3 ∧ A.i =3 〉 V 〈 Ei : i = n : sum.A.0.i = 3 ∧ A.i =3 〉)

( r = 〈 Ei : 0 ≤ i < n : sum.A.0.i = 3 ∧ A.i =3 〉 V sum.A.0.n = 3 ∧ A.n =3 )






```


```haskell


Falling factorial

ff.n.x = <Prod i : 0<i<=n : x-i >

-- Ej
ff.3.5 = <Prod i : 0<i<=3 : 5-i >

         4 * 3 * 2



Const X,N : Nat;
Var r : Nat;
{True}
S
{r = <Prod i : 0<i<=n : x-i >}

-- Primero intuyo

Const X,N : Nat;
Var r, n : Nat;
{True}
r:=1;
n:=N;
{I}
do n!=0 ->
  r = r * (X-n)
  n = n-1;
od
{r = <Prod i : 0<=i<=N : X-i >}

Const X,N : Nat;
Var r, n : Nat;
{True}
r:=1;
n:=0;
{I}
do n<N ->
  r = r * (X-n)
  n = n+1;
od
{r = <Prod i : 0<=i<=N : X-i >}

-- Necesitamos un bucle, y quizas inicializacion previa de variables.

Const X,N : Nat;
Var r : Nat;
{True}
S0
{I}
do b ->
  Si
od
{r = <Prod i : 0<i<=n : x-i >}













Const X : Int, N: Int, A: Array[0,N) of Int;
Var r : Int;
{ N ≥ 0 }
S
{ r = 〈 N i : 0 ≤ i < N : A.i = X * 2^i 〉 }


Vamos a necesitar un ciclo para contar los elementos que cumplen:

Propongo un invariante r = 〈 N i : 0 ≤ i < j : A.i = X * 2^i 〉 /\ 0 ≤ i < N /\ pot = 2^i 

Introduzco una variable pot para fortalecer mi invariante. Así luego tengo una hipótesis para reemplazar 2^i(No es parte de mi lenguaje de programación)

El programa tiene la forma: 

Const X : Int, N: Int, A: Array[0,N) of Int;
Var r : Int;
{ N ≥ 0 }
S0;
{I}
do b ->
  {I /\ !b}
  S1;
  {I}
od
{ r = 〈 N i : 0 ≤ i < N : A.i = X * 2^i 〉 }

Const X : Int, N: Int, A: Array[0,N) of Int;
Var r : Int;
{ N ≥ 0 }
r,j,pot := 0, 0, 1 
{I}
do j<N ->
  {I /\ b}
  if A.j = X * pot ->
   r := r+1
  fi
  pot = 2 * pot;
  j := j+1;
  {I}
od
{ r = 〈 N i : 0 ≤ i < N : A.i = X * 2^i 〉 }

El cuerpo del ciclo va a ser una asignación


{ r = 〈 N i : 0 ≤ i < j+1 : A.i = X * 2^i 〉 }

{ r = 〈 N i : 0 ≤ i < j /\ i < j+1 : A.i = X * 2^i 〉 }

{ r = 〈 N i : 0 ≤ i < j /\ (i=j V i < j) : A.i = X * 2^i 〉 }

{ r = 〈 (N i : 0 ≤ i < j /\ i=j) V (N i : 0 ≤ i < j /\ i < j) : A.i = X * 2^i 〉 }


Const N,X : Int;
Var r : Int;
{ N > 0 }
r,n := 1, N
do n!=0 ->
  r,n = r*n, n-1;
od
{ r = ff.X.N }


```
