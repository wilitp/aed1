#include <stdio.h>
#include <assert.h>

// 1.a
int main() {
  int x;
  printf("Ingresar un valor");
  scanf("%d", &x);
  assert(x==1);
  x = 5;
  return 0;
}
