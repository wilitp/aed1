#include <stdio.h>
#include <assert.h>

int pedirEntero(void) 
{
  int x;
  printf("Ingresar un numero");
  scanf("%d", &x);
  return x;
}

// Especificacion
// {x -> X, y -> Y}S{x -> Y, y -> X}
int main()
{
  int x, y, z;
  x = pedirEntero();
  y = pedirEntero();

  //Intercambio
  z = x;
  x = y;
  y = z;

  printf("x: %d, y: %d\n", x, y);

  return 0;
}
