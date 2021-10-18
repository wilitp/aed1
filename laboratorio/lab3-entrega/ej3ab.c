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
// 1.b
int main() {
  int x, y;
  x = pedirEntero();
  y = pedirEntero();
  assert(x==2 && y==5);
  x = x + y;
  y = y + y;
  printf("x=%d; y=%d", x, y);

  return 0;
}
