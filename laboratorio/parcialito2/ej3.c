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

int mult_pares(int array[], int tam)
{
  int prod = 0;
  int i = 0;
  int hay_pares = 0;
  assert(tam > 0);
  while(i < tam)
  {
    hay_pares = hay_pares || (array[i] % 2 == 0);
    i++;
  }
  i = 0;

  if(hay_pares)
  {
    prod = 1;
  }
  while(i < tam)
  {
    if(array[i] % 2 == 0)
    {
      prod = prod * array[i]; 
    }
    i++;
  }
  return prod;
}


int main(void)
{
  #define N 3
  int arr[N];
  pedirArreglo(arr, N);
  printf("Producto de los pares: %d\n", mult_pares(arr, N));

  return 0;
}
