#include <stdio.h>
#define N 2

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

int sumatoria(int a[], int tam)
{
  int s = 0;
  int i = 0;
  while(i < tam)
  {
    s += a[i];
    i++;
  }

  return s; 
}

int main(void)
{
  int arr[N];
  pedirArreglo(arr, N);  
  printf("Sumatoria: %d\n", sumatoria(arr, N));
}
