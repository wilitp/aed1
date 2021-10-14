#include <stdio.h>
#include <assert.h>
#include "../tools/tools.h"

int main(void) {
  int x, y;
  x = pedirEntero();
  y = pedirEntero();
  if (x >= y) 
  {
    x = 0;
  }
  else if (x <= y)
  {
    x = 2;
  }
}
