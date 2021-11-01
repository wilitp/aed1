#include <stdio.h>
#include <stdbool.h>
#define N 3

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

bool existe_positivo(int a[], int tam)
{
  bool res = false;
  int i = 0;
  while(i<tam)
  {
    res = res || (a[i] >= 0);
    i++;
  }

  return res;
}

bool todos_positivos(int a[], int tam)
{
  bool res = true;
  int i = 0;
  while(i<tam)
  {
    res = res && (a[i] >= 0);
    i++;
  }

  return res;
}

int main(void)
{
  int arr[N];
  int opt;
  pedirArreglo(arr, N);

  printf("Seleccionar funcion:\n  1.existe_positivo\n  2.todos_positivos\n");
  scanf("%d", &opt);
  while(opt != 1 && opt != 2)
  {
    printf("La seleccion debe ser entre 1 y 2!");
    printf("Seleccionar funcion:\n  1.existe_positivo\n  2.todos_positivos\n");
    scanf("%d", &opt);
  }

  if(opt == 1)
  {
    printf("%s\n", existe_positivo(arr, N) ? "Existe positivo!" : "No existe positivo");
  }

  if(opt == 2)
  {
    printf("%s\n", todos_positivos(arr, N) ? "Todos positivos!" : "No todos positivos!");
  }
  return 0;
}
