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
  return 0;
}
