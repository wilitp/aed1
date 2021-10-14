#include <stdio.h>
#include <assert.h>

// 1.c
int main() {
  int x, y;
  printf("Ingresar un valor");
  scanf("%d", &x);
  printf("Ingresar un valor");
  scanf("%d", &y);
  assert(x=2 && y==5);
  y = y + y;
  x = x + y;

  return 0;
}
