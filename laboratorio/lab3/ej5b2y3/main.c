#include <stdio.h>
#include <stdbool.h>
#include "../tools/tools.h"

int main(void)
{
  int x, i, temp;
  bool res;

  x = pedirEntero();
  i = pedirEntero();
  temp = pedirEntero();
  res = temp;

  i = 2;
  res = true;

  while(i < x && res)
  {
    res = res && (x % i != 0 );
    i = i + 1;
    printf("x: %d i: %d res: %d \n", x, i, res);
  }
  return 0;
}

/* Primera iteracion: (x->5, y->3, res->1) */
/* Segunda iteracion: (x->5, y->4, res->1) */
/* Tercera iteracion: (x->5, y->5, res->1) */


/* Ejercicio 5.b.2 */

/* - El programa 1 computa el cociente de la division entera entre x e y. */
/* - El programa 2 evalua si x es primo, el valor de res es la respuesta. */
