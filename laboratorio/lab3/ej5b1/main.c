#include <stdio.h>
#include "../tools/tools.h"

int main(void) 
{
  int x, y, i;
  x = pedirEntero();
  y = pedirEntero();
  i = pedirEntero();

  i = 0;

  while(x >= y)
  {
    x = x-y;
    i=i+1;
  }
  printf("x=%d, y=%d, i=%d", x, y, i);
  return 0;
}

/* Primera iteracion: (x->10, y->3, i->1) */
/* Segunda iteracion: (x->7, y->3, i->2) */
/* Tercera iteracion: (x->4, y->3, i->3) */
/* Cuarta iteracion: (x->1, y->3, i->4) */
