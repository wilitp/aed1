#include <stdio.h>
#include <assert.h>

// Asignacion multiple
/* var x, y, z: Int; */
/* {Pre: x = X, y = Y, z = Z, Z * X ≠ Y, Z * Y ≠ 0} */
/* x, y := (z + y) / (z * x - y), z mod y */
/* {Post: x = (Z + Y) / (Z * X - Y), y = Z mod Y} */

// Traduccion a asignaciones simples
/* var x, y, z: Int; */
/* {Pre: x = X, y = Y, z = Z, Z * X ≠ Y, Z * Y ≠ 0} */
/* x := ((z + y) / (z * x - y)); */
/* y := (z % y); */
/* {Post: x = (Z + Y) / (Z * X - Y), y = Z mod Y} */

int pedirEntero(void) 
{
  int x;
  printf("Ingresar un numero");
  scanf("%d", &x);
  return x;
}


int main(void)
{
  int x, y, z, k, m, t;
  x = pedirEntero();
  k = x;
  y = pedirEntero();
  m = y;
  z = pedirEntero();
  t = z;

  // Pre
  assert(z * x != y && z * y != 0);

  x = ((z + y) / (z * x - y));
  y = (z % y);

  // Post
  assert(x == (t + m) / (t * k - m) && y == t % m);
  printf("x = %d, y = %d\n", x, y);
  return 0;
}
