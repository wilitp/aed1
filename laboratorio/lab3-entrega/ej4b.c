#include <stdio.h>

int pedirEntero(void) 
{
  int x;
  printf("Ingresar un numero");
  scanf("%d", &x);
  return x;
}

void imprimeEntero(int x) {
  printf("%d\n", x);
}

int min(int x, int y, int z) 
{
  int m;
  if(x<y) 
  {
    m = x;
  }
  else if (x>=y)
  {
    m = y;
  }
  if (m < z){
  }
  else if (m>=z) 
  {
    m = z;
  }

  return m;
}

int main(void) 
{
  int x, y, z, m;
  
  x = pedirEntero();
  y = pedirEntero();
  z = pedirEntero();
  m = pedirEntero();

  m = min(x,y,z);
  imprimeEntero(m);

  return 0;
}


/* Sigma0 : (x->5, y->4 z->8, m->0) */
/* Sigma1 : (x->5, y->4 z->8, m->4) */
/* Sigma2 : (x->5, y->4 z->8, m->4) */

/* La variable m termina con valor 4 */
/* Este programa encuentra el mínimo entre 3 números */
/* Con el estado inicial : (x->2, y->10, z->9, m->0), el valor final de m es m=2 */
/* Con el estado inicial : (x->100, y->10, z->9, m->0), el valor final de m es m=9 */



