# 1)

f)
```haskell

Q = { (x = 0 V x = 2) /\ y = 1 }

wp.(if..fi).Q = ((x>=y) V (x<=y)) /\ ((x>=y) => wp.(x:=0).Q) /\ ((x<=y) => wp.(x:=2).Q)

              = ((x>=y) => wp.(x:=0).Q) /\ ((x<=y) => wp.(x:=2).Q)

              = ((x>=y) => (y = 1) /\ ((x<=y) => (y = 1))

              = (!(x>=y) V (y = 1) /\ (!(x<=y) V (y = 1))

              = (!(x>=y) /\ (!(x<=y)) V (y = 1)

              = !(x>=y V x<=y) V (y = 1)

              = False V (y = 1)

              = (y = 1)
```

# 2)

### a)
```haskell
{True}

  if (x ≥ 1) -> x := x + 1

  [](x ≤ 1) -> x := x − 1

  fi

{x != 1}

-- True implica wp? Veamos!

wp.(if..fi).(x!=1) = (x >= 1) => wp.(x:=x+1).(x!=1) /\ (x <= 1) => wp.(x:=x-1).(x!=1)

                   = (x >= 1) => (x+1!=1) /\ (x <= 1) => (x-1!=1)

                   = (x >= 1) => (x!=0) /\ (x <= 1) => (x!=2)

                   = True /\ True

                   = True

La pre implica la wp(True => True).
```

# 3) Para cada uno de los siguientes programas, elija valores para las expresiones E y F de modo que las ternas de Hoare sean correctas.

```haskell
a) Var x,y : Nat;
   {True}
    x, y := x + 1, E
   {y = x+1}

La terna es válida si y sólo si:

True => {y = x+1}(x->x+1, y->E)

={Aplico sustitucion}

True => {E = x+2}

E = x+2

```

```haskell
b) Var a, q, c, w : Num;
   {q = a * c /\ w = c^2}
    a, q := a + c, E
   {q = a * c}

La terna es válida si y sólo si:

(q=a*c /\ w=c^2) => {q = a * c}(a->a+c, q->E)

={Sustityo}

(q=a*c /\ w=c^2) => {E = (a+c) * c}

={Aritmetica}

(q=a*c /\ w=c^2) => {E = ac + c^2}

={ w = c^2 }

(q=a*c /\ w=c^2) => {E = ac + w}

={Caracterizacion}

!(q=a*c /\ w=c^2) V {E = ac + w}

={Hipotesis del programa}

False V {E = ac + w}

={Neutro}

E = ac + w
```

```haskell
c) Const A, B : Nat;
   Var q, r : Nat;
   {A = q ∗ B + r}
    q := E; r := r − B
   {A = q ∗ B + r}

La terna es valida <=>

{A = q ∗ B + r} => {A = q ∗ B + r}(q->E; r->r − B)

={Sust}

{A = q ∗ B + r} => {A = E * B + r - B}

={Aritmetica}

{A = q ∗ B + r} => {A = (E-1) * B + r}

={Aplico la premisa A = q ∗ B + r}

q ∗ B + r = (E-1) * B + r

={Resto r}

q ∗ B = (E-1) * B

Analizo por casos:
  B = 0:
   q ∗ B = (E-1) * B === True (0 = 0) // El valor de E no importa
   
  B != 0
    q ∗ B = (E-1) * B

    ={Divido por B}

    q = E-1

    ={Sumo 1}

    E = q+1

E = q + 1
```

```haskell
d) 
  Const N : Num;
  Var x, y, p, q : Num;
  {x ∗ y + p ∗ q = N}
   x := x − p;
   q := F
  {x ∗ y + p ∗ q = N}


Esta terna es equivalente a:

  Const N : Num;
  Var x, y, p, q : Num;
  {x ∗ y + p ∗ q = N}

   x, q := x − p, F

  {x ∗ y + p ∗ q = N}

La terna es valida <=>

(x ∗ y + p ∗ q = N) => {x ∗ y + p ∗ q = N}(x->x − p, q->F )

={Sust}

(x ∗ y + p ∗ q = N) => ((x-p) ∗ y + p ∗ F = N)

={Aplico premisa x ∗ y + p ∗ q = N}

((x-p) ∗ y + p ∗ F = x ∗ y + p ∗ q)

={Distributiva}

(x * y - p ∗ y + p ∗ F = x ∗ y + p ∗ q)

={Resto x * y en ambos lados}

p ∗ F - p ∗ y = p ∗ q

={Factor comun}

p ∗ (F - y) = p ∗ q

={Divido por p(si p fuera 0, la implicancia ya es verdadera de todas formas, pues 0 = 0)}

F = q + y

```

# 4. Especifique los siguientes problemas, enunciando pre y postcondición, y luego derive programas imperativos a partir de las especificaciones.

a) Calcular el mínimo de dos valores.

```haskell
-- Especificacion

Var r,x,y : Num;
{True}
S
{r = x min y}

Nos preguntamos si P => Q
Falso

Podemos reforzar nuestra post-condición y a su vez aclarar nuestra pre-condicion:

{x <= y V x > y}
S
{r = x min y /\ (r = x V r = y)}

Vamos a necesitar hacer una asignacion(r)

{x <= y V x > y}
r := R
{r = x min y /\ (r = x V r = y)}

Como vemos en nuestra postcondición, R=x V R=y

Nuestro programa es valido entonces si, y solo si,

(x<=y /\ R = x) V (x>y /\ R=y)



```
b) Calcular el valor absoluto de un número. 
