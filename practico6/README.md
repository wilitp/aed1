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

El valor de la expresion R va a depender de orden entre x e y. Introducimos un condicional y cambiamos R por otras 2 metavariables

{x <= y V x > y}
if
 b1 -> r := R1
 b2 -> r := R2
fi
{r = x min y /\ (r = x V r = y)}

Probamos con b1 y b2 siendo los dos casos de la precondicion

{x <= y V x > y}
if
 x <= y -> r := R1
 x > y -> r := R2
fi
{r = x min y /\ (r = x V r = y)}

Averigüemos cuales son los valores de R1 y R2, recordemos que estos pueden ser x o y

Nuestro programa es valido si y solo si:

True => wp.if..fi.Q

={True implica cualquier cosa verdadera}

wp.if..fi.Q

={Definicion de wp y tricotomia}

(x<=y => wp.(r:=R1).Q) /\ (x>y => wp.(r:=R2).Q)

={Definicion de wp}

(x<=y => {R1 = x min y /\ (R1 = x V R1 = y)}) /\ (x>y => {R2 = x min y /\ (R2 = x V R2 = y)})

={Uso las hipotesis de orden entre x e y}

(x<=y => {R1 = x /\ (R1 = x V R1 = y)}) /\ (x>y => {R2 = y /\ (R2 = x V R2 = y)})

={Leibniz e idempotencia de /\ (En el caso x = y, tenemos R1 = x === R1 =y. En ese caso aplicariamos idempotencia del V y tendriamos el mismo resultado)}

(x<=y => {R1 = x}) /\ (x>y => {R2 = y})

Tenemos entonces:
R1 = x
R2 = y 

{x <= y V x > y}
if
 x <= y -> r := x
 x > y -> r := y
fi
{r = x min y /\ (r = x V r = y)}

```

b) Calcular el valor absoluto de un número. 

```haskell
-- Especificacion

Const X : Num;
Var x : Num;
{x = X}
S
{r = |X|}


-- Podemos agregar informacion a nuestra precondicion usando un predicado equivalente.

Const X : Num;
Var x : Num;
{True /\ x = X}
S
{r = |X|}

=== 

Const X : Num;
Var x : Num;
Var r : Num;
{x>=0 V x<0 /\ x = X}
S
{r = |X|}

-- Es fácil ver que P no implica Q, por lo que es necesario asignarle un valor a r:

Const X : Num;
Var x : Num;
Var r : Num;
{x>=0 V x<0 /\ x = X}
r := R
{r = |X|}

-- Buscamos el valor de R usando la wp de la asignacion

P => wp.(r:=R).{r = |X|}
={Def de wp}
P => {R = |X|}
={P}
{x>=0 V x<0 /\ x = X} => {R = |X|}
={Leibniz}
{X>=0 V X<0 /\ x = X} => {R = |X|}

-- Para que esto valga R podria ser -X o X, dependiendo del signo de X.

-- Introducimos un condicional y proponemos las guardas x>=0 y x<0, también cambiamos nuestra metavariable R por R1 y R2

Const X : Num;
Var x : Num;
Var r : Num;
{x>=0 V x<0 /\ x = X}
 if
  x>=0 -> r := R1 
  x<0 -> r := R2 
 fi
{r = |X|}

Usamos la wp del condicional para ver los valores de R1 y R2

wp.if..fi.{r = |X|} = (x>=0 V x<0) /\ (x>=0 => (r->R1).{r = |X|} /\ (x<0 => (r->R2).{r = |X|}

={Tricotomia y neutro de /\ }

= (x>=0 => (r->R1).{r = |X|} /\ (x<0 => (r->R2).{r = |X|}

={Aplico las sustituciones}

= (x>=0 => {R1 = |X|} /\ (x<0 => {R2 = |X|}

={Hip}

= (X>=0 => {R1 = |X|} /\ (X<0 => {R2 = |X|}

-- Vemos entonces que R1 = X = x y R2 = -X = -x

Const X : Num;
Var x : Num;
Var r : Num;
{x>=0 V x<0 /\ x = X}
 if
  x>=0 -> r := X
  x<0 -> r := -X 
 fi
{r = |X|}

```

# 5 Demostrar que si a) es valido entonces b) es valido.

```haskell
a) 
{P}
 if
  B0 → S0
  B1 → S1
 fi
{Q}

b) 
{P}
 if 
  B0 → S0
  ¬B0 → S1
 fi
{Q}

Demostremos que:

(P => (B0 V B1) /\ (B0 => S0.Q) /\ (B1 => S1.Q)) => (P => (B0 V !B0) /\ (B0 => S0.Q) /\ (!B0 => S1.Q))

Tomando P y (P => (B0 V B1) /\ (B0 => S0.Q) /\ (B1 => S1.Q)) como premisas:

(P => (B0 V !B0) /\ (B0 => S0.Q) /\ (!B0 => S1.Q))

={Tercero excluido}

(P => (B0 => S0.Q) /\ (!B0 => S1.Q))

={Ya vimos que P => (B0 => S0.Q)}

(P => (!B0 => S1.Q))

={Logica}

P /\ !B0 => S1.Q

={!B0 => B1(!B0 es mas fuerte que B1)}
={{P /\ B1}S1{Q} => {P /\ !B0}S1{Q} -- Propiedad de las precondiciones }
={{P /\ B1}S1{Q} es premisa}

True


```

# 9 Derive un programa que calcule el máximo común divisor entre dos enteros positivos.

*Para la derivación serán de utilidad las siguientes propiedades del mcd:*

a) mcd.x.x = x
b) mcd.x.y = mcd.y.x
c) x > y ⇒ mcd.x.y = mcd.(x − y).y
d) y > x ⇒ mcd.x.y = mcd.x.(y − x)

Utilice como invariante {x > 0 ∧ y > 0 ∧ mcd.x.y = mcd.X.Y }

#### Especificacion
```haskell
{x=X, y=Y}
S
{res = mdc.x.y}
```

Voy a necesitar un ciclo para usar sucesivamente c) y d).
Ya tengo el invariante, así que puedo escribir el programa con anotaciones intermedias y un ciclo

```haskell
{x=X, y=Y, x,y>0}
 do (B) ->
  {I /\ B}
   S
  {I}
 od
{res = mdc.x.y}
```

P => I ? si, entonces no es necesario asignar nada antes del bucle para mantener el invariante.
De todas formas, es necesario asignarle un valor a res, asi que pruebo hacer esa asignacion despues del ciclo

```haskell
{x=X, y=Y, x,y>0}
 do (B) ->
  {I /\ B}
   S
  {I}
 od
 res = R -- Metavariable a despejar luego
{res = mdc.x.y}
```

Propongo la guarda y != x, y R = x. Ya que esto hace que I /\ !B => Q

```haskell
{x=X, y=Y, x,y>0}
 do (y!=x) ->
  {I /\ (y!=x)}
   S
  {I}
 od
 res := x
{res = mdc.x.y}
```

Busco una cota t tq I /\ B => t>=0. Propongo la cota t = |x-y|

Ahora solo nos queda derivar la terna:

```haskell
{I /\ (y!=x) /\ x-y = T}
 S
{I /\ x-y < T}
```

Como tenemos (y!=x), sabemos que T > 0.
Para que |x-y| disminuya, tenemos que asignarle valores a las variables de la cota:

```haskell
{I /\ (y!=x) /\ x-y = T}
 x, y := E, F
{I /\ x-y < T}
```

Busco los valores de E y F:

```haskell
( (x > 0 ∧ y > 0 ∧ mcd.x.y = mcd.X.Y) /\ (y!=x) /\ x-y = T) => ( (E > 0 ∧ F > 0 ∧ mcd.E.F = mcd.X.Y ) /\ E-F < T)
```

Podemos ver que E y F tienen que ser siempre mayores a 0 y su mcd tiene que ser igual al de los valores iniciales de X e Y.
Usemos entonces las ecuaciones c) y d) para plantear un análisis por casos y usar las guardas de estas en un condicional:


```haskell
{I /\ (y!=x) /\ x-y = T}
 if
  x > y -> x, y := E1, F1
  x < y -> x, y := E2, F2
 fi
{I /\ x-y < T}
```

Busquemos los valores a asignar en cada caso:

```haskell
I : (x > 0 ∧ y > 0 ∧ mcd.x.y = mcd.X.Y)

((P : I /\ (y!=x) /\ x-y = T)

=> 

(x > y V x < y)) /\ (P /\ x > y => ((E1 > 0 ∧ F1 > 0 ∧ mcd.E.F = mcd.X.Y) /\ E1-F1 < T)) /\ (P /\ x < y => {(E2 > 0 ∧ F2 > 0 ∧ mcd.E.F = mcd.X.Y) /\ E2-F2 < T})

={y!=x, entonces (x > y V x < y)}

(P /\ x > y => (I /\ E1-F1 < T)) /\ (P /\ x < y => (I /\ E2-F2 < T))

={Probamos E2 = x, F2 = y-x, E1 = x-y, F1 = y} 
={Vemos P => solo la primera implicancia}

(x > 0 ∧ y > 0 ∧ mcd.x.y = mcd.X.Y) /\ (y!=x) /\ x-y = T /\ x > y 

=> 

((x-y > 0 ∧ y > 0 ∧ mcd.(x-y).y = mcd.X.Y) /\ x-y-y < T)

={x-y > 0 e y > 0, pues x>y>0}

((mcd.(x-y).y = mcd.X.Y) /\ x-y-y < T)

={Premisa: mcd.x.y = mcd.X.Y}

((mcd.(x-y).y = mcd.x.y) /\ x-y-y < T)

={Propiedad mcd}

(x-y-y < T)

={Premisa: T = x-y}

(x-y-y < x-y)

={Suma y orden}

(x < x+y)

True

={Vemos P => Ahora con la segunda implicancia}

(x > 0 ∧ y > 0 ∧ mcd.x.y = mcd.X.Y) /\ (y!=x) /\ x-y = T /\ x < y 

=> 

((x > 0 ∧ y-x > 0 ∧ mcd.x.y-x = mcd.X.Y) /\ x-y+x < T)

={Aplicamos los mismos pasos}

(-y < x-y)

={Suma y orden}

0 < x

={Hipotesis}

True

```

#### Resultado parcial

```haskell
{I /\ (y!=x) /\ x-y = T}
 if
  x > y -> x, y := x-y, y
  x < y -> x, y := x, y-x
 fi
{I /\ x-y < T}
```

#### Resultado final

```haskell
{x=X, y=Y, x,y>0}
 do (y!=x) ->
  {I /\ (y!=x)}
   if
    x > y -> x, y := x-y, y
    x < y -> x, y := x, y-x
   fi
  {I}
 od
 res := x
{res = mdc.x.y}
```
