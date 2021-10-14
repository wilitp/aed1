#include <stdio.h>
#include <assert.h>
#include "../tools/tools.h"

// 1.b
int main() {
  int x, y;
  x = pedirEntero();
  y = pedirEntero();
  assert(x==2 && y==5);
  x = x + y;
  y = y + y;

  return 0;
}
