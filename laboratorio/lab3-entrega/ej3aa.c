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

// 1.a
int main() {
  int x;
  x = pedirEntero();
  assert(x==1);
  x = 5;
  imprimeEntero(x);
  return 0;
}
