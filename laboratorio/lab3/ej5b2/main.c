#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  int x, i, temp;
  bool res;

  printf("Ingresar valor");
  scanf("%d", &x);
  printf("Ingresar valor");
  scanf("%d", &i);
  printf("Ingresar valor");
  scanf("%d", &temp);
  res = temp;

  i = 2;
  res = true;

  while(i < x && res)
  {
    res = res && (x % i != 0 );
    i = i + 1;
    printf("x: %d i: %d res: %d \n", x, i, res);
  }
  return 0;
}
