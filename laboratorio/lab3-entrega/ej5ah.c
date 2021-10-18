#include <stdio.h>

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
int main(void)
{
  int i;
  i = pedirEntero();
  while (i != 0) {
    i = i - 1;
  }
  printf("i=%d\n", i);
  return 0;
}
