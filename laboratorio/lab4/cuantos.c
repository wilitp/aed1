#include <stdio.h>
#define N 3

struct comp_t {
  int menores;
  int iguales;
  int mayores;
};

struct comp_t cuantos(int a[], int tam, int elem)
{
  struct comp_t c = {0,0,0};
  int i = 0;
  while(i<tam)
  {
    if(a[i] < elem)
    {
      c.menores++;
    }
    else if(a[i] > elem)
    {
      c.mayores++;
    }
    else
    {
      c.iguales++;
    }
    i++;
  }
  return c;
}

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

int main(void)
{
  int arr[N];
  int elem = 2;
  pedirArreglo(arr, N);
  struct comp_t c = cuantos(arr, N, elem);
  printf("Mayores a %d: %d, Menores a %d: %d, Iguales a %d: %d\n", elem,c.mayores, elem, c.menores, elem, c.iguales);
}
