#include <stdio.h>
#include "../tools/tools.h"

int main(void) {
  int i;
  i = pedirEntero();
  while (i != 0) {
    i = 0;
  }
  imprimeEntero(i);
}
