#include <stdio.h>
#include <assert.h>

void holaHasta(int n)
{
  while(n>0)
  {
    printf("hola\n");
    n--;
  }
}

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
  int n = pedirEntero();
  assert(n>0);

  holaHasta(n);
}
