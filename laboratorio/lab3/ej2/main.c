#include <stdio.h>
#include "../tools/tools.h"


int main() {
  int x,y,z, b, w;
  x = pedirEntero();
  y = pedirEntero();
  z = pedirEntero();
  b = pedirEntero();
  w = pedirEntero();

  printf("(x%%4==0) = %d\n", x%4==0);
  printf("(x = y ==0) && ((y - x) == (-1) * z) = %d\n", (x = y ==0) && ((y - x) == (-1) * z));
  printf("not b && w = %d\n", !b && w);
  return 0;
}

/* x = 4 */
/* y = -4 */
/* z = 8 */

/* b = true */
/* w = false */
