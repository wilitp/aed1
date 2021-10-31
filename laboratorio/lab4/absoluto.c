#include <stdio.h>
#include <assert.h>

int pedirEntero(void) 
{
  int x;
  printf("Ingresar un numero");
  scanf("%d", &x);
  return x;
}

// Especificacion de absoluto
// {True}S{m = |x|}
int main()
{
  int x, m;
  x = pedirEntero();
  
  if(x < 0)
  {
    m = -x;
  }
  else
  {
    m = x;
  }

  printf("Absoluto: %d\n", m);

  return 0;
}
