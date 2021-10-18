#include <stdio.h>
#include <assert.h>

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

  printf("x=%d; y=%d\n", x, y);
  return 0;
}
