#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int pedirEntero(void) 
{
  int x;
  scanf("%d", &x);
  return x;
}


struct asoc_t {
int clave;
int valor;
};

void pedirArreglo(struct asoc_t a[], int n_max)
{
  printf("Ingrese los elementos enteros de un arreglo:\n");
  int i = 0;
  while(i < n_max ) {
    
    printf("Ingresar una clave\n");
    a[i].clave = pedirEntero();

    printf("Ingresar un valor\n");
    a[i].valor = pedirEntero();
    i++;
  }
}


bool hay_asoc(int key, struct asoc_t a[], int tam) 
{
  int i = 0;
  bool res = false;
  while(i < tam ) {
    res = res || (a[i].clave == key);
    i++;
  }
  return res;
}


int main(void)
{
  #define N 2
  struct asoc_t arr[N];
  int key;
  printf("Ingrese una lista de asociaciones\n");
  pedirArreglo(arr, N);
  printf("Ingresar una clave entera");
  key = pedirEntero();
  if(hay_asoc(key, arr, N))
  {
    printf("Hay asociacion!\n");
  }
  else {
    printf("No hay asociacion!\n");
  }

  return 0;
}
