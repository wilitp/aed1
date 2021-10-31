#include <stdio.h>
#include <assert.h>
#define N 4

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
void intercambiar(int a[], int tam, int i, int j)
{
  assert(i < tam && j < tam && 0 <= i && 0 <= j);
  int x;
  x = a[i];
  a[i] = a[j];
  a[j] = x;
}

void pedirIndice(int *i)
{
  while(1)
  {
    printf("Seleccionar un indice (Cantidad de elementos: %d)\n", N);
    scanf("%d", i);
    if(*i < N && 0 <= *i)
    {
      break;
    }
    printf("El indice debe ser valido!\n");
  }
}

int main(void)
{
  int arr[N];
  int i,j;
  pedirArreglo(arr, N);
  printf("Seleccionar los indices a intercambiar\n");
  pedirIndice(&i);
  pedirIndice(&j);
  intercambiar(arr, N, i, j);
  imprimeArreglo(arr, N);
  return 0;
}

