#include <stdio.h>
#include <stdbool.h>
#include "../tools/tools.h"

int main(void)
{
  int x, i, temp;
  bool res;

  x = pedirEntero();
  i = pedirEntero();
  temp = pedirEntero();
  res = temp;

  i = 2;
  res = true;

  while(i < x && res)
  {
    res = res && (x % i != 0 );
    i = i + 1;
    printf("x: %d i: %d res: %d \n", x, i, res);
  }
  return 0;
}
