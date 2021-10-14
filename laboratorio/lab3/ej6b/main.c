#include <stdio.h>
#include "../tools/tools.h"

int main(void) 
{
  int x, y, z, m;
  
  x = pedirEntero();
  y = pedirEntero();
  z = pedirEntero();
  m = pedirEntero();

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

  imprimeEntero(m);

  return 0;
}
