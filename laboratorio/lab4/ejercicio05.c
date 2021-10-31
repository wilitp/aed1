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
  int i = 0;
  printf("Ingrese los elementos enteros de un arreglo:\n");
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
  pedirArreglo(arr, N);  
  imprimeArreglo(arr, N);
}
