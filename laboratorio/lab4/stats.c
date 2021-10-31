#define N 4
#include <stdio.h>

struct datos_t {
  float maximo;
  float minimo;
  float promedio;
};

float pedirEntero(void) 
{
  float x;
  printf("Ingresar un numero");
  scanf("%f", &x);
  return x;
}

void pedirArreglo(float a[], int n_max)
{
  printf("Ingrese los elementos reales de un arreglo:\n");
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
struct datos_t stats(float a[], int tam)
{
  int i, sum, imax, imin;
  i = sum = imax = imin = 0;
  struct datos_t s;
  while(i < tam)
  {
    if(a[i] > a[imax]) 
    {
      imax = i;
    }
    if(a[i] < a[imin]) 
    {
      imin = i;
    }
    sum += a[i];
    i++;
  }

  s.maximo = a[imax];
  s.minimo = a[imin];
  s.promedio = sum / tam;
  return s;
}

int main(void)
{
  float arr[N];
  pedirArreglo(arr, N);
  struct datos_t s = stats(arr, N);
  printf("Promedio: %f, Maximo: %f, Minimo: %f\n", s.promedio, s.maximo, s.minimo);
}

