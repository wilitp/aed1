#include <stdio.h>
#include "../tools/tools.h"

int main(void)
{
  int x, y, z;
  x = pedirEntero();
  y = pedirEntero();
  z = pedirEntero();

  // Imprimir los valores
  printf("x+y+1=%d\n",x+y+1);
  printf("z*z+y*45-15*x=%d\n",z*z+y*45-15*x);
  printf("y - 2 == (x * 3 + 1)%%5 = %d\n",(y - 2 == (x * 3 + 1) % 5));
  printf("y / 2 * x = %f\n", (float)y / 2 * (float) x);
  printf("y < x *z = %d\n", (y < x *z));
}
