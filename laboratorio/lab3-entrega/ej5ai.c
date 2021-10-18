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
int main(void) {
  int i;
  i = pedirEntero();
  while (i != 0) {
    i = 0;
  }
  imprimeEntero(i);
  return 0;
}
