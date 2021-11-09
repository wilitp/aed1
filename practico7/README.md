
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
