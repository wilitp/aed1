#include <stdio.h>
#include <assert.h>
#include "../tools/tools.h"

// 1.a
int main() {
  int x;
  x = pedirEntero();
  assert(x==1);
  x = 5;
  imprimeEntero(x);
  return 0;
}
