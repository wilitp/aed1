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
