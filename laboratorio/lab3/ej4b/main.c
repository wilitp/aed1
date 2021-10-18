#include <stdio.h>
#include "../tools/tools.h"

int main(void) 
{
  int x, y, z, m;
  
  x = pedirEntero();
  y = pedirEntero();
  z = pedirEntero();
  m = pedirEntero();

  /* Sigma0 : (x->5, y->4 z->8, m->0) */

  if(x<y) 
  {
    m = x;
  }
  else if (x>=y)
  {
    m = y;
  }

  /* Sigma1 : (x->5, y->4 z->8, m->4) */

  if (m < z){
  }
  else if (m>=z) 
  {
    m = z;
  }
  /* Sigma2 : (x->5, y->4 z->8, m->4) */

  return 0;
}


/* La variable m termina con valor 4 */
/* Este programa encuentra el mínimo entre 3 números */
/* Con el estado inicial : (x->2, y->10, z->9, m->0), el valor final de m es m=2 */
/* Con el estado inicial : (x->100, y->10, z->9, m->0), el valor final de m es m=9 */



