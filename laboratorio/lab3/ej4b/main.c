#include <stdio.h>

int main(void) 
{
  int x, y, z, m;
  
  printf("Ingresar un valor");
  scanf("%d", &x);
  printf("Ingresar un valor");
  scanf("%d", &y);
  printf("Ingresar un valor");
  scanf("%d", &z);
  printf("Ingresar un valor");
  scanf("%d", &m);

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

  printf("%d", m);

  return 0;
}
