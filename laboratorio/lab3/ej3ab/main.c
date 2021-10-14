#include <stdio.h>
#include <assert.h>

// 1.b
int main() {
  int x, y;
  printf("Ingresar un valor");
  scanf("%d", &x);
  printf("Ingresar un valor");
  scanf("%d", &y);
  assert(x==2 && y==5);
  x = x + y;
  y = y + y;

  return 0;
}
