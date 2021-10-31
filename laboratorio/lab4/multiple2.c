
#include <stdio.h>


/* 
 Programa original
 {Pre: x = X, y = Y, z = Z}
  x, y, z := y, y + x + z, y + x
 {Post: x = Y, y = Y + X + Z, z = Y + X} 
*/

/* Version con asigancion simple
 {Pre: x = X, y = Y, z = Z}
  y := y + x + z;
  z := y - z;
  x := y - x - z;
 {Post: x = Y, y = Y + X + Z, z = Y + X} 
*/

int pedirEntero(void);

int main(void)
{
  int x, y, z; 
  x = pedirEntero();
  y = pedirEntero();
  z = pedirEntero();
  y = y + x + z;
  z = y - z;
  x = y - x - z;
  printf("x=%d, y=%d, z=%d\n", x, y, z);
  return 0;
}

int pedirEntero(void) 
{
  int x;
  printf("Ingresar un numero");
  scanf("%d", &x);
  return x;
}
