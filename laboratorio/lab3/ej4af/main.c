#include <stdio.h>
#include <assert.h>

int main(void) {
  int x, y;
  printf("Ingresar un valor");
  scanf("%d", &x);
  printf("Ingresar un valor");
  scanf("%d", &y);
  if (x >= y) 
  {
    x = 0;
  }
  else if (x <= y)
  {
    x = 2;
  }
}
