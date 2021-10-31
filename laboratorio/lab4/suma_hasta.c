#include <stdio.h>
#include <assert.h>

int pedirEntero(void) 
{
  int x;
  printf("Ingresar un numero");
  scanf("%d", &x);
  return x;
}

int suma_hasta(int n)
{
  int s = 0;
  
  for(int i = 1; i<=n; i++)
  {
    s += i;
  }

  return s;
}

int suma_hasta_gauss(int n)
{
  
  int s = n*(n+1)/2;
  return s;
}


int main(void)
{
  int x = pedirEntero();
  assert(x >= 0);
  printf("Suma: %d\n", suma_hasta(x));
  printf("Suma gauss: %d\n", suma_hasta_gauss(x));
}
