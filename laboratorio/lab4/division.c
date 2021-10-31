#include <stdio.h>

int pedirEntero(void) 
{
  int x;
  printf("Ingresar un numero");
  scanf("%d", &x);
  return x;
}

typedef struct {
  int cociente;
  int resto;
} div_t;

div_t division(int x, int y)
{
  return (div_t){x/y, x%y};
}


int main(void)
{
  int x = pedirEntero();
  int y = pedirEntero();
  div_t d = division(x, y);
  printf("Cociente: %d, Resto: %d\n", d.cociente, d.resto);
}
