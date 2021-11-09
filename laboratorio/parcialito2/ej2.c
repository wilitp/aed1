#include <stdio.h>
#include <assert.h>

int pedirEntero(void) 
{
  int x;
  printf("Ingresar un numero");
  scanf("%d", &x);
  return x;
}

struct orden_t {
  int primero;
  int segundo;
  int tercero;
};

struct orden_t orden(int x, int y, int z)
{
  struct orden_t ord;
  if(x <= y && y <= z)
  {
    ord = (struct orden_t) {x, y, z};
  }
  else if(x <= z && z <= y)
  {
    ord = (struct orden_t) {x, z, y};
  }
  else if(y <= x && x <= z)
  {
    ord = (struct orden_t) {y, x, z};
  }
  else if(y <= z && z <= x)
  {
    ord = (struct orden_t) {y, z, x};
  }
  else if(z <= x && x <= y)
  {
    ord = (struct orden_t) {z, x, y};
  }
  else if(z <= y && y <= x)
  {
    ord = (struct orden_t) {z, y, x};
  }

  return ord;
}

int main(void)
{
  int x, y, z;

  x = pedirEntero();
  y = pedirEntero();
  z = pedirEntero();

  struct orden_t ord = orden(x, y, z);
  printf("Primero: %d, Segundo: %d, Tercero: %d\n", ord.primero, ord.segundo, ord.tercero);
  return 0;
}
