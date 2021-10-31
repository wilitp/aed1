#include <stdio.h>
#include <assert.h>

int pedirEntero(void) 
{
  int x;
  printf("Ingresar un numero");
  scanf("%d", &x);
  return x;
}

void pedirArreglo(int a[], int n_max)
{
  printf("Ingrese los elementos enteros de un arreglo:\n");
  int i = 0;
  while(i < n_max ) {
    a[i] = pedirEntero();
    i++;
  }
}

void imprimeArreglo(int a[], int n_max)
{
  int i = 0;
  while(i < n_max) {
    printf("%d ", a[i]);
    i++;
  }
  printf("\n");
}

typedef struct {
  int cociente;
  int resto;
} div_t;

div_t division(int x, int y)
{
  return (div_t){x/y, x%y};
}


int main(void)
{
  int x = pedirEntero();
  int y = pedirEntero();
  assert(y != 0);
  div_t d = division(x, y);
  printf("Cociente: %d, Resto: %d\n", d.cociente, d.resto);
}
