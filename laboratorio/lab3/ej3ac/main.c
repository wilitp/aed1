#include <stdio.h>
#include <assert.h>
#include "../tools/tools.h"

// 1.c
int main() {
  int x, y;
  x = pedirEntero();
  y = pedirEntero();
  assert(x=2 && y==5);
  y = y + y;
  x = x + y;
  printf("x=%d; y=%d\n", x, y);

  return 0;
}
