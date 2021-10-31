#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 1

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

int primo(int n) 
{
  int res = 1;
  int i = 2;
  if(n < 2) 
    res = 0;
  while(i < n && res)
  {
    res = res && (n % i != 0 );
    i = i + 1;
  }
  return res;
}

int nesimo_primo(int n)
{
  int i, cont;
  i = 2;
  cont = N;
  
  while(cont < n)
  {
    i++; 
    if(primo(i))
    {
      cont++;
    }
  }
  return i;
}

// Respuesta a ejs a y b:
int main(void)
{
  int x;
  x = pedirEntero();

  // b
  while(x < N)
  {
    printf("Ingrese un numero mayor o igual a %d\n", N);
    x = pedirEntero();
  }

  // a
  assert(x >= N);
  printf("El %d-esimo primo es %d\n", x, nesimo_primo(x));

  return 0;
}


