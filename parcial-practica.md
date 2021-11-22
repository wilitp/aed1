1. Considerá el siguiente programa imperativo que calcula N^2 usando sólo sumas.
```haskell
Const N : Int;
Var r, s, i : Int;
{P}
r, s, i := 0, 0, 0;
do i != N ->
 r, s, i := r + s + 1, i + i, i + 1;
od
{Q}
```
