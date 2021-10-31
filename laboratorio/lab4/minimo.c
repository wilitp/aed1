#include <stdio.h>
#include <assert.h>

int pedirEntero(void) 
{
  int x;
  printf("Ingresar un numero");
  scanf("%d", &x);
  return x;
}


// Especificacion de minimo
// {True}S{res = x min y}

int main()
{
  int x, y, m;
  x = pedirEntero();
  y = pedirEntero();
  
  if (x < y)
  {
    m = x;
  }
  else
  {
    m = y;
  }

  printf("Minimo: %d\n", m);

  return 0;
}
