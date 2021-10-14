#include <stdio.h>

int main(void) 
{
  int x, y, i;
  printf("Ingresar valores");
  scanf("%d", &x);
  printf("Ingresar valores");
  scanf("%d", &y);
  printf("Ingresar valores");
  scanf("%d", &i);

  i = 0;

  while(x >= y)
  {
    x = x-y;
    i=i+1;
  }
  return 0;
}
