#include <stdio.h>


/* Programa original
 * {Pre: x = X, y = Y} 
 * x, y := x + 1, x + y
 * {Post: x = X + 1, y = X + Y} */

/* Version con asigancion simple
 * {Pre: x = X, y = Y}
 * y := x + y;
 * x := x + 1
 * {Post: x = X + 1, y = X + Y} */

int pedirEntero(void);

int main(void)
{
  int x,y; 
  x = pedirEntero();
  y = pedirEntero();
  y = x + y;
  x = x + 1;
  printf("x=%d, y=%d\n", x, y);
  return 0;
}

int pedirEntero(void) 
{
  int x;
  printf("Ingresar un numero");
  scanf("%d", &x);
  return x;
}
